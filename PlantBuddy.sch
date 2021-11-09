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
L PlantBuddy-rescue:+BATT-power #PWR0105
U 1 1 5FC54A7F
P 2375 1350
F 0 "#PWR0105" H 2375 1200 50  0001 C CNN
F 1 "+BATT" H 2390 1523 50  0000 C CNN
F 2 "" H 2375 1350 50  0001 C CNN
F 3 "" H 2375 1350 50  0001 C CNN
	1    2375 1350
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0106
U 1 1 5FC54E7E
P 1750 1850
F 0 "#PWR0106" H 1750 1600 50  0001 C CNN
F 1 "GND" H 1755 1677 50  0000 C CNN
F 2 "" H 1750 1850 50  0001 C CNN
F 3 "" H 1750 1850 50  0001 C CNN
	1    1750 1850
	1    0    0    -1  
$EndComp
Text Notes 650  2275 0    50   ~ 0
Reverse-voltage protection + Current measurement
$Comp
L PlantBuddy-rescue:R_Small-Device R4
U 1 1 6047E951
P 1350 1750
F 0 "R4" H 1200 1800 50  0000 L CNN
F 1 "10k" H 1175 1725 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1350 1750 50  0001 C CNN
F 3 "~" H 1350 1750 50  0001 C CNN
F 4 "C25744" H 1350 1750 50  0001 C CNN "LCSC"
	1    1350 1750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	900  1450 900  1350
Wire Wire Line
	900  1750 900  1850
Text Label 5125 1575 2    50   ~ 0
~RST
Text Label 5125 1175 2    50   ~ 0
SWDIO
Text Label 5125 1275 2    50   ~ 0
SWCLK
Wire Wire Line
	4800 1175 5125 1175
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0109
U 1 1 6119AC48
P 4025 1175
F 0 "#PWR0109" H 4025 1025 50  0001 C CNN
F 1 "+BATT" H 3875 1300 50  0000 C CNN
F 2 "" H 4025 1175 50  0001 C CNN
F 3 "" H 4025 1175 50  0001 C CNN
	1    4025 1175
	1    0    0    -1  
$EndComp
Wire Wire Line
	4025 1175 4300 1175
$Comp
L PlantBuddy-rescue:C_Small-Device C11
U 1 1 5F8E6679
P 1800 6100
F 0 "C11" H 1708 6054 50  0000 R CNN
F 1 "12pF" H 1708 6145 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1800 6100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 1800 6100 50  0001 C CNN
F 4 "C1547" H 1800 6100 50  0001 C CNN "LCSC"
	1    1800 6100
	-1   0    0    1   
$EndComp
Connection ~ 1800 6000
$Comp
L PlantBuddy-rescue:C_Small-Device C6
U 1 1 5F8E556C
P 1300 6100
F 0 "C6" H 1209 6054 50  0000 R CNN
F 1 "12pF" H 1209 6145 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1300 6100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 1300 6100 50  0001 C CNN
F 4 "C1547" H 1300 6100 50  0001 C CNN "LCSC"
	1    1300 6100
	1    0    0    1   
$EndComp
Connection ~ 1300 6000
Wire Wire Line
	1300 5825 1300 6000
$Comp
L PlantBuddy-rescue:Crystal_GND24_Small-Device Y1
U 1 1 5F8E3B8A
P 1550 6000
F 0 "Y1" H 1650 6225 50  0000 L CNN
F 1 "32MHz" H 1550 6150 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 1550 6000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/TXC-Corp-7V3205LCSC-EEE4G_C90934.pdf" H 1550 6000 50  0001 C CNN
F 4 "C90934" H 1550 6000 50  0001 C CNN "LCSC"
	1    1550 6000
	1    0    0    -1  
$EndComp
NoConn ~ 1550 5900
NoConn ~ 1550 6100
Wire Wire Line
	1650 6000 1800 6000
Wire Wire Line
	1450 6000 1300 6000
$Comp
L PlantBuddy-rescue:Crystal_Small-Device Y2
U 1 1 5F96EABD
P 1550 6900
F 0 "Y2" H 1550 7125 50  0000 C CNN
F 1 "32kHz" H 1550 7034 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm" H 1550 6900 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1901081604_Seiko-Epson-Q13FC1350000400_C32346.pdf" H 1550 6900 50  0001 C CNN
F 4 "C32346" H 1550 6900 50  0001 C CNN "LCSC"
	1    1550 6900
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C14
U 1 1 5F96F125
P 1775 7000
F 0 "C14" H 1683 6954 50  0000 R CNN
F 1 "12pF" H 1683 7045 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1775 7000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 1775 7000 50  0001 C CNN
F 4 "C1547" H 1775 7000 50  0001 C CNN "LCSC"
	1    1775 7000
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C13
U 1 1 5F96F76E
P 1325 7000
F 0 "C13" H 1234 6954 50  0000 R CNN
F 1 "12pF" H 1234 7045 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1325 7000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG120J500NT_C1547.pdf" H 1325 7000 50  0001 C CNN
F 4 "C1547" H 1325 7000 50  0001 C CNN "LCSC"
	1    1325 7000
	1    0    0    1   
$EndComp
Connection ~ 1775 6900
Wire Wire Line
	1775 6750 1775 6900
Text Label 2050 6750 2    50   ~ 0
XL1
Wire Wire Line
	1775 6750 2050 6750
Text Label 1050 6750 0    50   ~ 0
XL2
Connection ~ 1325 6900
Wire Wire Line
	1325 6750 1050 6750
Wire Wire Line
	1325 6900 1325 6750
Wire Wire Line
	1550 7100 1775 7100
Connection ~ 1550 7100
Wire Wire Line
	1325 7100 1550 7100
$Comp
L PlantBuddy-rescue:GND-power #PWR024
U 1 1 5F9806CE
P 1550 7100
F 0 "#PWR024" H 1550 6850 50  0001 C CNN
F 1 "GND" H 1555 6927 50  0000 C CNN
F 2 "" H 1550 7100 50  0001 C CNN
F 3 "" H 1550 7100 50  0001 C CNN
	1    1550 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6900 1775 6900
Wire Wire Line
	1325 6900 1450 6900
Wire Wire Line
	1800 5825 2050 5825
Wire Wire Line
	1300 5825 1050 5825
Text Label 2050 5825 2    50   ~ 0
XC1
Text Label 1050 5825 0    50   ~ 0
XC2
Wire Wire Line
	1800 6000 1800 5825
Wire Wire Line
	1550 6200 1800 6200
Connection ~ 1550 6200
Wire Wire Line
	1300 6200 1550 6200
$Comp
L PlantBuddy-rescue:GND-power #PWR019
U 1 1 5F8E4C67
P 1550 6200
F 0 "#PWR019" H 1550 5950 50  0001 C CNN
F 1 "GND" H 1555 6027 50  0000 C CNN
F 2 "" H 1550 6200 50  0001 C CNN
F 3 "" H 1550 6200 50  0001 C CNN
	1    1550 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4050 7025 4050
Wire Wire Line
	7025 3950 7400 3950
Wire Wire Line
	7025 3750 7400 3750
Text Label 7400 5350 2    50   ~ 0
Measure
Text Label 7400 5450 2    50   ~ 0
Charge
$Comp
L PlantBuddy-rescue:GND-power #PWR0120
U 1 1 61285F85
P 4400 7200
F 0 "#PWR0120" H 4400 6950 50  0001 C CNN
F 1 "GND" H 4525 7075 50  0000 C CNN
F 2 "" H 4400 7200 50  0001 C CNN
F 3 "" H 4400 7200 50  0001 C CNN
	1    4400 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R101
U 1 1 61260F94
P 3800 7000
F 0 "R101" H 3741 6954 50  0000 R CNN
F 1 "0R" H 3741 7045 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3800 7000 50  0001 C CNN
F 3 "~" H 3800 7000 50  0001 C CNN
F 4 "C25741" H 3800 7000 50  0001 C CNN "LCSC"
	1    3800 7000
	0    -1   -1   0   
$EndComp
Connection ~ 6125 5850
Wire Wire Line
	4300 3650 4300 5850
Wire Wire Line
	4300 5850 6125 5850
Wire Wire Line
	4650 3450 5225 3450
$Comp
L PlantBuddy-rescue:GND-power #PWR0102
U 1 1 611D8389
P 6125 5850
F 0 "#PWR0102" H 6125 5600 50  0001 C CNN
F 1 "GND" H 5975 5775 50  0000 C CNN
F 2 "" H 6125 5850 50  0001 C CNN
F 3 "" H 6125 5850 50  0001 C CNN
	1    6125 5850
	1    0    0    -1  
$EndComp
$Comp
L MCU_Nordic:nRF52832-QFxx U101
U 1 1 611BA942
P 6125 4150
F 0 "U101" H 6300 2350 50  0000 C CNN
F 1 "nRF52832-QFxx" H 6550 2425 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-48-1EP_6x6mm_P0.4mm_EP4.6x4.6mm_ThermalVias" H 6125 2050 50  0001 C CNN
F 3 "http://infocenter.nordicsemi.com/pdf/nRF52832_PS_v1.4.pdf" H 5625 4350 50  0001 C CNN
	1    6125 4150
	1    0    0    -1  
$EndComp
Text Label 4725 4750 0    50   ~ 0
~RST
Connection ~ 4975 4750
Wire Wire Line
	4975 4750 4725 4750
Wire Wire Line
	4300 3650 4650 3650
Connection ~ 4650 3650
Wire Wire Line
	4975 4750 5225 4750
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0111
U 1 1 604A80A0
P 4975 4550
F 0 "#PWR0111" H 4975 4400 50  0001 C CNN
F 1 "+BATT" H 4825 4650 50  0000 C CNN
F 2 "" H 4975 4550 50  0001 C CNN
F 3 "" H 4975 4550 50  0001 C CNN
	1    4975 4550
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:R_Small-Device R1
U 1 1 604A62C8
P 4975 4650
F 0 "R1" H 4825 4700 50  0000 L CNN
F 1 "10k" H 4800 4625 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4975 4650 50  0001 C CNN
F 3 "~" H 4975 4650 50  0001 C CNN
F 4 "C25744" H 4975 4650 50  0001 C CNN "LCSC"
	1    4975 4650
	-1   0    0    -1  
$EndComp
Text Notes 8000 3375 0    50   ~ 0
ADC configured with internal reference\nand gain 1/6 => 0 - 3.6V
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0119
U 1 1 6045E4C9
P 8250 3150
F 0 "#PWR0119" H 8250 3000 50  0001 C CNN
F 1 "+BATT" H 8265 3323 50  0000 C CNN
F 2 "" H 8250 3150 50  0001 C CNN
F 3 "" H 8250 3150 50  0001 C CNN
	1    8250 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3850 7025 3850
Text Label 7400 4050 2    50   ~ 0
SPEAKER
Text Label 7400 3850 2    50   ~ 0
LUX_INT
NoConn ~ 5725 2450
Connection ~ 5625 2250
Wire Wire Line
	5625 2250 5825 2250
$Comp
L PlantBuddy-rescue:C_Small-Device C9
U 1 1 60362D2D
P 5825 2350
F 0 "C9" H 5917 2396 50  0000 L CNN
F 1 "100pF" H 5875 2300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5825 2350 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Guangdong-Fenghua-Advanced-Tech-0402CG101J500NT_C1546.pdf" H 5825 2350 50  0001 C CNN
F 4 "C1546" H 5825 2350 50  0001 C CNN "LCSC"
	1    5825 2350
	1    0    0    -1  
$EndComp
Connection ~ 8025 2175
Connection ~ 8450 2175
Wire Wire Line
	8450 2175 8025 2175
Connection ~ 8025 1975
Wire Wire Line
	8450 1975 8025 1975
Wire Wire Line
	7600 2175 8025 2175
Connection ~ 7600 1975
Wire Wire Line
	7600 1975 8025 1975
Text Notes 8425 1950 0    50   ~ 0
Pin32
$Comp
L PlantBuddy-rescue:C_Small-Device C15
U 1 1 6030ABD4
P 8450 2075
F 0 "C15" H 8542 2121 50  0000 L CNN
F 1 "1uF" H 8542 2030 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8450 2075 50  0001 C CNN
F 3 "~" H 8450 2075 50  0001 C CNN
F 4 "C52923" H 8450 2075 50  0001 C CNN "LCSC"
	1    8450 2075
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0118
U 1 1 60304C54
P 8450 2175
F 0 "#PWR0118" H 8450 1925 50  0001 C CNN
F 1 "GND" H 8455 2002 50  0000 C CNN
F 2 "" H 8450 2175 50  0001 C CNN
F 3 "" H 8450 2175 50  0001 C CNN
	1    8450 2175
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0117
U 1 1 602D692B
P 5625 2250
F 0 "#PWR0117" H 5625 2000 50  0001 C CNN
F 1 "GND" H 5630 2077 50  0000 C CNN
F 2 "" H 5625 2250 50  0001 C CNN
F 3 "" H 5625 2250 50  0001 C CNN
	1    5625 2250
	-1   0    0    1   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0116
U 1 1 602C4F93
P 6325 1975
F 0 "#PWR0116" H 6325 1725 50  0001 C CNN
F 1 "GND" H 6330 1802 50  0000 C CNN
F 2 "" H 6325 1975 50  0001 C CNN
F 3 "" H 6325 1975 50  0001 C CNN
	1    6325 1975
	-1   0    0    1   
$EndComp
Connection ~ 6325 2175
Wire Wire Line
	5925 2175 5925 2450
Wire Wire Line
	6325 2175 5925 2175
Wire Wire Line
	6325 2250 6325 2175
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0114
U 1 1 602675D6
P 6125 2450
F 0 "#PWR0114" H 6125 2300 50  0001 C CNN
F 1 "+BATT" H 6140 2623 50  0000 C CNN
F 2 "" H 6125 2450 50  0001 C CNN
F 3 "" H 6125 2450 50  0001 C CNN
	1    6125 2450
	1    0    0    -1  
$EndComp
Text Label 4950 4850 0    50   ~ 0
SWCLK
Wire Wire Line
	5225 4850 4950 4850
Text Label 4950 4950 0    50   ~ 0
SWDIO
Wire Wire Line
	5225 4950 4950 4950
Text Label 7400 3750 2    50   ~ 0
SDA
Text Label 7400 3950 2    50   ~ 0
SCL
Wire Wire Line
	5050 4350 5225 4350
Wire Wire Line
	5050 3950 5225 3950
Text Label 5050 3950 0    50   ~ 0
XC1
Text Label 5050 4350 0    50   ~ 0
XC2
Wire Wire Line
	7025 2650 7225 2650
Text Label 7225 2650 2    50   ~ 0
XL1
Wire Wire Line
	7225 2750 7025 2750
Text Label 7225 2750 2    50   ~ 0
XL2
Connection ~ 4050 3450
Wire Wire Line
	4050 3450 3850 3450
Wire Wire Line
	4250 3450 4050 3450
$Comp
L PlantBuddy-rescue:GND-power #PWR0104
U 1 1 6017252E
P 4050 3650
F 0 "#PWR0104" H 4050 3400 50  0001 C CNN
F 1 "GND" H 4055 3477 50  0000 C CNN
F 2 "" H 4050 3650 50  0001 C CNN
F 3 "" H 4050 3650 50  0001 C CNN
	1    4050 3650
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C7
U 1 1 601721F0
P 4050 3550
F 0 "C7" H 4142 3596 50  0000 L CNN
F 1 "1.2pF" H 4142 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4050 3550 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Samsung-Electro-Mechanics-CL05C1R2BB5NNNC_C159809.pdf" H 4050 3550 50  0001 C CNN
F 4 "C159809" H 4050 3550 50  0001 C CNN "LCSC"
	1    4050 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3450 4450 3450
Connection ~ 4650 3450
$Comp
L PlantBuddy-rescue:L_Small-Device L1
U 1 1 6014BC37
P 4350 3450
F 0 "L1" V 4535 3450 50  0000 C CNN
F 1 "3.9nH" V 4444 3450 50  0000 C CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 4350 3450 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Sunlord-SDCL1005C3N9STDF_C14033.pdf" H 4350 3450 50  0001 C CNN
F 4 "C14033" V 4350 3450 50  0001 C CNN "LCSC"
	1    4350 3450
	0    -1   -1   0   
$EndComp
$Comp
L PlantBuddy-rescue:GND-power #PWR0103
U 1 1 60144A88
P 4650 3650
F 0 "#PWR0103" H 4650 3400 50  0001 C CNN
F 1 "GND" H 4655 3477 50  0000 C CNN
F 2 "" H 4650 3650 50  0001 C CNN
F 3 "" H 4650 3650 50  0001 C CNN
	1    4650 3650
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C8
U 1 1 601440B0
P 4650 3550
F 0 "C8" H 4742 3596 50  0000 L CNN
F 1 "0.8pF" H 4742 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4650 3550 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/YAGEO-CQ0402ARNPO9BNR80_C326068.pdf" H 4650 3550 50  0001 C CNN
F 4 "C285068" H 4650 3550 50  0001 C CNN "LCSC"
	1    4650 3550
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C4
U 1 1 5F7A2F2A
P 4400 7100
F 0 "C4" H 4492 7146 50  0000 L CNN
F 1 "C_Probe" H 4492 7055 50  0000 L CNN
F 2 "PlantBuddy:SoilProbe" H 4400 7100 50  0001 C CNN
F 3 "~" H 4400 7100 50  0001 C CNN
	1    4400 7100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C10
U 1 1 5F89342A
P 8025 2075
F 0 "C10" H 8150 2125 50  0000 L CNN
F 1 "100nF" H 8125 2050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8025 2075 50  0001 C CNN
F 3 "~" H 8025 2075 50  0001 C CNN
F 4 "C1525" H 8025 2075 50  0001 C CNN "LCSC"
	1    8025 2075
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C12
U 1 1 5F9CA7B8
P 7600 2075
F 0 "C12" H 7725 2125 50  0000 L CNN
F 1 "100nF" H 7700 2050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7600 2075 50  0001 C CNN
F 3 "~" H 7600 2075 50  0001 C CNN
F 4 "C1525" H 7600 2075 50  0001 C CNN "LCSC"
	1    7600 2075
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:L_Small-Device L4
U 1 1 5FC85C22
P 6325 2350
F 0 "L4" V 6510 2350 50  0000 C CNN
F 1 "10uH" V 6419 2350 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" H 6325 2350 50  0001 C CNN
F 3 "~" H 6325 2350 50  0001 C CNN
F 4 "C95978" V 6325 2350 50  0001 C CNN "LCSC"
	1    6325 2350
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C5
U 1 1 5FC9BF20
P 5625 2350
F 0 "C5" H 5717 2396 50  0000 L CNN
F 1 "100nF" H 5717 2305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5625 2350 50  0001 C CNN
F 3 "~" H 5625 2350 50  0001 C CNN
F 4 "C1525" H 5625 2350 50  0001 C CNN "LCSC"
	1    5625 2350
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C16
U 1 1 5FC9C991
P 6325 2075
F 0 "C16" H 6417 2121 50  0000 L CNN
F 1 "1uF" H 6417 2030 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6325 2075 50  0001 C CNN
F 3 "~" H 6325 2075 50  0001 C CNN
F 4 "C52923" H 6325 2075 50  0001 C CNN "LCSC"
	1    6325 2075
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0110
U 1 1 5FC6607C
P 7600 1975
F 0 "#PWR0110" H 7600 1825 50  0001 C CNN
F 1 "+BATT" H 7615 2148 50  0000 C CNN
F 2 "" H 7600 1975 50  0001 C CNN
F 3 "" H 7600 1975 50  0001 C CNN
	1    7600 1975
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1275 5125 1275
Wire Wire Line
	4800 1575 5125 1575
Wire Wire Line
	3900 7000 4000 7000
Wire Wire Line
	4000 6900 3325 6900
Wire Wire Line
	7025 5450 7400 5450
Wire Wire Line
	4000 7000 4000 6900
NoConn ~ 7025 5550
NoConn ~ 7025 5650
NoConn ~ 7025 5250
NoConn ~ 7025 5150
NoConn ~ 7025 5050
NoConn ~ 7025 4950
NoConn ~ 7025 4850
NoConn ~ 7025 4750
NoConn ~ 7025 4350
NoConn ~ 7025 4250
NoConn ~ 7025 3450
NoConn ~ 7025 3350
NoConn ~ 7025 3250
NoConn ~ 7025 3150
Wire Wire Line
	4025 1275 4025 1375
Wire Wire Line
	4300 1275 4025 1275
Wire Wire Line
	4300 1375 4025 1375
Connection ~ 4025 1275
Wire Wire Line
	3925 1275 4025 1275
$Comp
L PlantBuddy-rescue:GND-power #PWR0112
U 1 1 6119F486
P 3925 1275
F 0 "#PWR0112" H 3925 1025 50  0001 C CNN
F 1 "GND" H 4075 1200 50  0001 C CNN
F 2 "" H 3925 1275 50  0001 C CNN
F 3 "" H 3925 1275 50  0001 C CNN
	1    3925 1275
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:Battery_Cell-Device BT1
U 1 1 5FC5077F
P 900 1650
F 0 "BT1" H 1018 1746 50  0000 L CNN
F 1 "Li+" H 1018 1655 50  0000 L CNN
F 2 "PlantBuddy:BAT-HLD-001" V 900 1710 50  0001 C CNN
F 3 "~" V 900 1710 50  0001 C CNN
F 4 "" H 900 1650 50  0001 C CNN "LCSC"
F 5 "CR2032-BS-6-1" H 900 1650 50  0001 C CNN "MFR"
	1    900  1650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:AO3401A Q101
U 1 1 6134A6DD
P 1350 1450
F 0 "Q101" V 1692 1450 50  0000 C CNN
F 1 "AO3401A" V 1601 1450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 1550 1375 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3401A.pdf" H 1350 1450 50  0001 L CNN
	1    1350 1450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1150 1350 900  1350
Wire Wire Line
	900  1850 1350 1850
Wire Wire Line
	1350 1850 1750 1850
Connection ~ 1350 1850
Text Label 5125 1375 2    50   ~ 0
SWO
Wire Wire Line
	4800 1375 5125 1375
Text Label 7400 4450 2    50   ~ 0
SWO
Wire Wire Line
	7400 4450 7025 4450
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J101
U 1 1 6136EE02
P 4500 1375
F 0 "J101" H 4550 1792 50  0000 C CNN
F 1 "J-Link SWD" H 4550 1701 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical_SMD" H 4500 1375 50  0001 C CNN
F 3 "~" H 4500 1375 50  0001 C CNN
	1    4500 1375
	1    0    0    -1  
$EndComp
NoConn ~ 4800 1475
NoConn ~ 4300 1475
Text Notes 3575 1500 0    50   ~ 0
Non-existent ->
NoConn ~ 7025 4150
$Comp
L Device:Speaker_Crystal LS101
U 1 1 6138F133
P 7325 2850
F 0 "LS101" H 7500 2846 50  0000 L CNN
F 1 "Speaker_Crystal" H 7500 2755 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7290 2800 50  0001 C CNN
F 3 "~" H 7290 2800 50  0001 C CNN
	1    7325 2850
	1    0    0    -1  
$EndComp
NoConn ~ 7025 4550
NoConn ~ 7025 4650
$Comp
L Device:Antenna AE101
U 1 1 613B6725
P 3850 3250
F 0 "AE101" H 3650 3250 50  0000 L CNN
F 1 "Antenna" H 3525 3150 50  0000 L CNN
F 2 "PlantBuddy:monopole" H 3850 3250 50  0001 C CNN
F 3 "~" H 3850 3250 50  0001 C CNN
	1    3850 3250
	1    0    0    -1  
$EndComp
NoConn ~ 4300 1575
NoConn ~ 7025 3550
NoConn ~ 7025 3650
Wire Wire Line
	7125 2850 7025 2850
Wire Wire Line
	7125 2950 7025 2950
Wire Wire Line
	7025 3050 7325 3050
Wire Wire Line
	7325 3050 7325 3150
Wire Wire Line
	7325 3150 8250 3150
Connection ~ 4000 7000
Wire Wire Line
	4000 7000 4400 7000
Text Label 3325 7000 0    50   ~ 0
Charge
Text Label 3325 6900 0    50   ~ 0
Measure
Wire Wire Line
	7400 5350 7025 5350
$Comp
L Device:R_Small R102
U 1 1 618DEDD6
P 2050 1350
F 0 "R102" V 1854 1350 50  0000 C CNN
F 1 "10R" V 1945 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2050 1350 50  0001 C CNN
F 3 "~" H 2050 1350 50  0001 C CNN
	1    2050 1350
	0    1    1    0   
$EndComp
Text Notes 1975 1500 0    50   ~ 0
0.1%
Wire Wire Line
	2325 4625 2100 4625
Wire Wire Line
	2325 4525 2325 4625
Wire Wire Line
	2375 4525 2325 4525
Text Label 2375 4525 2    50   ~ 0
SCL
Connection ~ 1700 4925
Wire Wire Line
	850  4625 850  4925
Wire Wire Line
	1700 4925 850  4925
Wire Wire Line
	850  4125 1700 4125
Wire Wire Line
	850  4125 850  4425
$Comp
L Sensor_Optical:LTR-303ALS-01 U102
U 1 1 611AA492
P 1700 4525
F 0 "U102" H 1500 4875 50  0000 C CNN
F 1 "LTR-303ALS-01" H 1350 4125 50  0000 C CNN
F 2 "OptoDevice:Lite-On_LTR-303ALS-01" H 1700 4975 50  0001 C CNN
F 3 "http://optoelectronics.liteon.com/upload/download/DS86-2013-0004/LTR-303ALS-01_DS_V1.pdf" H 1400 4875 50  0001 C CNN
	1    1700 4525
	-1   0    0    -1  
$EndComp
Connection ~ 1700 4125
Text Notes 2175 3875 2    50   ~ 0
0 to 65535 Lux Light sensor
Wire Wire Line
	1200 3200 1200 3400
Connection ~ 1700 3400
Wire Wire Line
	1200 3400 1700 3400
Connection ~ 1700 2800
Wire Wire Line
	1200 2800 1200 3000
Wire Wire Line
	1700 2800 1200 2800
$Comp
L PlantBuddy-rescue:C_Small-Device C17
U 1 1 60156A34
P 1200 3100
F 0 "C17" H 1050 3200 50  0000 L CNN
F 1 "100nF" H 900 3050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1200 3100 50  0001 C CNN
F 3 "~" H 1200 3100 50  0001 C CNN
F 4 "C1525" H 1200 3100 50  0001 C CNN "LCSC"
	1    1200 3100
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:SHTC3-Sensor_Humidity U6
U 1 1 5FC00783
P 1800 3100
F 0 "U6" H 2044 3146 50  0000 L CNN
F 1 "SHTC3" H 2044 3055 50  0000 L CNN
F 2 "PlantBuddy:Sensirion_DFN-4-1EP_2x2mm_P1mm_EP0.7x1.6mm" H 2000 2750 50  0001 C CNN
F 3 "https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/0_Datasheets/Humidity/Sensirion_Humidity_Sensors_SHTC3_Datasheet.pdf" H 1500 3550 50  0001 C CNN
F 4 "C194656" H 1800 3100 50  0001 C CNN "LCSC"
	1    1800 3100
	-1   0    0    -1  
$EndComp
$Comp
L PlantBuddy-rescue:C_Small-Device C3
U 1 1 5FC58638
P 850 4525
F 0 "C3" H 900 4675 50  0000 L CNN
F 1 "100nF" H 900 4400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 850 4525 50  0001 C CNN
F 3 "~" H 850 4525 50  0001 C CNN
F 4 "C1525" H 850 4525 50  0001 C CNN "LCSC"
	1    850  4525
	1    0    0    -1  
$EndComp
Text Label 2300 3000 2    50   ~ 0
SCL
Text Label 2300 3200 2    50   ~ 0
SDA
Wire Wire Line
	2375 3200 2100 3200
Entry Wire Line
	2375 3200 2475 3300
Wire Wire Line
	2100 3000 2375 3000
Entry Wire Line
	2375 3000 2475 3100
Entry Wire Line
	2375 4525 2475 4425
Entry Wire Line
	2375 4425 2475 4325
Wire Wire Line
	2100 4425 2375 4425
$Comp
L PlantBuddy-rescue:+BATT-power #PWR0108
U 1 1 5FC5ABA5
P 1700 2800
F 0 "#PWR0108" H 1700 2650 50  0001 C CNN
F 1 "+BATT" H 1715 2973 50  0000 C CNN
F 2 "" H 1700 2800 50  0001 C CNN
F 3 "" H 1700 2800 50  0001 C CNN
	1    1700 2800
	-1   0    0    -1  
$EndComp
Text Notes 2225 2575 2    50   ~ 0
Temperature & Humidity\nReally cheap: 0.66$
$Comp
L PlantBuddy-rescue:GND-power #PWR026
U 1 1 5F7A91A0
P 1700 3400
F 0 "#PWR026" H 1700 3150 50  0001 C CNN
F 1 "GND" H 1550 3325 50  0000 C CNN
F 2 "" H 1700 3400 50  0001 C CNN
F 3 "" H 1700 3400 50  0001 C CNN
	1    1700 3400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	950  4525 1300 4525
Text Label 950  4525 0    50   ~ 0
LUX_INT
$Comp
L PlantBuddy-rescue:GND-power #PWR0101
U 1 1 5FBEAB3C
P 1700 4925
F 0 "#PWR0101" H 1700 4675 50  0001 C CNN
F 1 "GND" H 1705 4752 50  0000 C CNN
F 2 "" H 1700 4925 50  0001 C CNN
F 3 "" H 1700 4925 50  0001 C CNN
	1    1700 4925
	-1   0    0    -1  
$EndComp
Text Label 2375 4425 2    50   ~ 0
SDA
$Comp
L PlantBuddy-rescue:+BATT-power #PWR010
U 1 1 5F85BEB5
P 1700 4125
F 0 "#PWR010" H 1700 3975 50  0001 C CNN
F 1 "+BATT" H 1550 4225 50  0000 C CNN
F 2 "" H 1700 4125 50  0001 C CNN
F 3 "" H 1700 4125 50  0001 C CNN
	1    1700 4125
	-1   0    0    -1  
$EndComp
Wire Notes Line
	475  2300 2675 2300
Wire Notes Line
	625  2300 625  2175
Wire Notes Line
	625  2175 2675 2175
Wire Notes Line
	2675 5450 475  5450
Text Notes 1575 5425 0    50   ~ 0
Sensors (Light + ambiental)
Wire Notes Line
	1550 5450 1550 5300
Wire Notes Line
	1550 5300 2675 5300
Wire Notes Line
	2675 475  2675 7800
Text Notes 2375 7775 0    50   ~ 0
Clocks
Wire Notes Line
	2675 7675 2300 7675
Wire Notes Line
	2300 7675 2300 7800
Wire Notes Line
	2675 6575 5325 6575
Wire Notes Line
	5325 6575 5325 7800
Wire Notes Line
	475  7800 5325 7800
Text Notes 4625 7775 0    50   ~ 0
Soil Water Sensor
Wire Notes Line
	4600 7800 4600 7675
Wire Notes Line
	4600 7675 5325 7675
$Comp
L Connector_Generic:Conn_01x01 J103
U 1 1 619DEEF9
P 2250 875
F 0 "J103" V 2350 925 50  0000 R CNN
F 1 "C-" V 2225 775 50  0000 R CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 2250 875 50  0001 C CNN
F 3 "~" H 2250 875 50  0001 C CNN
	1    2250 875 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1550 1350 1850 1350
$Comp
L Connector_Generic:Conn_01x01 J102
U 1 1 619E1E8F
P 1850 875
F 0 "J102" V 1950 925 50  0000 R CNN
F 1 "C+" V 1825 1075 50  0000 R CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 1850 875 50  0001 C CNN
F 3 "~" H 1850 875 50  0001 C CNN
	1    1850 875 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1850 1075 1850 1350
Connection ~ 1850 1350
Wire Wire Line
	1850 1350 1950 1350
Wire Wire Line
	2150 1350 2250 1350
Wire Wire Line
	2250 1075 2250 1350
Connection ~ 2250 1350
Wire Wire Line
	2250 1350 2375 1350
Wire Wire Line
	3325 7000 3700 7000
Text Notes 3150 7500 0    50   ~ 0
Default is COMP-based measurement
Wire Bus Line
	2475 3100 2475 4425
$EndSCHEMATC
