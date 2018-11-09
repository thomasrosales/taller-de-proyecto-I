/*
 * highpass.c
 *
 *  Created on: 9/11/2018
 *      Author: Tom�s
 */

#include "highpass.h"

const int highpass_taps[HIGHPASS_TAP_NUM] = { -122, 3141, -10856, 18173, -17211,
		5158, 12023, -23882, 24053, -15473, 7683, -8440, 16442, -21074, 9975,
		20419, -59017, 84621, -79862, 45440, -2648, -20708, 11856, 16044,
		-35099, 28016, -4606, -7557, -8925, 41807, -59127, 40550, 996, -30719,
		26363, -597, -12788, -4550, 34792, -42283, 12434, 30688, -48434, 28593,
		1294, -4335, -23533, 46634, -28349, -24733, 62984, -42698, -25187,
		79446, -65926, -8107, 78504, -85075, 28714, 32033, -40411, -3862, 48960,
		-47001, 2315, 36957, -32201, -5363, 29340, -9946, -33913, 56372, -35450,
		-2775, 13006, 18847, -58880, 61176, -18271, -28835, 33167, 7844, -48216,
		41123, 11297, -59110, 56541, -10248, -27732, 15769, 31858, -59080,
		28468, 35460, -67770, 30153, 45248, -83174, 39504, 51543, -106409,
		70995, 27205, -104472, 98806, -24880, -45245, 53041, -4853, -43635,
		48143, -17537, -3188, -14226, 50678, -62673, 31720, 14434, -31334, 5348,
		32304, -39768, 9886, 22389, -18828, -18807, 48647, -33247, -18466,
		57523, -44559, -8383, 48231, -34359, -19336, 57850, -40951, -15957,
		58009, -46888, -1263, 34654, -21136, -18151, 32418, 2666, -56306, 72795,
		-29802, -36106, 64212, -30170, -29422, 54198, -21275, -32660, 51098,
		-17439, -27661, 29237, 23235, -82494, 90687, -39375, -20085, 27658,
		24882, -85984, 96544, -48753, -8165, 20749, 12269, -39292, 12426, 58033,
		-109245, 87478, -3708, -73653, 83285, -29343, -24926, 22070, 32070,
		-76136, 57051, 15337, -77186, 73532, -11997, -46437, 49483, -4560,
		-32481, 16929, 39018, -79773, 63877, -6555, -36062, 24696, 23338,
		-53228, 29572, 27745, -63840, 43507, 14409, -56404, 46926, -398, -38114,
		39856, -17188, 4241, -18106, 42228, -47825, 28167, -6382, 7539, -27871,
		37999, -17242, -19886, 35915, -10968, -30998, 42334, -2337, -55195,
		71756, -24253, -46970, 73889, -27961, -47479, 75937, -24150, -60592,
		94385, -40490, -51727, 93028, -41511, -54192, 100469, -51411, -44183,
		92069, -49138, -32237, 57777, 10834, -111742, 139977, -53958, -75878,
		131708, -65059, -53009, 100365, -24233, -103895, 155041, -70634, -74904,
		145127, -78025, -51372, 106410, -26635, -108162, 153701, -48393,
		-114772, 174322, -65366, -106376, 163010, -31782, -171969, 244544,
		-94373, -149323, 245676, -81233, -198932, 312681, -111795, -249186,
		418659, -168710, -340412, 625507, -273198, -671324, 1678687, -2108538,
		1678687, -671324, -273198, 625507, -340412, -168710, 418659, -249186,
		-111795, 312681, -198932, -81233, 245676, -149323, -94373, 244544,
		-171969, -31782, 163010, -106376, -65366, 174322, -114772, -48393,
		153701, -108162, -26635, 106410, -51372, -78025, 145127, -74904, -70634,
		155041, -103895, -24233, 100365, -53009, -65059, 131708, -75878, -53958,
		139977, -111742, 10834, 57777, -32237, -49138, 92069, -44183, -51411,
		100469, -54192, -41511, 93028, -51727, -40490, 94385, -60592, -24150,
		75937, -47479, -27961, 73889, -46970, -24253, 71756, -55195, -2337,
		42334, -30998, -10968, 35915, -19886, -17242, 37999, -27871, 7539,
		-6382, 28167, -47825, 42228, -18106, 4241, -17188, 39856, -38114, -398,
		46926, -56404, 14409, 43507, -63840, 27745, 29572, -53228, 23338, 24696,
		-36062, -6555, 63877, -79773, 39018, 16929, -32481, -4560, 49483,
		-46437, -11997, 73532, -77186, 15337, 57051, -76136, 32070, 22070,
		-24926, -29343, 83285, -73653, -3708, 87478, -109245, 58033, 12426,
		-39292, 12269, 20749, -8165, -48753, 96544, -85984, 24882, 27658,
		-20085, -39375, 90687, -82494, 23235, 29237, -27661, -17439, 51098,
		-32660, -21275, 54198, -29422, -30170, 64212, -36106, -29802, 72795,
		-56306, 2666, 32418, -18151, -21136, 34654, -1263, -46888, 58009,
		-15957, -40951, 57850, -19336, -34359, 48231, -8383, -44559, 57523,
		-18466, -33247, 48647, -18807, -18828, 22389, 9886, -39768, 32304, 5348,
		-31334, 14434, 31720, -62673, 50678, -14226, -3188, -17537, 48143,
		-43635, -4853, 53041, -45245, -24880, 98806, -104472, 27205, 70995,
		-106409, 51543, 39504, -83174, 45248, 30153, -67770, 35460, 28468,
		-59080, 31858, 15769, -27732, -10248, 56541, -59110, 11297, 41123,
		-48216, 7844, 33167, -28835, -18271, 61176, -58880, 18847, 13006, -2775,
		-35450, 56372, -33913, -9946, 29340, -5363, -32201, 36957, 2315, -47001,
		48960, -3862, -40411, 32033, 28714, -85075, 78504, -8107, -65926, 79446,
		-25187, -42698, 62984, -24733, -28349, 46634, -23533, -4335, 1294,
		28593, -48434, 30688, 12434, -42283, 34792, -4550, -12788, -597, 26363,
		-30719, 996, 40550, -59127, 41807, -8925, -7557, -4606, 28016, -35099,
		16044, 11856, -20708, -2648, 45440, -79862, 84621, -59017, 20419, 9975,
		-21074, 16442, -8440, 7683, -15473, 24053, -23882, 12023, 5158, -17211,
		18173, -10856, 3141, -122 };

