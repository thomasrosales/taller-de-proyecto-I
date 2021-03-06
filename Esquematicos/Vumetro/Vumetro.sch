EESchema Schematic File Version 4
LIBS:Vumetro-cache
EELAYER 29 0
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
$Comp
L Vumetro-rescue:R-Device-Vumetro-rescue R1
U 1 1 5BD08240
P 3350 2400
F 0 "R1" H 3420 2446 50  0000 L CNN
F 1 "5.6K" H 3420 2355 50  0000 L CNN
F 2 "" V 3280 2400 50  0001 C CNN
F 3 "~" H 3350 2400 50  0001 C CNN
	1    3350 2400
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:R-Device-Vumetro-rescue R2
U 1 1 5BD082FA
P 3350 2900
F 0 "R2" H 3420 2946 50  0000 L CNN
F 1 "2.7K" H 3420 2855 50  0000 L CNN
F 2 "" V 3280 2900 50  0001 C CNN
F 3 "~" H 3350 2900 50  0001 C CNN
	1    3350 2900
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0102
U 1 1 5BD08B01
P 3600 1000
F 0 "#PWR0102" H 3600 750 50  0001 C CNN
F 1 "GNDA" H 3605 827 50  0000 C CNN
F 2 "" H 3600 1000 50  0001 C CNN
F 3 "" H 3600 1000 50  0001 C CNN
	1    3600 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1400 1950 1400
$Comp
L Vumetro-rescue:R_POT-Device-Vumetro-rescue RV1
U 1 1 5BD09203
P 2800 1650
F 0 "RV1" H 2730 1696 50  0000 R CNN
F 1 "10K" H 2730 1605 50  0000 R CNN
F 2 "" H 2800 1650 50  0001 C CNN
F 3 "~" H 2800 1650 50  0001 C CNN
	1    2800 1650
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 1400 2400 1650
Wire Wire Line
	2400 1650 2650 1650
Wire Wire Line
	2950 1650 3400 1650
Wire Wire Line
	3400 1000 3600 1000
Wire Wire Line
	3350 2550 3350 2650
Wire Wire Line
	2800 2650 3350 2650
Wire Wire Line
	3350 2650 3350 2750
Connection ~ 3350 2650
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0103
U 1 1 5BD0D7F2
P 3350 3200
F 0 "#PWR0103" H 3350 2950 50  0001 C CNN
F 1 "GNDA" H 3355 3027 50  0000 C CNN
F 2 "" H 3350 3200 50  0001 C CNN
F 3 "" H 3350 3200 50  0001 C CNN
	1    3350 3200
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:C-Device-Vumetro-rescue C2
U 1 1 5BD1B29A
P 4250 2900
F 0 "C2" H 4365 2946 50  0000 L CNN
F 1 "2.2 nF" H 4365 2855 50  0000 L CNN
F 2 "" H 4288 2750 50  0001 C CNN
F 3 "~" H 4250 2900 50  0001 C CNN
	1    4250 2900
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0104
U 1 1 5BD1B343
P 4250 3200
F 0 "#PWR0104" H 4250 2950 50  0001 C CNN
F 1 "GNDA" H 4255 3027 50  0000 C CNN
F 2 "" H 4250 3200 50  0001 C CNN
F 3 "" H 4250 3200 50  0001 C CNN
	1    4250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3050 4250 3200
$Comp
L Vumetro-rescue:R-Device-Vumetro-rescue R4
U 1 1 5BD1B49E
P 3750 2650
F 0 "R4" V 3543 2650 50  0000 C CNN
F 1 "4.7K" V 3634 2650 50  0000 C CNN
F 2 "" V 3680 2650 50  0001 C CNN
F 3 "~" H 3750 2650 50  0001 C CNN
	1    3750 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 2650 4250 2650
Wire Wire Line
	4250 2650 4250 2750
Wire Wire Line
	3350 3050 3350 3200
Wire Wire Line
	3350 2650 3600 2650
Connection ~ 4250 2650
$Comp
L Vumetro-rescue:R-Device-Vumetro-rescue R5
U 1 1 5BD1FFCF
P 4250 1800
F 0 "R5" H 4320 1846 50  0000 L CNN
F 1 "4.7K" H 4320 1755 50  0000 L CNN
F 2 "" V 4180 1800 50  0001 C CNN
F 3 "~" H 4250 1800 50  0001 C CNN
	1    4250 1800
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:R-Device-Vumetro-rescue R6
U 1 1 5BD204D6
P 4700 1500
F 0 "R6" V 4493 1500 50  0000 C CNN
F 1 "2.7K" V 4584 1500 50  0000 C CNN
F 2 "" V 4630 1500 50  0001 C CNN
F 3 "~" H 4700 1500 50  0001 C CNN
	1    4700 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 1500 4250 1500
Connection ~ 4250 1500
Wire Wire Line
	4250 1500 4250 1650
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0105
U 1 1 5BD20C9D
P 4250 2200
F 0 "#PWR0105" H 4250 1950 50  0001 C CNN
F 1 "GNDA" H 4255 2027 50  0000 C CNN
F 2 "" H 4250 2200 50  0001 C CNN
F 3 "" H 4250 2200 50  0001 C CNN
	1    4250 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1950 4250 2200
$Comp
L Vumetro-rescue:C-Device-Vumetro-rescue C1
U 1 1 5BD214BE
P 2800 2200
F 0 "C1" H 2915 2246 50  0000 L CNN
F 1 "10 uF" H 2915 2155 50  0000 L CNN
F 2 "" H 2838 2050 50  0001 C CNN
F 3 "~" H 2800 2200 50  0001 C CNN
	1    2800 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 1800 2800 2050
Wire Wire Line
	2800 2350 2800 2650
Text Label 6900 1050 0    50   ~ 0
CH1
$Comp
L Vumetro-rescue:conn_pin8-vumetro-Vumetro-rescue-Vumetro-rescue-Vumetro-rescue U2
U 1 1 5BD8D993
P 4200 3850
F 0 "U2" H 4100 3950 50  0000 L CNN
F 1 "conn_pin8" H 4050 3850 50  0000 L CNN
F 2 "" H 4200 3850 50  0001 C CNN
F 3 "" H 4200 3850 50  0001 C CNN
	1    4200 3850
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:conn_pin8-vumetro-Vumetro-rescue-Vumetro-rescue-Vumetro-rescue U3
U 1 1 5BD8E115
P 4650 3850
F 0 "U3" H 4567 3915 50  0000 C CNN
F 1 "conn_pin8" H 4567 3824 50  0000 C CNN
F 2 "" H 4650 3850 50  0001 C CNN
F 3 "" H 4650 3850 50  0001 C CNN
	1    4650 3850
	-1   0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:opa2350pa-vumetro-Vumetro-rescue-Vumetro-rescue-Vumetro-rescue U4
U 1 1 5BD9369A
P 5350 2250
F 0 "U4" H 5350 2315 50  0000 C CNN
F 1 "opa2350pa" H 5350 2224 50  0000 C CNN
F 2 "" H 5350 2300 50  0001 C CNN
F 3 "" H 5350 2300 50  0001 C CNN
	1    5350 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2650 4950 2650
Wire Wire Line
	4850 1500 4850 2550
Wire Wire Line
	4850 2550 4950 2550
Wire Wire Line
	4950 1050 7050 1050
Wire Wire Line
	4250 1050 4950 1050
Wire Wire Line
	4250 1050 4250 1500
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0106
U 1 1 5BD9D42A
P 4850 2900
F 0 "#PWR0106" H 4850 2650 50  0001 C CNN
F 1 "GNDA" H 4855 2727 50  0000 C CNN
F 2 "" H 4850 2900 50  0001 C CNN
F 3 "" H 4850 2900 50  0001 C CNN
	1    4850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2900 4850 2750
Wire Wire Line
	4850 2750 4950 2750
NoConn ~ 5750 2550
NoConn ~ 5750 2650
NoConn ~ 5750 2750
Wire Wire Line
	2200 5350 2000 5350
Wire Wire Line
	2000 5350 2000 4750
Wire Wire Line
	2000 4750 3250 4750
Wire Wire Line
	2200 5650 1800 5650
Wire Wire Line
	1800 5650 1800 4550
Wire Wire Line
	3250 4550 1800 4550
Wire Wire Line
	2200 5750 1700 5750
Wire Wire Line
	1700 5750 1700 4450
Wire Wire Line
	1700 4450 3250 4450
Wire Wire Line
	2200 5850 1600 5850
Wire Wire Line
	3250 4350 1600 4350
Wire Wire Line
	2200 6150 1400 6150
Wire Wire Line
	1400 6150 1400 4150
Wire Wire Line
	1400 4150 3250 4150
Wire Wire Line
	2200 6250 1300 6250
Wire Wire Line
	1300 6250 1300 4050
Wire Wire Line
	1300 4050 3250 4050
Text Label 3250 4750 0    50   ~ 0
ROW0
Text Label 3800 4050 0    50   ~ 0
ROW4
Wire Wire Line
	3800 4050 4000 4050
Wire Wire Line
	4000 4150 3800 4150
Wire Wire Line
	4000 4250 3800 4250
Wire Wire Line
	4000 4350 3800 4350
Wire Wire Line
	4000 4450 3800 4450
Wire Wire Line
	4000 4550 3800 4550
Wire Wire Line
	4000 4650 3800 4650
Wire Wire Line
	4000 4750 3800 4750
Text Label 3250 4550 0    50   ~ 0
ROW6
Text Label 3250 4450 0    50   ~ 0
ROW2
Text Label 3250 4350 0    50   ~ 0
ROW3
Text Label 3250 4150 0    50   ~ 0
ROW5
Text Label 3250 4050 0    50   ~ 0
ROW1
Text Label 3800 4150 0    50   ~ 0
ROW6
Text Label 3800 4250 0    50   ~ 0
COL1
Text Label 3800 4350 0    50   ~ 0
COL2
Text Label 3800 4450 0    50   ~ 0
ROW7
Text Label 3800 4550 0    50   ~ 0
COL4
Text Label 3800 4650 0    50   ~ 0
ROW5
Text Label 3800 4750 0    50   ~ 0
ROW2
Wire Wire Line
	5300 5450 5300 4950
Wire Wire Line
	5500 5550 5500 4950
Wire Wire Line
	5700 5650 5700 4950
Wire Wire Line
	5900 5950 5900 4950
Wire Wire Line
	6100 6050 6100 4950
Wire Wire Line
	6300 6150 6300 4950
Wire Wire Line
	6500 6250 6500 4950
Wire Wire Line
	5100 5350 5100 4950
Wire Wire Line
	3200 5350 5100 5350
Wire Wire Line
	3200 5450 5300 5450
Wire Wire Line
	3200 5550 5500 5550
Wire Wire Line
	3200 5650 5700 5650
Wire Wire Line
	3200 5950 5900 5950
Wire Wire Line
	3200 6050 6100 6050
Wire Wire Line
	3200 6150 6300 6150
Wire Wire Line
	3200 6250 6500 6250
Text Label 5100 5150 1    50   ~ 0
COL3
Text Label 5300 5200 1    50   ~ 0
COL7
Text Label 5500 5150 1    50   ~ 0
COL2
Text Label 5700 5150 1    50   ~ 0
COL4
Text Label 5900 5150 1    50   ~ 0
COL0
Text Label 6100 5150 1    50   ~ 0
COL5
Text Label 6300 5150 1    50   ~ 0
COL1
Text Label 6500 5150 1    50   ~ 0
COL6
Wire Wire Line
	4850 4750 5100 4750
Wire Wire Line
	4850 4650 5100 4650
Wire Wire Line
	4850 4550 5100 4550
Wire Wire Line
	4850 4450 5100 4450
Wire Wire Line
	4850 4350 5100 4350
Wire Wire Line
	4850 4250 5100 4250
Wire Wire Line
	4850 4150 5100 4150
Wire Wire Line
	4850 4050 5100 4050
Text Label 5100 4050 0    50   ~ 0
COL7
Text Label 5100 4150 0    50   ~ 0
COL6
Text Label 5100 4250 0    50   ~ 0
ROW1
Text Label 5100 4350 0    50   ~ 0
COL0
Text Label 5100 4450 0    50   ~ 0
ROW3
Text Label 5100 4550 0    50   ~ 0
COL5
Text Label 5100 4650 0    50   ~ 0
COL3
Text Label 5100 4750 0    50   ~ 0
ROW0
Wire Wire Line
	2200 5550 1950 5550
Wire Wire Line
	2200 6050 1950 6050
Text Label 1950 6050 0    50   ~ 0
GNDA
Wire Wire Line
	3200 5850 3350 5850
Text Label 3350 5850 0    50   ~ 0
ISET
$Comp
L Vumetro-rescue:CAP-pspice-Vumetro-rescue C4
U 1 1 5BDF9589
P 4900 6800
F 0 "C4" H 5078 6846 50  0000 L CNN
F 1 "1.0uF" H 5078 6755 50  0000 L CNN
F 2 "" H 4900 6800 50  0001 C CNN
F 3 "" H 4900 6800 50  0001 C CNN
	1    4900 6800
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:CAP-pspice-Vumetro-rescue C3
U 1 1 5BDF96A7
P 4300 6800
F 0 "C3" H 4478 6846 50  0000 L CNN
F 1 "0.1uF" H 4478 6755 50  0000 L CNN
F 2 "" H 4300 6800 50  0001 C CNN
F 3 "" H 4300 6800 50  0001 C CNN
	1    4300 6800
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:R-Device-Vumetro-rescue R3
U 1 1 5BDF9744
P 3600 7050
F 0 "R3" V 3393 7050 50  0000 C CNN
F 1 "10K" V 3484 7050 50  0000 C CNN
F 2 "" V 3530 7050 50  0001 C CNN
F 3 "~" H 3600 7050 50  0001 C CNN
	1    3600 7050
	0    1    1    0   
$EndComp
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0107
U 1 1 5BDF9885
P 4300 7150
F 0 "#PWR0107" H 4300 6900 50  0001 C CNN
F 1 "GNDA" H 4305 6977 50  0000 C CNN
F 2 "" H 4300 7150 50  0001 C CNN
F 3 "" H 4300 7150 50  0001 C CNN
	1    4300 7150
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:+5V-power-Vumetro-rescue #PWR0108
U 1 1 5BDFBFF0
P 3800 6550
F 0 "#PWR0108" H 3800 6400 50  0001 C CNN
F 1 "+5V" H 3815 6723 50  0000 C CNN
F 2 "" H 3800 6550 50  0001 C CNN
F 3 "" H 3800 6550 50  0001 C CNN
	1    3800 6550
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0109
U 1 1 5BDFC0B2
P 4900 7150
F 0 "#PWR0109" H 4900 6900 50  0001 C CNN
F 1 "GNDA" H 4905 6977 50  0000 C CNN
F 2 "" H 4900 7150 50  0001 C CNN
F 3 "" H 4900 7150 50  0001 C CNN
	1    4900 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 7050 3800 7050
Wire Wire Line
	3800 7050 3800 6550
Wire Wire Line
	4300 6550 3800 6550
Connection ~ 3800 6550
Wire Wire Line
	4300 6550 4900 6550
Connection ~ 4300 6550
Wire Wire Line
	4300 7050 4300 7150
Wire Wire Line
	4900 7050 4900 7150
Wire Wire Line
	3450 7050 3150 7050
Text Label 3150 7050 0    50   ~ 0
ISET
Wire Wire Line
	3800 6550 3150 6550
Text Label 3150 6550 0    50   ~ 0
V+
Wire Wire Line
	3200 5750 3350 5750
Text Label 3350 5750 0    50   ~ 0
V+
Wire Wire Line
	2200 6350 1950 6350
Text Label 1950 6350 0    50   ~ 0
GPIO0
Wire Wire Line
	2200 5250 2100 5250
Wire Wire Line
	2100 5250 2100 4850
Wire Wire Line
	2100 4850 2300 4850
Text Label 2300 4850 0    50   ~ 0
SPI_MOSI
Wire Wire Line
	1600 5850 1600 4350
Wire Wire Line
	3200 6350 3400 6350
Text Label 3400 6350 0    50   ~ 0
SPI_SCK
NoConn ~ 3200 5250
$Comp
L Vumetro-rescue:AudioJack5_Ground-Connector-Vumetro-rescue J1
U 1 1 5BE5F8BB
P 1750 1200
F 0 "J1" H 1679 1642 50  0000 C CNN
F 1 "AudioJack5_Ground" H 1679 1551 50  0000 C CNN
F 2 "" H 1750 1200 50  0001 C CNN
F 3 "~" H 1750 1200 50  0001 C CNN
	1    1750 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1000 3400 1000
NoConn ~ 1950 1300
NoConn ~ 1950 1200
NoConn ~ 1950 1100
$Comp
L Vumetro-rescue:conn_pin40-vumetro-Vumetro-rescue P1
U 1 1 5BD936AB
P 9700 2750
F 0 "P1" H 9700 2815 50  0000 C CNN
F 1 "conn_pin40" H 9700 2724 50  0000 C CNN
F 2 "" H 9700 2750 50  0001 C CNN
F 3 "" H 9700 2750 50  0001 C CNN
	1    9700 2750
	1    0    0    -1  
$EndComp
NoConn ~ 8000 3350
NoConn ~ 8000 3650
NoConn ~ 8000 3750
NoConn ~ 8000 3850
NoConn ~ 8000 4050
NoConn ~ 8000 4450
NoConn ~ 8000 4550
NoConn ~ 8000 4650
NoConn ~ 8500 3050
NoConn ~ 8500 3150
NoConn ~ 8500 3250
NoConn ~ 8500 3350
NoConn ~ 8500 3450
NoConn ~ 8500 3550
NoConn ~ 8500 3650
NoConn ~ 8500 3750
NoConn ~ 8500 3950
NoConn ~ 8500 4050
NoConn ~ 8500 4150
NoConn ~ 8500 4250
NoConn ~ 8500 4350
NoConn ~ 8500 4450
NoConn ~ 8500 4550
NoConn ~ 8500 4650
NoConn ~ 8500 4750
NoConn ~ 8500 4850
NoConn ~ 9950 4550
NoConn ~ 9950 4650
NoConn ~ 9950 3150
NoConn ~ 9450 3050
NoConn ~ 9450 3150
NoConn ~ 9450 3850
NoConn ~ 9450 3950
NoConn ~ 9450 4050
Text Label 7650 2950 0    50   ~ 0
3V3
Text Label 7650 3050 0    50   ~ 0
GND
Text Label 7650 3150 0    50   ~ 0
GND
Text Label 7650 3250 0    50   ~ 0
GND
Text Label 7650 3450 0    50   ~ 0
GND
Text Label 7650 3550 0    50   ~ 0
GND
Text Label 7650 3950 0    50   ~ 0
SPI_MOSI
Wire Wire Line
	7650 3950 8000 3950
Wire Wire Line
	7650 2950 8000 2950
Wire Wire Line
	7650 3050 8000 3050
Wire Wire Line
	7650 3150 8000 3150
Wire Wire Line
	7650 3250 8000 3250
Wire Wire Line
	7650 3450 8000 3450
Wire Wire Line
	7650 3550 8000 3550
Text Label 7650 4150 0    50   ~ 0
GND
Text Label 7650 4250 0    50   ~ 0
GND
Text Label 7650 4750 0    50   ~ 0
GND
Text Label 7650 4750 0    50   ~ 0
GND
Wire Wire Line
	7650 4150 8000 4150
Wire Wire Line
	7650 4250 8000 4250
Wire Wire Line
	7650 4750 8000 4750
Text Label 7650 4850 0    50   ~ 0
GND
Wire Wire Line
	7650 4850 8000 4850
Text Label 8800 3850 2    50   ~ 0
SPI_SCK
Wire Wire Line
	8500 3850 8800 3850
Text Label 8750 2950 2    50   ~ 0
5V
Wire Wire Line
	8500 2950 8750 2950
Wire Wire Line
	9200 3250 9450 3250
Wire Wire Line
	9450 3550 9200 3550
Text Label 9200 3550 0    50   ~ 0
CH1
Text Label 9200 3250 0    50   ~ 0
GND
NoConn ~ 9450 3350
NoConn ~ 9450 3450
NoConn ~ 9450 3650
Wire Wire Line
	9200 2950 9450 2950
Text Label 9200 2950 0    50   ~ 0
3V3
Wire Wire Line
	9950 2950 10250 2950
Text Label 10250 2950 2    50   ~ 0
5V
Wire Wire Line
	9950 3050 10250 3050
Wire Wire Line
	9950 3250 10250 3250
Wire Wire Line
	9950 3350 10250 3350
Wire Wire Line
	9950 3450 10250 3450
Wire Wire Line
	9950 3550 10250 3550
Wire Wire Line
	9950 3650 10250 3650
Wire Wire Line
	9950 3750 10250 3750
Wire Wire Line
	9950 3850 10250 3850
Wire Wire Line
	9950 3950 10250 3950
Wire Wire Line
	9950 4050 10250 4050
Wire Wire Line
	9950 4150 10250 4150
Wire Wire Line
	9950 4250 10250 4250
Wire Wire Line
	9950 4350 10250 4350
Wire Wire Line
	9950 4450 10250 4450
Wire Wire Line
	9950 4750 10250 4750
Wire Wire Line
	9950 4850 10250 4850
Text Label 10250 3050 2    50   ~ 0
GND
Text Label 10250 3250 2    50   ~ 0
GNDA
Text Label 10250 3350 2    50   ~ 0
GNDA
Text Label 10250 3450 2    50   ~ 0
GNDA
Text Label 10250 3550 2    50   ~ 0
GNDA
Text Label 10250 3650 2    50   ~ 0
GNDA
Text Label 10250 3750 2    50   ~ 0
GNDA
Text Label 10250 3850 2    50   ~ 0
GND
Text Label 10250 3950 2    50   ~ 0
GND
Text Label 10250 4050 2    50   ~ 0
GND
Text Label 10250 4150 2    50   ~ 0
GND
Text Label 10250 4250 2    50   ~ 0
GND
Text Label 10250 4350 2    50   ~ 0
GND
Text Label 10250 4450 2    50   ~ 0
GND
Text Label 10250 4750 2    50   ~ 0
GND
Text Label 10250 4850 2    50   ~ 0
GND
NoConn ~ 9450 3750
Wire Wire Line
	3400 1000 3400 1650
Connection ~ 3400 1000
Connection ~ 4950 1050
Wire Wire Line
	4950 1050 4950 2450
$Comp
L Vumetro-rescue:PWR_FLAG-power-Vumetro-rescue #FLG0101
U 1 1 5C0A1FED
P 1050 1900
F 0 "#FLG0101" H 1050 1975 50  0001 C CNN
F 1 "PWR_FLAG" H 1050 2073 50  0000 C CNN
F 2 "" H 1050 1900 50  0001 C CNN
F 3 "~" H 1050 1900 50  0001 C CNN
	1    1050 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5450 1900 5450
Wire Wire Line
	1900 5450 1900 4650
Wire Wire Line
	1900 4650 3250 4650
Text Label 3250 4650 0    50   ~ 0
ROW4
Wire Wire Line
	2200 5950 1500 5950
Wire Wire Line
	1500 5950 1500 4250
Wire Wire Line
	1500 4250 3250 4250
Text Label 3250 4250 0    50   ~ 0
ROW7
$Comp
L Vumetro-rescue:MAX7219-vumetro-Vumetro-rescue U1
U 1 1 5BD94EE9
P 2700 5150
F 0 "U1" H 2700 5315 50  0000 C CNN
F 1 "MAX7219" H 2700 5224 50  0000 C CNN
F 2 "" H 2700 5350 50  0001 C CNN
F 3 "" H 2700 5350 50  0001 C CNN
	1    2700 5150
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:PWR_FLAG-power-Vumetro-rescue #FLG0102
U 1 1 5BDCD5F1
P 1050 3000
F 0 "#FLG0102" H 1050 3075 50  0001 C CNN
F 1 "PWR_FLAG" H 1050 3173 50  0000 C CNN
F 2 "" H 1050 3000 50  0001 C CNN
F 3 "~" H 1050 3000 50  0001 C CNN
	1    1050 3000
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:GNDA-power-Vumetro-rescue #PWR0110
U 1 1 5BE11156
P 1050 1900
F 0 "#PWR0110" H 1050 1650 50  0001 C CNN
F 1 "GNDA" H 1055 1727 50  0000 C CNN
F 2 "" H 1050 1900 50  0001 C CNN
F 3 "" H 1050 1900 50  0001 C CNN
	1    1050 1900
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:PWR_FLAG-power-Vumetro-rescue #FLG0103
U 1 1 5BE11DF9
P 1050 2450
F 0 "#FLG0103" H 1050 2525 50  0001 C CNN
F 1 "PWR_FLAG" H 1050 2623 50  0000 C CNN
F 2 "" H 1050 2450 50  0001 C CNN
F 3 "~" H 1050 2450 50  0001 C CNN
	1    1050 2450
	1    0    0    -1  
$EndComp
$Comp
L Vumetro-rescue:+5V-power-Vumetro-rescue #PWR0111
U 1 1 5BE126C5
P 1050 2450
F 0 "#PWR0111" H 1050 2300 50  0001 C CNN
F 1 "+5V" H 1065 2623 50  0000 C CNN
F 2 "" H 1050 2450 50  0001 C CNN
F 3 "" H 1050 2450 50  0001 C CNN
	1    1050 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3350 2250 3350 2050
$Comp
L Vumetro-rescue:+3V3-power-Vumetro-rescue #PWR0112
U 1 1 5BDC2B19
P 3350 2050
F 0 "#PWR0112" H 3350 1900 50  0001 C CNN
F 1 "+3V3" H 3365 2223 50  0000 C CNN
F 2 "" H 3350 2050 50  0001 C CNN
F 3 "" H 3350 2050 50  0001 C CNN
	1    3350 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2450 6050 2450
$Comp
L Vumetro-rescue:+3V3-power-Vumetro-rescue #PWR0101
U 1 1 5BDC0419
P 1050 3000
F 0 "#PWR0101" H 1050 2850 50  0001 C CNN
F 1 "+3V3" H 1065 3173 50  0000 C CNN
F 2 "" H 1050 3000 50  0001 C CNN
F 3 "" H 1050 3000 50  0001 C CNN
	1    1050 3000
	-1   0    0    1   
$EndComp
$Comp
L Vumetro-rescue:+3V3-power-Vumetro-rescue #PWR0113
U 1 1 5BDD5FCB
P 6050 2150
F 0 "#PWR0113" H 6050 2000 50  0001 C CNN
F 1 "+3V3" H 6065 2323 50  0000 C CNN
F 2 "" H 6050 2150 50  0001 C CNN
F 3 "" H 6050 2150 50  0001 C CNN
	1    6050 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2150 6050 2450
$Comp
L Connector:Conn_01x08_Female J2
U 1 1 5BEC2E1E
P 9050 1850
F 0 "J2" H 8700 2500 50  0000 L CNN
F 1 "Conn_Teclado_Matricial_4x4" H 8350 2350 50  0000 L CNN
F 2 "" H 9050 1850 50  0001 C CNN
F 3 "~" H 9050 1850 50  0001 C CNN
	1    9050 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1550 8650 1550
Wire Wire Line
	8850 1650 8650 1650
Wire Wire Line
	8850 1750 8650 1750
Wire Wire Line
	8850 1850 8650 1850
Wire Wire Line
	8850 1950 8650 1950
Wire Wire Line
	8850 2050 8650 2050
Wire Wire Line
	8850 2150 8650 2150
Wire Wire Line
	8850 2250 8650 2250
Text Label 8650 1550 2    50   ~ 0
232_TX
Text Label 8650 1650 2    50   ~ 0
CAN_RD
Text Label 8650 1750 2    50   ~ 0
CAN_TD
Text Label 8650 1850 2    50   ~ 0
T_COL1
Text Label 8650 1950 2    50   ~ 0
T_FIL0
Text Label 8650 2050 2    50   ~ 0
T_FIL3
Text Label 8650 2150 2    50   ~ 0
T_FIL2
Text Label 8650 2250 2    50   ~ 0
T_COL0
Wire Wire Line
	9250 4850 9450 4850
Wire Wire Line
	9450 4750 9250 4750
Wire Wire Line
	9450 4650 9250 4650
Wire Wire Line
	9450 4550 9250 4550
Wire Wire Line
	9450 4450 9250 4450
Wire Wire Line
	9450 4350 9250 4350
Wire Wire Line
	9450 4250 9250 4250
Wire Wire Line
	9450 4150 9250 4150
Text Label 9250 4850 2    50   ~ 0
T_COL0
Text Label 9250 4750 2    50   ~ 0
T_FIL2
Text Label 9250 4650 2    50   ~ 0
T_FIL3
Text Label 9250 4550 2    50   ~ 0
T_FIL0
Text Label 9250 4450 2    50   ~ 0
T_COL1
Text Label 9250 4350 2    50   ~ 0
CAN_TD
Text Label 9250 4250 2    50   ~ 0
CAN_RD
Text Label 9250 4150 2    50   ~ 0
232_TX
$Comp
L Vumetro-rescue:conn_pin40-vumetro-Vumetro-rescue P2
U 1 1 5BD92927
P 8250 2750
F 0 "P2" H 8250 2815 50  0000 C CNN
F 1 "conn_pin40" H 8250 2724 50  0000 C CNN
F 2 "" H 8250 2750 50  0001 C CNN
F 3 "" H 8250 2750 50  0001 C CNN
	1    8250 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 4350 7650 4350
Text Label 7650 4350 0    50   ~ 0
GPIO0
Text Label 1950 5550 0    50   ~ 0
GNDA
$EndSCHEMATC
