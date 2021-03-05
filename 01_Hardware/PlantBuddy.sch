EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2200 1575 0    50   ~ 0
Soil Humidity Measurement
Text Label 3375 2300 2    50   ~ 0
THR
Text Label 2025 1900 0    50   ~ 0
THR
Wire Wire Line
	2025 1900 2200 1900
Connection ~ 3675 2100
Text Label 3550 1900 2    50   ~ 0
fHumidity
Wire Wire Line
	3550 1900 3200 1900
Wire Wire Line
	3200 2100 3675 2100
Wire Wire Line
	3200 2300 3675 2300
Wire Wire Line
	1900 2300 1900 1700
Wire Wire Line
	1900 1700 2700 1700
Wire Wire Line
	1900 2300 2200 2300
Connection ~ 1900 1700
Wire Wire Line
	1675 1700 1900 1700
$Comp
L PlantBuddy-rescue:GND-power #PWR06
U 1 1 5F7A256D
P 1675 1900
F 0 "#PWR06" H 1675 1650 50  0001 C CNN
F 1 "GND" H 1680 1727 50  0000 C CNN
F 2 "" H 1675 1900 50  0001 C CNN
F 3 "" H 1675 1900 50  0001 C CNN
	1    1675 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3675 1900 3675 1700
Wire Wire Line
	3675 1700 2700 1700
Connection ~ 2700 1700
Wire Wire Line
	3975 2300 3675 2300
Connection ~ 3675 2300
Wire Wire Line
	3975 2500 2700 2500
Connection ~ 2700 2500
Wire Wire Line
	1775 2100 2200 2100
Wire Wire Line
	2700 2500 1775 2500
Wire Wire Line
	1775 2400 1775 2500
Wire Wire Line
	1775 2200 1775 2100
Wire Wire Line
	625  1875 625  1925
Wire Wire Line
	625  1925 1025 1925
Wire Wire Line
	625  1675 625  1625
Wire Wire Line
	625  1625 825  1625
Wire Wire Line
	1025 1925 1450 1925
Connection ~ 1025 1925
Text Label 1450 1925 2    50   ~ 0
~SOIL_EN~
Wire Wire Line
	10450 1000 10175 1000
Text Label 10175 1000 0    50   ~ 0
SWDIO
Wire Wire Line
	10450 900  10175 900 
Text Label 10175 900  0    50   ~ 0
SWCLK
$Comp
L PlantBuddy-rescue:GND-power #PWR040
U 1 1 5F81A7B8
P 10450 1100
F 0 "#PWR040" H 10450 850 50  0001 C CNN
F 1 "GND" H 10455 927 50  0000 C CNN
F 2 "" H 10450 1100 50  0001 C CNN
F 3 "" H 10450 1100 50  0001 C CNN
	1    10450 1100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR09
U 1 1 5F89441F
P 2700 2500
F 0 "#PWR09" H 2700 2250 50  0001 C CNN
F 1 "GND" H 2705 2327 50  0000 C CNN
F 2 "" H 2700 2500 50  0001 C CNN
F 3 "" H 2700 2500 50  0001 C CNN
	1    2700 2500
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:+BATT-power #PWR010
U 1 1 5F85BEB5
P 1375 5625
F 0 "#PWR010" H 1375 5475 50  0001 C CNN
F 1 "+BATT" H 1250 5750 50  0000 C CNN
F 2 "" H 1375 5625 50  0001 C CNN
F 3 "" H 1375 5625 50  0001 C CNN
	1    1375 5625
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR038
U 1 1 5F8EDD3C
P 5150 2375
F 0 "#PWR038" H 5150 2125 50  0001 C CNN
F 1 "GND" H 5155 2202 50  0000 C CNN
F 2 "" H 5150 2375 50  0001 C CNN
F 3 "" H 5150 2375 50  0001 C CNN
	1    5150 2375
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10400 4400 10400 4325
$Comp
L PlantBuddy-rescue:GND-power #PWR019
U 1 1 5F8E4C67
P 6575 5125
F 0 "#PWR019" H 6575 4875 50  0001 C CNN
F 1 "GND" H 6580 4952 50  0000 C CNN
F 2 "" H 6575 5125 50  0001 C CNN
F 3 "" H 6575 5125 50  0001 C CNN
	1    6575 5125
	1    0    0    -1  
$EndComp
Wire Wire Line
	6325 5125 6575 5125
Connection ~ 6575 5125
Wire Wire Line
	6575 5125 6825 5125
Wire Wire Line
	6825 4925 6825 4750
Connection ~ 6825 4925
Text Label 6075 4750 0    50   ~ 0
XC2
Text Label 7075 4750 2    50   ~ 0
XC1
Wire Wire Line
	6325 4750 6325 4925
Connection ~ 6325 4925
Wire Wire Line
	6325 4750 6075 4750
Wire Wire Line
	6825 4750 7075 4750
Wire Wire Line
	7650 4900 7775 4900
Wire Wire Line
	7975 4900 8100 4900
$Comp
L PlantBuddy-rescue:GND-power #PWR024
U 1 1 5F9806CE
P 7875 5100
F 0 "#PWR024" H 7875 4850 50  0001 C CNN
F 1 "GND" H 7880 4927 50  0000 C CNN
F 2 "" H 7875 5100 50  0001 C CNN
F 3 "" H 7875 5100 50  0001 C CNN
	1    7875 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5100 7875 5100
Connection ~ 7875 5100
Wire Wire Line
	7875 5100 8100 5100
Wire Wire Line
	7650 4900 7650 4750
Wire Wire Line
	7650 4750 7375 4750
Connection ~ 7650 4900
Text Label 7375 4750 0    50   ~ 0
XL2
Wire Wire Line
	8100 4750 8375 4750
Text Label 8375 4750 2    50   ~ 0
XL1
Wire Wire Line
	8100 4750 8100 4900
Connection ~ 8100 4900
Text Label 2050 5925 2    50   ~ 0
SDA
Text Label 2050 5825 2    50   ~ 0
SCL
$Comp
L PlantBuddy-rescue:GND-power #PWR0101
U 1 1 5FBEAB3C
P 1375 6325
F 0 "#PWR0101" H 1375 6075 50  0001 C CNN
F 1 "GND" H 1380 6152 50  0000 C CNN
F 2 "" H 1375 6325 50  0001 C CNN
F 3 "" H 1375 6325 50  0001 C CNN
	1    1375 6325
	-1   0    0    -1  
$EndComp
Text Label 2125 6125 2    50   ~ 0
LUX_INT
Wire Wire Line
	2125 6125 1775 6125
Text Notes 2050 6650 2    50   ~ 0
0 to 83865 Lux Light sensor
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0102
U 1 1 5FC30EFA
P 625 1625
F 0 "#PWR0102" H 625 1475 50  0001 C CNN
F 1 "+BATT" H 640 1798 50  0000 C CNN
F 2 "" H 625 1625 50  0001 C CNN
F 3 "" H 625 1625 50  0001 C CNN
	1    625  1625
	1    0    0    -1  
$EndComp
Connection ~ 625  1625
$Comp
L PlantBuddy-rescue:GND-power #PWR026
U 1 1 5F7A91A0
P 1375 4800
F 0 "#PWR026" H 1375 4550 50  0001 C CNN
F 1 "GND" H 1225 4725 50  0000 C CNN
F 2 "" H 1375 4800 50  0001 C CNN
F 3 "" H 1375 4800 50  0001 C CNN
	1    1375 4800
	-1   0    0    -1  
$EndComp
Text Notes 1950 5050 2    50   ~ 0
Temperature & Humidity\nReally cheap: 0.66$
Wire Wire Line
	2450 4050 2450 4100
Wire Wire Line
	2700 4100 2700 4050
Wire Wire Line
	2700 4050 2450 4050
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0105
U 1 1 5FC54A7F
P 3725 7025
F 0 "#PWR0105" H 3725 6875 50  0001 C CNN
F 1 "+BATT" H 3740 7198 50  0000 C CNN
F 2 "" H 3725 7025 50  0001 C CNN
F 3 "" H 3725 7025 50  0001 C CNN
	1    3725 7025
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0106
U 1 1 5FC54E7E
P 3725 7325
F 0 "#PWR0106" H 3725 7075 50  0001 C CNN
F 1 "GND" H 3730 7152 50  0000 C CNN
F 2 "" H 3725 7325 50  0001 C CNN
F 3 "" H 3725 7325 50  0001 C CNN
	1    3725 7325
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0107
U 1 1 5FC5A54D
P 2450 4050
F 0 "#PWR0107" H 2450 3900 50  0001 C CNN
F 1 "+BATT" H 2465 4223 50  0000 C CNN
F 2 "" H 2450 4050 50  0001 C CNN
F 3 "" H 2450 4050 50  0001 C CNN
	1    2450 4050
	1    0    0    -1  
$EndComp
Connection ~ 2450 4050
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0108
U 1 1 5FC5ABA5
P 1375 4200
F 0 "#PWR0108" H 1375 4050 50  0001 C CNN
F 1 "+BATT" H 1390 4373 50  0000 C CNN
F 2 "" H 1375 4200 50  0001 C CNN
F 3 "" H 1375 4200 50  0001 C CNN
	1    1375 4200
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0109
U 1 1 5FC5B8EB
P 10450 800
F 0 "#PWR0109" H 10450 650 50  0001 C CNN
F 1 "+BATT" H 10465 973 50  0000 C CNN
F 2 "" H 10450 800 50  0001 C CNN
F 3 "" H 10450 800 50  0001 C CNN
	1    10450 800 
	1    0    0    -1  
$EndComp
Text Notes 10000 1675 0    50   ~ 0
TODO:\nPut it in such a way that\n it is small and hidden\nWe will need to build \na programming rig for it!
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0110
U 1 1 5FC6607C
P 7850 1600
F 0 "#PWR0110" H 7850 1450 50  0001 C CNN
F 1 "+BATT" H 7865 1773 50  0000 C CNN
F 2 "" H 7850 1600 50  0001 C CNN
F 3 "" H 7850 1600 50  0001 C CNN
	1    7850 1600
	1    0    0    -1  
$EndComp
Text Label 10225 4325 0    50   ~ 0
LEDR
Wire Wire Line
	10225 4325 10400 4325
Wire Wire Line
	1225 1625 1675 1625
Wire Wire Line
	1675 1625 1675 1700
Connection ~ 1675 1700
Text Notes 3375 2725 0    50   ~ 0
Should I put 0402\nor leave 0805?
Wire Wire Line
	1775 5825 2050 5825
Wire Wire Line
	1775 5925 2050 5925
Wire Wire Line
	2450 4300 2450 4400
Entry Wire Line
	2050 5825 2150 5725
Entry Wire Line
	2050 5925 2150 5825
Entry Wire Line
	2050 4400 2150 4500
Wire Wire Line
	1775 4400 2050 4400
Entry Wire Line
	2050 4600 2150 4700
Wire Wire Line
	2050 4600 1775 4600
Text Label 1975 4600 2    50   ~ 0
SDA
Text Label 1975 4400 2    50   ~ 0
SCL
Entry Wire Line
	2600 4500 2700 4400
Entry Wire Line
	2350 4500 2450 4400
Text Label 2450 4400 2    50   ~ 0
SCL
Text Label 2700 4400 2    50   ~ 0
SDA
Text Label 2875 4625 0    50   ~ 0
SDA
Text Label 2875 4725 0    50   ~ 0
SCL
Wire Wire Line
	2700 4300 2700 4400
Wire Wire Line
	2600 4625 2600 4500
Wire Wire Line
	2600 4625 3050 4625
Wire Wire Line
	2350 4725 2350 4500
Wire Wire Line
	2350 4725 3050 4725
Wire Wire Line
	1375 6325 975  6325
Wire Wire Line
	975  5825 975  5625
Wire Wire Line
	975  5625 1375 5625
Text Notes 3750 1875 0    50   ~ 0
N5: The free-air capacitance is 46pF\nyielding a free-air frequency of 700kHz
Text Notes 7625 6175 0    50   ~ 0
A really small cheap button to be used\nfor resetting the bluetooth connection\nor reset to default settings
Wire Wire Line
	3725 7325 3550 7325
Wire Wire Line
	2875 7325 3150 7325
Wire Wire Line
	2875 7025 3350 7025
Text Notes 2825 7700 0    50   ~ 0
Reverse-voltage protection
$Comp
L PlantBuddy-rescue:GND-power #PWR0111
U 1 1 5FC9D7EF
P 8950 5675
F 0 "#PWR0111" H 8950 5425 50  0001 C CNN
F 1 "GND" H 8955 5502 50  0000 C CNN
F 2 "" H 8950 5675 50  0001 C CNN
F 3 "" H 8950 5675 50  0001 C CNN
	1    8950 5675
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 5675 8825 5675
Wire Wire Line
	8425 5675 8275 5675
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0112
U 1 1 5FCBCC7F
P 8275 5475
F 0 "#PWR0112" H 8275 5325 50  0001 C CNN
F 1 "+BATT" H 8290 5648 50  0000 C CNN
F 2 "" H 8275 5475 50  0001 C CNN
F 3 "" H 8275 5475 50  0001 C CNN
	1    8275 5475
	1    0    0    -1  
$EndComp
Text Label 7900 5675 0    50   ~ 0
~BLE_RST
Wire Wire Line
	7900 5675 8275 5675
Connection ~ 8275 5675
Wire Wire Line
	975  6025 975  6125
Connection ~ 1375 5625
Connection ~ 975  6125
Wire Wire Line
	975  6125 975  6325
Connection ~ 1375 6325
Text Notes 9825 5225 0    50   ~ 0
Yellow status LED => short blinks\nto notify user of different actions
$Comp
L PlantBuddy-rescue:R_Small-Device R1
U 1 1 5FCB6EA2
P 8275 5575
F 0 "R1" H 8125 5625 50  0000 L CNN
F 1 "10k" H 8100 5550 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 8275 5575 50  0001 C CNN
F 3 "~" H 8275 5575 50  0001 C CNN
F 4 "C25744" H 8275 5575 50  0001 C CNN "LCSC"
	1    8275 5575
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:SW_Push-Switch SW2
U 1 1 5FC9C6CC
P 8625 5675
F 0 "SW2" H 8575 5525 50  0000 C CNN
F 1 "BLE_RST_SW" H 8625 5600 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_EVQP7C" H 8625 5875 50  0001 C CNN
F 3 "~" H 8625 5875 50  0001 C CNN
F 4 "C388883" H 8625 5675 50  0001 C CNN "LCSC"
	1    8625 5675
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Q_NMOS_GSD-Device Q2
U 1 1 5FC7486C
P 3350 7225
F 0 "Q2" V 3599 7225 50  0000 C CNN
F 1 "AO3400A" V 3690 7225 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3550 7325 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081213_Alpha-Omega-Semicon-AO3400A_C20917.pdf" H 3350 7225 50  0001 C CNN
F 4 "C20917" V 3350 7225 50  0001 C CNN "LCSC"
	1    3350 7225
	0    -1   1    0   
$EndComp
$Comp
L PlantBuddy-rescue:Conn_01x01-Connector_Generic J3
U 1 1 5FC6BCF8
P 3250 4725
F 0 "J3" H 3225 4550 50  0000 L CNN
F 1 "Conn_I2C_SCL" H 3200 4625 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3250 4725 50  0001 C CNN
F 3 "~" H 3250 4725 50  0001 C CNN
	1    3250 4725
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Conn_01x01-Connector_Generic J2
U 1 1 5FC6B510
P 3250 4625
F 0 "J2" H 3225 4825 50  0000 L CNN
F 1 "Conn_I2C_SDA" H 3200 4750 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3250 4625 50  0001 C CNN
F 3 "~" H 3250 4625 50  0001 C CNN
	1    3250 4625
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C3
U 1 1 5FC58638
P 975 5925
F 0 "C3" H 825 6025 50  0000 L CNN
F 1 "100nF" H 675 5875 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 975 5925 50  0001 C CNN
F 3 "~" H 975 5925 50  0001 C CNN
F 4 "C1525" H 975 5925 50  0001 C CNN "LCSC"
	1    975  5925
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:SHTC3-Sensor_Humidity U6
U 1 1 5FC00783
P 1475 4500
F 0 "U6" H 1719 4546 50  0000 L CNN
F 1 "SHTC3" H 1719 4455 50  0000 L CNN
F 2 "PlantBuddy:Sensirion_DFN-4-1EP_2x2mm_P1mm_EP0.7x1.6mm" H 1675 4150 50  0001 C CNN
F 3 "https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/0_Datasheets/Humidity/Sensirion_Humidity_Sensors_SHTC3_Datasheet.pdf" H 1175 4950 50  0001 C CNN
F 4 "C194656" H 1475 4500 50  0001 C CNN "LCSC"
	1    1475 4500
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C16
U 1 1 5FC9C991
P 7350 1700
F 0 "C16" H 7442 1746 50  0000 L CNN
F 1 "1uF" H 7442 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7350 1700 50  0001 C CNN
F 3 "~" H 7350 1700 50  0001 C CNN
F 4 "C52923" H 7350 1700 50  0001 C CNN "LCSC"
	1    7350 1700
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C5
U 1 1 5FC9BF20
P 6650 1975
F 0 "C5" H 6742 2021 50  0000 L CNN
F 1 "100nF" H 6742 1930 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6650 1975 50  0001 C CNN
F 3 "~" H 6650 1975 50  0001 C CNN
F 4 "C1525" H 6650 1975 50  0001 C CNN "LCSC"
	1    6650 1975
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:L_Small-Device L4
U 1 1 5FC85C22
P 7350 1975
F 0 "L4" V 7535 1975 50  0000 C CNN
F 1 "10uH" V 7444 1975 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" H 7350 1975 50  0001 C CNN
F 3 "~" H 7350 1975 50  0001 C CNN
F 4 "C1046" V 7350 1975 50  0001 C CNN "LCSC"
	1    7350 1975
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Battery_Cell-Device BT1
U 1 1 5FC5077F
P 2875 7225
F 0 "BT1" H 2993 7321 50  0000 L CNN
F 1 "Li+" H 2993 7230 50  0000 L CNN
F 2 "PlantBuddy:BatteryHolder_LCSC_2032" V 2875 7285 50  0001 C CNN
F 3 "~" V 2875 7285 50  0001 C CNN
F 4 "C70377" H 2875 7225 50  0001 C CNN "LCSC"
F 5 "CR2032-BS-6-1" H 2875 7225 50  0001 C CNN "MFR"
	1    2875 7225
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R15
U 1 1 5F7AB23C
P 2700 4200
F 0 "R15" H 2759 4246 50  0000 L CNN
F 1 "10k" H 2759 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 2700 4200 50  0001 C CNN
F 3 "~" H 2700 4200 50  0001 C CNN
F 4 "C25744" H 2700 4200 50  0001 C CNN "LCSC"
	1    2700 4200
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R14
U 1 1 5F7AA80B
P 2450 4200
F 0 "R14" H 2509 4246 50  0000 L CNN
F 1 "10k" H 2509 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 2450 4200 50  0001 C CNN
F 3 "~" H 2450 4200 50  0001 C CNN
F 4 "C25744" H 2450 4200 50  0001 C CNN "LCSC"
	1    2450 4200
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C12
U 1 1 5F9CA7B8
P 7850 1700
F 0 "C12" H 7975 1750 50  0000 L CNN
F 1 "100nF" H 7950 1675 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7850 1700 50  0001 C CNN
F 3 "~" H 7850 1700 50  0001 C CNN
F 4 "C1525" H 7850 1700 50  0001 C CNN "LCSC"
	1    7850 1700
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C13
U 1 1 5F96F76E
P 7650 5000
F 0 "C13" H 7559 4954 50  0000 R CNN
F 1 "12pF" H 7559 5045 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7650 5000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 7650 5000 50  0001 C CNN
F 4 "C1547" H 7650 5000 50  0001 C CNN "LCSC"
	1    7650 5000
	1    0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C14
U 1 1 5F96F125
P 8100 5000
F 0 "C14" H 8008 4954 50  0000 R CNN
F 1 "12pF" H 8008 5045 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8100 5000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 8100 5000 50  0001 C CNN
F 4 "C1547" H 8100 5000 50  0001 C CNN "LCSC"
	1    8100 5000
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:Crystal_Small-Device Y2
U 1 1 5F96EABD
P 7875 4900
F 0 "Y2" H 7875 5125 50  0000 C CNN
F 1 "32kHz" H 7875 5034 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm" H 7875 4900 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1901081604_Seiko-Epson-Q13FC1350000400_C32346.pdf" H 7875 4900 50  0001 C CNN
F 4 "C32346" H 7875 4900 50  0001 C CNN "LCSC"
	1    7875 4900
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C11
U 1 1 5F8E6679
P 6825 5025
F 0 "C11" H 6733 4979 50  0000 R CNN
F 1 "12pF" H 6733 5070 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6825 5025 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 6825 5025 50  0001 C CNN
F 4 "C1547" H 6825 5025 50  0001 C CNN "LCSC"
	1    6825 5025
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C6
U 1 1 5F8E556C
P 6325 5025
F 0 "C6" H 6234 4979 50  0000 R CNN
F 1 "12pF" H 6234 5070 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6325 5025 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 6325 5025 50  0001 C CNN
F 4 "C1547" H 6325 5025 50  0001 C CNN "LCSC"
	1    6325 5025
	1    0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R16
U 1 1 5F86CA65
P 10400 4500
F 0 "R16" V 10204 4500 50  0000 C CNN
F 1 "1k" V 10295 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 10400 4500 50  0001 C CNN
F 3 "~" H 10400 4500 50  0001 C CNN
F 4 "C11702" V 10400 4500 50  0001 C CNN "LCSC"
	1    10400 4500
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:LED_Small-Device D2
U 1 1 5F86A474
P 10400 4700
F 0 "D2" V 10446 4630 50  0000 R CNN
F 1 "R" V 10355 4630 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" V 10400 4700 50  0001 C CNN
F 3 "~" V 10400 4700 50  0001 C CNN
F 4 "C2286" V 10400 4700 50  0001 C CNN "LCSC"
	1    10400 4700
	0    -1   -1   0   
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C2
U 1 1 5F8CAA05
P 1775 2300
F 0 "C2" H 1900 2375 50  0000 L CNN
F 1 "100nF" H 1875 2300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 1775 2300 50  0001 C CNN
F 3 "~" H 1775 2300 50  0001 C CNN
F 4 "C1525" H 1775 2300 50  0001 C CNN "LCSC"
	1    1775 2300
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R12
U 1 1 5F89EE4B
P 6000 3575
F 0 "R12" H 6059 3621 50  0000 L CNN
F 1 "10k" H 6059 3530 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 6000 3575 50  0001 C CNN
F 3 "~" H 6000 3575 50  0001 C CNN
F 4 "C25744" H 6000 3575 50  0001 C CNN "LCSC"
	1    6000 3575
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C10
U 1 1 5F89342A
P 8275 1700
F 0 "C10" H 8400 1750 50  0000 L CNN
F 1 "100nF" H 8375 1675 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8275 1700 50  0001 C CNN
F 3 "~" H 8275 1700 50  0001 C CNN
F 4 "C1525" H 8275 1700 50  0001 C CNN "LCSC"
	1    8275 1700
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Antenna_Shield-Device AE1
U 1 1 5F7B40C5
P 5250 2175
F 0 "AE1" H 5394 2214 50  0000 L CNN
F 1 "2.45GHz PCB antenna" H 5394 2123 50  0000 L CNN
F 2 "RF_Antenna:Texas_SWRA117D_2.4GHz_Right" H 5250 2275 50  0001 C CNN
F 3 "~" H 5250 2275 50  0001 C CNN
	1    5250 2175
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R2
U 1 1 5F7A2C9F
P 625 1775
F 0 "R2" H 684 1821 50  0000 L CNN
F 1 "10k" H 684 1730 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 625 1775 50  0001 C CNN
F 3 "~" H 625 1775 50  0001 C CNN
F 4 "C25744" H 625 1775 50  0001 C CNN "LCSC"
	1    625  1775
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:AO3401A-Transistor_FET Q1
U 1 1 5F79FD2D
P 1025 1725
F 0 "Q1" V 1367 1725 50  0000 C CNN
F 1 "AO3401" V 1276 1725 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 1225 1650 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3401A.pdf" H 1025 1725 50  0001 L CNN
F 4 "C15127" V 1025 1725 50  0001 C CNN "LCSC"
	1    1025 1725
	0    1    -1   0   
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C4
U 1 1 5F7A2F2A
P 3975 2400
F 0 "C4" H 4067 2446 50  0000 L CNN
F 1 "C_Probe" H 4067 2355 50  0000 L CNN
F 2 "PlantBuddy:SoilProbe" H 3975 2400 50  0001 C CNN
F 3 "~" H 3975 2400 50  0001 C CNN
	1    3975 2400
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C1
U 1 1 5F7A1B63
P 1675 1800
F 0 "C1" H 1525 1875 50  0000 L CNN
F 1 "100nF" H 1675 1700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 1675 1800 50  0001 C CNN
F 3 "~" H 1675 1800 50  0001 C CNN
F 4 "C1525" H 1675 1800 50  0001 C CNN "LCSC"
	1    1675 1800
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R8
U 1 1 5F79A78D
P 3675 2000
F 0 "R8" H 3734 2046 50  0000 L CNN
F 1 "10k" H 3734 1955 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 3675 2000 50  0001 C CNN
F 3 "~" H 3675 2000 50  0001 C CNN
F 4 "C25744" H 3675 2000 50  0001 C CNN "LCSC"
	1    3675 2000
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R9
U 1 1 5F799CF9
P 3675 2200
F 0 "R9" H 3734 2246 50  0000 L CNN
F 1 "10k" H 3734 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 3675 2200 50  0001 C CNN
F 3 "~" H 3675 2200 50  0001 C CNN
F 4 "C25744" H 3675 2200 50  0001 C CNN "LCSC"
	1    3675 2200
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:LMC555xM-Timer U3
U 1 1 5F7817A6
P 2700 2100
F 0 "U3" H 2375 1750 50  0000 C CNN
F 1 "LMC555xM" H 2950 1750 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3550 1700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lmc555.pdf" H 3550 1700 50  0001 C CNN
F 4 "C90760" H 2700 2100 50  0001 C CNN "LCSC"
	1    2700 2100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy:OPT3001 U1
U 1 1 5FD09708
P 1375 6375
F 0 "U1" H 1375 7396 50  0000 C CNN
F 1 "OPT3001" H 1575 7075 50  0000 C CNN
F 2 "Package_DFN_QFN:DFN-6-1EP_2x2mm_P0.65mm_EP1x1.6mm" H 1375 6375 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/opt3001.pdf" H 1375 6375 50  0001 C CNN
F 4 "C90462" H 1575 6450 50  0001 C CNN "LCSC"
	1    1375 6375
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Conn_01x04-Connector_Generic J1
U 1 1 5F817EB3
P 10650 900
F 0 "J1" H 10730 892 50  0000 L CNN
F 1 "SWD" H 10730 801 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 10650 900 50  0001 C CNN
F 3 "~" H 10650 900 50  0001 C CNN
F 4 "C541879" H 10650 900 50  0001 C CNN "LCSC"
	1    10650 900 
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:LED_Small-Device D1
U 1 1 5FC270B5
P 10025 4700
F 0 "D1" V 10071 4630 50  0000 R CNN
F 1 "Y" V 9980 4630 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" V 10025 4700 50  0001 C CNN
F 3 "~" V 10025 4700 50  0001 C CNN
F 4 "C72038" V 10025 4700 50  0001 C CNN "LCSC"
	1    10025 4700
	0    -1   -1   0   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR01
U 1 1 5FC2781D
P 10225 4800
F 0 "#PWR01" H 10225 4550 50  0001 C CNN
F 1 "GND" H 10230 4627 50  0000 C CNN
F 2 "" H 10225 4800 50  0001 C CNN
F 3 "" H 10225 4800 50  0001 C CNN
	1    10225 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10225 4800 10025 4800
Wire Wire Line
	10225 4800 10400 4800
Connection ~ 10225 4800
$Comp
L PlantBuddy-rescue:R_Small-Device R3
U 1 1 5FC33886
P 10025 4500
F 0 "R3" V 9829 4500 50  0000 C CNN
F 1 "1k" V 9920 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 10025 4500 50  0001 C CNN
F 3 "~" H 10025 4500 50  0001 C CNN
F 4 "C11702" V 10025 4500 50  0001 C CNN "LCSC"
	1    10025 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	10025 4400 10025 4325
Wire Wire Line
	10025 4325 9850 4325
Text Label 9850 4325 0    50   ~ 0
LEDY
$Comp
L PlantBuddy-rescue:nRF52810-QCxx-MCU_Nordic U2
U 1 1 601392C1
P 7150 3075
F 0 "U2" H 6400 2075 50  0000 C CNN
F 1 "nRF52810-QCxx" H 7650 2075 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.6x3.6mm_ThermalVias" H 7150 1725 50  0001 C CNN
F 3 "http://infocenter.nordicsemi.com/pdf/nRF52810_PS_v1.1.pdf" H 6650 3275 50  0001 C CNN
F 4 "C519278" H 7150 3075 50  0001 C CNN "LCSC"
	1    7150 3075
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C8
U 1 1 601440B0
P 6050 2475
F 0 "C8" H 6142 2521 50  0000 L CNN
F 1 "0.8pF" H 6142 2430 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6050 2475 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/YAGEO-CQ0402ARNPO9BNR80_C326068.pdf" H 6050 2475 50  0001 C CNN
F 4 "C326068" H 6050 2475 50  0001 C CNN "LCSC"
	1    6050 2475
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0103
U 1 1 60144A88
P 6050 2575
F 0 "#PWR0103" H 6050 2325 50  0001 C CNN
F 1 "GND" H 6055 2402 50  0000 C CNN
F 2 "" H 6050 2575 50  0001 C CNN
F 3 "" H 6050 2575 50  0001 C CNN
	1    6050 2575
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:L_Small-Device L1
U 1 1 6014BC37
P 5750 2375
F 0 "L1" V 5935 2375 50  0000 C CNN
F 1 "3.9nH" V 5844 2375 50  0000 C CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 5750 2375 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Sunlord-SDCL1005C3N9STDF_C14033.pdf" H 5750 2375 50  0001 C CNN
F 4 "C14033" V 5750 2375 50  0001 C CNN "LCSC"
	1    5750 2375
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6250 2375 6050 2375
Connection ~ 6050 2375
Wire Wire Line
	6050 2375 5850 2375
$Comp
L PlantBuddy-rescue:C_Small-Device C7
U 1 1 601721F0
P 5450 2475
F 0 "C7" H 5542 2521 50  0000 L CNN
F 1 "1.2pF" H 5542 2430 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5450 2475 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Samsung-Electro-Mechanics-CL05C1R2BB5NNNC_C159809.pdf" H 5450 2475 50  0001 C CNN
F 4 "C159809" H 5450 2475 50  0001 C CNN "LCSC"
	1    5450 2475
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0104
U 1 1 6017252E
P 5450 2575
F 0 "#PWR0104" H 5450 2325 50  0001 C CNN
F 1 "GND" H 5455 2402 50  0000 C CNN
F 2 "" H 5450 2575 50  0001 C CNN
F 3 "" H 5450 2575 50  0001 C CNN
	1    5450 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2375 5450 2375
Wire Wire Line
	5450 2375 5250 2375
Connection ~ 5450 2375
Text Label 8250 2475 2    50   ~ 0
XL2
Wire Wire Line
	8250 2475 8050 2475
Text Label 8250 2375 2    50   ~ 0
XL1
Wire Wire Line
	8050 2375 8250 2375
$Comp
L PlantBuddy-rescue:GND-power #PWR0113
U 1 1 601D2FD0
P 7150 4075
F 0 "#PWR0113" H 7150 3825 50  0001 C CNN
F 1 "GND" H 7155 3902 50  0000 C CNN
F 2 "" H 7150 4075 50  0001 C CNN
F 3 "" H 7150 4075 50  0001 C CNN
	1    7150 4075
	1    0    0    -1  
$EndComp
Wire Wire Line
	6475 4925 6325 4925
Wire Wire Line
	6675 4925 6825 4925
NoConn ~ 6575 5025
NoConn ~ 6575 4825
$Comp
L PlantBuddy-rescue:Crystal_GND24_Small-Device Y1
U 1 1 5F8E3B8A
P 6575 4925
F 0 "Y1" H 6675 5150 50  0000 L CNN
F 1 "32MHz" H 6575 5075 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 6575 4925 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/TXC-Corp-7V3205LCSC-EEE4G_C90934.pdf" H 6575 4925 50  0001 C CNN
F 4 "C90934" H 6575 4925 50  0001 C CNN "LCSC"
	1    6575 4925
	1    0    0    -1  
$EndComp
Text Label 6075 3275 0    50   ~ 0
XC2
Text Label 6075 2875 0    50   ~ 0
XC1
Wire Wire Line
	6075 2875 6250 2875
Wire Wire Line
	6075 3275 6250 3275
Wire Wire Line
	3350 7025 3725 7025
Connection ~ 3350 7025
Text Label 8425 2775 2    50   ~ 0
~SOIL_EN~
Text Label 8425 2875 2    50   ~ 0
fHumidity
Text Label 8275 3375 2    50   ~ 0
SCL
Text Label 8275 3275 2    50   ~ 0
SDA
Wire Wire Line
	6250 3875 5975 3875
Text Label 5975 3875 0    50   ~ 0
SWDIO
Wire Wire Line
	6250 3775 5975 3775
Text Label 5975 3775 0    50   ~ 0
SWCLK
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0114
U 1 1 602675D6
P 7150 2075
F 0 "#PWR0114" H 7150 1925 50  0001 C CNN
F 1 "+BATT" H 7165 2248 50  0000 C CNN
F 2 "" H 7150 2075 50  0001 C CNN
F 3 "" H 7150 2075 50  0001 C CNN
	1    7150 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	8275 3375 8050 3375
Wire Wire Line
	8275 3275 8050 3275
Wire Wire Line
	6250 3675 6000 3675
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0115
U 1 1 602A5380
P 6000 3475
F 0 "#PWR0115" H 6000 3325 50  0001 C CNN
F 1 "+BATT" H 5800 3550 50  0000 C CNN
F 2 "" H 6000 3475 50  0001 C CNN
F 3 "" H 6000 3475 50  0001 C CNN
	1    6000 3475
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1875 7350 1800
Wire Wire Line
	7350 1800 6950 1800
Wire Wire Line
	6950 1800 6950 2075
Connection ~ 7350 1800
$Comp
L PlantBuddy-rescue:GND-power #PWR0116
U 1 1 602C4F93
P 7350 1600
F 0 "#PWR0116" H 7350 1350 50  0001 C CNN
F 1 "GND" H 7355 1427 50  0000 C CNN
F 2 "" H 7350 1600 50  0001 C CNN
F 3 "" H 7350 1600 50  0001 C CNN
	1    7350 1600
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0117
U 1 1 602D692B
P 6650 1875
F 0 "#PWR0117" H 6650 1625 50  0001 C CNN
F 1 "GND" H 6655 1702 50  0000 C CNN
F 2 "" H 6650 1875 50  0001 C CNN
F 3 "" H 6650 1875 50  0001 C CNN
	1    6650 1875
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0118
U 1 1 60304C54
P 8700 1800
F 0 "#PWR0118" H 8700 1550 50  0001 C CNN
F 1 "GND" H 8705 1627 50  0000 C CNN
F 2 "" H 8700 1800 50  0001 C CNN
F 3 "" H 8700 1800 50  0001 C CNN
	1    8700 1800
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C15
U 1 1 6030ABD4
P 8700 1700
F 0 "C15" H 8792 1746 50  0000 L CNN
F 1 "4.7uF" H 8792 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8700 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Samsung-Electro-Mechanics-CL05A475MP5NRNC_C23733.pdf" H 8700 1700 50  0001 C CNN
F 4 "C23733" H 8700 1700 50  0001 C CNN "LCSC"
	1    8700 1700
	1    0    0    -1  
$EndComp
Text Notes 8675 1575 0    50   ~ 0
Pin32
Wire Wire Line
	7850 1600 8275 1600
Connection ~ 7850 1600
Wire Wire Line
	7850 1800 8275 1800
Wire Wire Line
	8700 1600 8275 1600
Connection ~ 8275 1600
Wire Wire Line
	8700 1800 8275 1800
Connection ~ 8700 1800
Connection ~ 8275 1800
$Comp
L PlantBuddy-rescue:C_Small-Device C9
U 1 1 60362D2D
P 6850 1975
F 0 "C9" H 6942 2021 50  0000 L CNN
F 1 "100pF" H 6900 1925 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6850 1975 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG101J500NT_C1546.pdf" H 6850 1975 50  0001 C CNN
F 4 "C1546" H 6850 1975 50  0001 C CNN "LCSC"
	1    6850 1975
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 1875 6850 1875
Connection ~ 6650 1875
NoConn ~ 6750 2075
Wire Wire Line
	8425 2775 8050 2775
Wire Wire Line
	8425 2875 8050 2875
Text Label 8325 3475 2    50   ~ 0
LEDR
Text Label 8425 2975 2    50   ~ 0
LUX_INT
Text Label 8450 3175 2    50   ~ 0
~BLE_RST
Wire Wire Line
	8050 3175 8450 3175
Text Label 8325 3575 2    50   ~ 0
LEDY
Wire Wire Line
	8050 3575 8325 3575
Wire Wire Line
	8050 3475 8325 3475
Wire Wire Line
	8425 2975 8050 2975
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0119
U 1 1 6045E4C9
P 8425 2575
F 0 "#PWR0119" H 8425 2425 50  0001 C CNN
F 1 "+BATT" H 8440 2748 50  0000 C CNN
F 2 "" H 8425 2575 50  0001 C CNN
F 3 "" H 8425 2575 50  0001 C CNN
	1    8425 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	8425 2575 8050 2575
Text Notes 8500 2650 0    50   ~ 0
ADC configured with internal reference\nand gain 1/6 => 0 - 3.6V
Text Notes 7275 6875 0    50   ~ 0
Fuck BlueNRG.
NoConn ~ 8050 2675
NoConn ~ 8050 3075
NoConn ~ 8050 3775
NoConn ~ 8050 3875
$Comp
L PlantBuddy-rescue:C_Small-Device C17
U 1 1 60156A34
P 875 4500
F 0 "C17" H 725 4600 50  0000 L CNN
F 1 "100nF" H 575 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 875 4500 50  0001 C CNN
F 3 "~" H 875 4500 50  0001 C CNN
F 4 "C1525" H 875 4500 50  0001 C CNN "LCSC"
	1    875  4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1375 4200 875  4200
Wire Wire Line
	875  4200 875  4400
Connection ~ 1375 4200
Wire Wire Line
	875  4800 1375 4800
Connection ~ 1375 4800
Wire Wire Line
	875  4600 875  4800
Text Notes 7550 6350 0    50   ~ 0
TODO: Muta reset btn-ul mai sus, altfel nu il pot\naccesa din cauza pamantului
Wire Bus Line
	2150 4500 2600 4500
Wire Bus Line
	2150 4500 2150 5825
$EndSCHEMATC
