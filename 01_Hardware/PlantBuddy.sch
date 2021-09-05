EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Plant Buddy"
Date "2021-08-14"
Rev "4"
Comp "G&C"
Comment1 "Rev4: Changed layout to use nRF52832 instead of nRF52811. Improved capacitance sensing"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PlantBuddy-rescue:+BATT-power #PWR010
U 1 1 5F85BEB5
P 1400 6350
F 0 "#PWR010" H 1400 6200 50  0001 C CNN
F 1 "+BATT" H 1225 6625 50  0000 C CNN
F 2 "" H 1400 6350 50  0001 C CNN
F 3 "" H 1400 6350 50  0001 C CNN
	1    1400 6350
	-1   0    0    -1  
$EndComp
Text Label 2075 6650 2    50   ~ 0
SDA
$Comp
L PlantBuddy-rescue:GND-power #PWR0101
U 1 1 5FBEAB3C
P 1400 7150
F 0 "#PWR0101" H 1400 6900 50  0001 C CNN
F 1 "GND" H 1405 6977 50  0000 C CNN
F 2 "" H 1400 7150 50  0001 C CNN
F 3 "" H 1400 7150 50  0001 C CNN
	1    1400 7150
	-1   0    0    -1  
$EndComp
Text Label 650  6750 0    50   ~ 0
LUX_INT
Wire Wire Line
	650  6750 1000 6750
$Comp
L PlantBuddy-rescue:GND-power #PWR026
U 1 1 5F7A91A0
P 1400 5625
F 0 "#PWR026" H 1400 5375 50  0001 C CNN
F 1 "GND" H 1250 5550 50  0000 C CNN
F 2 "" H 1400 5625 50  0001 C CNN
F 3 "" H 1400 5625 50  0001 C CNN
	1    1400 5625
	-1   0    0    -1  
$EndComp
Text Notes 1975 5875 2    50   ~ 0
Temperature & Humidity\nReally cheap: 0.66$
Wire Wire Line
	2475 4875 2475 4925
Wire Wire Line
	2725 4925 2725 4875
Wire Wire Line
	2725 4875 2475 4875
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0105
U 1 1 5FC54A7F
P 3725 6800
F 0 "#PWR0105" H 3725 6650 50  0001 C CNN
F 1 "+BATT" H 3740 6973 50  0000 C CNN
F 2 "" H 3725 6800 50  0001 C CNN
F 3 "" H 3725 6800 50  0001 C CNN
	1    3725 6800
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0106
U 1 1 5FC54E7E
P 3725 7300
F 0 "#PWR0106" H 3725 7050 50  0001 C CNN
F 1 "GND" H 3730 7127 50  0000 C CNN
F 2 "" H 3725 7300 50  0001 C CNN
F 3 "" H 3725 7300 50  0001 C CNN
	1    3725 7300
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0107
U 1 1 5FC5A54D
P 2475 4875
F 0 "#PWR0107" H 2475 4725 50  0001 C CNN
F 1 "+BATT" H 2490 5048 50  0000 C CNN
F 2 "" H 2475 4875 50  0001 C CNN
F 3 "" H 2475 4875 50  0001 C CNN
	1    2475 4875
	1    0    0    -1  
$EndComp
Connection ~ 2475 4875
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0108
U 1 1 5FC5ABA5
P 1400 5025
F 0 "#PWR0108" H 1400 4875 50  0001 C CNN
F 1 "+BATT" H 1415 5198 50  0000 C CNN
F 2 "" H 1400 5025 50  0001 C CNN
F 3 "" H 1400 5025 50  0001 C CNN
	1    1400 5025
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1800 6650 2075 6650
Wire Wire Line
	2475 5125 2475 5225
Entry Wire Line
	2075 6650 2175 6550
Entry Wire Line
	2075 6750 2175 6650
Entry Wire Line
	2075 5225 2175 5325
Wire Wire Line
	1800 5225 2075 5225
Entry Wire Line
	2075 5425 2175 5525
Wire Wire Line
	2075 5425 1800 5425
Text Label 2000 5425 2    50   ~ 0
SDA
Text Label 2000 5225 2    50   ~ 0
SCL
Entry Wire Line
	2625 5325 2725 5225
Entry Wire Line
	2375 5325 2475 5225
Text Label 2475 5225 2    50   ~ 0
SCL
Text Label 2725 5225 2    50   ~ 0
SDA
Text Label 2900 5450 0    50   ~ 0
SDA
Text Label 2900 5550 0    50   ~ 0
SCL
Wire Wire Line
	2725 5125 2725 5225
Wire Wire Line
	2625 5450 2625 5325
Wire Wire Line
	2625 5450 3075 5450
Wire Wire Line
	2375 5550 2375 5325
Wire Wire Line
	2375 5550 3075 5550
Text Notes 2825 7675 0    50   ~ 0
Reverse-voltage protection
$Comp
L PlantBuddy-rescue:Conn_01x01-Connector_Generic J3
U 1 1 5FC6BCF8
P 3275 5550
F 0 "J3" H 3250 5375 50  0000 L CNN
F 1 "Conn_I2C_SCL" H 3225 5450 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3275 5550 50  0001 C CNN
F 3 "~" H 3275 5550 50  0001 C CNN
	1    3275 5550
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Conn_01x01-Connector_Generic J2
U 1 1 5FC6B510
P 3275 5450
F 0 "J2" H 3250 5650 50  0000 L CNN
F 1 "Conn_I2C_SDA" H 3225 5575 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3275 5450 50  0001 C CNN
F 3 "~" H 3275 5450 50  0001 C CNN
	1    3275 5450
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C3
U 1 1 5FC58638
P 550 6750
F 0 "C3" H 600 6900 50  0000 L CNN
F 1 "100nF" H 600 6625 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 550 6750 50  0001 C CNN
F 3 "~" H 550 6750 50  0001 C CNN
F 4 "C1525" H 550 6750 50  0001 C CNN "LCSC"
	1    550  6750
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:SHTC3-Sensor_Humidity U6
U 1 1 5FC00783
P 1500 5325
F 0 "U6" H 1744 5371 50  0000 L CNN
F 1 "SHTC3" H 1744 5280 50  0000 L CNN
F 2 "PlantBuddy:Sensirion_DFN-4-1EP_2x2mm_P1mm_EP0.7x1.6mm" H 1700 4975 50  0001 C CNN
F 3 "https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/0_Datasheets/Humidity/Sensirion_Humidity_Sensors_SHTC3_Datasheet.pdf" H 1200 5775 50  0001 C CNN
F 4 "C194656" H 1500 5325 50  0001 C CNN "LCSC"
	1    1500 5325
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R15
U 1 1 5F7AB23C
P 2725 5025
F 0 "R15" H 2784 5071 50  0000 L CNN
F 1 "10k" H 2784 4980 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 2725 5025 50  0001 C CNN
F 3 "~" H 2725 5025 50  0001 C CNN
F 4 "C25744" H 2725 5025 50  0001 C CNN "LCSC"
	1    2725 5025
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R14
U 1 1 5F7AA80B
P 2475 5025
F 0 "R14" H 2534 5071 50  0000 L CNN
F 1 "10k" H 2534 4980 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 2475 5025 50  0001 C CNN
F 3 "~" H 2475 5025 50  0001 C CNN
F 4 "C25744" H 2475 5025 50  0001 C CNN "LCSC"
	1    2475 5025
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C17
U 1 1 60156A34
P 900 5325
F 0 "C17" H 750 5425 50  0000 L CNN
F 1 "100nF" H 600 5275 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 900 5325 50  0001 C CNN
F 3 "~" H 900 5325 50  0001 C CNN
F 4 "C1525" H 900 5325 50  0001 C CNN "LCSC"
	1    900  5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 5025 900  5025
Wire Wire Line
	900  5025 900  5225
Connection ~ 1400 5025
Wire Wire Line
	900  5625 1400 5625
Connection ~ 1400 5625
Wire Wire Line
	900  5425 900  5625
$Comp
L PlantBuddy-rescue:R_Small-Device R4
U 1 1 6047E951
P 3325 7200
F 0 "R4" H 3175 7250 50  0000 L CNN
F 1 "10k" H 3150 7175 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 3325 7200 50  0001 C CNN
F 3 "~" H 3325 7200 50  0001 C CNN
F 4 "C25744" H 3325 7200 50  0001 C CNN "LCSC"
	1    3325 7200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2875 6900 2875 6800
Wire Wire Line
	2875 7200 2875 7300
Text Label 10925 1275 2    50   ~ 0
~RST
Text Label 10925 875  2    50   ~ 0
SWDIO
Text Label 10925 975  2    50   ~ 0
SWCLK
Wire Wire Line
	10600 875  10925 875 
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0109
U 1 1 6119AC48
P 9825 875
F 0 "#PWR0109" H 9825 725 50  0001 C CNN
F 1 "+BATT" H 9675 1000 50  0000 C CNN
F 2 "" H 9825 875 50  0001 C CNN
F 3 "" H 9825 875 50  0001 C CNN
	1    9825 875 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9825 875  10100 875 
Text Notes 1850 7500 2    50   ~ 0
0 to 65535 Lux Light sensor
$Comp
L PlantBuddy-rescue:C_Small-Device C11
U 1 1 5F8E6679
P 5850 5825
F 0 "C11" H 5758 5779 50  0000 R CNN
F 1 "12pF" H 5758 5870 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5850 5825 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 5850 5825 50  0001 C CNN
F 4 "C1547" H 5850 5825 50  0001 C CNN "LCSC"
	1    5850 5825
	-1   0    0    1   
$EndComp
Connection ~ 5850 5725
$Comp
L PlantBuddy-rescue:C_Small-Device C6
U 1 1 5F8E556C
P 5350 5825
F 0 "C6" H 5259 5779 50  0000 R CNN
F 1 "12pF" H 5259 5870 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5350 5825 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 5350 5825 50  0001 C CNN
F 4 "C1547" H 5350 5825 50  0001 C CNN "LCSC"
	1    5350 5825
	1    0    0    1   
$EndComp
Connection ~ 5350 5725
Wire Wire Line
	5350 5550 5350 5725
$Comp
L PlantBuddy-rescue:Crystal_GND24_Small-Device Y1
U 1 1 5F8E3B8A
P 5600 5725
F 0 "Y1" H 5700 5950 50  0000 L CNN
F 1 "32MHz" H 5600 5875 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 5600 5725 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/TXC-Corp-7V3205LCSC-EEE4G_C90934.pdf" H 5600 5725 50  0001 C CNN
F 4 "C90934" H 5600 5725 50  0001 C CNN "LCSC"
	1    5600 5725
	1    0    0    -1  
$EndComp
NoConn ~ 5600 5625
NoConn ~ 5600 5825
Wire Wire Line
	5700 5725 5850 5725
Wire Wire Line
	5500 5725 5350 5725
$Comp
L PlantBuddy-rescue:Crystal_Small-Device Y2
U 1 1 5F96EABD
P 6900 5700
F 0 "Y2" H 6900 5925 50  0000 C CNN
F 1 "32kHz" H 6900 5834 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm" H 6900 5700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1901081604_Seiko-Epson-Q13FC1350000400_C32346.pdf" H 6900 5700 50  0001 C CNN
F 4 "C32346" H 6900 5700 50  0001 C CNN "LCSC"
	1    6900 5700
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C14
U 1 1 5F96F125
P 7125 5800
F 0 "C14" H 7033 5754 50  0000 R CNN
F 1 "12pF" H 7033 5845 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7125 5800 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 7125 5800 50  0001 C CNN
F 4 "C1547" H 7125 5800 50  0001 C CNN "LCSC"
	1    7125 5800
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C13
U 1 1 5F96F76E
P 6675 5800
F 0 "C13" H 6584 5754 50  0000 R CNN
F 1 "12pF" H 6584 5845 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6675 5800 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 6675 5800 50  0001 C CNN
F 4 "C1547" H 6675 5800 50  0001 C CNN "LCSC"
	1    6675 5800
	1    0    0    1   
$EndComp
Connection ~ 7125 5700
Wire Wire Line
	7125 5550 7125 5700
Text Label 7400 5550 2    50   ~ 0
XL1
Wire Wire Line
	7125 5550 7400 5550
Text Label 6400 5550 0    50   ~ 0
XL2
Connection ~ 6675 5700
Wire Wire Line
	6675 5550 6400 5550
Wire Wire Line
	6675 5700 6675 5550
Wire Wire Line
	6900 5900 7125 5900
Connection ~ 6900 5900
Wire Wire Line
	6675 5900 6900 5900
$Comp
L PlantBuddy-rescue:GND-power #PWR024
U 1 1 5F9806CE
P 6900 5900
F 0 "#PWR024" H 6900 5650 50  0001 C CNN
F 1 "GND" H 6905 5727 50  0000 C CNN
F 2 "" H 6900 5900 50  0001 C CNN
F 3 "" H 6900 5900 50  0001 C CNN
	1    6900 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 5700 7125 5700
Wire Wire Line
	6675 5700 6800 5700
Wire Wire Line
	5850 5550 6100 5550
Wire Wire Line
	5350 5550 5100 5550
Text Label 6100 5550 2    50   ~ 0
XC1
Text Label 5100 5550 0    50   ~ 0
XC2
Wire Wire Line
	5850 5725 5850 5550
Wire Wire Line
	5600 5925 5850 5925
Connection ~ 5600 5925
Wire Wire Line
	5350 5925 5600 5925
$Comp
L PlantBuddy-rescue:GND-power #PWR019
U 1 1 5F8E4C67
P 5600 5925
F 0 "#PWR019" H 5600 5675 50  0001 C CNN
F 1 "GND" H 5605 5752 50  0000 C CNN
F 2 "" H 5600 5925 50  0001 C CNN
F 3 "" H 5600 5925 50  0001 C CNN
	1    5600 5925
	1    0    0    -1  
$EndComp
Wire Wire Line
	7375 3075 7000 3075
Wire Wire Line
	7000 2875 7375 2875
Wire Wire Line
	7000 2775 7375 2775
Text Label 7100 4375 0    50   ~ 0
Discharge
Text Label 7100 4475 0    50   ~ 0
Charge
$Comp
L PlantBuddy-rescue:GND-power #PWR0120
U 1 1 61285F85
P 7675 4675
F 0 "#PWR0120" H 7675 4425 50  0001 C CNN
F 1 "GND" H 7800 4550 50  0000 C CNN
F 2 "" H 7675 4675 50  0001 C CNN
F 3 "" H 7675 4675 50  0001 C CNN
	1    7675 4675
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R101
U 1 1 61260F94
P 7475 4475
F 0 "R101" H 7416 4429 50  0000 R CNN
F 1 "100k" H 7416 4520 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 7475 4475 50  0001 C CNN
F 3 "~" H 7475 4475 50  0001 C CNN
F 4 "C25741" H 7475 4475 50  0001 C CNN "LCSC"
	1    7475 4475
	0    -1   -1   0   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0113
U 1 1 61255887
P 7475 2375
F 0 "#PWR0113" H 7475 2125 50  0001 C CNN
F 1 "GND" H 7325 2325 50  0001 C CNN
F 2 "" H 7475 2375 50  0001 C CNN
F 3 "" H 7475 2375 50  0001 C CNN
	1    7475 2375
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0115
U 1 1 6125528E
P 7475 2875
F 0 "#PWR0115" H 7475 2625 50  0001 C CNN
F 1 "GND" H 7625 2800 50  0001 C CNN
F 2 "" H 7475 2875 50  0001 C CNN
F 3 "" H 7475 2875 50  0001 C CNN
	1    7475 2875
	1    0    0    -1  
$EndComp
Connection ~ 7475 2675
Wire Wire Line
	7800 2675 7475 2675
Connection ~ 7475 2575
Wire Wire Line
	7800 2575 7475 2575
$Comp
L Connector_Generic:Conn_01x02 J102
U 1 1 6124EEAB
P 8000 2575
F 0 "J102" H 8080 2567 50  0000 L CNN
F 1 "NFC Antenna" H 8080 2476 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8000 2575 50  0001 C CNN
F 3 "~" H 8000 2575 50  0001 C CNN
	1    8000 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	7475 2575 7000 2575
Wire Wire Line
	7000 2675 7475 2675
$Comp
L PlantBuddy-rescue:C_Small-Device C102
U 1 1 61247050
P 7475 2775
F 0 "C102" H 7567 2821 50  0000 L CNN
F 1 "N/P" H 7567 2730 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7475 2775 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/YAGEO-CQ0402ARNPO9BNR80_C326068.pdf" H 7475 2775 50  0001 C CNN
F 4 "C326068" H 7475 2775 50  0001 C CNN "LCSC"
	1    7475 2775
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C101
U 1 1 612463B5
P 7475 2475
F 0 "C101" H 7567 2521 50  0000 L CNN
F 1 "N/P" H 7567 2430 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7475 2475 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/YAGEO-CQ0402ARNPO9BNR80_C326068.pdf" H 7475 2475 50  0001 C CNN
F 4 "C326068" H 7475 2475 50  0001 C CNN "LCSC"
	1    7475 2475
	1    0    0    -1  
$EndComp
Connection ~ 6100 4875
Wire Wire Line
	4275 2675 4275 4875
Wire Wire Line
	4275 4875 6100 4875
Wire Wire Line
	4625 2475 5200 2475
$Comp
L PlantBuddy-rescue:GND-power #PWR0102
U 1 1 611D8389
P 6100 4875
F 0 "#PWR0102" H 6100 4625 50  0001 C CNN
F 1 "GND" H 5950 4800 50  0000 C CNN
F 2 "" H 6100 4875 50  0001 C CNN
F 3 "" H 6100 4875 50  0001 C CNN
	1    6100 4875
	1    0    0    -1  
$EndComp
$Comp
L MCU_Nordic:nRF52832-QFxx U101
U 1 1 611BA942
P 6100 3175
F 0 "U101" H 6275 1375 50  0000 C CNN
F 1 "nRF52832-QFxx" H 6525 1450 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-48-1EP_6x6mm_P0.4mm_EP4.6x4.6mm_ThermalVias" H 6100 1075 50  0001 C CNN
F 3 "http://infocenter.nordicsemi.com/pdf/nRF52832_PS_v1.4.pdf" H 5600 3375 50  0001 C CNN
	1    6100 3175
	1    0    0    -1  
$EndComp
Text Label 4700 3775 0    50   ~ 0
~RST
Connection ~ 4950 3775
Wire Wire Line
	4950 3775 4700 3775
Wire Wire Line
	4275 2675 4625 2675
Connection ~ 4625 2675
Wire Wire Line
	4950 3775 5200 3775
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0111
U 1 1 604A80A0
P 4950 3575
F 0 "#PWR0111" H 4950 3425 50  0001 C CNN
F 1 "+BATT" H 4800 3675 50  0000 C CNN
F 2 "" H 4950 3575 50  0001 C CNN
F 3 "" H 4950 3575 50  0001 C CNN
	1    4950 3575
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R1
U 1 1 604A62C8
P 4950 3675
F 0 "R1" H 4800 3725 50  0000 L CNN
F 1 "10k" H 4775 3650 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 4950 3675 50  0001 C CNN
F 3 "~" H 4950 3675 50  0001 C CNN
F 4 "C25744" H 4950 3675 50  0001 C CNN "LCSC"
	1    4950 3675
	-1   0    0    -1  
$EndComp
Text Notes 7450 2150 0    50   ~ 0
ADC configured with internal reference\nand gain 1/6 => 0 - 3.6V
Wire Wire Line
	7375 2075 7000 2075
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0119
U 1 1 6045E4C9
P 7375 2075
F 0 "#PWR0119" H 7375 1925 50  0001 C CNN
F 1 "+BATT" H 7390 2248 50  0000 C CNN
F 2 "" H 7375 2075 50  0001 C CNN
F 3 "" H 7375 2075 50  0001 C CNN
	1    7375 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	7375 3175 7000 3175
Text Label 7375 3075 2    50   ~ 0
SPEAKER
Text Label 7375 3175 2    50   ~ 0
LUX_INT
NoConn ~ 5700 1475
Connection ~ 5600 1275
Wire Wire Line
	5600 1275 5800 1275
$Comp
L PlantBuddy-rescue:C_Small-Device C9
U 1 1 60362D2D
P 5800 1375
F 0 "C9" H 5892 1421 50  0000 L CNN
F 1 "100pF" H 5850 1325 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5800 1375 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG101J500NT_C1546.pdf" H 5800 1375 50  0001 C CNN
F 4 "C1546" H 5800 1375 50  0001 C CNN "LCSC"
	1    5800 1375
	1    0    0    -1  
$EndComp
Connection ~ 8000 1200
Connection ~ 8425 1200
Wire Wire Line
	8425 1200 8000 1200
Connection ~ 8000 1000
Wire Wire Line
	8425 1000 8000 1000
Wire Wire Line
	7575 1200 8000 1200
Connection ~ 7575 1000
Wire Wire Line
	7575 1000 8000 1000
Text Notes 8400 975  0    50   ~ 0
Pin32
$Comp
L PlantBuddy-rescue:C_Small-Device C15
U 1 1 6030ABD4
P 8425 1100
F 0 "C15" H 8517 1146 50  0000 L CNN
F 1 "1uF" H 8517 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8425 1100 50  0001 C CNN
F 3 "~" H 8425 1100 50  0001 C CNN
F 4 "C52923" H 8425 1100 50  0001 C CNN "LCSC"
	1    8425 1100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0118
U 1 1 60304C54
P 8425 1200
F 0 "#PWR0118" H 8425 950 50  0001 C CNN
F 1 "GND" H 8430 1027 50  0000 C CNN
F 2 "" H 8425 1200 50  0001 C CNN
F 3 "" H 8425 1200 50  0001 C CNN
	1    8425 1200
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0117
U 1 1 602D692B
P 5600 1275
F 0 "#PWR0117" H 5600 1025 50  0001 C CNN
F 1 "GND" H 5605 1102 50  0000 C CNN
F 2 "" H 5600 1275 50  0001 C CNN
F 3 "" H 5600 1275 50  0001 C CNN
	1    5600 1275
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0116
U 1 1 602C4F93
P 6300 1000
F 0 "#PWR0116" H 6300 750 50  0001 C CNN
F 1 "GND" H 6305 827 50  0000 C CNN
F 2 "" H 6300 1000 50  0001 C CNN
F 3 "" H 6300 1000 50  0001 C CNN
	1    6300 1000
	-1   0    0    1   
$EndComp
Connection ~ 6300 1200
Wire Wire Line
	5900 1200 5900 1475
Wire Wire Line
	6300 1200 5900 1200
Wire Wire Line
	6300 1275 6300 1200
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0114
U 1 1 602675D6
P 6100 1475
F 0 "#PWR0114" H 6100 1325 50  0001 C CNN
F 1 "+BATT" H 6115 1648 50  0000 C CNN
F 2 "" H 6100 1475 50  0001 C CNN
F 3 "" H 6100 1475 50  0001 C CNN
	1    6100 1475
	1    0    0    -1  
$EndComp
Text Label 4925 3875 0    50   ~ 0
SWCLK
Wire Wire Line
	5200 3875 4925 3875
Text Label 4925 3975 0    50   ~ 0
SWDIO
Wire Wire Line
	5200 3975 4925 3975
Text Label 7375 2775 2    50   ~ 0
SDA
Text Label 7375 2875 2    50   ~ 0
SCL
Wire Wire Line
	5025 3375 5200 3375
Wire Wire Line
	5025 2975 5200 2975
Text Label 5025 2975 0    50   ~ 0
XC1
Text Label 5025 3375 0    50   ~ 0
XC2
Wire Wire Line
	7000 1675 7200 1675
Text Label 7200 1675 2    50   ~ 0
XL1
Wire Wire Line
	7200 1775 7000 1775
Text Label 7200 1775 2    50   ~ 0
XL2
Connection ~ 4025 2475
Wire Wire Line
	4025 2475 3825 2475
Wire Wire Line
	4225 2475 4025 2475
$Comp
L PlantBuddy-rescue:GND-power #PWR0104
U 1 1 6017252E
P 4025 2675
F 0 "#PWR0104" H 4025 2425 50  0001 C CNN
F 1 "GND" H 4030 2502 50  0000 C CNN
F 2 "" H 4025 2675 50  0001 C CNN
F 3 "" H 4025 2675 50  0001 C CNN
	1    4025 2675
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C7
U 1 1 601721F0
P 4025 2575
F 0 "C7" H 4117 2621 50  0000 L CNN
F 1 "1.2pF" H 4117 2530 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4025 2575 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Samsung-Electro-Mechanics-CL05C1R2BB5NNNC_C159809.pdf" H 4025 2575 50  0001 C CNN
F 4 "C159809" H 4025 2575 50  0001 C CNN "LCSC"
	1    4025 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4625 2475 4425 2475
Connection ~ 4625 2475
$Comp
L PlantBuddy-rescue:L_Small-Device L1
U 1 1 6014BC37
P 4325 2475
F 0 "L1" V 4510 2475 50  0000 C CNN
F 1 "3.9nH" V 4419 2475 50  0000 C CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 4325 2475 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Sunlord-SDCL1005C3N9STDF_C14033.pdf" H 4325 2475 50  0001 C CNN
F 4 "C14033" V 4325 2475 50  0001 C CNN "LCSC"
	1    4325 2475
	0    -1   -1   0   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0103
U 1 1 60144A88
P 4625 2675
F 0 "#PWR0103" H 4625 2425 50  0001 C CNN
F 1 "GND" H 4630 2502 50  0000 C CNN
F 2 "" H 4625 2675 50  0001 C CNN
F 3 "" H 4625 2675 50  0001 C CNN
	1    4625 2675
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C8
U 1 1 601440B0
P 4625 2575
F 0 "C8" H 4717 2621 50  0000 L CNN
F 1 "0.8pF" H 4717 2530 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4625 2575 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/YAGEO-CQ0402ARNPO9BNR80_C326068.pdf" H 4625 2575 50  0001 C CNN
F 4 "C285068" H 4625 2575 50  0001 C CNN "LCSC"
	1    4625 2575
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C4
U 1 1 5F7A2F2A
P 7675 4575
F 0 "C4" H 7767 4621 50  0000 L CNN
F 1 "C_Probe" H 7767 4530 50  0000 L CNN
F 2 "PlantBuddy:SoilProbe" H 7675 4575 50  0001 C CNN
F 3 "~" H 7675 4575 50  0001 C CNN
	1    7675 4575
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Antenna_Shield-Device AE1
U 1 1 5F7B40C5
P 3825 2275
F 0 "AE1" H 3969 2314 50  0000 L CNN
F 1 "2.45GHz PCB antenna" H 3969 2223 50  0000 L CNN
F 2 "RF_Antenna:Texas_SWRA117D_2.4GHz_Right" H 3825 2375 50  0001 C CNN
F 3 "~" H 3825 2375 50  0001 C CNN
	1    3825 2275
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C10
U 1 1 5F89342A
P 8000 1100
F 0 "C10" H 8125 1150 50  0000 L CNN
F 1 "100nF" H 8100 1075 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8000 1100 50  0001 C CNN
F 3 "~" H 8000 1100 50  0001 C CNN
F 4 "C1525" H 8000 1100 50  0001 C CNN "LCSC"
	1    8000 1100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C12
U 1 1 5F9CA7B8
P 7575 1100
F 0 "C12" H 7700 1150 50  0000 L CNN
F 1 "100nF" H 7675 1075 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7575 1100 50  0001 C CNN
F 3 "~" H 7575 1100 50  0001 C CNN
F 4 "C1525" H 7575 1100 50  0001 C CNN "LCSC"
	1    7575 1100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:L_Small-Device L4
U 1 1 5FC85C22
P 6300 1375
F 0 "L4" V 6485 1375 50  0000 C CNN
F 1 "10uH" V 6394 1375 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" H 6300 1375 50  0001 C CNN
F 3 "~" H 6300 1375 50  0001 C CNN
F 4 "C95978" V 6300 1375 50  0001 C CNN "LCSC"
	1    6300 1375
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C5
U 1 1 5FC9BF20
P 5600 1375
F 0 "C5" H 5692 1421 50  0000 L CNN
F 1 "100nF" H 5692 1330 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5600 1375 50  0001 C CNN
F 3 "~" H 5600 1375 50  0001 C CNN
F 4 "C1525" H 5600 1375 50  0001 C CNN "LCSC"
	1    5600 1375
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C16
U 1 1 5FC9C991
P 6300 1100
F 0 "C16" H 6392 1146 50  0000 L CNN
F 1 "1uF" H 6392 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6300 1100 50  0001 C CNN
F 3 "~" H 6300 1100 50  0001 C CNN
F 4 "C52923" H 6300 1100 50  0001 C CNN "LCSC"
	1    6300 1100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0110
U 1 1 5FC6607C
P 7575 1000
F 0 "#PWR0110" H 7575 850 50  0001 C CNN
F 1 "+BATT" H 7590 1173 50  0000 C CNN
F 2 "" H 7575 1000 50  0001 C CNN
F 3 "" H 7575 1000 50  0001 C CNN
	1    7575 1000
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR038
U 1 1 5F8EDD3C
P 3725 2475
F 0 "#PWR038" H 3725 2225 50  0001 C CNN
F 1 "GND" H 3730 2302 50  0000 C CNN
F 2 "" H 3725 2475 50  0001 C CNN
F 3 "" H 3725 2475 50  0001 C CNN
	1    3725 2475
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10600 975  10925 975 
Wire Wire Line
	10600 1275 10925 1275
Wire Wire Line
	7575 4475 7675 4475
Wire Wire Line
	7675 4375 7000 4375
Wire Wire Line
	7000 4475 7375 4475
Wire Wire Line
	7675 4475 7675 4375
Connection ~ 7675 4475
NoConn ~ 7000 4575
NoConn ~ 7000 4675
NoConn ~ 7000 4275
NoConn ~ 7000 4175
NoConn ~ 7000 4075
NoConn ~ 7000 3975
NoConn ~ 7000 3875
NoConn ~ 7000 3775
NoConn ~ 7000 3375
NoConn ~ 7000 3275
NoConn ~ 7000 2475
NoConn ~ 7000 2375
NoConn ~ 7000 2275
NoConn ~ 7000 2175
NoConn ~ 7000 1975
NoConn ~ 7000 1875
Wire Wire Line
	9825 975  9825 1075
Wire Wire Line
	10100 975  9825 975 
Wire Wire Line
	10100 1075 9825 1075
Connection ~ 9825 975 
Wire Wire Line
	9725 975  9825 975 
$Comp
L PlantBuddy-rescue:GND-power #PWR0112
U 1 1 6119F486
P 9725 975
F 0 "#PWR0112" H 9725 725 50  0001 C CNN
F 1 "GND" H 9875 900 50  0001 C CNN
F 2 "" H 9725 975 50  0001 C CNN
F 3 "" H 9725 975 50  0001 C CNN
	1    9725 975 
	1    0    0    -1  
$EndComp
Connection ~ 1400 6350
$Comp
L Sensor_Optical:LTR-303ALS-01 U102
U 1 1 611AA492
P 1400 6750
F 0 "U102" H 1400 7331 50  0000 C CNN
F 1 "LTR-303ALS-01" H 1050 6350 50  0000 C CNN
F 2 "OptoDevice:Lite-On_LTR-303ALS-01" H 1400 7200 50  0001 C CNN
F 3 "http://optoelectronics.liteon.com/upload/download/DS86-2013-0004/LTR-303ALS-01_DS_V1.pdf" H 1100 7100 50  0001 C CNN
	1    1400 6750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	550  6350 550  6650
Wire Wire Line
	550  6350 1400 6350
Wire Wire Line
	1400 7150 550  7150
Wire Wire Line
	550  6850 550  7150
Connection ~ 1400 7150
Text Label 2075 6750 2    50   ~ 0
SCL
Wire Wire Line
	2075 6750 2025 6750
Wire Wire Line
	2025 6750 2025 6850
Wire Wire Line
	2025 6850 1800 6850
Text Notes 9825 5500 0    50   ~ 0
TODO: Consider micro-speaker with low-cost low-power driver\nNOTE: Piezo-electric speaker should be enough
$Comp
L PlantBuddy-rescue:Battery_Cell-Device BT1
U 1 1 5FC5077F
P 2875 7100
F 0 "BT1" H 2993 7196 50  0000 L CNN
F 1 "Li+" H 2993 7105 50  0000 L CNN
F 2 "PlantBuddy:BAT-HLD-001" V 2875 7160 50  0001 C CNN
F 3 "~" V 2875 7160 50  0001 C CNN
F 4 "" H 2875 7100 50  0001 C CNN "LCSC"
F 5 "CR2032-BS-6-1" H 2875 7100 50  0001 C CNN "MFR"
	1    2875 7100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:AO3401A Q101
U 1 1 6134A6DD
P 3325 6900
F 0 "Q101" V 3667 6900 50  0000 C CNN
F 1 "AO3401A" V 3576 6900 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3525 6825 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3401A.pdf" H 3325 6900 50  0001 L CNN
	1    3325 6900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3125 6800 2875 6800
Wire Wire Line
	3525 6800 3725 6800
Wire Wire Line
	2875 7300 3325 7300
Wire Wire Line
	3325 7300 3725 7300
Connection ~ 3325 7300
Text Notes 7875 2850 0    50   ~ 0
TODO: Do we really need NFC?
Text Label 10925 1075 2    50   ~ 0
SWO
Wire Wire Line
	10600 1075 10925 1075
Text Label 7375 3475 2    50   ~ 0
SWO
Wire Wire Line
	7375 3475 7000 3475
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J101
U 1 1 6136EE02
P 10300 1075
F 0 "J101" H 10350 1492 50  0000 C CNN
F 1 "J-Link SWD" H 10350 1401 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical_SMD" H 10300 1075 50  0001 C CNN
F 3 "~" H 10300 1075 50  0001 C CNN
	1    10300 1075
	1    0    0    -1  
$EndComp
NoConn ~ 10600 1175
NoConn ~ 10100 1175
Text Notes 9375 1200 0    50   ~ 0
Non-existent ->
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0121
U 1 1 6137FB50
P 9825 1275
F 0 "#PWR0121" H 9825 1125 50  0001 C CNN
F 1 "+BATT" H 9675 1400 50  0000 C CNN
F 2 "" H 9825 1275 50  0001 C CNN
F 3 "" H 9825 1275 50  0001 C CNN
	1    9825 1275
	-1   0    0    1   
$EndComp
Wire Wire Line
	9825 1275 10100 1275
NoConn ~ 7000 2975
$Comp
L Device:Speaker_Crystal LS101
U 1 1 6138F133
P 10325 3925
F 0 "LS101" H 10500 3921 50  0000 L CNN
F 1 "Speaker_Crystal" H 10500 3830 50  0000 L CNN
F 2 "" H 10290 3875 50  0001 C CNN
F 3 "~" H 10290 3875 50  0001 C CNN
	1    10325 3925
	1    0    0    -1  
$EndComp
NoConn ~ 7000 3575
NoConn ~ 7000 3675
Wire Bus Line
	2175 5325 2625 5325
Wire Bus Line
	2175 5325 2175 6650
$EndSCHEMATC
