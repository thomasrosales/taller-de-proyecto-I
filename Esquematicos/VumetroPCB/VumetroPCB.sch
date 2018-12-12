EESchema Schematic File Version 4
LIBS:VumetroPCB-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Poncho Mediano - Modelo - Ejemplo - Template"
Date "lun 05 oct 2015"
Rev "1.0"
Comp "Proyecto CIAA - COMPUTADORA INDUSTRIAL ABIERTA ARGENTINA"
Comment1 "https://github.com/ciaa/Ponchos/tree/master/modelos/doc"
Comment2 "Autores y Licencia del template (Diego Brengi - UNLaM)"
Comment3 "Autor del poncho (COMPLETAR NOMBRE Y APELLIDO). Ver directorio \"doc\""
Comment4 "CÓDIGO PONCHO:"
$EndDescr
$Comp
L vumetro:MatrixLed8x8 U4
U 1 1 5BF4B00E
P 4900 5000
F 0 "U4" H 4850 5600 50  0000 L CNN
F 1 "MatrixLed8x8" H 4650 5500 50  0000 L CNN
F 2 "Projecto:Matriz_8x8" H 4800 5000 50  0001 C CNN
F 3 "" H 4800 5000 50  0001 C CNN
	1    4900 5000
	1    0    0    -1  
$EndComp
$Comp
L vumetro:MAX7219 U3
U 1 1 5BF4B9E6
P 2400 4250
F 0 "U3" H 2400 4415 50  0000 C CNN
F 1 "MAX7219" H 2400 4324 50  0000 C CNN
F 2 "Projecto:MAX7219" H 2400 4450 50  0001 C CNN
F 3 "" H 2400 4450 50  0001 C CNN
	1    2400 4250
	1    0    0    -1  
$EndComp
$Comp
L vumetro:opa2350pa U2
U 1 1 5BF4C651
P 5850 2150
F 0 "U2" H 5850 2215 50  0000 C CNN
F 1 "opa2350pa" H 5850 2124 50  0000 C CNN
F 2 "Projecto:OPA2350PA" H 5850 2200 50  0001 C CNN
F 3 "" H 5850 2200 50  0001 C CNN
	1    5850 2150
	1    0    0    -1  
$EndComp
NoConn ~ 8350 3850
NoConn ~ 8350 3950
NoConn ~ 7150 4850
NoConn ~ 9150 4450
Wire Wire Line
	8850 4350 9150 4350
Wire Wire Line
	8850 4950 9150 4950
Wire Wire Line
	8850 5050 9150 5050
Wire Wire Line
	8850 5150 9150 5150
Wire Wire Line
	8850 5250 9150 5250
Wire Wire Line
	8850 5350 9150 5350
Wire Wire Line
	8850 5450 9150 5450
Wire Wire Line
	8850 5550 9150 5550
Wire Wire Line
	8850 5650 9150 5650
Text Label 6600 5050 0    50   ~ 0
GND
Text Label 6600 4950 0    50   ~ 0
GND
Wire Wire Line
	10350 4450 10500 4450
Text Label 8500 3750 0    50   ~ 0
+5V
Text Label 10500 4450 0    50   ~ 0
GNDA
Text Label 6600 5150 0    50   ~ 0
GPIO0(CIAA)
Text Label 6600 4750 0    50   ~ 0
SPI_MOSI(CIAA)
Wire Wire Line
	8350 4650 8500 4650
Text Label 8500 4650 0    50   ~ 0
SPI_CLK
Text Label 8850 4950 0    50   ~ 0
232_TX
Text Label 8850 5050 0    50   ~ 0
CAN_RD
Text Label 8850 5150 0    50   ~ 0
CAN_TD
Text Label 8850 5250 0    50   ~ 0
T_COL1
Text Label 8850 5350 0    50   ~ 0
T_FIL0
Text Label 8850 5450 0    50   ~ 0
T_FIL3
Text Label 8850 5550 0    50   ~ 0
T_FIL2
Text Label 8850 5650 0    50   ~ 0
T_COL0
Text Label 8850 4350 0    50   ~ 0
CH1
Wire Wire Line
	9150 1550 8650 1550
Wire Wire Line
	9150 1650 8650 1650
Wire Wire Line
	9150 1750 8650 1750
Wire Wire Line
	9150 1850 8650 1850
Wire Wire Line
	9150 1950 8650 1950
Wire Wire Line
	9150 2050 8650 2050
Wire Wire Line
	9150 2150 8650 2150
Wire Wire Line
	9150 2250 8650 2250
Text Label 8650 1550 0    50   ~ 0
232_TX
Text Label 8650 1650 0    50   ~ 0
CAN_RD
Text Label 8650 1750 0    50   ~ 0
CAN_TD
Text Label 8650 1850 0    50   ~ 0
T_COL1
Text Label 8650 1950 0    50   ~ 0
T_FIL0
Text Label 8650 2050 0    50   ~ 0
T_FIL3
Text Label 8650 2150 0    50   ~ 0
T_FIL2
Text Label 8650 2250 0    50   ~ 0
T_COL0
NoConn ~ 2900 4350
NoConn ~ 1700 1850
NoConn ~ 1700 1650
NoConn ~ 1700 1750
Wire Wire Line
	2900 4450 3050 4450
Wire Wire Line
	2900 4550 3050 4550
Wire Wire Line
	2900 4650 3050 4650
Wire Wire Line
	2900 4750 3050 4750
Wire Wire Line
	2900 4850 3050 4850
Wire Wire Line
	2900 4950 3050 4950
Wire Wire Line
	2900 5050 3050 5050
Wire Wire Line
	2900 5150 3050 5150
Wire Wire Line
	2900 5250 3050 5250
Wire Wire Line
	2900 5350 3050 5350
Wire Wire Line
	2900 5450 3050 5450
Wire Wire Line
	5350 4700 5500 4700
Wire Wire Line
	5350 4800 5500 4800
Wire Wire Line
	5350 4900 5500 4900
Wire Wire Line
	5350 5000 5500 5000
Wire Wire Line
	5350 5100 5500 5100
Wire Wire Line
	5350 5200 5500 5200
Wire Wire Line
	5350 5300 5500 5300
Wire Wire Line
	5350 5400 5500 5400
Wire Wire Line
	4450 4700 3950 4700
Wire Wire Line
	4450 4800 3950 4800
Wire Wire Line
	4450 4900 3950 4900
Wire Wire Line
	4450 5000 3950 5000
Wire Wire Line
	4450 5100 3950 5100
Wire Wire Line
	4450 5200 3950 5200
Wire Wire Line
	4450 5300 3950 5300
Wire Wire Line
	4450 5400 3950 5400
Wire Wire Line
	1900 4350 1400 4350
Wire Wire Line
	1900 4450 1400 4450
Wire Wire Line
	1900 4550 1400 4550
Wire Wire Line
	1900 4650 1400 4650
Wire Wire Line
	1900 4750 1400 4750
Wire Wire Line
	1900 4850 1400 4850
Wire Wire Line
	1900 4950 1400 4950
Wire Wire Line
	1900 5050 1400 5050
Wire Wire Line
	1900 5150 1400 5150
Wire Wire Line
	1900 5250 1400 5250
Wire Wire Line
	1900 5350 1400 5350
Wire Wire Line
	1900 5450 1400 5450
Text Label 3050 4450 0    50   ~ 0
COL2(U3)
Text Label 3050 4550 0    50   ~ 0
COL3(U3)
Text Label 3050 4650 0    50   ~ 0
COL5(U3)
Text Label 3050 4750 0    50   ~ 0
COL4
Text Label 3050 4850 0    50   ~ 0
V+
Text Label 3050 4950 0    50   ~ 0
ISET
Text Label 3050 5050 0    50   ~ 0
COL6
Text Label 3050 5150 0    50   ~ 0
COL1
Text Label 3050 5250 0    50   ~ 0
COL7
Text Label 3050 5350 0    50   ~ 0
COL8
Text Label 3050 5450 0    50   ~ 0
SPI_CLK
Text Label 1400 4350 0    50   ~ 0
SPI_MOSI(U3)
Text Label 1400 4450 0    50   ~ 0
ROW5
Text Label 1400 4550 0    50   ~ 0
ROW7
Text Label 1400 4650 0    50   ~ 0
GND
Text Label 1400 4750 0    50   ~ 0
ROW8
Text Label 1400 4850 0    50   ~ 0
ROW6
Text Label 1400 4950 0    50   ~ 0
ROW3
Text Label 1400 5050 0    50   ~ 0
ROW1
Text Label 1400 5150 0    50   ~ 0
GND
Text Label 1400 5250 0    50   ~ 0
ROW4
Text Label 1400 5350 0    50   ~ 0
ROW2
Text Label 1400 5450 0    50   ~ 0
GPIO0(U3)
Text Label 3950 4700 0    50   ~ 0
ROW5
Text Label 3950 4800 0    50   ~ 0
ROW7
Text Label 3950 5100 0    50   ~ 0
ROW8
Text Label 3950 5200 0    50   ~ 0
COL5(U4)
Text Label 3950 5300 0    50   ~ 0
ROW6
Text Label 3950 5400 0    50   ~ 0
ROW3
Text Label 3950 5000 0    50   ~ 0
COL3(U4)
Text Label 3950 4900 0    50   ~ 0
COL2(U4)
Text Label 5500 4700 0    50   ~ 0
COL8
Text Label 5500 4800 0    50   ~ 0
COL7
Text Label 5500 5000 0    50   ~ 0
COL1
Text Label 5500 5200 0    50   ~ 0
COL6
Text Label 5500 5300 0    50   ~ 0
COL4
Text Label 5500 5400 0    50   ~ 0
ROW1
Text Label 5500 5100 0    50   ~ 0
ROW4
Text Label 5500 4900 0    50   ~ 0
ROW2
$Comp
L vumetro:R R3
U 1 1 5C140F9E
P 3450 2300
F 0 "R3" H 3520 2346 50  0000 L CNN
F 1 "5.6K" H 3520 2255 50  0000 L CNN
F 2 "Projecto:Resistor" V 3380 2300 50  0001 C CNN
F 3 "~" H 3450 2300 50  0001 C CNN
	1    3450 2300
	1    0    0    -1  
$EndComp
$Comp
L vumetro:R R1
U 1 1 5C141C3A
P 4850 1650
F 0 "R1" V 4643 1650 50  0000 C CNN
F 1 "2.7K" V 4734 1650 50  0000 C CNN
F 2 "Projecto:Resistor" V 4780 1650 50  0001 C CNN
F 3 "~" H 4850 1650 50  0001 C CNN
	1    4850 1650
	0    1    1    0   
$EndComp
$Comp
L vumetro:R R5
U 1 1 5C146F75
P 3450 2800
F 0 "R5" H 3520 2846 50  0000 L CNN
F 1 "2.7K" H 3520 2755 50  0000 L CNN
F 2 "Projecto:Resistor" V 3380 2800 50  0001 C CNN
F 3 "~" H 3450 2800 50  0001 C CNN
	1    3450 2800
	1    0    0    -1  
$EndComp
$Comp
L vumetro:R R4
U 1 1 5C14C23E
P 3850 2550
F 0 "R4" V 3643 2550 50  0000 C CNN
F 1 "4.7K" V 3734 2550 50  0000 C CNN
F 2 "Projecto:Resistor" V 3780 2550 50  0001 C CNN
F 3 "~" H 3850 2550 50  0001 C CNN
	1    3850 2550
	0    1    1    0   
$EndComp
$Comp
L vumetro:R R2
U 1 1 5C1516D1
P 4500 1950
F 0 "R2" H 4570 1996 50  0000 L CNN
F 1 "4.7K" H 4570 1905 50  0000 L CNN
F 2 "Projecto:Resistor" V 4430 1950 50  0001 C CNN
F 3 "~" H 4500 1950 50  0001 C CNN
	1    4500 1950
	1    0    0    -1  
$EndComp
$Comp
L vumetro:R_POT RV1
U 1 1 5C16359C
P 2350 1750
F 0 "RV1" V 2143 1750 50  0000 C CNN
F 1 "10K" V 2234 1750 50  0000 C CNN
F 2 "Projecto:Potentiometer_Bourns" H 2350 1750 50  0001 C CNN
F 3 "~" H 2350 1750 50  0001 C CNN
	1    2350 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 2650 3450 2550
Connection ~ 3450 2550
Wire Wire Line
	3450 2550 3450 2450
$Comp
L vumetro:C C1
U 1 1 5C1AD64D
P 2350 2200
F 0 "C1" H 2100 2250 50  0000 L CNN
F 1 "10uF" H 2050 2150 50  0000 L CNN
F 2 "Projecto:Capacitor" H 2350 2200 50  0001 C CNN
F 3 "~" H 2350 2200 50  0001 C CNN
	1    2350 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2050 3450 2150
Wire Wire Line
	3700 2550 3450 2550
Wire Wire Line
	3450 3100 3450 2950
Wire Wire Line
	5450 2550 4350 2550
Wire Wire Line
	5450 2650 5100 2650
Wire Wire Line
	5450 2450 5150 2450
Wire Wire Line
	5150 2450 5150 1650
Wire Wire Line
	5450 2350 5300 2350
Wire Wire Line
	5300 2350 5300 1250
Wire Wire Line
	6250 2350 6450 2350
Wire Wire Line
	6450 2350 6450 2150
Wire Wire Line
	4500 1800 4500 1650
Wire Wire Line
	4500 1250 5300 1250
Wire Wire Line
	4700 1650 4500 1650
Connection ~ 4500 1650
Wire Wire Line
	4500 1650 4500 1250
Wire Wire Line
	5000 1650 5150 1650
Wire Wire Line
	4500 2100 4500 2250
Text Label 6500 1250 0    50   ~ 0
CH1
NoConn ~ 6250 2450
NoConn ~ 6250 2550
NoConn ~ 6250 2650
$Comp
L vumetro:R R6
U 1 1 5C2B9D21
P 1650 6950
F 0 "R6" V 1443 6950 50  0000 C CNN
F 1 "10K" V 1534 6950 50  0000 C CNN
F 2 "Projecto:Resistor" V 1580 6950 50  0001 C CNN
F 3 "~" H 1650 6950 50  0001 C CNN
	1    1650 6950
	0    1    1    0   
$EndComp
Wire Wire Line
	1500 6950 1250 6950
Wire Wire Line
	1800 6950 1900 6950
Wire Wire Line
	1900 6950 1900 6450
Wire Wire Line
	1250 6450 1900 6450
Connection ~ 1900 6450
$Comp
L vumetro:C C2
U 1 1 5C2EDC52
P 2300 6650
F 0 "C2" H 2050 6700 50  0000 L CNN
F 1 "0.1uF" H 2000 6600 50  0000 L CNN
F 2 "Projecto:Capacitor_Disco" H 2300 6650 50  0001 C CNN
F 3 "~" H 2300 6650 50  0001 C CNN
	1    2300 6650
	1    0    0    -1  
$EndComp
$Comp
L vumetro:C C3
U 1 1 5C2F59E3
P 2800 6650
F 0 "C3" H 2600 6700 50  0000 L CNN
F 1 "1uF" H 2550 6600 50  0000 L CNN
F 2 "Projecto:Capacitor" H 2800 6650 50  0001 C CNN
F 3 "~" H 2800 6650 50  0001 C CNN
	1    2800 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 6450 2800 6550
Wire Wire Line
	1900 6450 2100 6450
Wire Wire Line
	2300 6450 2300 6550
Connection ~ 2300 6450
Wire Wire Line
	2300 6450 2800 6450
Wire Wire Line
	2800 6750 2800 6850
Wire Wire Line
	2300 6750 2300 6850
Wire Wire Line
	2300 6850 2800 6850
Text Label 1250 6450 0    50   ~ 0
V+
Text Label 1250 6950 0    50   ~ 0
ISET
Wire Wire Line
	5300 1250 6500 1250
Connection ~ 5300 1250
$Comp
L vumetro:AudioJack J1
U 1 1 5BF6C01E
P 1500 1650
F 0 "J1" H 1430 2092 50  0000 C CNN
F 1 "AudioJack" H 1430 2001 50  0000 C CNN
F 2 "Projecto:AudioJack" H 1500 1650 50  0001 C CNN
F 3 "~" H 1500 1650 50  0001 C CNN
	1    1500 1650
	1    0    0    -1  
$EndComp
$Comp
L vumetro:conn_teclado_4x4 U1
U 1 1 5BFB17EC
P 9350 1350
F 0 "U1" H 9250 1450 50  0000 L CNN
F 1 "conn_teclado_4x4" H 9000 1350 50  0000 L CNN
F 2 "Projecto:conn_teclado4x4" H 9350 1350 50  0001 C CNN
F 3 "" H 9350 1350 50  0001 C CNN
	1    9350 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2550 3450 2550
Wire Wire Line
	2350 1900 2350 2100
Wire Wire Line
	2350 2300 2350 2550
Wire Wire Line
	2500 1750 2800 1750
Connection ~ 2800 1750
Wire Wire Line
	2800 1750 2800 1900
Wire Wire Line
	2800 1450 2800 1750
Wire Wire Line
	1700 1450 2800 1450
Wire Wire Line
	2200 1750 1950 1750
Wire Wire Line
	1950 1750 1950 1550
Wire Wire Line
	1950 1550 1700 1550
Wire Wire Line
	2100 6450 2100 6300
Connection ~ 2100 6450
Wire Wire Line
	2100 6450 2300 6450
Wire Wire Line
	5100 2650 5100 2900
$Comp
L Misc_Poncho_Grande:GNDA #PWR0106
U 1 1 5C2716DB
P 4500 2250
F 0 "#PWR0106" H 4500 2250 40  0001 C CNN
F 1 "GNDA" H 4500 2317 40  0000 C CNN
F 2 "" H 4500 2250 60  0000 C CNN
F 3 "" H 4500 2250 60  0000 C CNN
	1    4500 2250
	1    0    0    -1  
$EndComp
$Comp
L Misc_Poncho_Grande:GNDA #PWR0101
U 1 1 5C1848D1
P 2800 1900
F 0 "#PWR0101" H 2800 1900 40  0001 C CNN
F 1 "GNDA" H 2800 1967 40  0000 C CNN
F 2 "" H 2800 1900 60  0000 C CNN
F 3 "" H 2800 1900 60  0000 C CNN
	1    2800 1900
	1    0    0    -1  
$EndComp
$Comp
L Misc_Poncho_Grande:GNDA #PWR0104
U 1 1 5C21926A
P 5100 2900
F 0 "#PWR0104" H 5100 2900 40  0001 C CNN
F 1 "GNDA" H 5100 2967 40  0000 C CNN
F 2 "" H 5100 2900 60  0000 C CNN
F 3 "" H 5100 2900 60  0000 C CNN
	1    5100 2900
	1    0    0    -1  
$EndComp
$Comp
L Misc_Poncho_Grande:GNDA #PWR0103
U 1 1 5C1E8D45
P 3450 3100
F 0 "#PWR0103" H 3450 3100 40  0001 C CNN
F 1 "GNDA" H 3450 3167 40  0000 C CNN
F 2 "" H 3450 3100 60  0000 C CNN
F 3 "" H 3450 3100 60  0000 C CNN
	1    3450 3100
	1    0    0    -1  
$EndComp
Connection ~ 2800 6850
Wire Wire Line
	2800 6850 2800 6950
$Comp
L Misc_Poncho_Grande:GNDA #PWR0107
U 1 1 5C33AF3D
P 2800 6950
F 0 "#PWR0107" H 2800 6950 40  0001 C CNN
F 1 "GNDA" H 2900 6900 40  0000 C CNN
F 2 "" H 2800 6950 60  0000 C CNN
F 3 "" H 2800 6950 60  0000 C CNN
	1    2800 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 2700 1400 2500
$Comp
L Misc_Poncho_Grande:PWR_FLAG #FLG0101
U 1 1 5C1DBE4E
P 1400 2500
F 0 "#FLG0101" H 1400 2595 30  0001 C CNN
F 1 "PWR_FLAG" H 1400 2708 30  0000 C CNN
F 2 "" H 1400 2500 60  0000 C CNN
F 3 "" H 1400 2500 60  0000 C CNN
	1    1400 2500
	1    0    0    -1  
$EndComp
$Comp
L Misc_Poncho_Grande:GNDA #PWR0111
U 1 1 5C1DB47F
P 1400 2700
F 0 "#PWR0111" H 1400 2700 40  0001 C CNN
F 1 "GNDA" H 1400 2600 40  0000 C CNN
F 2 "" H 1400 2700 60  0000 C CNN
F 3 "" H 1400 2700 60  0000 C CNN
	1    1400 2700
	1    0    0    -1  
$EndComp
$Comp
L Misc_Poncho_Grande:+5V #PWR0110
U 1 1 5C002C2B
P 2100 6300
F 0 "#PWR0110" H 2100 6390 20  0001 C CNN
F 1 "+5V" H 2097 6428 30  0000 C CNN
F 2 "" H 2100 6300 60  0000 C CNN
F 3 "" H 2100 6300 60  0000 C CNN
	1    2100 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 4350 10500 4350
Text Label 10500 4350 0    50   ~ 0
GNDA
NoConn ~ 7150 4650
$Comp
L vumetro:Conn_Poncho2P_2x_20x2_personalizado XA1
U 1 1 5C06DBD9
P 9400 4050
F 0 "XA1" H 9750 4597 60  0000 C CNN
F 1 "Conn_Poncho2P_2x_20x2_personalizado" H 9750 4491 60  0000 C CNN
F 2 "Projecto:Conn_Poncho_Personalizado" H 9400 4050 60  0001 C CNN
F 3 "" H 9400 4050 60  0000 C CNN
	1    9400 4050
	1    0    0    -1  
$EndComp
$Comp
L vumetro:Conn_Poncho2P_2x_20x2_personalizado XA1
U 2 1 5C06BDFF
P 7400 4050
F 0 "XA1" H 7750 4597 60  0000 C CNN
F 1 "Conn_Poncho2P_2x_20x2_personalizado" H 7750 4491 60  0000 C CNN
F 2 "Projecto:Conn_Poncho_Personalizado" H 7400 4050 60  0001 C CNN
F 3 "" H 7400 4050 60  0000 C CNN
	2    7400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 5150 6600 5150
Wire Wire Line
	7150 4950 6600 4950
Wire Wire Line
	7150 5050 6600 5050
$Comp
L Misc_Poncho_Grande:GNDA #PWR0102
U 1 1 5C0DA997
P 4350 3100
F 0 "#PWR0102" H 4350 3100 40  0001 C CNN
F 1 "GNDA" H 4350 3167 40  0000 C CNN
F 2 "" H 4350 3100 60  0000 C CNN
F 3 "" H 4350 3100 60  0000 C CNN
	1    4350 3100
	1    0    0    -1  
$EndComp
$Comp
L vumetro:C C4
U 1 1 5C0E684C
P 4350 2800
F 0 "C4" H 4100 2850 50  0000 L CNN
F 1 "2.2nF" H 4050 2750 50  0000 L CNN
F 2 "Projecto:Capacitor_Disco" H 4350 2800 50  0001 C CNN
F 3 "~" H 4350 2800 50  0001 C CNN
	1    4350 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2550 4350 2700
Wire Wire Line
	4350 2900 4350 3100
Connection ~ 4350 2550
Wire Wire Line
	4350 2550 4000 2550
Text Label 10500 4550 0    50   ~ 0
GNDA
Wire Wire Line
	10350 4550 10500 4550
Wire Wire Line
	8850 4550 9150 4550
Text Label 8850 4550 0    50   ~ 0
VDDA
Text Label 6450 2150 0    50   ~ 0
VDDA
Wire Wire Line
	7150 4750 6600 4750
Wire Wire Line
	8350 3750 8500 3750
NoConn ~ 7150 3750
Text Label 6600 3950 0    50   ~ 0
GND
Text Label 6600 3850 0    50   ~ 0
GND
Wire Wire Line
	7150 3850 6600 3850
Wire Wire Line
	7150 3950 6600 3950
$Comp
L vumetro:Pin_Puente P1
U 1 1 5C14675C
P 4150 6150
F 0 "P1" H 4278 6196 50  0000 L CNN
F 1 "Pin_Puente" H 4278 6105 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 4150 6400 50  0001 C CNN
F 3 "" H 4150 6400 50  0001 C CNN
	1    4150 6150
	1    0    0    -1  
$EndComp
$Comp
L vumetro:Pin_Puente P3
U 1 1 5C14D1A1
P 4150 6400
F 0 "P3" H 4278 6446 50  0000 L CNN
F 1 "Pin_Puente" H 4278 6355 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 4150 6650 50  0001 C CNN
F 3 "" H 4150 6650 50  0001 C CNN
	1    4150 6400
	1    0    0    -1  
$EndComp
$Comp
L vumetro:Pin_Puente P5
U 1 1 5C15251F
P 4150 6650
F 0 "P5" H 4278 6696 50  0000 L CNN
F 1 "Pin_Puente" H 4278 6605 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 4150 6900 50  0001 C CNN
F 3 "" H 4150 6900 50  0001 C CNN
	1    4150 6650
	1    0    0    -1  
$EndComp
$Comp
L vumetro:Pin_Puente P7
U 1 1 5C157AD8
P 4150 6900
F 0 "P7" H 4278 6946 50  0000 L CNN
F 1 "Pin_Puente" H 4278 6855 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 4150 7150 50  0001 C CNN
F 3 "" H 4150 7150 50  0001 C CNN
	1    4150 6900
	1    0    0    -1  
$EndComp
$Comp
L vumetro:Pin_Puente P9
U 1 1 5C15CF23
P 4150 7150
F 0 "P9" H 4278 7196 50  0000 L CNN
F 1 "Pin_Puente" H 4278 7105 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 4150 7400 50  0001 C CNN
F 3 "" H 4150 7400 50  0001 C CNN
	1    4150 7150
	1    0    0    -1  
$EndComp
$Comp
L vumetro:Pin_Puente P10
U 1 1 5C163C16
P 5500 7150
F 0 "P10" H 5628 7196 50  0000 L CNN
F 1 "Pin_Puente" H 5628 7105 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 5500 7400 50  0001 C CNN
F 3 "" H 5500 7400 50  0001 C CNN
	1    5500 7150
	-1   0    0    1   
$EndComp
$Comp
L vumetro:Pin_Puente P8
U 1 1 5C163C1C
P 5500 6900
F 0 "P8" H 5628 6946 50  0000 L CNN
F 1 "Pin_Puente" H 5628 6855 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 5500 7150 50  0001 C CNN
F 3 "" H 5500 7150 50  0001 C CNN
	1    5500 6900
	-1   0    0    1   
$EndComp
$Comp
L vumetro:Pin_Puente P6
U 1 1 5C163C22
P 5500 6650
F 0 "P6" H 5628 6696 50  0000 L CNN
F 1 "Pin_Puente" H 5628 6605 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 5500 6900 50  0001 C CNN
F 3 "" H 5500 6900 50  0001 C CNN
	1    5500 6650
	-1   0    0    1   
$EndComp
$Comp
L vumetro:Pin_Puente P4
U 1 1 5C163C28
P 5500 6400
F 0 "P4" H 5628 6446 50  0000 L CNN
F 1 "Pin_Puente" H 5628 6355 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 5500 6650 50  0001 C CNN
F 3 "" H 5500 6650 50  0001 C CNN
	1    5500 6400
	-1   0    0    1   
$EndComp
$Comp
L vumetro:Pin_Puente P2
U 1 1 5C163C2E
P 5500 6150
F 0 "P2" H 5628 6196 50  0000 L CNN
F 1 "Pin_Puente" H 5628 6105 50  0000 L CNN
F 2 "Projecto:Pin_Puente" H 5500 6400 50  0001 C CNN
F 3 "" H 5500 6400 50  0001 C CNN
	1    5500 6150
	-1   0    0    1   
$EndComp
Text Label 3450 6150 0    50   ~ 0
COL2(U3)
Wire Wire Line
	3950 6150 3450 6150
Text Label 3450 6400 0    50   ~ 0
COL3(U3)
Wire Wire Line
	3950 6400 3450 6400
Text Label 3450 6650 0    50   ~ 0
COL5(U3)
Wire Wire Line
	3950 6650 3450 6650
Text Label 3450 6900 0    50   ~ 0
GPIO0(U3)
Wire Wire Line
	3950 6900 3450 6900
Text Label 3450 7150 0    50   ~ 0
SPI_MOSI(U3)
Wire Wire Line
	3950 7150 3450 7150
Wire Wire Line
	5700 6150 5850 6150
Wire Wire Line
	5700 6400 5850 6400
Wire Wire Line
	5700 6650 5850 6650
Wire Wire Line
	5700 6900 5850 6900
Wire Wire Line
	5700 7150 5850 7150
Text Label 5850 6150 0    50   ~ 0
COL2(U4)
Text Label 5850 6400 0    50   ~ 0
COL3(U4)
Text Label 5850 6650 0    50   ~ 0
COL5(U4)
Text Label 5850 6900 0    50   ~ 0
GPIO0(CIAA)
Text Label 5850 7150 0    50   ~ 0
SPI_MOSI(CIAA)
Text Label 3450 2050 0    50   ~ 0
VDDA
$EndSCHEMATC
