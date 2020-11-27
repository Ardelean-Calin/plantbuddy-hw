#include "ble.h"
#include "BLE_config.h"
#include "FreeRTOS.h"
#include "ble_const.h"
#include "bluenrg1_stack.h"
#include "freertos_ble.h"
#include "semphr.h"
#include "sleep.h"
#include "task.h"

/* Private defines */
#define ADV_INTERVAL_FAST_MS 100
#define ADV_INTERVAL_SLOW_MS 1000

#define DEVICE_IDLE_STATE         0
#define DEVICE_ADV_STATE          1
#define DEVICE_CONN_STATE         2
#define DEVICE_SLEEP_STATE        3
#define DEVICE_DISCONNECTED_STATE 4

/* Private variables */
uint8_t  device_state;
uint16_t connection_interval;

/* Static function definitions */
static void vBLEStackInit(void);
static void Set_DeviceConnectable(uint16_t adv_interval);
static void vBLEPeriodicTask(void* pvParams);

/* Binary semaphore used to synchronize Stack Tick and radio ISR. */
SemaphoreHandle_t radioActivitySemaphoreHandle;
/* Mutex used to avoid that the BLE Stack Tick can be interrupted by an ACI
   function in another thread. */
SemaphoreHandle_t BLETickSemaphoreHandle;

void vBLEInit(void)
{
  uint8_t ret;

  /* Create a binary semaphore to sync with radio interrupts */
  radioActivitySemaphoreHandle = xSemaphoreCreateBinary();
  /* Create a mutex semaphore to avoid calling aci functions while
    BTLE_StackTick() is running.*/
  BLETickSemaphoreHandle = xSemaphoreCreateMutex();

  /* BlueNRG-1 stack init */
  ret = BlueNRG_Stack_Initialization(&BlueNRG_Stack_Init_params);
  while (ret)
    ;

  /* Create tasks */
  xTaskCreate(vBLEPeriodicTask, 'BLET', 64, NULL, tskIDLE_PRIORITY + 1, NULL);
}

static void vBLEPeriodicTask(void* pvParams)
{
  /* To make sure no other BLE functions are called from other tasks. */
  //   xSemaphoreTake(BLETickSemaphoreHandle, portMAX_DELAY);

  /* Init the BlueNRG-1 device */
  vBLEStackInit();

  /* Start Beacon Non Connectable Mode*/
  //   Start_Beaconing();

  /* BLE is initialized. Let other tasks call BLE functions. */
  //   xSemaphoreGive(BLETickSemaphoreHandle);

  while (1)
  {
    /* Take the semaphore to avoid that other ACI functions can interrupt the
       execution of BTLE_StackTick();   */
    // xSemaphoreTake(BLETickSemaphoreHandle, portMAX_DELAY);
    BTLE_StackTick();
    Set_DeviceConnectable(ADV_INTERVAL_SLOW_MS);
    // xSemaphoreGive(BLETickSemaphoreHandle);
    if (BlueNRG_Stack_Perform_Deep_Sleep_Check() != SLEEPMODE_RUNNING)
    {
      //   xSemaphoreTake(radioActivitySemaphoreHandle, portMAX_DELAY);
    }
  }
}

static void vBLEStackInit(void)
{
  uint8_t          bdaddr[] = {0x01, 0x00, 0x80, 0xE1, 0x80, 0x02};
  volatile uint8_t ret;
  uint16_t         service_handle;
  uint16_t         dev_name_char_handle;
  uint16_t         appearance_char_handle;
  uint8_t          device_name[] = {'P', 'l', 'a', 'n', 't', 'B', 'u', 'd', 'd', 'y'};

  /* Configure Public address */
  ret = aci_hal_write_config_data(CONFIG_DATA_PUBADDR_OFFSET, CONFIG_DATA_PUBADDR_LEN, bdaddr);

  /* Set the TX Power to -2 dBm */
  ret = aci_hal_set_tx_power_level(1, 4);
  while (ret)
    ;

  /* Init the GATT */
  ret = aci_gatt_init();
  while (ret)
    ;

  /* Init the GAP */
  ret = aci_gap_init(GAP_PERIPHERAL_ROLE,
                     0,
                     sizeof(device_name),
                     &service_handle,
                     &dev_name_char_handle,
                     &appearance_char_handle);
  while (ret)
    ;

  /* Update device name */
  ret = aci_gatt_update_char_value_ext(0,
                                       service_handle,
                                       dev_name_char_handle,
                                       0,
                                       sizeof(device_name),
                                       0,
                                       sizeof(device_name),
                                       device_name);
  while (ret)
    ;
}

/*******************************************************************************
 * Function Name  : Set_DeviceConnectable.
 * Description    : Puts the device in connectable mode.
 * Input          : None.
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
static void Set_DeviceConnectable(uint16_t adv_interval)
{
  uint8_t ret;
  uint8_t local_name[] = {
      AD_TYPE_COMPLETE_LOCAL_NAME, 'P', 'l', 'a', 'n', 't', 'B', 'u', 'd', 'd', 'y'};

  hci_le_set_scan_response_data(0, NULL);

  ret = aci_gap_set_discoverable(ADV_IND,
                                 (adv_interval * 1000) / 625,
                                 (adv_interval * 1000) / 625,
                                 PUBLIC_ADDR,
                                 NO_WHITE_LIST_USE,
                                 sizeof(local_name),
                                 local_name,
                                 0,
                                 NULL,
                                 0,
                                 0);
  if (ret != BLE_STATUS_SUCCESS) {}
  else
  {
    device_state = DEVICE_ADV_STATE;
  }
}