/*
 * bandpass.c
 *
 *  Created on: Sep 7, 2013
 *      Author: Pablo
 */

/*

sampling frequency: 44100 Hz

fixed point precision: 16 bits

* 0 Hz - 100 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

* 160 Hz - 300 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 360 Hz - 20000 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

*/

#include "bandpass1.h"

const int bandpass_taps[BANDPASS_TAP_NUM_1] = { 25883, -26940, -26773, 33517,
		19928, -32531, -18561, 34753, 15534, -36813, -10567, 34850, 10362,
		-36064, -10831, 41988, 6486, -49880, 11238, 35030, -4131, -40025, 8210,
		43436, -19400, -34472, 18282, 33699, -20821, -31937, 23746, 28356,
		-23348, -28829, 26945, 24634, -22533, -34330, 36653, 26961, -41789,
		-19639, 43700, 12388, -40609, -13579, 48222, 1131, -38384, -9419, 49547,
		2546, -58149, 15470, 49986, -22911, -40797, 21879, 40364, -27199,
		-33986, 24689, 37177, -31786, -32136, 31388, 36725, -45444, -23594,
		44553, 17039, -42068, -14822, 40812, 16491, -46366, -12895, 51327, 5866,
		-52486, -828, 54930, -6268, -56545, 16982, 50136, -19098, -50317, 26789,
		43468, -25870, -44278, 26797, 54207, -49579, -36202, 51046, 23310,
		-43868, -21162, 38492, 27630, -44977, -28481, 55391, 20505, -60004,
		-13491, 66394, -2808, -57007, 3317, 58490, -11282, -52990, 12474, 50726,
		-11800, -53282, 12967, 60625, -23509, -62050, 36979, 53451, -40472,
		-51970, 50558, 41241, -50885, -37705, 54507, 33497, -61038, -22242,
		57414, 20170, -60180, -15027, 62456, 6623, -58006, -7710, 62540, 3589,
		-69784, 10446, 64983, -18496, -57498, 17113, 61514, -28059, -53742,
		28314, 54088, -35891, -47119, 36012, 44244, -34942, -49008, 44926,
		41667, -43362, -48892, 61528, 32285, -58989, -29279, 63155, 21505,
		-63242, -17299, 64525, 13873, -70147, -3186, 66156, 1643, -71507, 9383,
		67000, -13656, -64481, 12781, 73367, -27582, -69701, 38178, 60701,
		-40518, -57624, 42795, 59566, -53649, -55593, 65900, 42870, -71968,
		-25856, 63145, 24144, -62595, -23093, 66144, 19205, -72564, -7390,
		68239, 4563, -71153, 5393, 63527, -2258, -68987, 6158, 76426, -19821,
		-75337, 33522, 64623, -35979, -61080, 41745, 50855, -32187, -66359,
		53378, 54155, -58584, -44465, 55735, 48047, -69067, -35961, 71239,
		26383, -68564, -25294, 72838, 22453, -84271, -4463, 77970, -1008,
		-76728, 6746, 74847, -8647, -81515, 21717, 78932, -32157, -73850, 40162,
		67985, -47746, -57789, 45780, 58081, -51517, -55354, 58199, 49717,
		-63314, -42374, 62565, 45366, -76701, -32533, 80269, 21441, -80671,
		-11474, 76698, 9528, -81775, 701, 81060, -9136, -79940, 19176, 72680,
		-20246, -74240, 28364, 70952, -34319, -67643, 39929, 63237, -42934,
		-62020, 48796, 58707, -52451, -60548, 66716, 47939, -67907, -43630,
		74570, 32566, -71447, -33010, 79378, 25484, -84429, -16871, 89599, 3122,
		-87017, 7268, 78969, -3913, -89289, 19384, 85521, -29341, -78667, 31686,
		80743, -43238, -73274, 46283, 72306, -52880, -70862, 60881, 71622,
		-79638, -54304, 81911, 45704, -86957, -33119, 84261, 29952, -88040,
		-26329, 100088, 8299, -98848, 5896, 92697, -13440, -87341, 15065, 93672,
		-31356, -85461, 39161, 78418, -44243, -70336, 41432, 76992, -55513,
		-68477, 60336, 64540, -67388, -57100, 70216, 55608, -80450, -44526,
		81778, 42090, -91770, -30264, 96873, 16647, -94678, -9062, 95010, 4391,
		-103448, 15040, 95228, -19789, -97689, 36270, 86720, -39978, -81228,
		40737, 87551, -57732, -77771, 66818, 66178, -66124, -66124, 77161,
		57137, -83051, -47079, 84278, 44889, -94962, -32193, 99914, 18913,
		-99947, -8951, 103728, -9220, -92354, 11758, 91724, -16555, -95828,
		32653, 86372, -37150, -81563, 39258, 86470, -56401, -72909, 55867,
		76255, -72845, -60374, 72860, 57347, -83189, -42735, 82376, 35022,
		-82323, -28881, 81796, 28469, -92146, -14456, 91220, 6159, -91303, 2249,
		90141, -8669, -90591, 14700, 96131, -31944, -88204, 40229, 80255,
		-39940, -88541, 62287, 71245, -63246, -67271, 70172, 62002, -81900,
		-45339, 78900, 39116, -78232, -38673, 86753, 30893, -96322, -12865,
		90485, 8418, -95661, 5887, 91228, -14419, -88486, 21868, 87062, -31480,
		-86010, 48524, 67809, -46121, -61900, 42653, 66782, -53309, -61881,
		60578, 55762, -69137, -42349, 65159, 40117, -66794, -39817, 73696,
		37037, -87727, -19421, 87453, 6102, -81966, -1899, 84240, -9934, -78299,
		13352, 78170, -19320, -79850, 28984, 81472, -49992, -60685, 45881,
		56933, -48697, -52404, 51706, 46921, -52004, -47919, 62459, 35954,
		-61120, -31696, 61748, 29642, -67782, -21162, 67784, 16401, -69507,
		-13421, 78200, -2735, -72680, 9296, 69735, -15985, -65587, 18842, 65961,
		-26464, -64543, 38237, 50403, -33422, -49870, 31319, 58400, -46683,
		-51013, 53678, 44035, -62416, -28837, 57191, 24639, -58114, -16764,
		50691, 20398, -53218, -25096, 68017, 10973, -69571, -1549, 68553, -4822,
		-74986, 26343, 56718, -25623, -49713, 19318, 58087, -33671, -49181,
		35045, 45808, -39927, -41160, 42170, 37336, -47101, -32108, 51164,
		21348, -47106, -21441, 51245, 12579, -49370, -8991, 49157, -41, -39562,
		-6520, 41438, 9583, -53232, 347, 56886, -18161, -43308, 16379, 40074,
		-20466, -32584, 15198, 32672, -14432, -35080, 14400, 40211, -24930,
		-33986, 24803, 31897, -25492, -34261, 30873, 31653, -36625, -25658,
		34132, 30484, -49275, -14940, 46345, 4076, -34748, -10252, 35280, 15675,
		-49815, 849, 42232, -4921, -36641, 5151, 30950, 2160, -37640, -161,
		41569, -2228, -50395, 19717, 37481, -17227, -36424, 20197, 32319,
		-19804, -27967, 13530, 35175, -17436, -37011, 23882, 31736, -18134,
		-39087, 22856, 46516, -36904, -37554, 37785, 37559, -40083, -38431,
		46687, 37244, -49206, -41326, 64424, 31161, -62999, -33527, 73358,
		30520, -78484, -31309, 89523, 37085, -114389, -24968, 133064, 15550,
		-149545, -19926, 204430, -3712, -267495, 30955, 427896, -177258,
		-829738, 1423456, -829738, -177258, 427896, 30955, -267495, -3712,
		204430, -19926, -149545, 15550, 133064, -24968, -114389, 37085, 89523,
		-31309, -78484, 30520, 73358, -33527, -62999, 31161, 64424, -41326,
		-49206, 37244, 46687, -38431, -40083, 37559, 37785, -37554, -36904,
		46516, 22856, -39087, -18134, 31736, 23882, -37011, -17436, 35175,
		13530, -27967, -19804, 32319, 20197, -36424, -17227, 37481, 19717,
		-50395, -2228, 41569, -161, -37640, 2160, 30950, 5151, -36641, -4921,
		42232, 849, -49815, 15675, 35280, -10252, -34748, 4076, 46345, -14940,
		-49275, 30484, 34132, -25658, -36625, 31653, 30873, -34261, -25492,
		31897, 24803, -33986, -24930, 40211, 14400, -35080, -14432, 32672,
		15198, -32584, -20466, 40074, 16379, -43308, -18161, 56886, 347, -53232,
		9583, 41438, -6520, -39562, -41, 49157, -8991, -49370, 12579, 51245,
		-21441, -47106, 21348, 51164, -32108, -47101, 37336, 42170, -41160,
		-39927, 45808, 35045, -49181, -33671, 58087, 19318, -49713, -25623,
		56718, 26343, -74986, -4822, 68553, -1549, -69571, 10973, 68017, -25096,
		-53218, 20398, 50691, -16764, -58114, 24639, 57191, -28837, -62416,
		44035, 53678, -51013, -46683, 58400, 31319, -49870, -33422, 50403,
		38237, -64543, -26464, 65961, 18842, -65587, -15985, 69735, 9296,
		-72680, -2735, 78200, -13421, -69507, 16401, 67784, -21162, -67782,
		29642, 61748, -31696, -61120, 35954, 62459, -47919, -52004, 46921,
		51706, -52404, -48697, 56933, 45881, -60685, -49992, 81472, 28984,
		-79850, -19320, 78170, 13352, -78299, -9934, 84240, -1899, -81966, 6102,
		87453, -19421, -87727, 37037, 73696, -39817, -66794, 40117, 65159,
		-42349, -69137, 55762, 60578, -61881, -53309, 66782, 42653, -61900,
		-46121, 67809, 48524, -86010, -31480, 87062, 21868, -88486, -14419,
		91228, 5887, -95661, 8418, 90485, -12865, -96322, 30893, 86753, -38673,
		-78232, 39116, 78900, -45339, -81900, 62002, 70172, -67271, -63246,
		71245, 62287, -88541, -39940, 80255, 40229, -88204, -31944, 96131,
		14700, -90591, -8669, 90141, 2249, -91303, 6159, 91220, -14456, -92146,
		28469, 81796, -28881, -82323, 35022, 82376, -42735, -83189, 57347,
		72860, -60374, -72845, 76255, 55867, -72909, -56401, 86470, 39258,
		-81563, -37150, 86372, 32653, -95828, -16555, 91724, 11758, -92354,
		-9220, 103728, -8951, -99947, 18913, 99914, -32193, -94962, 44889,
		84278, -47079, -83051, 57137, 77161, -66124, -66124, 66178, 66818,
		-77771, -57732, 87551, 40737, -81228, -39978, 86720, 36270, -97689,
		-19789, 95228, 15040, -103448, 4391, 95010, -9062, -94678, 16647, 96873,
		-30264, -91770, 42090, 81778, -44526, -80450, 55608, 70216, -57100,
		-67388, 64540, 60336, -68477, -55513, 76992, 41432, -70336, -44243,
		78418, 39161, -85461, -31356, 93672, 15065, -87341, -13440, 92697, 5896,
		-98848, 8299, 100088, -26329, -88040, 29952, 84261, -33119, -86957,
		45704, 81911, -54304, -79638, 71622, 60881, -70862, -52880, 72306,
		46283, -73274, -43238, 80743, 31686, -78667, -29341, 85521, 19384,
		-89289, -3913, 78969, 7268, -87017, 3122, 89599, -16871, -84429, 25484,
		79378, -33010, -71447, 32566, 74570, -43630, -67907, 47939, 66716,
		-60548, -52451, 58707, 48796, -62020, -42934, 63237, 39929, -67643,
		-34319, 70952, 28364, -74240, -20246, 72680, 19176, -79940, -9136,
		81060, 701, -81775, 9528, 76698, -11474, -80671, 21441, 80269, -32533,
		-76701, 45366, 62565, -42374, -63314, 49717, 58199, -55354, -51517,
		58081, 45780, -57789, -47746, 67985, 40162, -73850, -32157, 78932,
		21717, -81515, -8647, 74847, 6746, -76728, -1008, 77970, -4463, -84271,
		22453, 72838, -25294, -68564, 26383, 71239, -35961, -69067, 48047,
		55735, -44465, -58584, 54155, 53378, -66359, -32187, 50855, 41745,
		-61080, -35979, 64623, 33522, -75337, -19821, 76426, 6158, -68987,
		-2258, 63527, 5393, -71153, 4563, 68239, -7390, -72564, 19205, 66144,
		-23093, -62595, 24144, 63145, -25856, -71968, 42870, 65900, -55593,
		-53649, 59566, 42795, -57624, -40518, 60701, 38178, -69701, -27582,
		73367, 12781, -64481, -13656, 67000, 9383, -71507, 1643, 66156, -3186,
		-70147, 13873, 64525, -17299, -63242, 21505, 63155, -29279, -58989,
		32285, 61528, -48892, -43362, 41667, 44926, -49008, -34942, 44244,
		36012, -47119, -35891, 54088, 28314, -53742, -28059, 61514, 17113,
		-57498, -18496, 64983, 10446, -69784, 3589, 62540, -7710, -58006, 6623,
		62456, -15027, -60180, 20170, 57414, -22242, -61038, 33497, 54507,
		-37705, -50885, 41241, 50558, -51970, -40472, 53451, 36979, -62050,
		-23509, 60625, 12967, -53282, -11800, 50726, 12474, -52990, -11282,
		58490, 3317, -57007, -2808, 66394, -13491, -60004, 20505, 55391, -28481,
		-44977, 27630, 38492, -21162, -43868, 23310, 51046, -36202, -49579,
		54207, 26797, -44278, -25870, 43468, 26789, -50317, -19098, 50136,
		16982, -56545, -6268, 54930, -828, -52486, 5866, 51327, -12895, -46366,
		16491, 40812, -14822, -42068, 17039, 44553, -23594, -45444, 36725,
		31388, -32136, -31786, 37177, 24689, -33986, -27199, 40364, 21879,
		-40797, -22911, 49986, 15470, -58149, 2546, 49547, -9419, -38384, 1131,
		48222, -13579, -40609, 12388, 43700, -19639, -41789, 26961, 36653,
		-34330, -22533, 24634, 26945, -28829, -23348, 28356, 23746, -31937,
		-20821, 33699, 18282, -34472, -19400, 43436, 8210, -40025, -4131, 35030,
		11238, -49880, 6486, 41988, -10831, -36064, 10362, 34850, -10567,
		-36813, 15534, 34753, -18561, -32531, 19928, 33517, -26773, -26940,
		25883 };
