/*
 * bandpass2.c
 *
 *  Created on: 9/11/2018
 *      Author: Tom�s
 */
/*
 sampling frequency: 44100 Hz

 fixed point precision: 16 bits

 * 0 Hz - 200 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 * 300 Hz - 600 Hz
 gain = 1
 desired ripple = 5 dB
 actual ripple = n/a

 * 700 Hz - 20000 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 */

#include "bandpass2.h"

const int bandpass_taps_2[BANDPASS_TAP_NUM_2] = {

-6074, 13868, -12336, 4277, 2779, -3701, 200, 1531, 2458, -9455, 12556, -7838,
		-895, 5121, -98, -9574, 13757, -6996, -5230, 11515, -6261, -4260, 8481,
		-1789, -8854, 12677, -6099, -4738, 11126, -9398, 1945, 6451, -11370,
		10045, -3360, -2803, 1510, 7738, -16676, 16258, -6470, -3831, 7091,
		-3838, -1172, 6027, -10713, 12153, -6029, -4669, 9502, -2935, -6543,
		7032, -407, 764, -12254, 19211, -6624, -14312, 16654, 5220, -22522,
		8791, 21299, -26797, -3942, 33930, -24105, -13352, 31156, -10752,
		-12994, 3460, 24752, -26305, -7344, 33390, -17175, -17136, 21433, 7532,
		-23737, 1860, 23914, -9642, -29140, 36273, 3074, -34648, 10957, 37772,
		-41059, -10535, 47717, -16458, -43489, 51822, 1712, -42142, 14852,
		39450, -43433, -6279, 36945, -5072, -40696, 31599, 21890, -45215, 8760,
		30594, -13792, -32236, 34673, 16185, -48155, 11207, 46862, -44482,
		-17211, 53943, -16021, -41711, 38266, 19399, -48443, 9633, 38598,
		-27442, -22122, 31922, 16714, -54021, 23699, 32569, -33644, -23039,
		55055, -12972, -47354, 42886, 17690, -46542, 2619, 48311, -28131,
		-40521, 63280, -6679, -55218, 43813, 16273, -37415, -5945, 44603,
		-19079, -34860, 40048, 7821, -35101, -1535, 49774, -37687, -21481,
		45517, -904, -49814, 36060, 20735, -40566, -1269, 40609, -20513, -27134,
		28807, 21055, -51309, 15607, 38811, -38236, -14416, 43758, -10188,
		-36872, 30682, 16947, -36404, 551, 36556, -20330, -26954, 38472, 18,
		-32880, 15301, 22569, -23337, -14153, 33426, -4744, -32524, 26634,
		11543, -27284, 2063, 20223, -896, -34873, 32845, 10344, -40239, 19762,
		19776, -24532, -7285, 27523, -9822, -14795, 8015, 17966, -19638, -10239,
		30032, -9369, -24124, 23993, 8673, -24919, -1289, 36230, -32110, -5435,
		27546, -8659, -19944, 18714, 7582, -20512, 6502, 9097, -2096, -13622,
		11978, 5906, -13272, 2091, 6092, 6288, -20973, 11366, 16767, -27803,
		8174, 14162, -6693, -20273, 30496, -11974, -6584, 1298, 13936, -9901,
		-10154, 16376, 1833, -15570, 519, 24694, -21468, -9761, 27118, -4851,
		-26221, 21304, 15649, -34874, 11598, 20510, -16881, -13563, 24359, 732,
		-23440, 9824, 19488, -18781, -12104, 25842, 3991, -39643, 31309, 12401,
		-34113, 9275, 21569, -12700, -18827, 20967, 13793, -32829, 1426, 41683,
		-34010, -20365, 52712, -23384, -22835, 20825, 22885, -41260, 4878,
		34674, -20094, -27807, 38658, 4691, -41074, 18521, 28349, -28891,
		-21099, 49155, -11564, -42699, 37400, 20088, -49212, 7094, 48651,
		-43904, -10371, 33735, 4339, -44199, 21723, 33517, -42130, -12624,
		54373, -22999, -42909, 55953, -3631, -40608, 19612, 27647, -31299,
		-9591, 27107, 8264, -44034, 21356, 31910, -39590, -13851, 54045, -21939,
		-42140, 50560, 8114, -54251, 26778, 32707, -42551, -4804, 36126, -6214,
		-38387, 29433, 22381, -42950, 2721, 40698, -25769, -24053, 35937, 6638,
		-39756, 13470, 35524, -35953, -13766, 43431, -11298, -34935, 27697,
		24116, -47415, 10601, 33089, -22767, -22159, 33113, 7009, -37867, 10779,
		39566, -42865, -5532, 38410, -11914, -32411, 29664, 15508, -36321, 2203,
		37827, -25533, -21839, 38356, -3409, -29372, 13423, 24360, -23221,
		-18625, 41315, -8259, -37056, 34376, 10128, -30869, 176, 36179, -23404,
		-19827, 33654, -1063, -25164, 6491, 27521, -19661, -22421, 37777, 3300,
		-46177, 30637, 27156, -48581, 5546, 45714, -38134, -10286, 31407, -748,
		-27395, 8138, 30776, -27953, -14526, 34697, 549, -40513, 23775, 32770,
		-52286, 7184, 40816, -26505, -27580, 43942, -2548, -33727, 10395, 35303,
		-31703, -23803, 52815, -12246, -45776, 40095, 18100, -46155, 1011,
		51896, -38779, -24518, 47839, -4028, -41019, 17141, 38832, -44585,
		-14848, 54756, -21257, -37477, 33125, 24228, -46317, -9225, 63313,
		-33551, -46998, 63448, 10144, -70441, 24136, 68526, -74268, -25232,
		95605, -36611, -71712, 76090, 30464, -90599, 9518, 100314, -69819,
		-69019, 112659, 26361, -158853, 72189, 148661, -182583, -74396, 301425,
		-120326, -333118, 444537, 194537, -1194925, 1682275, -1194925, 194537,
		444537, -333118, -120326, 301425, -74396, -182583, 148661, 72189,
		-158853, 26361, 112659, -69019, -69819, 100314, 9518, -90599, 30464,
		76090, -71712, -36611, 95605, -25232, -74268, 68526, 24136, -70441,
		10144, 63448, -46998, -33551, 63313, -9225, -46317, 24228, 33125,
		-37477, -21257, 54756, -14848, -44585, 38832, 17141, -41019, -4028,
		47839, -24518, -38779, 51896, 1011, -46155, 18100, 40095, -45776,
		-12246, 52815, -23803, -31703, 35303, 10395, -33727, -2548, 43942,
		-27580, -26505, 40816, 7184, -52286, 32770, 23775, -40513, 549, 34697,
		-14526, -27953, 30776, 8138, -27395, -748, 31407, -10286, -38134, 45714,
		5546, -48581, 27156, 30637, -46177, 3300, 37777, -22421, -19661, 27521,
		6491, -25164, -1063, 33654, -19827, -23404, 36179, 176, -30869, 10128,
		34376, -37056, -8259, 41315, -18625, -23221, 24360, 13423, -29372,
		-3409, 38356, -21839, -25533, 37827, 2203, -36321, 15508, 29664, -32411,
		-11914, 38410, -5532, -42865, 39566, 10779, -37867, 7009, 33113, -22159,
		-22767, 33089, 10601, -47415, 24116, 27697, -34935, -11298, 43431,
		-13766, -35953, 35524, 13470, -39756, 6638, 35937, -24053, -25769,
		40698, 2721, -42950, 22381, 29433, -38387, -6214, 36126, -4804, -42551,
		32707, 26778, -54251, 8114, 50560, -42140, -21939, 54045, -13851,
		-39590, 31910, 21356, -44034, 8264, 27107, -9591, -31299, 27647, 19612,
		-40608, -3631, 55953, -42909, -22999, 54373, -12624, -42130, 33517,
		21723, -44199, 4339, 33735, -10371, -43904, 48651, 7094, -49212, 20088,
		37400, -42699, -11564, 49155, -21099, -28891, 28349, 18521, -41074,
		4691, 38658, -27807, -20094, 34674, 4878, -41260, 22885, 20825, -22835,
		-23384, 52712, -20365, -34010, 41683, 1426, -32829, 13793, 20967,
		-18827, -12700, 21569, 9275, -34113, 12401, 31309, -39643, 3991, 25842,
		-12104, -18781, 19488, 9824, -23440, 732, 24359, -13563, -16881, 20510,
		11598, -34874, 15649, 21304, -26221, -4851, 27118, -9761, -21468, 24694,
		519, -15570, 1833, 16376, -10154, -9901, 13936, 1298, -6584, -11974,
		30496, -20273, -6693, 14162, 8174, -27803, 16767, 11366, -20973, 6288,
		6092, 2091, -13272, 5906, 11978, -13622, -2096, 9097, 6502, -20512,
		7582, 18714, -19944, -8659, 27546, -5435, -32110, 36230, -1289, -24919,
		8673, 23993, -24124, -9369, 30032, -10239, -19638, 17966, 8015, -14795,
		-9822, 27523, -7285, -24532, 19776, 19762, -40239, 10344, 32845, -34873,
		-896, 20223, 2063, -27284, 11543, 26634, -32524, -4744, 33426, -14153,
		-23337, 22569, 15301, -32880, 18, 38472, -26954, -20330, 36556, 551,
		-36404, 16947, 30682, -36872, -10188, 43758, -14416, -38236, 38811,
		15607, -51309, 21055, 28807, -27134, -20513, 40609, -1269, -40566,
		20735, 36060, -49814, -904, 45517, -21481, -37687, 49774, -1535, -35101,
		7821, 40048, -34860, -19079, 44603, -5945, -37415, 16273, 43813, -55218,
		-6679, 63280, -40521, -28131, 48311, 2619, -46542, 17690, 42886, -47354,
		-12972, 55055, -23039, -33644, 32569, 23699, -54021, 16714, 31922,
		-22122, -27442, 38598, 9633, -48443, 19399, 38266, -41711, -16021,
		53943, -17211, -44482, 46862, 11207, -48155, 16185, 34673, -32236,
		-13792, 30594, 8760, -45215, 21890, 31599, -40696, -5072, 36945, -6279,
		-43433, 39450, 14852, -42142, 1712, 51822, -43489, -16458, 47717,
		-10535, -41059, 37772, 10957, -34648, 3074, 36273, -29140, -9642, 23914,
		1860, -23737, 7532, 21433, -17136, -17175, 33390, -7344, -26305, 24752,
		3460, -12994, -10752, 31156, -13352, -24105, 33930, -3942, -26797,
		21299, 8791, -22522, 5220, 16654, -14312, -6624, 19211, -12254, 764,
		-407, 7032, -6543, -2935, 9502, -4669, -6029, 12153, -10713, 6027,
		-1172, -3838, 7091, -3831, -6470, 16258, -16676, 7738, 1510, -2803,
		-3360, 10045, -11370, 6451, 1945, -9398, 11126, -4738, -6099, 12677,
		-8854, -1789, 8481, -4260, -6261, 11515, -5230, -6996, 13757, -9574,
		-98, 5121, -895, -7838, 12556, -9455, 2458, 1531, 200, -3701, 2779,
		4277, -12336, 13868, -6074 };