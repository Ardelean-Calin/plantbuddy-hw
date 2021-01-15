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
L power:GND #PWR06
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
Text Label 5500 4025 0    50   ~ 0
SDA
Text Label 5500 4125 0    50   ~ 0
SCL
Wire Wire Line
	5775 4425 6475 4425
Connection ~ 6475 4425
Wire Wire Line
	5775 3375 5500 3375
Text Label 5500 3375 0    50   ~ 0
SWDIO
Wire Wire Line
	5775 3475 5500 3475
Text Label 5500 3475 0    50   ~ 0
SWCLK
Wire Wire Line
	5500 4025 5775 4025
Wire Wire Line
	5500 4125 5775 4125
Text Label 7525 3025 2    50   ~ 0
fHumidity
Wire Wire Line
	7125 3025 7525 3025
Wire Wire Line
	6475 4425 7125 4425
Wire Wire Line
	7125 4425 7125 4225
Wire Wire Line
	10450 1000 10175 1000
Text Label 10175 1000 0    50   ~ 0
SWDIO
Wire Wire Line
	10450 900  10175 900 
Text Label 10175 900  0    50   ~ 0
SWCLK
$Comp
L power:GND #PWR040
U 1 1 5F81A7B8
P 10450 1100
F 0 "#PWR040" H 10450 850 50  0001 C CNN
F 1 "GND" H 10455 927 50  0000 C CNN
F 2 "" H 10450 1100 50  0001 C CNN
F 3 "" H 10450 1100 50  0001 C CNN
	1    10450 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7525 3125 7125 3125
Text Label 7525 3225 2    50   ~ 0
~SOIL_EN~
Wire Wire Line
	7125 3225 7525 3225
$Comp
L power:GND #PWR09
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
L power:GND #PWR023
U 1 1 5F8986BA
P 6475 4425
F 0 "#PWR023" H 6475 4175 50  0001 C CNN
F 1 "GND" H 6480 4252 50  0000 C CNN
F 2 "" H 6475 4425 50  0001 C CNN
F 3 "" H 6475 4425 50  0001 C CNN
	1    6475 4425
	1    0    0    -1  
$EndComp
Text Notes 9600 2900 0    50   ~ 0
50Ω matched trace
$Comp
L power:+BATT #PWR010
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
L power:GND #PWR014
U 1 1 5F893F2C
P 5125 2425
F 0 "#PWR014" H 5125 2175 50  0001 C CNN
F 1 "GND" H 4975 2350 50  0000 C CNN
F 2 "" H 5125 2425 50  0001 C CNN
F 3 "" H 5125 2425 50  0001 C CNN
	1    5125 2425
	1    0    0    -1  
$EndComp
Wire Wire Line
	5775 2725 5725 2725
$Comp
L power:GND #PWR038
U 1 1 5F8EDD3C
P 10425 2775
F 0 "#PWR038" H 10425 2525 50  0001 C CNN
F 1 "GND" H 10430 2602 50  0000 C CNN
F 2 "" H 10425 2775 50  0001 C CNN
F 3 "" H 10425 2775 50  0001 C CNN
	1    10425 2775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR032
U 1 1 5F8F4F49
P 8475 2250
F 0 "#PWR032" H 8475 2000 50  0001 C CNN
F 1 "GND" H 8480 2077 50  0000 C CNN
F 2 "" H 8475 2250 50  0001 C CNN
F 3 "" H 8475 2250 50  0001 C CNN
	1    8475 2250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR033
U 1 1 5F904D43
P 8475 3300
F 0 "#PWR033" H 8475 3050 50  0001 C CNN
F 1 "GND" H 8480 3127 50  0000 C CNN
F 2 "" H 8475 3300 50  0001 C CNN
F 3 "" H 8475 3300 50  0001 C CNN
	1    8475 3300
	1    0    0    -1  
$EndComp
Text Notes 8350 2000 0    50   ~ 0
Balun\n25.4Ω to 50Ω
Text Notes 8300 3800 0    50   ~ 0
Ideal values:\nL = 2.3nH\nC = 1.8pF
Wire Notes Line
	8300 2200 8300 3375
Wire Wire Line
	7125 2725 7650 2725
Wire Wire Line
	7650 2725 7650 2675
Wire Wire Line
	7125 2825 7650 2825
Wire Wire Line
	7650 2825 7650 2875
Text Notes 7050 6725 0    50   ~ 0
N3: DO NOT debug with battery connected!
Text Label 7525 3425 2    50   ~ 0
LEDR
Wire Wire Line
	10400 4400 10400 4325
NoConn ~ 7125 3725
NoConn ~ 7125 3825
Text Notes 7050 6825 0    50   ~ 0
N4: The BlueNRG has an internal temperature sensor
$Comp
L power:GND #PWR018
U 1 1 5F8E426C
P 5325 4950
F 0 "#PWR018" H 5325 4700 50  0001 C CNN
F 1 "GND" H 5330 4777 50  0000 C CNN
F 2 "" H 5325 4950 50  0001 C CNN
F 3 "" H 5325 4950 50  0001 C CNN
	1    5325 4950
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5F8E4C67
P 5325 5250
F 0 "#PWR019" H 5325 5000 50  0001 C CNN
F 1 "GND" H 5330 5077 50  0000 C CNN
F 2 "" H 5325 5250 50  0001 C CNN
F 3 "" H 5325 5250 50  0001 C CNN
	1    5325 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5425 5050 5575 5050
Wire Wire Line
	5225 5050 5075 5050
Wire Wire Line
	5075 5250 5325 5250
Connection ~ 5325 5250
Wire Wire Line
	5325 5250 5575 5250
Wire Wire Line
	5325 5150 5325 5250
Wire Wire Line
	5575 5050 5575 4875
Connection ~ 5575 5050
Text Label 4825 4875 0    50   ~ 0
FXTAL1
Text Label 5825 4875 2    50   ~ 0
FXTAL0
Wire Wire Line
	5075 4875 5075 5050
Connection ~ 5075 5050
Wire Wire Line
	5075 4875 4825 4875
Wire Wire Line
	5575 4875 5825 4875
Text Label 5475 2875 0    50   ~ 0
FXTAL1
Wire Wire Line
	5475 2875 5775 2875
Text Label 5475 2975 0    50   ~ 0
FXTAL0
Wire Wire Line
	5475 2975 5775 2975
Wire Wire Line
	6400 5025 6525 5025
Wire Wire Line
	6725 5025 6850 5025
$Comp
L power:GND #PWR024
U 1 1 5F9806CE
P 6625 5225
F 0 "#PWR024" H 6625 4975 50  0001 C CNN
F 1 "GND" H 6630 5052 50  0000 C CNN
F 2 "" H 6625 5225 50  0001 C CNN
F 3 "" H 6625 5225 50  0001 C CNN
	1    6625 5225
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 5225 6625 5225
Connection ~ 6625 5225
Wire Wire Line
	6625 5225 6850 5225
Wire Wire Line
	6400 5025 6400 4875
Wire Wire Line
	6400 4875 6125 4875
Connection ~ 6400 5025
Text Label 6125 4875 0    50   ~ 0
SXTAL1
Wire Wire Line
	6850 4875 7125 4875
Text Label 7125 4875 2    50   ~ 0
SXTAL0
Wire Wire Line
	6850 4875 6850 5025
Connection ~ 6850 5025
Text Label 5475 3125 0    50   ~ 0
SXTAL1
Wire Wire Line
	5475 3125 5775 3125
Text Label 5475 3225 0    50   ~ 0
SXTAL0
Wire Wire Line
	5475 3225 5775 3225
Wire Wire Line
	5125 2425 5550 2425
Connection ~ 5125 2425
Connection ~ 5550 2425
Wire Wire Line
	5550 2425 5975 2425
Wire Wire Line
	5975 2225 5550 2225
Connection ~ 5550 2225
Wire Wire Line
	5550 2225 5125 2225
$Comp
L power:GND #PWR016
U 1 1 5F9E8FDD
P 5125 3300
F 0 "#PWR016" H 5125 3050 50  0001 C CNN
F 1 "GND" H 4975 3225 50  0000 C CNN
F 2 "" H 5125 3300 50  0001 C CNN
F 3 "" H 5125 3300 50  0001 C CNN
	1    5125 3300
	1    0    0    -1  
$EndComp
NoConn ~ 5775 3625
NoConn ~ 5775 3725
Wire Wire Line
	5525 2725 5725 2725
Connection ~ 5725 2725
$Comp
L power:GND #PWR017
U 1 1 5FA12A29
P 5325 2725
F 0 "#PWR017" H 5325 2475 50  0001 C CNN
F 1 "GND" H 5175 2650 50  0000 C CNN
F 2 "" H 5325 2725 50  0001 C CNN
F 3 "" H 5325 2725 50  0001 C CNN
	1    5325 2725
	1    0    0    -1  
$EndComp
Wire Wire Line
	8475 2500 8475 2550
Wire Wire Line
	8475 2450 8475 2500
Connection ~ 8475 2500
Wire Wire Line
	8475 2500 8025 2500
Wire Wire Line
	8475 3050 8475 3000
Wire Wire Line
	8475 3100 8475 3050
Connection ~ 8475 3050
Wire Wire Line
	8475 3050 8025 3050
Text Notes 6775 2500 0    50   ~ 0
Impedance matching to 25.4Ω\nby subtracting imaginary part\n
Wire Wire Line
	8025 2675 8025 2500
Wire Wire Line
	8025 2875 8025 3050
Wire Wire Line
	7650 2675 8025 2675
Wire Wire Line
	7650 2875 8025 2875
Text Notes 8300 3900 0    50   ~ 0
VSWR with current design: ~~1.4\n
Wire Wire Line
	8850 2825 8850 2775
Wire Wire Line
	8850 2775 8975 2775
Wire Wire Line
	9175 2775 9300 2775
Wire Wire Line
	9300 2775 9300 2825
$Comp
L power:GND #PWR036
U 1 1 5F8D23C1
P 8850 3025
F 0 "#PWR036" H 8850 2775 50  0001 C CNN
F 1 "GND" H 8855 2852 50  0000 C CNN
F 2 "" H 8850 3025 50  0001 C CNN
F 3 "" H 8850 3025 50  0001 C CNN
	1    8850 3025
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR037
U 1 1 5F8D2748
P 9300 3025
F 0 "#PWR037" H 9300 2775 50  0001 C CNN
F 1 "GND" H 9305 2852 50  0000 C CNN
F 2 "" H 9300 3025 50  0001 C CNN
F 3 "" H 9300 3025 50  0001 C CNN
	1    9300 3025
	1    0    0    -1  
$EndComp
Wire Wire Line
	8475 2750 8475 2775
Wire Wire Line
	8850 2775 8475 2775
Connection ~ 8850 2775
Connection ~ 8475 2775
Wire Wire Line
	8475 2775 8475 2800
Text Notes 8875 3425 0    50   ~ 0
^PI Low-pass Filter @ 2.45GHz
Wire Notes Line
	7700 2200 7700 3375
Wire Wire Line
	6575 2525 6475 2525
Connection ~ 6475 2525
Wire Wire Line
	9450 2775 9300 2775
Connection ~ 9300 2775
Wire Wire Line
	9650 2775 10325 2775
Text Notes 9600 2750 0    50   ~ 0
DC blocking
Wire Notes Line
	8775 2200 8775 3375
Connection ~ 8025 2875
Connection ~ 8025 2675
Text Notes 7800 3275 0    26   ~ 0
Should be ~~3.1pF\nbut considering\nparasitic capacitances\nwe chose this value
Text Notes 7800 3350 0    26   ~ 0
RoT: ~~0.3pF per PAD
Wire Wire Line
	7375 4125 7125 4125
Text Label 2050 5925 2    50   ~ 0
SDA
Text Label 2050 5825 2    50   ~ 0
SCL
$Comp
L power:GND #PWR0101
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
Text Label 7525 3125 2    50   ~ 0
LUX_INT
Text Notes 2050 6650 2    50   ~ 0
0 to 83865 Lux Light sensor
$Comp
L power:+BATT #PWR0102
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
L power:GND #PWR026
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
L power:+BATT #PWR0103
U 1 1 5FC46D16
P 6475 2525
F 0 "#PWR0103" H 6475 2375 50  0001 C CNN
F 1 "+BATT" H 6490 2698 50  0000 C CNN
F 2 "" H 6475 2525 50  0001 C CNN
F 3 "" H 6475 2525 50  0001 C CNN
	1    6475 2525
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0104
U 1 1 5FC47AF7
P 5125 3100
F 0 "#PWR0104" H 5125 2950 50  0001 C CNN
F 1 "+BATT" H 5140 3273 50  0000 C CNN
F 2 "" H 5125 3100 50  0001 C CNN
F 3 "" H 5125 3100 50  0001 C CNN
	1    5125 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0105
U 1 1 5FC54A7F
P 4625 7100
F 0 "#PWR0105" H 4625 6950 50  0001 C CNN
F 1 "+BATT" H 4640 7273 50  0000 C CNN
F 2 "" H 4625 7100 50  0001 C CNN
F 3 "" H 4625 7100 50  0001 C CNN
	1    4625 7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
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
L power:+BATT #PWR0107
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
L power:+BATT #PWR0108
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
L power:+BATT #PWR0109
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
Put it in such a way that\n it is small and hidden\nWe will need to build \na programming rig for it!
$Comp
L power:+BATT #PWR0110
U 1 1 5FC6607C
P 5975 2225
F 0 "#PWR0110" H 5975 2075 50  0001 C CNN
F 1 "+BATT" H 5990 2398 50  0000 C CNN
F 2 "" H 5975 2225 50  0001 C CNN
F 3 "" H 5975 2225 50  0001 C CNN
	1    5975 2225
	1    0    0    -1  
$EndComp
Connection ~ 5975 2225
NoConn ~ 5775 3825
NoConn ~ 5775 3925
Text Notes 4700 3925 0    50   ~ 0
ADC can be configured to\ninternally sense VBat
Wire Wire Line
	6375 2525 5725 2525
Wire Wire Line
	6475 2525 6375 2525
Connection ~ 6375 2525
Wire Wire Line
	7525 3425 7125 3425
Text Label 10225 4325 0    50   ~ 0
LEDR
Wire Wire Line
	10225 4325 10400 4325
Wire Wire Line
	7325 4025 7375 4025
Wire Wire Line
	7375 4025 7375 4125
Wire Wire Line
	7375 4125 7450 4125
Wire Wire Line
	7850 4125 7850 4175
Connection ~ 7375 4125
Wire Wire Line
	7450 4175 7450 4125
Connection ~ 7450 4125
Wire Wire Line
	7450 4125 7850 4125
Wire Wire Line
	7850 4375 7850 4425
Wire Wire Line
	7850 4425 7450 4425
Connection ~ 7125 4425
Wire Wire Line
	7450 4375 7450 4425
Connection ~ 7450 4425
Wire Wire Line
	7450 4425 7125 4425
Text Notes 7550 4100 0    50   ~ 0
Added SMPS\nfor minimum\npower
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
Text Notes 3975 7450 0    50   ~ 0
Low-power reverse voltage protection\n& shutdown switch
Text Notes 7625 6175 0    50   ~ 0
A really small cheap button to be used\nfor resetting the bluetooth connection\nor reset to default settings
Wire Wire Line
	3725 7325 3550 7325
Wire Wire Line
	2875 7325 3150 7325
Wire Wire Line
	2875 7025 3350 7025
Connection ~ 3350 7025
Text Notes 2825 7700 0    50   ~ 0
Reverse-voltage protection
$Comp
L power:GND #PWR0111
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
L power:+BATT #PWR0112
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
Text Label 7525 3325 2    50   ~ 0
~BLE_RST
Wire Wire Line
	7125 3325 7525 3325
Wire Wire Line
	3350 7025 3925 7025
Wire Wire Line
	4325 7125 4625 7125
Wire Wire Line
	4625 7125 4625 7100
NoConn ~ 4325 6925
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
L Device:R_Small R1
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
L Switch:SW_Push SW2
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
L Switch:SW_SPDT SW1
U 1 1 5FC9AEF2
P 4125 7025
F 0 "SW1" H 4125 7310 50  0000 C CNN
F 1 "PWR_SW" H 4125 7219 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPDT_CK-JS102011SAQN" H 4125 7025 50  0001 C CNN
F 3 "~" H 4125 7025 50  0001 C CNN
F 4 "C514018" H 4125 7025 50  0001 C CNN "LCSC"
	1    4125 7025
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q2
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
L Connector_Generic:Conn_01x01 J3
U 1 1 5FC6BCF8
P 3250 4725
F 0 "J3" H 3225 4550 50  0000 L CNN
F 1 "Conn_I2C_SCL" H 3200 4625 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3250 4725 50  0001 C CNN
F 3 "~" H 3250 4725 50  0001 C CNN
	1    3250 4725
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 5FC6B510
P 3250 4625
F 0 "J2" H 3225 4825 50  0000 L CNN
F 1 "Conn_I2C_SDA" H 3200 4750 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3250 4625 50  0001 C CNN
F 3 "~" H 3250 4625 50  0001 C CNN
	1    3250 4625
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
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
L Sensor_Humidity:SHTC3 U6
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
L Device:C_Small C16
U 1 1 5FC9C991
P 7850 4275
F 0 "C16" H 7942 4321 50  0000 L CNN
F 1 "1uF" H 7942 4230 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7850 4275 50  0001 C CNN
F 3 "~" H 7850 4275 50  0001 C CNN
F 4 "C52923" H 7850 4275 50  0001 C CNN "LCSC"
	1    7850 4275
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 5FC9BF20
P 7450 4275
F 0 "C5" H 7542 4321 50  0000 L CNN
F 1 "100nF" H 7542 4230 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7450 4275 50  0001 C CNN
F 3 "~" H 7450 4275 50  0001 C CNN
F 4 "C1525" H 7450 4275 50  0001 C CNN "LCSC"
	1    7450 4275
	1    0    0    -1  
$EndComp
$Comp
L PlantBuddy:BlueNRG-M1 U5
U 1 1 5F7C70EA
P 6025 3025
F 0 "U5" H 5950 3475 50  0000 C CNN
F 1 "BlueNRG-M1" H 6800 1675 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.3x3.3mm_ThermalVias" H 6425 1175 50  0001 C CNN
F 3 "" H 6025 2925 50  0001 C CNN
F 4 "C133308" H 6025 3025 50  0001 C CNN "LCSC"
	1    6025 3025
	1    0    0    -1  
$EndComp
$Comp
L Device:L_Small L4
U 1 1 5FC85C22
P 7225 4025
F 0 "L4" V 7410 4025 50  0000 C CNN
F 1 "10uH" V 7319 4025 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" H 7225 4025 50  0001 C CNN
F 3 "~" H 7225 4025 50  0001 C CNN
F 4 "C1046" V 7225 4025 50  0001 C CNN "LCSC"
	1    7225 4025
	0    -1   -1   0   
$EndComp
$Comp
L Device:Battery_Cell BT1
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
L Device:R_Small R15
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
L Device:R_Small R14
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
L Device:C_Small C20
U 1 1 5F8FFCFF
P 8475 3200
F 0 "C20" H 8383 3154 50  0000 R CNN
F 1 "1.5pF" H 8383 3245 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8475 3200 50  0001 C CNN
F 3 "~" H 8475 3200 50  0001 C CNN
F 4 "C1552" H 8475 3200 50  0001 C CNN "LCSC"
	1    8475 3200
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C18
U 1 1 5F83AB78
P 8025 2775
F 0 "C18" H 7775 2825 50  0000 L CNN
F 1 "2.2pF" H 7725 2725 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8025 2775 50  0001 C CNN
F 3 "~" H 8025 2775 50  0001 C CNN
F 4 "C1559" H 8025 2775 50  0001 C CNN "LCSC"
	1    8025 2775
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C26
U 1 1 5F860759
P 9550 2775
F 0 "C26" V 9350 2850 50  0000 R CNN
F 1 "20pF" V 9425 2875 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 9550 2775 50  0001 C CNN
F 3 "~" H 9550 2775 50  0001 C CNN
F 4 "C1554" H 9550 2775 50  0001 C CNN "LCSC"
	1    9550 2775
	0    1    1    0   
$EndComp
$Comp
L Device:L_Small L3
U 1 1 5F8BD9C0
P 9075 2775
F 0 "L3" V 9250 2875 50  0000 R CNN
F 1 "3.3nH" V 9150 2875 50  0000 R CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 9075 2775 50  0001 C CNN
F 3 "~" H 9075 2775 50  0001 C CNN
F 4 "C77122" H 9075 2775 50  0001 C CNN "LCSC"
	1    9075 2775
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C23
U 1 1 5F8BD6A1
P 9300 2925
F 0 "C23" H 9208 2879 50  0000 R CNN
F 1 "2pF" H 9208 2970 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 9300 2925 50  0001 C CNN
F 3 "~" H 9300 2925 50  0001 C CNN
F 4 "C1558" H 9300 2925 50  0001 C CNN "LCSC"
	1    9300 2925
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C22
U 1 1 5F8BD3DC
P 8850 2925
F 0 "C22" H 8758 2879 50  0000 R CNN
F 1 "2pF" H 8758 2970 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8850 2925 50  0001 C CNN
F 3 "~" H 8850 2925 50  0001 C CNN
F 4 "C1558" H 8850 2925 50  0001 C CNN "LCSC"
	1    8850 2925
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C19
U 1 1 5F8393ED
P 8475 2650
F 0 "C19" H 8383 2604 50  0000 R CNN
F 1 "1.5pF" H 8383 2695 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8475 2650 50  0001 C CNN
F 3 "~" H 8475 2650 50  0001 C CNN
F 4 "C1552" H 8475 2650 50  0001 C CNN "LCSC"
	1    8475 2650
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5FA07E6E
P 5425 2725
F 0 "C9" H 5475 2800 50  0000 L CNN
F 1 "100nF" H 5450 2650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5425 2725 50  0001 C CNN
F 3 "~" H 5425 2725 50  0001 C CNN
F 4 "C1525" H 5425 2725 50  0001 C CNN "LCSC"
	1    5425 2725
	0    1    -1   0   
$EndComp
$Comp
L Device:C_Small C8
U 1 1 5F9DEACC
P 5125 3200
F 0 "C8" H 5033 3154 50  0000 R CNN
F 1 "22uF" H 5033 3245 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5125 3200 50  0001 C CNN
F 3 "~" H 5125 3200 50  0001 C CNN
F 4 "C59461" H 5125 3200 50  0001 C CNN "LCSC"
	1    5125 3200
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C12
U 1 1 5F9CA7B8
P 5975 2325
F 0 "C12" H 6100 2375 50  0000 L CNN
F 1 "100nF" H 6075 2300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5975 2325 50  0001 C CNN
F 3 "~" H 5975 2325 50  0001 C CNN
F 4 "C1525" H 5975 2325 50  0001 C CNN "LCSC"
	1    5975 2325
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5F9CA13F
P 5125 2325
F 0 "C7" H 5250 2375 50  0000 L CNN
F 1 "100nF" H 5225 2300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5125 2325 50  0001 C CNN
F 3 "~" H 5125 2325 50  0001 C CNN
F 4 "C1525" H 5125 2325 50  0001 C CNN "LCSC"
	1    5125 2325
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C13
U 1 1 5F96F76E
P 6400 5125
F 0 "C13" H 6309 5079 50  0000 R CNN
F 1 "20pF" H 6309 5170 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6400 5125 50  0001 C CNN
F 3 "~" H 6400 5125 50  0001 C CNN
F 4 "C1554" H 6400 5125 50  0001 C CNN "LCSC"
	1    6400 5125
	1    0    0    1   
$EndComp
$Comp
L Device:C_Small C14
U 1 1 5F96F125
P 6850 5125
F 0 "C14" H 6758 5079 50  0000 R CNN
F 1 "20pF" H 6758 5170 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6850 5125 50  0001 C CNN
F 3 "~" H 6850 5125 50  0001 C CNN
F 4 "C1554" H 6850 5125 50  0001 C CNN "LCSC"
	1    6850 5125
	-1   0    0    1   
$EndComp
$Comp
L Device:Crystal_Small Y2
U 1 1 5F96EABD
P 6625 5025
F 0 "Y2" H 6625 5250 50  0000 C CNN
F 1 "32kHz" H 6625 5159 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm" H 6625 5025 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1901081604_Seiko-Epson-Q13FC1350000400_C32346.pdf" H 6625 5025 50  0001 C CNN
F 4 "C32346" H 6625 5025 50  0001 C CNN "LCSC"
	1    6625 5025
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5F8E6679
P 5575 5150
F 0 "C11" H 5483 5104 50  0000 R CNN
F 1 "12pF" H 5483 5195 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5575 5150 50  0001 C CNN
F 3 "~" H 5575 5150 50  0001 C CNN
F 4 "C1547" H 5575 5150 50  0001 C CNN "LCSC"
	1    5575 5150
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5F8E556C
P 5075 5150
F 0 "C6" H 4984 5104 50  0000 R CNN
F 1 "12pF" H 4984 5195 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5075 5150 50  0001 C CNN
F 3 "~" H 5075 5150 50  0001 C CNN
F 4 "C1547" H 5075 5150 50  0001 C CNN "LCSC"
	1    5075 5150
	1    0    0    1   
$EndComp
$Comp
L Device:Crystal_GND24_Small Y1
U 1 1 5F8E3B8A
P 5325 5050
F 0 "Y1" H 5425 5250 50  0000 L CNN
F 1 "16MHz" H 5325 5150 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 5325 5050 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Yangxing-Tech-X322516MLB4SI_C13738.pdf" H 5325 5050 50  0001 C CNN
F 4 "C13738" H 5325 5050 50  0001 C CNN "LCSC"
	1    5325 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R16
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
L Device:LED_Small D2
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
L Device:L_Small L2
U 1 1 5F8FF82A
P 8475 2900
F 0 "L2" H 8431 2854 50  0000 R CNN
F 1 "2.7nH" H 8431 2945 50  0000 R CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 8475 2900 50  0001 C CNN
F 3 "~" H 8475 2900 50  0001 C CNN
F 4 "C27123" H 8475 2900 50  0001 C CNN "LCSC"
	1    8475 2900
	-1   0    0    1   
$EndComp
$Comp
L Device:L_Small L1
U 1 1 5F8F41EF
P 8475 2350
F 0 "L1" H 8431 2304 50  0000 R CNN
F 1 "2.7nH" H 8431 2395 50  0000 R CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 8475 2350 50  0001 C CNN
F 3 "~" H 8475 2350 50  0001 C CNN
F 4 "C27123" H 8475 2350 50  0001 C CNN "LCSC"
	1    8475 2350
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C2
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
L Device:R_Small R12
U 1 1 5F89EE4B
P 5725 2625
F 0 "R12" H 5784 2671 50  0000 L CNN
F 1 "10k" H 5784 2580 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 5725 2625 50  0001 C CNN
F 3 "~" H 5725 2625 50  0001 C CNN
F 4 "C25744" H 5725 2625 50  0001 C CNN "LCSC"
	1    5725 2625
	-1   0    0    -1  
$EndComp
$Comp
L Device:C_Small C10
U 1 1 5F89342A
P 5550 2325
F 0 "C10" H 5675 2375 50  0000 L CNN
F 1 "100nF" H 5650 2300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5550 2325 50  0001 C CNN
F 3 "~" H 5550 2325 50  0001 C CNN
F 4 "C1525" H 5550 2325 50  0001 C CNN "LCSC"
	1    5550 2325
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R13
U 1 1 5F7C98A8
P 5775 4325
F 0 "R13" H 5575 4375 50  0000 L CNN
F 1 "10k" H 5575 4275 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" H 5775 4325 50  0001 C CNN
F 3 "~" H 5775 4325 50  0001 C CNN
F 4 "C25744" H 5775 4325 50  0001 C CNN "LCSC"
	1    5775 4325
	1    0    0    -1  
$EndComp
$Comp
L Device:Antenna_Shield AE1
U 1 1 5F7B40C5
P 10325 2575
F 0 "AE1" H 10469 2614 50  0000 L CNN
F 1 "2.45GHz PCB antenna" H 10469 2523 50  0000 L CNN
F 2 "RF_Antenna:Texas_SWRA117D_2.4GHz_Right" H 10325 2675 50  0001 C CNN
F 3 "~" H 10325 2675 50  0001 C CNN
	1    10325 2575
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
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
L Transistor_FET:AO3401A Q1
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
L Device:C_Small C4
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
L Device:C_Small C1
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
L Device:R_Small R8
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
L Device:R_Small R9
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
L Timer:LMC555xM U3
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
L Connector_Generic:Conn_01x04 J1
U 1 1 5F817EB3
P 10650 900
F 0 "J1" H 10730 892 50  0000 L CNN
F 1 "SWD" H 10730 801 50  0000 L CNN
F 2 "PlantBuddy:Debug_Connector" H 10650 900 50  0001 C CNN
F 3 "~" H 10650 900 50  0001 C CNN
F 4 "C541879" H 10650 900 50  0001 C CNN "LCSC"
	1    10650 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_Small D1
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
L power:GND #PWR01
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
L Device:R_Small R3
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
Text Label 7525 3525 2    50   ~ 0
LEDY
Wire Wire Line
	7525 3525 7125 3525
Text Label 9850 4325 0    50   ~ 0
LEDY
Wire Bus Line
	2150 4500 2600 4500
Wire Bus Line
	2150 4500 2150 5825
$EndSCHEMATC
