#include "MiroCamera.h"

const int MiroCamera::MIRO_LinLUT[1024] = {
  2, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 17, 18,
  19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 33,
  34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 48,
  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 63,
  64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94,
  94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
  110, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124,
  125, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 137, 138,
  139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154,
  156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 167, 168, 169, 170, 171, 172,
  173, 175, 176, 177, 178, 179, 181, 182, 183, 184, 186, 187, 188, 189, 191, 192,
  193, 194, 196, 197, 198, 200, 201, 202, 204, 205, 206, 208, 209, 210, 212, 213,
  215, 216, 217, 219, 220, 222, 223, 225, 226, 227, 229, 230, 232, 233, 235, 236,
  238, 239, 241, 242, 244, 245, 247, 249, 250, 252, 253, 255, 257, 258, 260, 261,
  263, 265, 266, 268, 270, 271, 273, 275, 276, 278, 280, 281, 283, 285, 287, 288,
  290, 292, 294, 295, 297, 299, 301, 302, 304, 306, 308, 310, 312, 313, 315, 317,
  319, 321, 323, 325, 327, 328, 330, 332, 334, 336, 338, 340, 342, 344, 346, 348,
  350, 352, 354, 356, 358, 360, 362, 364, 366, 368, 370, 372, 374, 377, 379, 381,
  383, 385, 387, 389, 391, 394, 396, 398, 400, 402, 404, 407, 409, 411, 413, 416,
  418, 420, 422, 425, 427, 429, 431, 434, 436, 438, 441, 443, 445, 448, 450, 452,
  455, 457, 459, 462, 464, 467, 469, 472, 474, 476, 479, 481, 484, 486, 489, 491,
  494, 496, 499, 501, 504, 506, 509, 511, 514, 517, 519, 522, 524, 527, 529, 532,
  535, 537, 540, 543, 545, 548, 551, 553, 556, 559, 561, 564, 567, 570, 572, 575,
  578, 581, 583, 586, 589, 592, 594, 597, 600, 603, 606, 609, 611, 614, 617, 620,
  623, 626, 629, 632, 635, 637, 640, 643, 646, 649, 652, 655, 658, 661, 664, 667,
  670, 673, 676, 679, 682, 685, 688, 691, 694, 698, 701, 704, 707, 710, 713, 716,
  719, 722, 726, 729, 732, 735, 738, 742, 745, 748, 751, 754, 758, 761, 764, 767,
  771, 774, 777, 781, 784, 787, 790, 794, 797, 800, 804, 807, 811, 814, 817, 821,
  824, 828, 831, 834, 838, 841, 845, 848, 852, 855, 859, 862, 866, 869, 873, 876,
  880, 883, 887, 890, 894, 898, 901, 905, 908, 912, 916, 919, 923, 927, 930, 934,
  938, 941, 945, 949, 952, 956, 960, 964, 967, 971, 975, 979, 982, 986, 990, 994,
  998,1001,1005,1009,1013,1017,1021,1025,1028,1032,1036,1040,1044,1048,1052,1056,
  1060,1064,1068,1072,1076,1080,1084,1088,1092,1096,1100,1104,1108,1112,1116,1120,
  1124,1128,1132,1137,1141,1145,1149,1153,1157,1162,1166,1170,1174,1178,1183,1187,
  1191,1195,1200,1204,1208,1212,1217,1221,1225,1230,1234,1238,1243,1247,1251,1256,
  1260,1264,1269,1273,1278,1282,1287,1291,1295,1300,1304,1309,1313,1318,1322,1327,
  1331,1336,1340,1345,1350,1354,1359,1363,1368,1372,1377,1382,1386,1391,1396,1400,
  1405,1410,1414,1419,1424,1428,1433,1438,1443,1447,1452,1457,1462,1466,1471,1476,
  1481,1486,1490,1495,1500,1505,1510,1515,1520,1524,1529,1534,1539,1544,1549,1554,
  1559,1564,1569,1574,1579,1584,1589,1594,1599,1604,1609,1614,1619,1624,1629,1634,
  1639,1644,1649,1655,1660,1665,1670,1675,1680,1685,1691,1696,1701,1706,1711,1717,
  1722,1727,1732,1738,1743,1748,1753,1759,1764,1769,1775,1780,1785,1791,1796,1801,
  1807,1812,1818,1823,1828,1834,1839,1845,1850,1856,1861,1867,1872,1878,1883,1889,
  1894,1900,1905,1911,1916,1922,1927,1933,1939,1944,1950,1956,1961,1967,1972,1978,
  1984,1989,1995,2001,2007,2012,2018,2024,2030,2035,2041,2047,2053,2058,2064,2070,
  2076,2082,2087,2093,2099,2105,2111,2117,2123,2129,2135,2140,2146,2152,2158,2164,
  2170,2176,2182,2188,2194,2200,2206,2212,2218,2224,2231,2237,2243,2249,2255,2261,
  2267,2273,2279,2286,2292,2298,2304,2310,2317,2323,2329,2335,2341,2348,2354,2360,
  2366,2373,2379,2385,2392,2398,2404,2411,2417,2423,2430,2436,2443,2449,2455,2462,
  2468,2475,2481,2488,2494,2501,2507,2514,2520,2527,2533,2540,2546,2553,2559,2566,
  2572,2579,2586,2592,2599,2605,2612,2619,2625,2632,2639,2645,2652,2659,2666,2672,
  2679,2686,2693,2699,2706,2713,2720,2726,2733,2740,2747,2754,2761,2767,2774,2781,
  2788,2795,2802,2809,2816,2823,2830,2837,2844,2850,2857,2864,2871,2878,2885,2893,
  2900,2907,2914,2921,2928,2935,2942,2949,2956,2963,2970,2978,2985,2992,2999,3006,
  3013,3021,3028,3035,3042,3049,3057,3064,3071,3078,3086,3093,3100,3108,3115,3122,
  3130,3137,3144,3152,3159,3166,3174,3181,3189,3196,3204,3211,3218,3226,3233,3241,
  3248,3256,3263,3271,3278,3286,3294,3301,3309,3316,3324,3331,3339,3347,3354,3362,
  3370,3377,3385,3393,3400,3408,3416,3423,3431,3439,3447,3454,3462,3470,3478,3486,
  3493,3501,3509,3517,3525,3533,3540,3548,3556,3564,3572,3580,3588,3596,3604,3612,
  3620,3628,3636,3644,3652,3660,3668,3676,3684,3692,3700,3708,3716,3724,3732,3740,
  3749,3757,3765,3773,3781,3789,3798,3806,3814,3822,3830,3839,3847,3855,3863,3872,
  3880,3888,3897,3905,3913,3922,3930,3938,3947,3955,3963,3972,3980,3989,3997,4006,
  4014,4022,4031,4039,4048,4056,4064,4095,4095,4095,4095,4095,4095,4095,4095,4095
};

const char *MiroCamera::MIRO_CnNameString[] = {
    "MIRO_C0_NAME",
    "MIRO_C1_NAME",
    "MIRO_C2_NAME",
    "MIRO_C3_NAME",
    "MIRO_C4_NAME",
    "MIRO_C5_NAME",
    "MIRO_C6_NAME",
    "MIRO_C7_NAME",
    "MIRO_C8_NAME",
    "MIRO_C9_NAME",
    "MIRO_C10_NAME",
    "MIRO_C11_NAME",
    "MIRO_C12_NAME",
    "MIRO_C13_NAME",
    "MIRO_C14_NAME",
    "MIRO_C15_NAME",
    "MIRO_C16_NAME"
};

const char *MiroCamera::MIRO_CnWidthString[] = {
    "MIRO_C0_WIDTH",
    "MIRO_C1_WIDTH",
    "MIRO_C2_WIDTH",
    "MIRO_C3_WIDTH",
    "MIRO_C4_WIDTH",
    "MIRO_C5_WIDTH",
    "MIRO_C6_WIDTH",
    "MIRO_C7_WIDTH",
    "MIRO_C8_WIDTH",
    "MIRO_C9_WIDTH",
    "MIRO_C10_WIDTH",
    "MIRO_C11_WIDTH",
    "MIRO_C12_WIDTH",
    "MIRO_C13_WIDTH",
    "MIRO_C14_WIDTH",
    "MIRO_C15_WIDTH",
    "MIRO_C16_WIDTH"
};

const char *MiroCamera::MIRO_CnHeightString[] = {
    "MIRO_C0_HEIGHT",
    "MIRO_C1_HEIGHT",
    "MIRO_C2_HEIGHT",
    "MIRO_C3_HEIGHT",
    "MIRO_C4_HEIGHT",
    "MIRO_C5_HEIGHT",
    "MIRO_C6_HEIGHT",
    "MIRO_C7_HEIGHT",
    "MIRO_C8_HEIGHT",
    "MIRO_C9_HEIGHT",
    "MIRO_C10_HEIGHT",
    "MIRO_C11_HEIGHT",
    "MIRO_C12_HEIGHT",
    "MIRO_C13_HEIGHT",
    "MIRO_C14_HEIGHT",
    "MIRO_C15_HEIGHT",
    "MIRO_C16_HEIGHT"
};

const char *MiroCamera::MIRO_CnStatusString[] = {
    "MIRO_C0_STATUS",
    "MIRO_C1_STATUS",
    "MIRO_C2_STATUS",
    "MIRO_C3_STATUS",
    "MIRO_C4_STATUS",
    "MIRO_C5_STATUS",
    "MIRO_C6_STATUS",
    "MIRO_C7_STATUS",
    "MIRO_C8_STATUS",
    "MIRO_C9_STATUS",
    "MIRO_C10_STATUS",
    "MIRO_C11_STATUS",
    "MIRO_C12_STATUS",
    "MIRO_C13_STATUS",
    "MIRO_C14_STATUS",
    "MIRO_C15_STATUS",
    "MIRO_C16_STATUS"
};

const char *MiroCamera::MIRO_CnFrameCountString[] = {
    "MIRO_C0_FR_COUNT",
    "MIRO_C1_FR_COUNT",
    "MIRO_C2_FR_COUNT",
    "MIRO_C3_FR_COUNT",
    "MIRO_C4_FR_COUNT",
    "MIRO_C5_FR_COUNT",
    "MIRO_C6_FR_COUNT",
    "MIRO_C7_FR_COUNT",
    "MIRO_C8_FR_COUNT",
    "MIRO_C9_FR_COUNT",
    "MIRO_C10_FR_COUNT",
    "MIRO_C11_FR_COUNT",
    "MIRO_C12_FR_COUNT",
    "MIRO_C13_FR_COUNT",
    "MIRO_C14_FR_COUNT",
    "MIRO_C15_FR_COUNT",
    "MIRO_C16_FR_COUNT"
};

const char *MiroCamera::MIRO_CnFirstFrameString[] = {
    "MIRO_C0_FIRST_FR",
    "MIRO_C1_FIRST_FR",
    "MIRO_C2_FIRST_FR",
    "MIRO_C3_FIRST_FR",
    "MIRO_C4_FIRST_FR",
    "MIRO_C5_FIRST_FR",
    "MIRO_C6_FIRST_FR",
    "MIRO_C7_FIRST_FR",
    "MIRO_C8_FIRST_FR",
    "MIRO_C9_FIRST_FR",
    "MIRO_C10_FIRST_FR",
    "MIRO_C11_FIRST_FR",
    "MIRO_C12_FIRST_FR",
    "MIRO_C13_FIRST_FR",
    "MIRO_C14_FIRST_FR",
    "MIRO_C15_FIRST_FR",
    "MIRO_C16_FIRST_FR"
};

const char *MiroCamera::MIRO_CnLastFrameString[] = {
    "MIRO_C0_LAST_FR",
    "MIRO_C1_LAST_FR",
    "MIRO_C2_LAST_FR",
    "MIRO_C3_LAST_FR",
    "MIRO_C4_LAST_FR",
    "MIRO_C5_LAST_FR",
    "MIRO_C6_LAST_FR",
    "MIRO_C7_LAST_FR",
    "MIRO_C8_LAST_FR",
    "MIRO_C9_LAST_FR",
    "MIRO_C10_LAST_FR",
    "MIRO_C11_LAST_FR",
    "MIRO_C12_LAST_FR",
    "MIRO_C13_LAST_FR",
    "MIRO_C14_LAST_FR",
    "MIRO_C15_LAST_FR",
    "MIRO_C16_LAST_FR"
};

const char *MiroCamera::MIRO_CnRecordStartString[] = {
    "MIRO_C0_REC_START",
    "MIRO_C1_REC_START",
    "MIRO_C2_REC_START",
    "MIRO_C3_REC_START",
    "MIRO_C4_REC_START",
    "MIRO_C5_REC_START",
    "MIRO_C6_REC_START",
    "MIRO_C7_REC_START",
    "MIRO_C8_REC_START",
    "MIRO_C9_REC_START",
    "MIRO_C10_REC_START",
    "MIRO_C11_REC_START",
    "MIRO_C12_REC_START",
    "MIRO_C13_REC_START",
    "MIRO_C14_REC_START",
    "MIRO_C15_REC_START",
    "MIRO_C16_REC_START"
};

const char *MiroCamera::MIRO_CnRecordEndString[] = {
    "MIRO_C0_REC_END",
    "MIRO_C1_REC_END",
    "MIRO_C2_REC_END",
    "MIRO_C3_REC_END",
    "MIRO_C4_REC_END",
    "MIRO_C5_REC_END",
    "MIRO_C6_REC_END",
    "MIRO_C7_REC_END",
    "MIRO_C8_REC_END",
    "MIRO_C9_REC_END",
    "MIRO_C10_REC_END",
    "MIRO_C11_REC_END",
    "MIRO_C12_REC_END",
    "MIRO_C13_REC_END",
    "MIRO_C14_REC_END",
    "MIRO_C15_REC_END",
    "MIRO_C16_REC_END"
};

const char *MiroCamera::MIRO_CnRecordString[] = {
    "MIRO_C0_RECORD",
    "MIRO_C1_RECORD",
    "MIRO_C2_RECORD",
    "MIRO_C3_RECORD",
    "MIRO_C4_RECORD",
    "MIRO_C5_RECORD",
    "MIRO_C6_RECORD",
    "MIRO_C7_RECORD",
    "MIRO_C8_RECORD",
    "MIRO_C9_RECORD",
    "MIRO_C10_RECORD",
    "MIRO_C11_RECORD",
    "MIRO_C12_RECORD",
    "MIRO_C13_RECORD",
    "MIRO_C14_RECORD",
    "MIRO_C15_RECORD",
    "MIRO_C16_RECORD"
};

const char *MiroCamera::MIRO_CnRecordCountString[] = {
    "MIRO_C0_REC_COUNT",
    "MIRO_C1_REC_COUNT",
    "MIRO_C2_REC_COUNT",
    "MIRO_C3_REC_COUNT",
    "MIRO_C4_REC_COUNT",
    "MIRO_C5_REC_COUNT",
    "MIRO_C6_REC_COUNT",
    "MIRO_C7_REC_COUNT",
    "MIRO_C8_REC_COUNT",
    "MIRO_C9_REC_COUNT",
    "MIRO_C10_REC_COUNT",
    "MIRO_C11_REC_COUNT",
    "MIRO_C12_REC_COUNT",
    "MIRO_C13_REC_COUNT",
    "MIRO_C14_REC_COUNT",
    "MIRO_C15_REC_COUNT",
    "MIRO_C16_REC_COUNT"
};

const char *MiroCamera::MIRO_CfFileNameString[] = {
    "MIRO_CF1_FILE_NAME",
    "MIRO_CF2_FILE_NAME",
    "MIRO_CF3_FILE_NAME",
    "MIRO_CF4_FILE_NAME",
    "MIRO_CF5_FILE_NAME",
    "MIRO_CF6_FILE_NAME",
    "MIRO_CF7_FILE_NAME",
    "MIRO_CF8_FILE_NAME"
};

const char *MiroCamera::MIRO_CfFileSizeString[] = {
    "MIRO_CF1_FILE_SIZE",
    "MIRO_CF2_FILE_SIZE",
    "MIRO_CF3_FILE_SIZE",
    "MIRO_CF4_FILE_SIZE",
    "MIRO_CF5_FILE_SIZE",
    "MIRO_CF6_FILE_SIZE",
    "MIRO_CF7_FILE_SIZE",
    "MIRO_CF8_FILE_SIZE"
};

const char *MiroCamera::MIRO_CfFileDateString[] = {
    "MIRO_CF1_FILE_DATE",
    "MIRO_CF2_FILE_DATE",
    "MIRO_CF3_FILE_DATE",
    "MIRO_CF4_FILE_DATE",
    "MIRO_CF5_FILE_DATE",
    "MIRO_CF6_FILE_DATE",
    "MIRO_CF7_FILE_DATE",
    "MIRO_CF8_FILE_DATE"
};

/**
 * A bit of C glue to make the config function available in the startup script (ioc shell) 
 */
extern "C"
{
  int miroCameraConfig(const char *portName, const char *ctrlPort, const char *dataPort, int maxBuffers, size_t maxMemory, int priority,	int stackSize)
  {
    new MiroCamera(portName, ctrlPort, dataPort, maxBuffers, maxMemory, priority, stackSize);
    return asynSuccess;
  }

  int miroSetDebugLevel(const char *driver, const char *method, int debug)
  {
    MiroCamera *sA;
    static const char *functionName = "miroSetDebugLevel";

    sA = (MiroCamera*)findAsynPortDriver(driver);
    if (!sA){
      printf("%s: Error: port %s not found.", functionName, driver);
      return -1;
    }
    return sA->debugLevel(method, debug);
  }
}

/**
 * Function to run the camera task within a separate thread in C++
 */
static void miroCameraTaskC(void *drvPvt)
{
  MiroCamera *pPvt = (MiroCamera *)drvPvt;
  pPvt->miroCameraTask();
}

/**
 * Function to run the status task within a separate thread in C++
 */
static void miroStatusTaskC(void *drvPvt)
{
  MiroCamera *pPvt = (MiroCamera *)drvPvt;
  pPvt->miroStatusTask();
}

/**
 * Function to run the camera task within a separate thread in C++
 */
static void miroPreviewTaskC(void *drvPvt)
{
  MiroCamera *pPvt = (MiroCamera *)drvPvt;
  pPvt->miroPreviewTask();
}

/**
 * Function to run the flash delete and format task within a separate thread in C++
 */
static void miroFlashTaskC(void *drvPvt)
{
  MiroCamera *pPvt = (MiroCamera *)drvPvt;
  pPvt->miroFlashTask();
}

/**
 * miroCamera destructor
 */
MiroCamera::~MiroCamera()
{
}

MiroCamera::MiroCamera(const char *portName, const char *ctrlPort, const char *dataPort, int maxBuffers, size_t maxMemory, int priority, int stackSize) :
/** 
    Constructor for the ADDriver class. 
[in]	portNameIn	The name of the asyn port.
[in]	maxAddr 	The maximum number of asyn addr addresses this driver supports. Often 
                        it is 1 (which is the minimum). This controls the number of parameter tables that are 
                        created.
[in]	numParams	The number of parameters that this driver supports.
[in]	maxBuffers	The maximum number of NDArray buffers that the NDArrayPool for this driver is allowed to 
                        allocate. Set this to 0 to allow an unlimited number of buffers.
[in]	maxMemory	The maximum amount of memory that the NDArrayPool for this driver is allowed to allocate. 
                        Set this to 0 to allow an unlimited amount of memory. 
[in]	interfaceMask	Bit mask defining the asyn interfaces that this driver supports. The bit mask values are 
                        defined in asynPortDriver.h, e.g. asynInt32Mask.
[in]	interruptMask	Bit mask definining the asyn interfaces that can generate interrupts (callbacks). The bit 
                        mask values are defined in asynPortDriver.h, e.g. asynInt8ArrayMask.
[in]	asynFlags	Flags when creating the asyn port driver; includes ASYN_CANBLOCK and ASYN_MULTIDEVICE.
[in]	autoConnect	The autoConnect flag for the asyn port driver. 1 if the driver should autoconnect.
[in]	priority	The thread priority for the asyn port driver thread if ASYN_CANBLOCK is set in asynFlags. 
                        If it is 0 then the default value of epicsThreadPriorityMedium will be assigned by 
                        asynManager.
[in]	stackSize	The stack size for the asyn port driver thread if ASYN_CANBLOCK is set in asynFlags. If it 
                        is 0 then the default value of epicsThreadGetStackSize(epicsThreadStackMedium) will be  
                        assigned by asynManager. 
*/
  ADDriver(portName,
           1,
           NUM_MIRO_PARAMS,
           maxBuffers,
           maxMemory,
           asynEnumMask | asynFloat64ArrayMask,
           asynEnumMask | asynFloat64ArrayMask, /* No interfaces beyond those set in ADDriver.cpp */
           ASYN_CANBLOCK,
           1, //asynflags (CANBLOCK means separate thread for this driver)
           priority,
           stackSize) // thread priority and stack size (0=default)
{
  static const char *functionName = "MiroCamera::MiroCamera";
  int status = asynSuccess;
  int index = 0;

  // Setup flag to state this is our first connection
  firstConnect_ = true;

  // Initialise the debugger
  initDebugger(0);

  //Initialize non static data members
  portUser_  = NULL;
  dataChannel_ = NULL;
  strcpy(ctrlPort_, ctrlPort);
  strcpy(dataPort_, dataPort);
  
  // Create the epicsEvents for signalling to the MIRO task when acquisition starts
  this->startEventId_ = epicsEventCreate(epicsEventEmpty);
  if (!this->startEventId_){
    debug(functionName, "epicsEventCreate failure for start event");
    status = asynError;
  }

  // Create the epicsEvents for signalling to the MIRO Analyser task when acquisition stops
  this->stopEventId_ = epicsEventCreate(epicsEventEmpty);
  if (!this->stopEventId_){
    debug(functionName, "epicsEventCreate failure for stop event");
    status = asynError;
  }

  // Create the epicsEvents for signalling to the MIRO task when acquisition starts
  this->startPreviewEventId_ = epicsEventCreate(epicsEventEmpty);
  if (!this->startPreviewEventId_){
    debug(functionName, "epicsEventCreate failure for start preview event");
    status = asynError;
  }

  // Create the epicsEvents for signalling to the MIRO Analyser task when acquisition stops
  this->stopPreviewEventId_ = epicsEventCreate(epicsEventEmpty);
  if (!this->stopPreviewEventId_){
    debug(functionName, "epicsEventCreate failure for stop preview event");
    status = asynError;
  }

  // Create the epicsEvents for signalling to the MIRO flash task when format or file delete occurs
  this->flashEventId_ = epicsEventCreate(epicsEventEmpty);
  if (!this->flashEventId_){
    debug(functionName, "epicsEventCreate failure to create flash event");
    status = asynError;
  }

  // Create all MIRO parameters
  createParam(MIROConnectString,                   asynParamInt32,         &MIROConnect_);
  createParam(MIROConnectedString,                 asynParamInt32,         &MIROConnected_);
  createParam(MIRO_AcquireStateString,             asynParamInt32,         &MIRO_AcquireState_);
  createParam(MIRO_SoftwareTriggerString,          asynParamInt32,         &MIRO_SoftwareTrigger_);
  createParam(MIRO_PerformCSRString,               asynParamInt32,         &MIRO_PerformCSR_);
  createParam(MIRO_CSRCountString,                 asynParamInt32,         &MIRO_CSRCount_);
  createParam(MIRO_SettingsSlotString,             asynParamInt32,         &MIRO_SettingsSlot_);
  createParam(MIRO_SettingsSaveString,             asynParamInt32,         &MIRO_SettingsSave_);
  createParam(MIRO_SettingsLoadString,             asynParamInt32,         &MIRO_SettingsLoad_);
  createParam(MIRO_AutoSaveString,                 asynParamInt32,         &MIRO_AutoSave_);
  createParam(MIRO_AutoRestartString,              asynParamInt32,         &MIRO_AutoRestart_);
  createParam(MIRO_AutoCSRString,                  asynParamInt32,         &MIRO_AutoCSR_);
  createParam(MIRO_PostTrigCountString,            asynParamInt32,         &MIRO_PostTrigCount_);
  createParam(MIRO_TotalFrameCountString,          asynParamInt32,         &MIRO_TotalFrameCount_);
  createParam(MIRO_MaxFrameCountString,            asynParamInt32,         &MIRO_MaxFrameCount_);
  createParam(MIRO_SelectedCineString,             asynParamInt32,         &MIRO_SelectedCine_);
  createParam(MIRO_CineNameString,                 asynParamOctet,         &MIRO_CineName_);
  createParam(MIRO_CineWidthString,                asynParamInt32,         &MIRO_CineWidth_);
  createParam(MIRO_CineHeightString,               asynParamInt32,         &MIRO_CineHeight_);
  createParam(MIRO_CineFrameCountString,           asynParamInt32,         &MIRO_CineFrameCount_);
  createParam(MIRO_CineFirstFrameString,           asynParamInt32,         &MIRO_CineFirstFrame_);
  createParam(MIRO_CineLastFrameString,            asynParamInt32,         &MIRO_CineLastFrame_);
  createParam(MIRO_CineRecordStartString,          asynParamInt32,         &MIRO_CineRecordStart_);
  createParam(MIRO_CineRecordEndString,            asynParamInt32,         &MIRO_CineRecordEnd_);
  createParam(MIRO_CineRecordString,               asynParamInt32,         &MIRO_CineRecord_);
  createParam(MIRO_CineRecordCountString,          asynParamInt32,         &MIRO_CineRecordCount_);
  createParam(MIRO_CineSaveCFString,               asynParamInt32,         &MIRO_CineSaveCF_);
  createParam(MIRO_LivePreviewString,              asynParamInt32,         &MIRO_LivePreview_);
  createParam(MIRO_SetPartitionString,             asynParamInt32,         &MIRO_SetPartition_);
  createParam(MIRO_GetCineCountString,             asynParamInt32,         &MIRO_GetCineCount_);
  createParam(MIRO_CFStateString,                  asynParamInt32,         &MIRO_CFState_);
  createParam(MIRO_CFActionString,                 asynParamInt32,         &MIRO_CFAction_);
  createParam(MIRO_CFSizeString,                   asynParamInt32,         &MIRO_CFSize_);
  createParam(MIRO_CFUsedString,                   asynParamInt32,         &MIRO_CFUsed_);
  createParam(MIRO_CFProgressString,               asynParamInt32,         &MIRO_CFProgress_);
  createParam(MIRO_CFErrorString,                  asynParamInt32,         &MIRO_CFError_);
  createParam(MIRO_CFNumFilesString,               asynParamInt32,         &MIRO_CFNumFiles_);
  createParam(MIRO_CFFormatString,                 asynParamInt32,         &MIRO_CFFormat_);
  createParam(MIRO_CFMaxPagesString,               asynParamInt32,         &MIRO_CFMaxPages_);
  createParam(MIRO_CFCurPageString,                asynParamInt32,         &MIRO_CFCurPage_);
  createParam(MIRO_CFFileNameString,               asynParamOctet,         &MIRO_CFFileName_);
  createParam(MIRO_CFSIndexString,                 asynParamInt32,         &MIRO_CFSIndex_);
  createParam(MIRO_CFSWidthString,                 asynParamInt32,         &MIRO_CFSWidth_);
  createParam(MIRO_CFSHeightString,                asynParamInt32,         &MIRO_CFSHeight_);
  createParam(MIRO_CFSFrameCountString,            asynParamInt32,         &MIRO_CFSFrameCount_);
  createParam(MIRO_CFSFirstFrameString,            asynParamInt32,         &MIRO_CFSFirstFrame_);
  createParam(MIRO_CFSLastFrameString,             asynParamInt32,         &MIRO_CFSLastFrame_);
  createParam(MIRO_CFSRecordStartString,           asynParamInt32,         &MIRO_CFSRecordStart_);
  createParam(MIRO_CFSRecordEndString,             asynParamInt32,         &MIRO_CFSRecordEnd_);
  createParam(MIRO_CFSRecordString,                asynParamInt32,         &MIRO_CFSRecord_);
  createParam(MIRO_CFSRecordCountString,           asynParamInt32,         &MIRO_CFSRecordCount_);
  createParam(MIRO_CFSFileDeleteString,            asynParamInt32,         &MIRO_CFSFileDelete_);
  createParam(MIRO_InfoSensorTempString,           asynParamInt32,         &MIRO_InfoSensorTemp_);
  createParam(MIRO_InfoThermoPowerString,          asynParamInt32,         &MIRO_InfoThermoPower_);
  createParam(MIRO_InfoCameraTempString,           asynParamInt32,         &MIRO_InfoCameraTemp_);
  createParam(MIRO_InfoFanPowerString,             asynParamInt32,         &MIRO_InfoFanPower_);
  createParam(MIRO_EDRString,                      asynParamInt32,         &MIRO_EDR_);
  createParam(MIRO_CamExtSyncString,               asynParamInt32,         &MIRO_CamExtSync_);
  createParam(MIRO_CamFrameDelayString,            asynParamInt32,         &MIRO_CamFrameDelay_);
  createParam(MIRO_CamTriggerEdgeString,           asynParamInt32,         &MIRO_CamTriggerEdge_);
  createParam(MIRO_CamTriggerFilterString,         asynParamInt32,         &MIRO_CamTriggerFilter_);
  createParam(MIRO_CamReadySignalString,           asynParamInt32,         &MIRO_CamReadySignal_);
  createParam(MIRO_CamAuxPinString,                asynParamInt32,         &MIRO_CamAuxPin_);
  createParam(MIRO_SyncClockString,                asynParamInt32,         &MIRO_SyncClock);
  for (index = 0; index < MIRO_NUMBER_OF_CINES; index++){
    createParam(MIRO_CnNameString[index],            asynParamOctet,         &MIRO_CnName_[index]);
    createParam(MIRO_CnWidthString[index],           asynParamInt32,         &MIRO_CnWidth_[index]);
    createParam(MIRO_CnHeightString[index],          asynParamInt32,         &MIRO_CnHeight_[index]);
    createParam(MIRO_CnStatusString[index],          asynParamInt32,         &MIRO_CnStatus_[index]);
    createParam(MIRO_CnFrameCountString[index],      asynParamInt32,         &MIRO_CnFrameCount_[index]);
    createParam(MIRO_CnFirstFrameString[index],      asynParamInt32,         &MIRO_CnFirstFrame_[index]);
    createParam(MIRO_CnLastFrameString[index],       asynParamInt32,         &MIRO_CnLastFrame_[index]);
    createParam(MIRO_CnRecordStartString[index],     asynParamInt32,         &MIRO_CnRecordStart_[index]);
    createParam(MIRO_CnRecordEndString[index],       asynParamInt32,         &MIRO_CnRecordEnd_[index]);
    createParam(MIRO_CnRecordString[index],          asynParamInt32,         &MIRO_CnRecord_[index]);
    createParam(MIRO_CnRecordCountString[index],     asynParamInt32,         &MIRO_CnRecordCount_[index]);
  }
  for (index = 0; index < MIRO_NUMBER_OF_FLASH_FILES; index++){
    createParam(MIRO_CfFileNameString[index],        asynParamOctet,         &MIRO_CfFileName_[index]);
    createParam(MIRO_CfFileSizeString[index],        asynParamOctet,         &MIRO_CfFileSize_[index]);
    createParam(MIRO_CfFileDateString[index],        asynParamOctet,         &MIRO_CfFileDate_[index]);
  }
 
  // Initialise MIRO parameters
  setIntegerParam(MIROConnected_, 0);
  setIntegerParam(MIRO_TotalFrameCount_, 0);
  setIntegerParam(MIRO_AcquireState_, 0);
  setIntegerParam(ADSizeX, 1280);
  setIntegerParam(ADSizeY, 800);
  setIntegerParam(MIRO_LivePreview_, 0);
  setIntegerParam(MIRO_SelectedCine_, 1);
  setStringParam(ADManufacturer,  "Vision Research");
  setStringParam(MIRO_CFFileName_,  "");
  setIntegerParam(MIRO_SettingsSlot_,  1);

  // Initialise meta data to save
  metaArray_.push_back(new MiroMeta("exposure", "Camera exposure time", "c%d.exp", NDAttrInt32, 0x674, 4));
  metaArray_.push_back(new MiroMeta("rate", "Camera frame rate", "c%d.rate", NDAttrInt32, 0x354, 4));
  metaArray_.push_back(new MiroMeta("trigger_secs", "Trigger time (seconds since 1970)", "c%d.trigtime.secs", NDAttrInt32, 0x028, 4));
  metaArray_.push_back(new MiroMeta("trigger_usecs", "Trigger time fraction (micro seconds)", "c%d.trigtime.frac", NDAttrInt32, 0x024, 4));
  metaArray_.push_back(new MiroMeta("label", "Label of data capture", "c%d.meta.name", NDAttrString, 0x1B9C, 256));
  metaArray_.push_back(new MiroMeta("trigger_polarity", "1 = Rising Edge, 0 = Falling Edge", "c%d.cam.trigpol", NDAttrInt32, 0x1690, 4));
  metaArray_.push_back(new MiroMeta("trigger_filter", "Trigger filter time (us)", "c%d.cam.trigfilt", NDAttrInt32, 0x1694, 4));
  metaArray_.push_back(new MiroMeta("fsync", "Frame sync mode", "c%d.cam.syncimg", NDAttrInt32, 0x065, 1));
  metaArray_.push_back(new MiroMeta("roi_width", "Region of interest pixel width", "c%d.meta.vw", NDAttrInt32, 0x030, 4));
  metaArray_.push_back(new MiroMeta("roi_height", "Region of interest pixel height", "c%d.meta.vh", NDAttrInt32, 0x034, 4));
  metaArray_.push_back(new MiroMeta("aux1_mode", "Auxiliary mode 1", "c%d.cam.aux1mode", NDAttrInt32, 0x0, 0));
  metaArray_.push_back(new MiroMeta("first_frame", "First frame number", "c%d.firstfr", NDAttrInt32, 0x010, 4));
  metaArray_.push_back(new MiroMeta("frame_count", "Total frame count", "c%d.frcount", NDAttrInt32, 0x014, 4));
//  metaArray_.push_back(new MiroMeta("post_trig_frames", "Post trigger frame count", "c%d.lastfr", NDAttrInt32, 0x0, 0));

  if (status == asynSuccess){
    debug(functionName, "Starting up polling task....");
    // Create the thread that runs the acquisition
    status = (epicsThreadCreate("MiroCameraTask",
                                epicsThreadPriorityMedium,
                                epicsThreadGetStackSize(epicsThreadStackMedium),
                                (EPICSTHREADFUNC)miroCameraTaskC,
                                this) == NULL);
    if (status){
      debug(functionName, "epicsTheadCreate failure for image task");
    }
  }

  if (status == asynSuccess){
    debug(functionName, "Starting up preview task....");
    // Create the thread that runs the acquisition
    status = (epicsThreadCreate("MiroPreviewTask",
                                epicsThreadPriorityMedium,
                                epicsThreadGetStackSize(epicsThreadStackMedium),
                                (EPICSTHREADFUNC)miroPreviewTaskC,
                                this) == NULL);
    if (status){
      debug(functionName, "epicsTheadCreate failure for preview task");
    }
  }

  if (status == asynSuccess){
    debug(functionName, "Starting up status task....");
    // Create the thread that runs the live preview
    status = (epicsThreadCreate("MiroStatusTask",
                                epicsThreadPriorityMedium,
                                epicsThreadGetStackSize(epicsThreadStackMedium),
                                (EPICSTHREADFUNC)miroStatusTaskC,
                                this) == NULL);
    if (status){
      debug(functionName, "epicsTheadCreate failure for status task");
    }
  }

  if (status == asynSuccess){
    debug(functionName, "Starting up flash task....");
    // Create the thread that runs the flash format and delete
    status = (epicsThreadCreate("MiroFlashTask",
                                epicsThreadPriorityMedium,
                                epicsThreadGetStackSize(epicsThreadStackMedium),
                                (EPICSTHREADFUNC)miroFlashTaskC,
                                this) == NULL);
    if (status){
      debug(functionName, "epicsTheadCreate failure for flash task");
    }
  }

  if (status == asynSuccess){
    // Attempt connection
    status |= makeConnection();

    if (status == asynSuccess){
      int sens_width = 0;
      int sens_height = 0;
      getCameraDataStruc("info", paramMap_);
      setStringParam(ADModel, (paramMap_["info.model"].getValue()).c_str());
      stringToInteger(paramMap_["info.xmax"].getValue(), sens_width);
      setIntegerParam(ADMaxSizeX, sens_width);
      stringToInteger(paramMap_["info.ymax"].getValue(), sens_height);
      setIntegerParam(ADMaxSizeY, sens_height);
    }
    if (status == asynSuccess){
      int exp_nano = 0;
      double fps = 0;
      getCameraDataStruc("defc", paramMap_);
      stringToInteger(paramMap_["defc.exp"].getValue(), exp_nano);
      setDoubleParam(ADAcquireTime, (double)exp_nano/1000000000.0);
      stringToDouble(paramMap_["defc.rate"].getValue(), fps);
      setDoubleParam(ADAcquirePeriod, (double)1.0/fps);
    }
  // Check if the status is bad.  If it is do our best to set the status record and message
  else if (status != asynSuccess){
    setIntegerParam(ADStatus, ADStatusError);
    setStringParam(ADStatusMessage, "Failed to initialise - check connection");
    }
  }
  callParamCallbacks();

}

asynStatus MiroCamera::makeConnection()
{
  int status = asynSuccess;
  static const char *functionName = "MiroCamera::makeConnection";
  
  status = connect();
  std::cout << "makeConnection(). connection status = " << status << '\n';
  if (status == asynSuccess){
    debug(functionName, "Connected OK");
    if (firstConnect_ == true){
      // Publish any updates necessary
      callParamCallbacks();

      if (status == asynSuccess){
        // First connection established, set flag
        firstConnect_ = false;
      }
    }
  }

  return (asynStatus)status;
}

asynStatus MiroCamera::connect()
{
  asynStatus status = asynSuccess;
  const char *functionName = "MiroCamera::connect";

  // Connect our Asyn user to the low level port that is a parameter to this constructor
  status = asynPortConnect(ctrlPort_, 0, &portUser_, "\n", "\n");
  if (status != asynSuccess){
    debug(functionName, "Failed to connect to low level asynOctetSyncIO port", ctrlPort_);
    // Failure, set the connected status to 0
    setIntegerParam(MIROConnected_,     0);
    setIntegerParam(ADStatus, ADStatusError);
    callParamCallbacks();
  } else {
    // Success, set the connected status to 1
    setIntegerParam(MIROConnected_,     1);
    setStringParam(ADStatusMessage, "Connected to MIRO");
    setIntegerParam(ADStatus, ADStatusIdle);
    callParamCallbacks();
  }

  if (status == asynSuccess){
    debug(functionName, "Connected to low level asynOctetSyncIO port", ctrlPort_);
    // Connect to the data asyn port
    status = pasynOctetSyncIO->connect(dataPort_, 0, &dataChannel_, NULL);
  }
  if (status != asynSuccess){
    debug(functionName, "Failed to connect to low level asynOctetSyncIO port", dataPort_);
    // Failure, set the connected status to 0
    setIntegerParam(MIROConnected_,     0);
    setIntegerParam(ADStatus, ADStatusError);
    callParamCallbacks();
  } else {
    debug(functionName, "Connected to low level asynOctetSyncIO port", "dataPort");
    attachToPort("dataPort");
  }

  return status;
}

asynStatus MiroCamera::disconnect()
{
  asynStatus status = asynSuccess;
  const char *functionName = "MiroCamera::disconnect";
  int connected = 0;

  getIntegerParam(MIROConnected_, &connected);
  // We can only force a disconnect if we are connected
  if (connected == 1){
    // disconnect from the ctrl port
    status = asynPortDisconnect(portUser_);
    if (status != asynSuccess){
      debug(functionName, "Failed to disconnect to low level asynOctetSyncIO port", ctrlPort_);
    }
  }
  return status;
}

/** 
 *  This function runs the acquisition thread.
 *  It is started in the class constructor and must not return until the IOC stops.
 *
*/ 
void MiroCamera::miroCameraTask()
{
  static const char *functionName = "MiroCamera::miroCameraTask";
  int status = asynSuccess;
  int acquire = 0;
  int imageMode = 0;
  int numImages = 0;
  int imageCounter = 0;
  int numImagesCounter = 0;
  int cine = 0;
  int firstFrame = 0;
  int lastFrame = 0;
  int frameCount = 0;
  int cineState = 0;
  int autoSave = 0;
  int autoAcquire = 0;
  char command[MIRO_MAX_STRING];
  std::string response;
  std::string cineStr;

  this->lock();
  // The following is needed for this kind of acquisition

  // Read in the cine number that we should be recording to
  // ? Read in the number of frames and partition ?
  // Start the cine recording by issuing a rec <cine_number>
  // Monitor the cine structure and check how many frames have been recorded
  // c#.state = State (recording, completed etc)
  // c#.frcount = Number of frames recorded
  // Increment the counters from the cine structure and decide when we have finished
  // right now start by monitoring cine 1 state and report the two items
  while (1){
    getIntegerParam(ADAcquire, &acquire);
    // If we are not acquiring or encountered a problem then wait for a semaphore that is given when acquisition is started
    if (!acquire){
      // Only set the status message if we didn't encounter a problem last time, so we don't overwrite the error mesage
      if(!status){
        debug(functionName, "Waiting for the acquire command");
        setStringParam(ADStatusMessage, "Ready");
        setIntegerParam(ADStatus, ADStatusIdle);
      }
      // Reset the counters
      setIntegerParam(ADNumExposuresCounter, 0);
      setIntegerParam(ADNumImagesCounter, 0);
      callParamCallbacks();

      // Release the lock while we wait for an event that says acquire has started, then lock again
      this->unlock();
      debug(functionName, "Waiting for acquire to start");
      status = epicsEventWait(this->startEventId_);
      this->lock();
      getIntegerParam(ADAcquire, &acquire);

      // Read in the selected cine
      getIntegerParam(MIRO_SelectedCine_, &cine);
      // Acquisition has been requested, read in the cine
      // Issue the start recording for the cine
      sprintf(command, "rec %d", cine);
      status = sendSimpleCommand(command, &response);

      // Create the cine string
      sprintf(command, "c%d", cine);
      cineStr.assign(command);
    }

    setStringParam(ADStatusMessage, "Recording frames into Cine");
    setIntegerParam(ADStatus, ADStatusAcquire);

    // Read out the cine status and counter
    getCameraDataStruc(cineStr, paramMap_);
    // Decode the status
    debug(functionName, paramMap_[cineStr + ".state"].getValue().c_str());
    cineStates(paramMap_[cineStr + ".state"].getValue(), cineState);
    setIntegerParam(MIRO_AcquireState_, cineState);
    if (checkState(paramMap_[cineStr + ".state"].getValue(), "WTR")){
      debug(functionName, "WTR state");
    }
    if (checkState(paramMap_[cineStr + ".state"].getValue(), "STR")){
      debug(functionName, "STR state");
    }
    if (checkState(paramMap_[cineStr + ".state"].getValue(), "TRG")){
      debug(functionName, "TRG state");
    }
    if (checkState(paramMap_[cineStr + ".state"].getValue(), "ACT")){
      debug(functionName, "ACT state");
    }
    // Decode the frame count
    status = stringToInteger(paramMap_[cineStr + ".frcount"].getValue(), frameCount);
    status = stringToInteger(paramMap_[cineStr + ".firstfr"].getValue(), firstFrame);
    status = stringToInteger(paramMap_[cineStr + ".lastfr"].getValue(), lastFrame);
    if (lastFrame > 0){
      imageCounter = lastFrame+1;
    } else {
      imageCounter = 0;
    }
    numImagesCounter = imageCounter;

    // Set a bit of areadetector image/frame statistics...
    getIntegerParam(ADNumImages, &numImages);
    getIntegerParam(ADImageMode, &imageMode);
    setIntegerParam(NDArrayCounter, imageCounter);
    setIntegerParam(ADNumImagesCounter, numImagesCounter);
    setIntegerParam(MIRO_TotalFrameCount_, frameCount);

    getIntegerParam(MIRO_AutoSave_, &autoSave);
    getIntegerParam(MIRO_AutoRestart_, &autoAcquire);

    debug(functionName, "cineState", cineState);
    debug(functionName, "cineState", (cineState & MIRO_CINE_STATE_STR));
    if ((cineState & MIRO_CINE_STATE_STR) == MIRO_CINE_STATE_STR){
      bool found = false;
      // Check if set to auto record cines
      if (autoSave == 1 && autoAcquire == 1){
        // Find the next active cine
        updateCine(1);
        updateCine(2);
        updateCine(3);
        updateCine(4);
        updateCine(5);
        updateCine(6);
        updateCine(7);
        updateCine(8);
        updateCine(9);
        updateCine(10);
        updateCine(11);
        updateCine(12);
        updateCine(13);
        updateCine(14);
        updateCine(15);
        updateCine(16);
        for (int index = 1; index < MIRO_NUMBER_OF_CINES; index++){
          getIntegerParam(MIRO_CnStatus_[index], &cineState);
          if ((cineState & MIRO_CINE_STATE_ACT) == MIRO_CINE_STATE_ACT){
            cine = index;
            // Write out the selected cine
            setIntegerParam(MIRO_SelectedCine_, cine);
            // Update the cine string
            sprintf(command, "c%d", cine);
            cineStr.assign(command);
            found = true;
          }
        }
      }
      if (!found){
        acquire = 0;
        setIntegerParam(ADAcquire, 0);
      }
    }

    if (status != asynError){
      // Check to see if acquisition is complete
      if ((imageMode == ADImageSingle) || ((imageMode == ADImageMultiple) && (numImagesCounter >= numImages))){
        setIntegerParam(ADAcquire, 0);
        debug(functionName, "Acquisition completed");
      }
      // Call the callbacks to update any changes
      callParamCallbacks();
      getIntegerParam(ADAcquire, &acquire);

      // If we are acquiring then check for a stop event
      if (acquire){
        callParamCallbacks();
        this->unlock();
        status = epicsEventWaitWithTimeout(this->stopEventId_, 0.1);
        this->lock();
      }
    }
  }
}

void MiroCamera::miroStatusTask()
{
  static const char *functionName = "MiroCamera::miroStatusTask";
  int status = asynSuccess;
  int cine = 0;
  char command[MIRO_MAX_STRING];
  std::string cineStr;
  int frameCount = 0;
  int acquire = 0;

  debug(functionName, "Starting thread...");
  while (1){
    epicsThreadSleep(0.25);
    this->lock();

    // Read out the preview cine status
    status = getCameraDataStruc("cam", paramMap_);

    if (status == asynSuccess){
      int cines = 0;
      std::string scines = paramMap_["cam.cines"].getValue();
      cleanString(scines, " ");
      status = stringToInteger(scines, cines);
      setIntegerParam(MIRO_GetCineCount_, cines);
    }

    updateInfoStatus();
    updateCameraStatus();
    updateDefcStatus();
    updateMetaStatus();
    updateFlash();
    updateAutoStatus();

    updateCine(1);
    updateCine(2);
    updateCine(3);
    updateCine(4);
    updateCine(5);
    updateCine(6);
    updateCine(7);
    updateCine(8);
    updateCine(9);
    updateCine(10);
    updateCine(11);
    updateCine(12);
    updateCine(13);
    updateCine(14);
    updateCine(15);
    updateCine(16);

    getIntegerParam(ADAcquire, &acquire);
    // If we are not acquiring update the cine frame count
    if (!acquire){
      // Read in the selected cine
      getIntegerParam(MIRO_SelectedCine_, &cine);
      // Create the cine string
      sprintf(command, "c%d", cine);
      cineStr.assign(command);
      // Read out the cine status and counter
      getCameraDataStruc(cineStr, paramMap_);
      status = stringToInteger(paramMap_[cineStr + ".frcount"].getValue(), frameCount);
      // Set a bit of areadetector image/frame statistics...
      setIntegerParam(MIRO_TotalFrameCount_, frameCount);
      callParamCallbacks();
    }

    this->unlock();
  }
}

void MiroCamera::miroPreviewTask()
{
  static const char *functionName = "MiroCamera::miroPreviewTask";
  int status = asynSuccess;
  int preview = 0;
  std::string response;

  this->lock();
  while (1){
    getIntegerParam(MIRO_LivePreview_, &preview);
    // If we are not acquiring or encountered a problem then wait for a semaphore that is given when acquisition is started
    if (!preview){
      // Release the lock while we wait for an event that says acquire has started, then lock again
      this->unlock();
      debug(functionName, "Waiting for preview to start");
      status = epicsEventWait(this->startPreviewEventId_);
      this->lock();
      getIntegerParam(MIRO_LivePreview_, &preview);
      status = updatePreviewCine();
      //status = attachToPort("dataPort");

      // Issue the start recording for the cine
      status = sendSimpleCommand("rec 0", &response);
    }

    // Now perform a readout of the preview cine
    readoutPreviewData();

    if (preview){
      this->unlock();
      status = epicsEventWaitWithTimeout(this->stopPreviewEventId_, 0.1);
      this->lock();
    }
  }
}

void MiroCamera::miroFlashTask()
{
  static const char *functionName = "MiroCamera::miroFlashTask";
  int status = asynSuccess;
  int formatFlash = 0;
  int deleteFile = 0;

  this->lock();
  while (1){
    // Release the lock while we wait for an event that says acquire has started, then lock again
    this->unlock();
    debug(functionName, "Waiting for flash event");
    status = epicsEventWait(this->flashEventId_);
    this->lock();
    getIntegerParam(MIRO_CFFormat_, &formatFlash);
    if (formatFlash){
      this->unlock();
      this->formatFlash();
      this->lock();
      setIntegerParam(MIRO_CFFormat_, 0);
    }
    getIntegerParam(MIRO_CFSFileDelete_, &deleteFile);
    if (deleteFile){
      this->unlock();
      this->deleteFlashFile();
      this->lock();
      setIntegerParam(MIRO_CFSFileDelete_, 0);
    }
    callParamCallbacks();
  }
}

/**
 * Connect to the underlying low level Asyn port that is used for comms.
 * This uses the asynOctetSyncIO interface, and also sets the input and output terminators.
 *
 * @param port - Name of the port to connect to.
 * @param addr - Address to connect to.
 * @param ppasynUser - Pointer to the asyn user structure.
 * @param inputEos - String input EOS.
 * @param outputEos - String output EOS.
 */
asynStatus MiroCamera::asynPortConnect(const char *port, int addr, asynUser **ppasynUser, const char *inputEos, const char *outputEos)
{
  static const char *functionName = "MiroCamera::asynPortConnect";

  asynStatus status = asynSuccess;
  std::map<std::string, std::string> data;

  status = pasynOctetSyncIO->connect( port, addr, ppasynUser, NULL);
  if (status) {
    debug(functionName, "Unable to connect to port", port);
    return status;
  }

  status = pasynOctetSyncIO->setInputEos(*ppasynUser, inputEos, strlen(inputEos));
  status = pasynOctetSyncIO->setOutputEos(*ppasynUser, outputEos, strlen(outputEos));

  debug(functionName, "Connected to low level asynOctetSyncIO port", port);

  // Record that we are connected
  setIntegerParam(MIROConnected_, 1);

/*  // Issue the connect command to complete connection
  status = sendSimpleCommand(MIRO_CMD_CONNECT, &data);
  if (status != asynSuccess){
    debug(functionName, "Failed to send command", MIRO_CMD_CONNECT);
  } else {
    debug(functionName, "Connect command return data", data);
  } */
  if (status == asynSuccess){
    // The connection was successful, record the server name and the protocol version
/*    std::string server = data["ServerName"];
    cleanString(server, "\"");
    setStringParam(MIROServerName_, server.c_str());
    std::string protocol = data["ProtocolVersion"];
    cleanString(protocol, "\"");
    setStringParam(MIROProtocolVersion_, protocol.c_str()); */
  }
  return status;
}

asynStatus MiroCamera::asynPortDisconnect(asynUser *pasynUser)
{
  static const char *functionName = "MiroCamera::asynPortDisconnect";

  asynStatus status = asynSuccess;
  std::map<std::string, std::string> data;

  status = pasynOctetSyncIO->disconnect(pasynUser);
  if (status) {
    debug(functionName, "Unable to disconnect from asyn port");
  }
  // Record that we are not connected
  setIntegerParam(MIROConnected_, 0);

  return status;
}

/**
 * Method for sending a simple command (no parameters) that will check the
 * error status and do the right thing.
 */
asynStatus MiroCamera::sendSimpleCommand(const std::string& command, std::string *response, double timeout)
{
  static const char *functionName = "MiroCamera::sendSimpleCommand";
  asynStatus status = asynSuccess;

  debug(functionName, "Sending command", command);
// Send the command and get the reply
  status = commandResponse(command, response, timeout);
  
// Check the command sent OK
  if (status == asynSuccess){
    // Check the response for any errors
    std::string errstr(MIRO_ERROR_STRING);
    if (*response == errstr){
      debug(functionName, "Unable to successfully issue the command", command);
//      debug(functionName, "Returned error", response);
      setStringParam(ADStatusMessage, response->c_str());
      status = asynError;
    }
  }
  return status;
}

/**
 * This sends a command to the device and parses the response.  Data is returned
 * in a std::map that is indexed by the parameter name
 * @param command - String command to send.
 * @param response - String response back (OK or ERROR)
 * @param data - Map of data items indexed by name
 */
asynStatus MiroCamera::commandResponse(const std::string &command, std::string *response, double timeout)
{
  static const char *functionName = "MiroCamera::commandResponse";

  asynStatus status = asynSuccess;
  std::string errorCode = "";
  std::string replyString = "";
  std::string nameValueString = "";
  char replyArray[MIRO_MAX_STRING];

  debug(functionName, "Command to send", command);
  status = asynWriteRead(command.c_str(), replyArray, timeout);
  // Only continue if the status is good...
  if (status == asynSuccess){
    // OK we need to first find out if the command was accepted or not
    response->assign(replyArray);
    //std::cout << "commandResponse: reply received = " << *response << '\n';
  } 
  else {
    //std::cout << "Error in commandResponse: status = " << status << '\n';
  }
  return status;
}

/**
 * Wrapper for asynOctetSyncIO write/read functions.
 * @param command - String command to send.
 * @param response - String response back.
 */
asynStatus MiroCamera::asynWriteRead(const char *command, char *response, double timeout)
{
  static const char *functionName = "MiroCamera::asynWriteRead";

  asynStatus status = asynSuccess;
  int eomReason;
  size_t nwrite = 0;
  size_t nread = 0;
  size_t tot = 0;
  int connected = 0;
  char sendString[256];
  char *inpPtr;

  callParamCallbacks();

  debug(functionName, "Writing command", command);

  //Setup the string to send to the detector
  sprintf(sendString, "%s\n", command);

  // If there is no asyn port user then something higher up has failed
  // Make sure to set connected to 0 and then bail out of this call with an error
  if (!portUser_) {
    setIntegerParam(MIROConnected_, 0);
    return asynError;
  }

  // Get the connected status
  getIntegerParam(MIROConnected_, &connected);

  // Only proceed if we are connected
  if (connected == 1){
	  inpPtr = response;
	  status = pasynOctetSyncIO->writeRead(portUser_ ,
	  																		 sendString, strlen(sendString),
                                         inpPtr, MIRO_MAX_STRING,
                                         timeout,
                                         &nwrite, &nread, &eomReason );
	  tot += nread;
	  inpPtr += nread;
	  while (response[tot-2] == '\\'){
	  	*inpPtr = '\n';
	  	inpPtr++;
	  	tot++;
	  	status = pasynOctetSyncIO->read(portUser_ ,
	  																	inpPtr,
																			MIRO_MAX_STRING,
																			MIRO_TIMEOUT,
																			&nread,
																			&eomReason);
	  	tot += nread;
	  	inpPtr += nread;
	  }
  }
  // Return error if no data read
  return (tot == 0 ? asynError : asynSuccess);
}

int MiroCamera::getLocalPortNum(const std::string& driverPort)
{
// Get local TCP socket port number for asyn port
  FILE *fp;
  struct sockaddr_in sa;
  int status = 0;
  
  //tfname = tmpnam(NULL);
  fp = fopen("/tmp/miro_port","w");
  pasynManager->report(fp, 2, driverPort.c_str());  // Output asynManager Report (level 2) into temp file
  fclose(fp);
  std::string stfname("/tmp/miro_port");
  std::string asynRepString = fileToString(stfname);  // Read file into a string
  std::size_t fd_pos = asynRepString.find("fd:");  // Locate line starting "fd:"
  if (fd_pos!=std::string::npos)
  {
    std::string sfd = asynRepString.substr(fd_pos+3, -1);
    std::size_t cr_pos = sfd.find("\n");           // Find string following "fd:" to end of line
    sfd = asynRepString.substr(fd_pos+3, cr_pos);  // This is the socket fd as a string
    int sa_len = sizeof(sa);
// Call getsockname() to get the local TCP socket number in the structure sa
    status = getsockname(atoi(sfd.c_str()), (struct sockaddr *)&sa, (socklen_t *)&sa_len);
  }
  remove("/tmp/miro_port");
  return (status == 0 ? (int)ntohs(sa.sin_port) : 0);
}

asynStatus MiroCamera::cleanString(std::string &str, const std::string &search, int where)
{
  if (str != ""){
    if (where == 0 || where == 1){
      // Clean up from the front of the string
      while (str.substr(0, 1).find_first_of(search) != std::string::npos){
        str = str.substr(1);
      }
    }
    if (where == 0 || where == 2){
      // Clean up from the back of the string
      while (str.substr(str.length()-1, 1).find_first_of(search) != std::string::npos){
        str = str.substr(0, str.length()-1);
      }
    }
  }
  return asynSuccess;
}

/** Called when asyn clients call pasynEnum->read().
  * The base class implementation simply prints an error message.
  * @param pasynUser - pasynUser structure that encodes the reason and address.
  * @param strings - Array of string pointers.
  * @param values - Array of values
  * @param severities - Array of severities
  * @param nElements - Size of value array
  * @param nIn - Number of elements actually returned 

asynStatus MiroCamera::readEnum(asynUser *pasynUser, char *strings[], int values[], int severities[], size_t nElements, size_t *nIn)
{

  const char *functionName = "MiroCamera::readEnum";
  asynStatus status = asynSuccess;
  int function = pasynUser->reason;
  size_t index;

  if (function == MIROLensMode_){
    for (index = 0; ((index < (size_t)lensModes_.size()) && (index < nElements)); index++){
      if (strings[index]){
        free(strings[index]);
      }
      strings[index] = epicsStrDup(lensModes_[index].c_str());
      debug(functionName, "Reading lens mode", strings[index]);
      values[index] = index;
      severities[index] = 0;
    }
    *nIn = index;
  } else if (function == MIROScanRange_){
    for (index = 0; ((index < (size_t)scanRanges_.size()) && (index < nElements)); index++){
      if (strings[index]){
        free(strings[index]);
      }
      strings[index] = epicsStrDup(scanRanges_[index].c_str());
      debug(functionName, "Reading scan range", strings[index]);
      values[index] = index;
      severities[index] = 0;
    }
    *nIn = index;
  } else if (function == MIRORunMode_){
    for (index = 0; ((index < (size_t)runModes_.size()) && (index < nElements)); index++){
      if (strings[index]){
        free(strings[index]);
      }
      strings[index] = epicsStrDup(runModes_[index].c_str());
      debug(functionName, "Reading run mode", strings[index]);
      values[index] = index;
      severities[index] = 0;
    }
    *nIn = index;
  } else {
    *nIn = 0;
    status = asynError;
  }

  *nIn = 0;
  return status;
}
*/

/**
 * Called when asyn clients call pasynInt32->write().
 * Write integer value to the drivers parameter table.
 *
 * @param pasynUser - Pointer to the asyn user structure.
 * @param value - The new value to write
 */
asynStatus MiroCamera::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
  const char *functionName = "MiroCamera::writeInt32";
  int status = asynSuccess;
  int function = pasynUser->reason;
  int oldValue;

  // parameters for functions
  int adstatus;

  getIntegerParam(function, &oldValue);
  setIntegerParam(function, value);
  getIntegerParam(ADStatus, &adstatus);
  setStringParam(ADStatusMessage, "Ready");
  setIntegerParam(ADStatus, ADStatusIdle);

  if (function == ADAcquire){
    if (value && (adstatus == ADStatusIdle || adstatus == ADStatusError || adstatus == ADStatusAborted)){
      // Send an event to wake up the electronAnalyser task.
      epicsEventSignal(this->startEventId_);
    }
    if (!value && (adstatus != ADStatusIdle)){
      // Sent the message to the miro to stop
      std::string response = "";
      sendSimpleCommand(MIRO_CMD_ABORT, &response);
      // Stop acquiring ( abort any hardware processing )
      epicsEventSignal(this->stopEventId_);
    }
  } else if (function == MIRO_LivePreview_){
    if (value){
      // Send an event to wake up the live preview
      epicsEventSignal(this->startPreviewEventId_);
    }
    if (!value){
      // Stop live preview
      epicsEventSignal(this->stopPreviewEventId_);
    }
  } else if (function == MIRO_SoftwareTrigger_){
    sendSoftwareTrigger();
  } else if (function == MIRO_CineRecord_){
    int preview = 0;
    bool rangeValid = false;
    int cine;
    epicsInt32 record_start;
    epicsInt32 record_end;
    epicsInt32 first_frame;
    epicsInt32 last_frame;
    getIntegerParam(MIRO_SelectedCine_, &cine);
    getIntegerParam(MIRO_LivePreview_, &preview);
    getIntegerParam(MIRO_CineRecordStart_, &record_start);
    getIntegerParam(MIRO_CineRecordEnd_, &record_end);
    getIntegerParam(MIRO_CnFirstFrame_[cine], &first_frame);
    getIntegerParam(MIRO_CnLastFrame_[cine], &last_frame);

    if (record_start < first_frame || record_start > last_frame) {
      rangeValid=false;
      setStringParam(ADStatusMessage, "record_start value invalid");
    } else if(record_end < first_frame || record_end > last_frame) {
      rangeValid=false;
      setStringParam(ADStatusMessage, "record_end value invalid");
    } else if (record_end < record_start) {
      rangeValid=false;
      setStringParam(ADStatusMessage, "record_end can't be less than record_start");
    } else
      rangeValid=true;

    if (preview){
      setStringParam(ADStatusMessage, "Cannot download while live previewing");
      setIntegerParam(ADStatus, ADStatusError);
      status |= asynError;
    } else if (rangeValid) {
      status |= downloadCineFile(value);
    }
  } else if (function == MIRO_CineSaveCF_){
    status |= saveCineToFlash(value);
  } else if (function == MIRO_SettingsSave_){
    status |= saveSettings();
  } else if (function == MIRO_SettingsLoad_){
    status |= loadSettings();
  } else if (function == MIRO_SelectedCine_){
    // Set up the selected cine
    status |= selectCine(value);
  } else if (function == MIRO_SetPartition_){
    // Set up the partition
    status |= setPartition(value);
  } else if (function == MIRO_CFCurPage_){
    // Set the current page
    status |= updateFlashFileTable();
  } else if (function == MIRO_CFSIndex_){
    // Select the flash file from the table by index
    status |= selectFlashByIndex(value);
  } else if (function == MIRO_CFSRecord_){
    // Download the flash file
    int preview = 0;
    getIntegerParam(MIRO_LivePreview_, &preview);
    if (preview){
      setStringParam(ADStatusMessage, "Cannot download while live previewing");
      setIntegerParam(ADStatus, ADStatusError);
      status |= asynError;
    } else {
      status |= downloadFlashFile();
    }
  } else if (function == MIRO_CFSFileDelete_){
    // Delete the flash file
    epicsEventSignal(this->flashEventId_);
  } else if (function == MIRO_CFFormat_){
    // Format the flash disk
    epicsEventSignal(this->flashEventId_);
  } else if (function == MIRO_CamExtSync_){
    status |= setCameraParameter("cam.syncimg", value);
  } else if (function == MIRO_CamFrameDelay_){
    status |= setCameraParameter("cam.frdelay", value);
  } else if (function == MIRO_CamTriggerEdge_){
    status |= setCameraParameter("cam.trigpol", value);
  } else if (function == MIRO_CamTriggerFilter_){
    status |= setCameraParameter("cam.trigfilt", value);
  } else if (function == MIRO_CamReadySignal_){
    status |= setCameraParameter("cam.longready", value);
  } else if (function == MIRO_CamAuxPin_){
    status |= setCameraParameter("cam.aux1mode", value);
  } else if (function == ADSizeX || function == ADSizeY){
    status |= setCameraResolution();
  } else if (function == MIRO_PostTrigCount_){
    int maxFrameCount = 1;
    getIntegerParam(MIRO_MaxFrameCount_, &maxFrameCount);
    if (value > maxFrameCount){
      value = maxFrameCount;
    }
    status |= setCameraParameter("defc.ptframes", value);
  } else if (function == MIRO_PerformCSR_){
    status |= performCSR();
  } else if (function == MIRO_AutoSave_){
    status |= setCameraParameter("auto.filesave", value);
  } else if (function == MIRO_AutoRestart_){
    status |= setCameraParameter("auto.acqrestart", value);
  } else if (function == MIRO_AutoCSR_){
    status |= setCameraParameter("auto.bref", value);
  } else if (function == MIRO_EDR_){
    status |= setCameraParameter("defc.edrexp", value);
  } else if (function == MIRO_SyncClock){
    char command[MIRO_MAX_STRING];
    std::string response;
    sprintf(command, "setrtc %d", std::time(NULL));
    sendSimpleCommand(command, &response);
  }

  // If the status is bad reset the original value
  if (status){
    setIntegerParam(function, oldValue);
  }
  this->lock();
  // Do callbacks so higher layers see any changes
  callParamCallbacks();
  this->unlock();
  if (status){
    debug(functionName, "Error, status", status);
    debug(functionName, "Error, function", function);
    debug(functionName, "Error, value", value);
    setIntegerParam(function, oldValue);
  } else {
    debug(functionName, "Function", function);
    debug(functionName, "Value", value);
  }

  return (asynStatus)status;
}

/**
 * Called when asyn clients call pasynFloat64->write().
 * Write integer value to the drivers parameter table.
 *
 * @param pasynUser - Pointer to the asyn user structure.
 * @param value - The new value to write
*/
asynStatus MiroCamera::writeFloat64(asynUser *pasynUser, epicsFloat64 value)
{
  const char *functionName = "MiroCamera::writeFloat64";
  asynStatus status = asynSuccess;
  int function = pasynUser->reason;
  double oldValue;
  char command[MIRO_MAX_STRING];
  int exposure = 0;
  double fps = 0;
  std::string response;

  // parameters for functions
  int adstatus;

  getDoubleParam(function, &oldValue);
  setDoubleParam(function, value);
  getIntegerParam(ADStatus, &adstatus);

  if (function == ADAcquireTime){
    // Exposure time in nanoseconds
    exposure = (int)(value * 1000000000.0);
    // Create the command
    sprintf(command, "set defc.exp %d", exposure);
    sendSimpleCommand(command, &response);
    getCameraDataStruc("defc", paramMap_);
    stringToInteger(paramMap_["defc.exp"].getValue(), exposure);
    value = (double)exposure/1000000000.0;
    setDoubleParam(function, (double)exposure/1000000000.0);
  } else if (function == ADAcquirePeriod){
    // Number of frames per second
    fps = (double)(1.0 / value);
    // Create the command
    sprintf(command, "set defc.rate %f", fps);
    sendSimpleCommand(command, &response);
    getCameraDataStruc("defc", paramMap_);
    stringToDouble(paramMap_["defc.rate"].getValue(), fps);
    value = (double)1.0/(double)(fps);
    setDoubleParam(function, value);
  }

  /*
  // Check if the function is one of our stored parameter index values
  if (paramIndexes_.count(function) == 1){
    // This means the parameter was read out from the MIRO hardware at startup
    debug(functionName, "Update request of parameter", paramIndexes_[function]);
    debug(functionName, "New Value", value);
    status = setCameraParameter(paramMap_[paramIndexes_[function]], value);
    double newValue = 0.0;
    if (status == asynSuccess){
      status = getCameraParameter(paramMap_[paramIndexes_[function]], newValue);
    }
    if (status == asynSuccess){
      setDoubleParam(function, newValue);
    } else {
      setDoubleParam(function, oldValue);
    }
  }
*/
  this->lock();
  // Do callbacks so higher layers see any changes
  callParamCallbacks();
  this->unlock();
  if (status){
    debug(functionName, "Error, status", status);
    debug(functionName, "Error, function", function);
    debug(functionName, "Error, value", value);
  } else {
    debug(functionName, "Function", function);
    debug(functionName, "Value", (double)value);
  }

  return status;
}

asynStatus MiroCamera::writeOctet(asynUser *pasynUser, const char *value, size_t nChars, size_t *nActual)
{
  int addr=0;
  int function = pasynUser->reason;
  asynStatus status = asynSuccess;
  const char *functionName = "writeOctet";
  status = getAddress(pasynUser, &addr); if (status != asynSuccess) return(status);
  // Set the parameter in the parameter library.
  status = (asynStatus)setStringParam(addr, function, (char *)value);
  if (status != asynSuccess) return(status);

  if (function == MIRO_CFFileName_){
    status = this->downloadFlashHeader(value);
  } else if (function == MIRO_CineName_){
    status = this->setCameraParameter("meta.name", value);
  }

  // Do callbacks so higher layers see any changes
  callParamCallbacks(addr, addr);

  //Call base class method. This will handle callCallbacks even if the function was handled here.
  status = ADDriver::writeOctet(pasynUser, value, nChars, nActual);


  if (status != asynSuccess){
    epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize,
                  "%s: status=%d, function=%d, value=%s",
                  functionName, status, function, value);
  } else {
    asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
              "%s: function=%d, value=%s\n",
              functionName, function, value);
  }
  *nActual = nChars;
  return status;
}

asynStatus MiroCamera::setCameraResolution()
{
  const char * functionName = "MiroCamera::setCameraResolution";
  char command[MIRO_MAX_STRING];
  std::string response;
  int x = 0;
  int y = 0;
  asynStatus status = asynSuccess;

  // Read both the desired x and y and set the resolution
  getIntegerParam(ADSizeX, &x);
  getIntegerParam(ADSizeY, &y);

  sprintf(command, "%s defc.res %dx%d", MIRO_CMD_SET_VALUE, x, y);

  debug(functionName, "Sending command", command);
  status = sendSimpleCommand(command, &response);

  return status;
}

asynStatus MiroCamera::performCSR()
{
  const char * functionName = "MiroCamera::performCSR";
  std::string response;
  asynStatus status = asynSuccess;

  debug(functionName, "Sending command", MIRO_CMD_BLACKREF);
  status = sendSimpleCommand(MIRO_CMD_BLACKREF, &response);

  return status;
}

asynStatus MiroCamera::attachToPort(const std::string& portName)
{
  const char * functionName = "MiroCamera::attachToPort";
  char command[MIRO_MAX_STRING];
  std::string response;
  asynStatus status = asynSuccess;

  int port = this->getLocalPortNum(portName.c_str());

  debug(functionName, "Data port number", port);
  sprintf(command, "attach {port:%d}", port);
  status = sendSimpleCommand(command, &response);
  debug(functionName, "Response", response);
  printf("%s response: %s\n", functionName, response.c_str());
  return status;
}

asynStatus MiroCamera::readoutPreviewData()
{
  const char * functionName = "MiroCamera::readoutPreviewData";
  int nBytes = 0;
  std::string response;
  NDArray *pImage;
  size_t dims[2];
  NDDataType_t dataType;
  int acquire;
  int nbytes;
  int arrayCallbacks   = 0;
  asynStatus status = asynSuccess;

  // Calculate the number of bytes to read
  nBytes = (int)((double)previewWidth_ * (double)previewHeight_ * 1.25);
  debug(functionName, "nBytes", nBytes);

  // Flush the data connection
  pasynOctetSyncIO->flush(dataChannel_);

  // Read in the acquire state and selected cine
  getIntegerParam(ADAcquire, &acquire);
  if (acquire){
    status = sendSimpleCommand("img {cine:-1, start:0, cnt:1, fmt:P10}", &response);
  } else {
    status = sendSimpleCommand("img {cine:0, start:0, cnt:1, fmt:P10}", &response);
  }
  debug(functionName, "Response", response);

  this->readFrame(nBytes);

  unsigned char *input = (unsigned char *)data_;
  unsigned char *output = (unsigned char *)flashData_;
  for (int bIndex = 0; bIndex < nBytes/5; bIndex++){
    this->convert10BitPacketTo12Bit(input+(bIndex*5), output+(bIndex*8));
  }

  // Allocate NDArray memory
  dims[0] = previewWidth_;
  dims[1] = previewHeight_;
  nbytes = (dims[0] * dims[1]) * sizeof(int16_t);
  dataType= NDUInt16;
  pImage = this->pNDArrayPool->alloc(2, dims, dataType, nbytes, NULL);

  memcpy(pImage->pData, flashData_, nbytes);
  pImage->dims[0].size = dims[0];
  pImage->dims[1].size = dims[1];

  getIntegerParam(NDArrayCallbacks, &arrayCallbacks);
  if (arrayCallbacks){
    // Must release the lock here, or we can get into a deadlock, because we can
    // block on the plugin lock, and the plugin can be calling us
    this->unlock();
    debug(functionName, "Calling NDArray callback");
    doCallbacksGenericPointer(pImage, NDArrayData, 0);
    this->lock();
  }

  // Free the image buffer
  pImage->release();

  return status;
}

asynStatus MiroCamera::sendSoftwareTrigger()
{
  const char * functionName = "MiroCamera::readoutDataStream";
  std::string response;
  asynStatus status = asynSuccess;

  status = sendSimpleCommand(MIRO_CMD_TRIG, &response);
  debug(functionName, "Response", response);

  return status;
}

asynStatus MiroCamera::downloadCineFile(int cine)
{
  const char * functionName = "MiroCamera::downloadCineFile";
  int start = 0;
  int end = 0;
  std::string response;
  asynStatus status = asynSuccess;

  // Read in the number of frames to download
  getIntegerParam(MIRO_CineRecordStart_, &start);
  getIntegerParam(MIRO_CineRecordEnd_, &end);

  debug(functionName, "Download start", start);
  debug(functionName, "Download end", end);

  // Attach to the correct port
  //status = attachToPort("dataPort");

  // Download the timestamp information
  status = readoutTimestamps(cine, start, end);

  // Download the data and process arrays
  status = readoutDataStream(cine, start, end);

  return status;
}

asynStatus MiroCamera::saveCineToFlash(int cine)
{
  const char * functionName = "MiroCamera::saveCineToFlash";
  char command[MIRO_MAX_STRING];
  std::string response = "";
  asynStatus status = asynSuccess;

  // Verify the cine file is valid
  if (cine < 1 || cine > 16){
    printf("%s: Error - Invalid cine index %d\n", functionName, cine);
    status = asynError;
  }

  if (status == asynSuccess){
    // Execute the save cine command
    sprintf(command, "%s {cine: %d}", MIRO_CMD_CFSAVE, cine);
    status = sendSimpleCommand(command, &response);
  }

  return status;
}

asynStatus MiroCamera::saveSettings()
{
  const char * functionName = "MiroCamera::saveSettings";
  char command[MIRO_MAX_STRING];
  std::string response = "";
  int slot = 1;
  asynStatus status = asynSuccess;

  getIntegerParam(MIRO_SettingsSlot_, &slot);
  sprintf(command, "%s { slot: %d }", MIRO_CMD_USERSAVE, slot);
  status = sendSimpleCommand(command, &response);
  debug(functionName, response.c_str());
  return status;
}

asynStatus MiroCamera::loadSettings()
{
  const char * functionName = "MiroCamera::loadSettings";
  char command[MIRO_MAX_STRING];
  std::string response = "";
  int slot = 1;
  asynStatus status = asynSuccess;

  getIntegerParam(MIRO_SettingsSlot_, &slot);
  sprintf(command, "%s { slot: %d }", MIRO_CMD_USERLOAD, slot);
  status = sendSimpleCommand(command, &response);
  debug(functionName, response.c_str());
  return status;
}

asynStatus MiroCamera::formatFlash()
{
  const char * functionName = "MiroCamera::formatFlash";
  std::string response = "";
  asynStatus status = asynSuccess;

  status = sendSimpleCommand(MIRO_CMD_CFFORMAT, &response, MIRO_EXTENDED_TIMEOUT);
  debug(functionName, response.c_str());
  return status;
}

asynStatus MiroCamera::deleteFlashFile()
{
  const char * functionName = "MiroCamera::deleteFlashFile";
  char command[MIRO_MAX_STRING];
  char filename[MIRO_MAX_STRING];
  std::string response = "";
  asynStatus status = asynSuccess;

  // Read in the selected file
  getStringParam(MIRO_CFFileName_, MIRO_MAX_STRING, filename);

  // Verify the cine file is valid
  if (strcmp(filename, "") == 0){
    printf("%s: Error - Invalid empty filename\n", functionName);
    status = asynError;
  }

  if (status == asynSuccess){
    // Execute the save cine command
    sprintf(command, "%s {filename: \"%s\"}", MIRO_CMD_CFRM, filename);
    status = sendSimpleCommand(command, &response);
  }

  return status;
}

asynStatus MiroCamera::selectFlashByIndex(int index)
{
  const char * functionName = "MiroCamera::selectFlashByIndex";
  char filename[MIRO_MAX_STRING];
  asynStatus status = asynSuccess;

  // Check the index is between 1 and 8
  if (index < 1 || index > 8){
    debug(functionName, "Select flash index out of range (1-8)");
    status = asynError;
  }
  if (status == asynSuccess){
    getStringParam(MIRO_CfFileName_[index-1], MIRO_MAX_STRING, filename);
    if (strcmp(filename, "")){
      setStringParam(MIRO_CFFileName_, filename);
      status = downloadFlashHeader(filename);
    }
  }
  return status;
}

asynStatus MiroCamera::downloadFlashFile()
{
  const char * functionName = "MiroCamera::downloadFlashFile";
  int start = 0;
  int end = 0;
  char filename[MIRO_MAX_STRING];
  asynStatus status = asynSuccess;

  // Read in the number of frames to download
  getIntegerParam(MIRO_CFSRecordStart_, &start);
  getIntegerParam(MIRO_CFSRecordEnd_, &end);

  // Attach to the correct port
  //status = attachToPort("dataPort");

  // Read in the selected file
  getStringParam(MIRO_CFFileName_, MIRO_MAX_STRING, filename);

  // Verify the file is valid
  if (strcmp(filename, "") == 0){
    printf("%s: Error - Invalid empty filename\n", functionName);
    status = asynError;
  }

  if (start < (int)cineHeader_.FirstImageNo || start > (int)(cineHeader_.FirstImageNo + cineHeader_.ImageCount)){
    printf("Flash Download failed: Invalid start index\n");
    setStringParam(ADStatusMessage, "Flash Download failed: Index error");
    setIntegerParam(ADStatus, ADStatusError);
    callParamCallbacks();
    status = asynError;
  }
  if (end < (int)cineHeader_.FirstImageNo || end > (int)(cineHeader_.FirstImageNo + cineHeader_.ImageCount)){
    printf("Flash Download failed: Invalid end index\n");
    setStringParam(ADStatusMessage, "Flash Download failed: Index error");
    setIntegerParam(ADStatus, ADStatusError);
    callParamCallbacks();
    status = asynError;
  }
  if (start > end){
    printf("Flash Download failed: End index must be greater than start index\n");
    setStringParam(ADStatusMessage, "Flash Download failed: Index error");
    setIntegerParam(ADStatus, ADStatusError);
    callParamCallbacks();
    status = asynError;
  }

  // we need to calculate the index values of the frames (starting at index 0)
  start = start - cineHeader_.FirstImageNo;
  end = end - cineHeader_.FirstImageNo;

  //printf("*** Flash: first image index: %d\n", start);
  //printf("*** Flash: last image index: %d\n", end);

  if (status == asynSuccess){
    // Download the data and process arrays
    status = downloadFlashImages(filename, start, end);
  }
  return status;
}

asynStatus MiroCamera::downloadFlashHeader(const std::string& filename)
{
  const char * functionName = "MiroCamera::downloadFlashHeader";
  char command[MIRO_MAX_STRING];
  std::string response;
  short setupLength = 0;
  int noOfTimes = 0;
  int ofsBlock = 0;
  int defaultExposure = 0;
  INFOBLOCK block;
  asynStatus status = asynSuccess;

  // Attach to the correct port
  //status = attachToPort("dataPort");
  // Clear out timestamp data
  flashTsData_.clear();
  flashExpData_.clear();

  if (status == asynSuccess){
    // Flush the data connection
    pasynOctetSyncIO->flush(dataChannel_);

    sprintf(command, "cfread {filename: \"%s\", offset: 0, count:44 }", filename.c_str());
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }

  if (status == asynSuccess){
    status = this->readFrame(44);
  }

  if (status == asynSuccess){
    memcpy(&cineHeader_, data_, 44);
    char stype[3];
    strncpy(stype, (char *)&(cineHeader_.Type), 2);
    stype[2] = 0;
    debug(functionName, "OffImageOffsets", (int)cineHeader_.OffImageOffsets);
  }

  if (status == asynSuccess){
    sprintf(command, "cfread {filename: \"%s\", offset: 44, count:40 }", filename.c_str());
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }

  if (status == asynSuccess){
    status = this->readFrame(40);
    memcpy(&cineBitmapHeader_, data_, 40);
    setIntegerParam(MIRO_CFSWidth_, cineBitmapHeader_.biWidth);
    setIntegerParam(MIRO_CFSHeight_, cineBitmapHeader_.biHeight);
    setIntegerParam(MIRO_CFSFrameCount_, cineHeader_.TotalImageCount);
    setIntegerParam(MIRO_CFSFirstFrame_, cineHeader_.FirstImageNo);
    std::cout<<"cineHeader_.FirstImageNo: "<<cineHeader_.FirstImageNo<<std::endl;
    setIntegerParam(MIRO_CFSLastFrame_, cineHeader_.FirstImageNo + cineHeader_.ImageCount - 1);
  }

  // Read in the default exposure time ns
  if (status == asynSuccess){
    sprintf(command, "cfread {filename: \"%s\", offset: 1652, count:4 }", filename.c_str());
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }
  if (status == asynSuccess){
    status = this->readFrame(4);
    memcpy(&defaultExposure, data_, 4);
  }

  // Read in the setup length
  if (status == asynSuccess){
    sprintf(command, "cfread {filename: \"%s\", offset: 226, count:2 }", filename.c_str());
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }
  if (status == asynSuccess){
    status = this->readFrame(2);
    memcpy(&setupLength, data_, 2);
    // Now read in the first tagged information block header
    ofsBlock = 84 + setupLength;
    sprintf(command, "cfread {filename: \"%s\", offset: %d, count:8 }", filename.c_str(), ofsBlock);
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }
  if (status == asynSuccess){
    status = this->readFrame(8);
    memcpy(&block, data_, 8);
    noOfTimes = (block.size - 8) / 8;
    // Read out the data block and record the time values
    ofsBlock += 8;
    sprintf(command, "cfread {filename: \"%s\", offset: %d, count:%d }", filename.c_str(), ofsBlock, (block.size-8));
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }
  if (status == asynSuccess){
    tagTIME64 ts;
    status = this->readFrame(block.size-8);
    char *ptr = data_;
    for (int count = 0; count < noOfTimes; count++){
      memcpy(&ts, ptr, 8);
      char locked = ts.frac & 0x01;
      flashIrigData_.push_back(locked);
      char event_active = (ts.frac & 0x02) >> 1;
      flashEventData_.push_back(event_active);
      //printf("tsec: %d\n", ts.secs);
      //printf("tusec: %d\n", (int32_t)round((double)(ts.frac) / 4294.967296));
      ts.frac = (uint32_t)round((double)(ts.frac) / 4294.967296);
      flashTsData_.push_back(ts);
      ptr+= 8;
    }
  }
  if (status == asynSuccess){
    // Now read in the second tagged information block header
    ofsBlock += (block.size - 16);
    sprintf(command, "cfread {filename: \"%s\", offset: %d, count:8 }", filename.c_str(), ofsBlock);
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }
  if (status == asynSuccess){
    status = this->readFrame(8);
    memcpy(&block, data_, 8);
    noOfTimes = (block.size - 8) / 4;
    // Read out the data block and record the time values
    ofsBlock += 8;
    sprintf(command, "cfread {filename: \"%s\", offset: %d, count:%d }", filename.c_str(), ofsBlock, (block.size-8));
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
  }
  if (status == asynSuccess){
    status = this->readFrame(block.size-8);
    uint32_t *exp = (uint32_t *)data_;
    for (int count = 0; count < noOfTimes; count++){
      if (*exp == 0){
        flashExpData_.push_back((uint32_t)defaultExposure);
      } else {
        flashExpData_.push_back((uint32_t)round((double)(*exp) / 4294.967296));
      }
      exp++;
    }
  }

  // Loop over meta array to read values
  for (int mc = 0; mc < (int)metaArray_.size(); mc++){
    if (metaArray_[mc]->offset_ > 0){
      sprintf(command, "cfread {filename: \"%s\", offset: %d, count:%d }", filename.c_str(), metaArray_[mc]->offset_, metaArray_[mc]->size_);
      status = sendSimpleCommand(command, &response);
      debug(functionName, "Response", response);
      status = this->readFrame(metaArray_[mc]->size_);
      memcpy(metaArray_[mc]->vPtr_, data_, metaArray_[mc]->size_);
      if (metaArray_[mc]->type_ == NDAttrInt32){
        int32_t *ival = (int32_t *)metaArray_[mc]->vPtr_;
        if (metaArray_[mc]->name_ == "trigger_usecs"){
          uint32_t uival = (uint32_t)*ival;
          double timeVal = (double)(uival) / 4294.967296;
          int32_t tival = (int32_t)round(timeVal);
          flashTrigUsecs_ = tival;
          memcpy(metaArray_[mc]->vPtr_, &tival, 4);
          ival = (int32_t *)metaArray_[mc]->vPtr_;
        }
        if (metaArray_[mc]->name_ == "trigger_secs"){
          uint32_t uival = (uint32_t)*ival;
          flashTrigSecs_ = uival;
        }
      }
    }
  }

  return status;
}

asynStatus MiroCamera::downloadFlashImages(const std::string& filename, int start, int end)
{
  const char * functionName = "MiroCamera::downloadFlashFile";
  char command[MIRO_MAX_STRING];
  std::string response;
  NDArray *pImage;
  size_t dims[2];
  NDDataType_t dataType;
  int width = 0;
  int height = 0;
  int nBytes = 0;
  int nbytes = 0;
  int arrayCallbacks   = 0;
  int recordCount = 0;
  int metaFrame = 0;
  int frames = end - start + 1;
  int firstfr = 0;
  int postTrig = 0;
  int first_tv_sec = 0;
  int first_tv_usec = 0;
  asynStatus status = asynSuccess;

  // Attach to the correct port
  //status = attachToPort("dataPort");

  // Flush the data connection
  pasynOctetSyncIO->flush(dataChannel_);

  // Obtain the post trig count
  postTrig = cineHeader_.FirstImageNo + cineHeader_.TotalImageCount;
  // Obtain the first frame number
  firstfr = start + cineHeader_.FirstImageNo;

  sprintf(command, "cfread {filename: \"%s\", offset:%d, count:%d }", filename.c_str(), cineHeader_.OffImageOffsets, (8*cineHeader_.TotalImageCount) );
  status = sendSimpleCommand(command, &response);
  debug(functionName, "Response", response);
  status = this->readFrame(8*cineHeader_.TotalImageCount);
  unsigned long imagePtr[8*cineHeader_.TotalImageCount];
  memcpy(imagePtr, data_, 8*cineHeader_.TotalImageCount);

  // Read the frame size for the selected cine file
  width = cineBitmapHeader_.biWidth;
  height = cineBitmapHeader_.biHeight;
  // Calculate the number of bytes to read
  // In packet format there are 10 bits per pixel,
  // which equates to 1.25 bytes
  nBytes = (int)((double)width * (double)height * 1.25);
  debug(functionName, "Width", width);
  debug(functionName, "Height", height);
  debug(functionName, "nBytes", nBytes);

  first_tv_sec = flashTsData_[start].secs;
  first_tv_usec = flashTsData_[start].frac;
  recordCount = 0;
  for (int count = start; count <= end; count++){
    metaFrame = count + cineHeader_.FirstImageNo;
    //printf("Image %d offset value: %lX\n", count, imagePtr[count]);
    sprintf(command, "cfread {filename: \"%s\", offset:%lu, count:4 }", filename.c_str(), imagePtr[count]);
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
    status = this->readFrame(4);
    unsigned int *iPtr = (unsigned int *)data_;
    //printf("Annotation size %d\n", *iPtr);
    unsigned long pixelCountAddress = imagePtr[count] + *iPtr - 4;
    //printf("Pixel count address: %lX\n", pixelCountAddress);
    sprintf(command, "cfread {filename: \"%s\", offset:%lu, count:4 }", filename.c_str(), pixelCountAddress );
    status = sendSimpleCommand(command, &response);
    debug(functionName, "Response", response);
    status = this->readFrame(4);
    iPtr = (unsigned int *)data_;
    debug(functionName, "Pixel count", (int)(*iPtr));
    pixelCountAddress += 4;
    sprintf(command, "cfread {filename: \"%s\", offset:%lu, count:%d }", filename.c_str(), pixelCountAddress, nBytes/2);
    status = sendSimpleCommand(command, &response);
    //printf("%s Response: %s\n", functionName, response.c_str());
    pixelCountAddress += nBytes/2;
    sprintf(command, "cfread {filename: \"%s\", offset:%lu, count:%d }", filename.c_str(), pixelCountAddress, nBytes/2);
    status = sendSimpleCommand(command, &response);
    //printf("%s Response: %s\n", functionName, response.c_str());
    debug(functionName, "Response", response);
    status = this->readFrame(nBytes);

    unsigned char *input = (unsigned char *)data_;
    unsigned char *output = (unsigned char *)flashData_;
    for (int bIndex = 0; bIndex < nBytes/5; bIndex++){
      this->convert10BitPacketTo12Bit(input+(bIndex*5), output+(bIndex*8));
    }

    if (status == asynSuccess){
      // Allocate NDArray memory
      dims[0] = cineBitmapHeader_.biWidth;
      dims[1] = cineBitmapHeader_.biHeight;
      setIntegerParam(NDArraySizeX, cineBitmapHeader_.biWidth);
      setIntegerParam(NDArraySizeY, cineBitmapHeader_.biHeight);
      nbytes = (dims[0] * dims[1]) * sizeof(int16_t);
      dataType= NDUInt16;
      pImage = this->pNDArrayPool->alloc(2, dims, dataType, nbytes, NULL);

      memcpy(pImage->pData, flashData_, nbytes);
      pImage->dims[0].size = dims[0];
      pImage->dims[1].size = dims[1];
      // Add the frame number attribute
      pImage->pAttributeList->add("number", "Frame number", NDAttrInt32, (void *)(&metaFrame));
      // Add the download start frame
      pImage->pAttributeList->add("rec_first_frame", "First frame of recording", NDAttrInt32, (void *)(&firstfr));
      // Add the download frame count
      pImage->pAttributeList->add("rec_frame_count", "Frame count of recording", NDAttrInt32, (void *)(&frames));
      // Add the flash filename
      char sval[256];
      strncpy(sval, (char *)filename.c_str(), 256);
      pImage->pAttributeList->add("filename", "Flash file name", NDAttrString, (void *)(sval));
      // Add the post trigger frame count
      pImage->pAttributeList->add("post_trig_frames", "Post trigger frame count", NDAttrInt32, (void *)(&postTrig));

      int tv_sec = flashTsData_[count].secs;
      pImage->pAttributeList->add("ts_sec", "Timestamp of frames (seconds since 1970)", NDAttrUInt32, (void *)(&tv_sec));
      int tv_usec = flashTsData_[count].frac;
      pImage->pAttributeList->add("ts_usec", "Timestamp of frames (microseconds)", NDAttrUInt32, (void *)(&tv_usec));

      pImage->pAttributeList->add("exp_time", "Exposure time (nanoseconds)", NDAttrUInt32, (void *)(&(flashExpData_[count])));
      pImage->pAttributeList->add("irig_sync", "IRIG synchronized", NDAttrInt8, (void *)(&(flashIrigData_[count])));
      pImage->pAttributeList->add("event_input", "Event Input (1 = open)", NDAttrInt8, (void *)(&(flashEventData_[count])));

      // Loop over meta array to create attributes
      for (int mc = 0; mc < (int)metaArray_.size(); mc++){
        if (metaArray_[mc]->type_ == NDAttrInt8){
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrInt8,
              metaArray_[mc]->vPtr_);
        } else if (metaArray_[mc]->type_ == NDAttrInt32){
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrInt32,
              metaArray_[mc]->vPtr_);
        } else if (metaArray_[mc]->type_ == NDAttrFloat64){
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrFloat64,
              metaArray_[mc]->vPtr_);
        } else if (metaArray_[mc]->type_ == NDAttrString){
          char sval[256];
          strncpy(sval, (char *)metaArray_[mc]->vPtr_, metaArray_[mc]->size_);
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrString,
              (void *)(sval));
        }
      }
      int tfts = tv_sec - flashTrigSecs_;
      int tftus = tv_usec - flashTrigUsecs_;
      if (tftus < 0){
        tfts--;
        tftus += 1000000;
      }
      int tft = (tfts * 1000000) + tftus;
      pImage->pAttributeList->add("tft", "Time from trigger (microseconds)", NDAttrInt32, (void *)(&tft));

      int ifts = tv_sec - first_tv_sec;
      int iftus = tv_usec - first_tv_usec;
      if (iftus < 0){
        ifts--;
        iftus += 1000000;
      }
      int ift = (ifts * 1000000) + iftus;
      pImage->pAttributeList->add("ift", "Inter frame time (microseconds)", NDAttrInt32, (void *)(&ift));
      first_tv_sec = tv_sec;
      first_tv_usec = tv_usec;

      getIntegerParam(NDArrayCallbacks, &arrayCallbacks);
      if (arrayCallbacks){
        // Must release the lock here, or we can get into a deadlock, because we can
        // block on the plugin lock, and the plugin can be calling us
        this->unlock();
        debug(functionName, "Calling NDArray callback");
        doCallbacksGenericPointer(pImage, NDArrayData, 0);
        this->lock();
      }

      // Free the image buffer
      pImage->release();
    }
    recordCount++;
    setIntegerParam(MIRO_CFSRecordCount_, recordCount);
    callParamCallbacks();
  }

  return status;
}

asynStatus MiroCamera::convert10BitPacketTo12Bit(void *input, void *output)
{
  const char * functionName = "convert10BitPacketTo12Bit";
  asynStatus status = asynSuccess;

  debug(functionName, "Method called");

  unsigned char *inBytes = (unsigned char *)input;
  unsigned char *outBytes = (unsigned char *)output;
  int pIndex = 0;
  int rawValue = MIRO_LinLUT[(inBytes[0]<<2) + ((inBytes[1]&0xC0)>>6)];
  outBytes[pIndex] = (rawValue&0x00FF);
  pIndex++;
  outBytes[pIndex] = (rawValue&0xFF00)>>8;
  pIndex++;

  rawValue = MIRO_LinLUT[((inBytes[1]&0x3F)<<4) + ((inBytes[2]&0xF0)>>4)];
  outBytes[pIndex] = (rawValue&0x00FF);
  pIndex++;
  outBytes[pIndex] = (rawValue&0xFF00)>>8;
  pIndex++;

  rawValue = MIRO_LinLUT[((inBytes[2]&0x0F)<<6) + ((inBytes[3]&0xFC)>>2)];
  outBytes[pIndex] = (rawValue&0x00FF);
  pIndex++;
  outBytes[pIndex] = (rawValue&0xFF00)>>8;
  pIndex++;

  rawValue = MIRO_LinLUT[((inBytes[3]&0x03)<<8) + inBytes[4]];
  outBytes[pIndex] = (rawValue&0x00FF);
  pIndex++;
  outBytes[pIndex] = (rawValue&0xFF00)>>8;
  pIndex++;

  return status;
}

asynStatus MiroCamera::readoutTimestamps(int cine, int start, int end)
{
  const char * functionName = "MiroCamera::readoutTimestamps";
  char command[MIRO_MAX_STRING];
  int nBytes = 0;
  std::string response;
  int frames = end - start + 1;
  short_time_stamp32 ts;
  asynStatus status = asynSuccess;


  // Flush the data connection
  pasynOctetSyncIO->flush(dataChannel_);
  // Clear any old timestamp data out
  timestampData_.clear();

  sprintf(command, "time {cine:%d, start:%d, cnt:%d}", cine, start, frames);
  status = sendSimpleCommand(command, &response);
  debug(functionName, "Response", response);

  // Read back all of the timestamps in one go
  nBytes = frames * 12;
  status = this->readFrame(nBytes);
  char *dPtr = data_;
  for (int frame = 0; frame < frames; frame++){
    memcpy(&ts, dPtr, 12);
    // time from beginning of the year in 1/100 sec units
    //printf("Time sec 1/100: %u\n", ntohl(ts.csecs));
    // exposure time in us
    //printf("Exp time us: %d\n", ts.exptime);
    // bits[15..2]: fractions (us to 10000); b[1]:event; b[0]:lock
    //printf("Fractions us to 10000: %u\n", ntohs(ts.frac)>>2);
    // exposure extension up to 32 bits
    //printf("Exposure extension: %d\n", ts.exptime32);
    //uint32_t ns_exp = (ntohs(ts.exptime)*1000) + (int)(floor((double)ntohs(ts.exptime32)/65535.0*1000.0 + 0.5));
    //printf("Total Exposure ns: %d\n", ns_exp);
    // fractions extension up to 32 bits
    //printf("Fractions extension: %d\n", ts.frac32);
    dPtr+=12;
    timestampData_.push_back(ts);
  }

  return status;
}

asynStatus MiroCamera::readoutDataStream(int cine, int start, int end)
{
  const char * functionName = "MiroCamera::readoutDataStream";
  char command[MIRO_MAX_STRING];
  int width = 0;
  int height = 0;
  int nBytes = 0;
  int frame = 0;
  std::string response;
  NDArray *pImage;
  size_t dims[2];
  NDDataType_t dataType;
  int nbytes;
  int arrayCallbacks   = 0;
  int frames = end - start + 1;
  int metaExposure = 0;
  int metaRate = 0;
  int metaFrame = 0;
  int lastfr = 0;
  int irigYear = 0;
  int trigSecs = 0;
  int trigUSecs = 0;
  unsigned int first_tv_sec = 0;
  unsigned int first_tv_usec = 0;
  asynStatus status = asynSuccess;

  // Read the meta data
  sprintf(command, "c%d.rate", cine);
  status = stringToInteger(paramMap_[command].getValue(), metaRate);
  sprintf(command, "c%d.exp", cine);
  status = stringToInteger(paramMap_[command].getValue(), metaExposure);
  sprintf(command, "c%d.lastfr", cine);
  status = stringToInteger(paramMap_[command].getValue(), lastfr);
  lastfr++;

  status = getCameraDataStruc("irig", paramMap_);
  status = stringToInteger(paramMap_["irig.yearbegin"].getValue(), irigYear);
  sprintf(command, "c%d.trigtime.secs", cine);
  status = stringToInteger(paramMap_[command].getValue(), trigSecs);
  sprintf(command, "c%d.trigtime.frac", cine);
  status = stringToInteger(paramMap_[command].getValue(), trigUSecs);

  // Loop over meta array to read values
  for (int mc = 0; mc < (int)metaArray_.size(); mc++){
    sprintf(command, metaArray_[mc]->param_.c_str(), cine);
    metaArray_[mc]->setStringVal(paramMap_[command].getValue());
  }

  // Read the frame size for the selected cine
  getIntegerParam(MIRO_CnWidth_[cine], &width);
  getIntegerParam(MIRO_CnHeight_[cine], &height);
  // Calculate the number of bytes to read
  // In packet format there are 10 bits per pixel,
  // which equates to 1.25 bytes
  nBytes = (int)((double)width * (double)height * 1.25);
  debug(functionName, "Width", width);
  debug(functionName, "Height", height);
  debug(functionName, "nBytes", nBytes);

  // Flush the data connection
  pasynOctetSyncIO->flush(dataChannel_);

  sprintf(command, "img {cine:%d, start:%d, cnt:%d, fmt:P10}", cine, start, frames);
  status = sendSimpleCommand(command, &response);
  debug(functionName, "Response", response);

  if (frame == 0){
    short_time_stamp32 tss = timestampData_[0];
    first_tv_sec = (ntohl(tss.csecs) / 100) + irigYear;
    first_tv_usec = ((ntohl(tss.csecs) % 100) * 10000) + (ntohs(tss.frac) >> 2);
  }
  //for (int frame = 0; frame < frames; frame++){
  while ((frame < frames) && (status == asynSuccess)){
    metaFrame = start+frame;
    frame++;
    setIntegerParam(MIRO_CineRecordCount_, frame);
    callParamCallbacks();
    status = this->readFrame(nBytes);

    unsigned char *input = (unsigned char *)data_;
    unsigned char *output = (unsigned char *)flashData_;
    for (int bIndex = 0; bIndex < nBytes/5; bIndex++){
      this->convert10BitPacketTo12Bit(input+(bIndex*5), output+(bIndex*8));
    }

    if (status == asynSuccess){
      // Allocate NDArray memory
      dims[0] = width;
      dims[1] = height;
      setIntegerParam(NDArraySizeX, width);
      setIntegerParam(NDArraySizeY, height);
      nbytes = (dims[0] * dims[1]) * sizeof(int16_t);
      dataType= NDUInt16;
      pImage = this->pNDArrayPool->alloc(2, dims, dataType, nbytes, NULL);

      memcpy(pImage->pData, flashData_, nbytes);
      pImage->dims[0].size = dims[0];
      pImage->dims[1].size = dims[1];
      // Add the frame number attribute
      pImage->pAttributeList->add("number", "Frame number", NDAttrInt32, (void *)(&metaFrame));
      // Add the download start frame
      pImage->pAttributeList->add("rec_first_frame", "First frame of recording", NDAttrInt32, (void *)(&start));
      // Add the download frame count
      pImage->pAttributeList->add("rec_frame_count", "Frame count of recording", NDAttrInt32, (void *)(&frames));
      // Add the partition number
      pImage->pAttributeList->add("partition", "Partition number", NDAttrInt32, (void *)(&cine));
      // Add the post trigger frame count
      pImage->pAttributeList->add("post_trig_frames", "Post trigger frame count", NDAttrInt32, (void *)(&lastfr));
      // Add the image UniqueID
      pImage->pAttributeList->add("NDArrayUniqueId", "uniqueId", NDAttrInt32, (void *)(&frame));      // Loop over meta array to create attributes
      pImage->uniqueId = frame;
      for (int mc = 0; mc < (int)metaArray_.size(); mc++){
        if (metaArray_[mc]->type_ == NDAttrInt8){
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrInt8,
              (void *)(&metaArray_[mc]->cval_));
        } else if (metaArray_[mc]->type_ == NDAttrInt32){
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrInt32,
              (void *)(&metaArray_[mc]->ival_));
        } else if (metaArray_[mc]->type_ == NDAttrFloat64){
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrFloat64,
              (void *)(&metaArray_[mc]->dval_));
        } else if (metaArray_[mc]->type_ == NDAttrString){
          char sval[256];
          strncpy(sval, metaArray_[mc]->sval_.c_str(), 256);
          pImage->pAttributeList->add(metaArray_[mc]->name_.c_str(),
              metaArray_[mc]->desc_.c_str(),
              NDAttrString,
              (void *)(sval));
        }
      }

      // Add the timing attributes
      short_time_stamp32 ts = timestampData_[frame-1];
      unsigned int tv_sec = (ntohl(ts.csecs) / 100) + irigYear;
      pImage->pAttributeList->add("ts_sec", "Timestamp of frames (seconds since 1970)", NDAttrUInt32, (void *)(&tv_sec));
      unsigned int tv_usec = ((ntohl(ts.csecs) % 100) * 10000) + (ntohs(ts.frac) >> 2);
      pImage->pAttributeList->add("ts_usec", "Timestamp of frames (microseconds)", NDAttrUInt32, (void *)(&tv_usec));
      char locked = ntohs(ts.frac) & 0x01;
      pImage->pAttributeList->add("irig_sync", "IRIG synchronized", NDAttrInt8, (void *)(&locked));
      char event_active = (ntohs(ts.frac) & 0x02) >> 1;
      pImage->pAttributeList->add("event_input", "Event Input (1 = open)", NDAttrInt8, (void *)(&event_active));
      //unsigned int exp_time = ntohs(ts.exptime);
      unsigned int exp_time = (ntohs(ts.exptime)*1000) + (int)(floor((double)ntohs(ts.exptime32)/65535.0*1000.0 + 0.5));
      pImage->pAttributeList->add("exp_time", "Exposure time (nanoseconds)", NDAttrUInt32, (void *)(&exp_time));
      int tfts = tv_sec - trigSecs;
      int tftus = tv_usec - trigUSecs;
      if (tftus < 0){
        tfts--;
        tftus += 1000000;
      }
      int tft = (tfts * 1000000) + tftus;
      pImage->pAttributeList->add("tft", "Time from trigger (microseconds)", NDAttrInt32, (void *)(&tft));

      int ifts = tv_sec - first_tv_sec;
      int iftus = tv_usec - first_tv_usec;
      if (iftus < 0){
        ifts--;
        iftus += 1000000;
      }
      int ift = (ifts * 1000000) + iftus;
      pImage->pAttributeList->add("ift", "Inter frame time (microseconds)", NDAttrInt32, (void *)(&ift));
      first_tv_sec = tv_sec;
      first_tv_usec = tv_usec;

      getIntegerParam(NDArrayCallbacks, &arrayCallbacks);
      if (arrayCallbacks){
        // Must release the lock here, or we can get into a deadlock, because we can
        // block on the plugin lock, and the plugin can be calling us
        this->unlock();
        debug(functionName, "Calling NDArray callback");
        doCallbacksGenericPointer(pImage, NDArrayData, 0);
        this->lock();
      }

      // Free the image buffer
      pImage->release();
    }
  }
  setIntegerParam(MIRO_CineRecordCount_, 0);
  callParamCallbacks();

  return status;
}

asynStatus MiroCamera::readFrame(int bytes)
{
  const char * functionName = "MiroCamera::readFrame";
  size_t nread = 0;
  int eomReason = 0;
  std::string response;
  asynStatus status = asynSuccess;

  char *dataPtr = data_;
  int totalRead = 0;
  //printf("Bytes to read: %d\n", (int)bytes);
  while (status == asynSuccess && totalRead < bytes){
    status = pasynOctetSyncIO->read(dataChannel_,
                                    dataPtr,
                                    (bytes-totalRead),
                                    MIRO_TIMEOUT,
                                    &nread,
                                    &eomReason);

    //printf("Read status %d\n", (int)status);
    debug(functionName, "Read status", (int)status);
    debug(functionName, "nread", (int)nread);
    debug(functionName, "eomReason", (int)eomReason);
    totalRead += nread;
    debug(functionName, "total read bytes", (int)totalRead);
    dataPtr += nread;
  }
  return status;
}

asynStatus MiroCamera::updatePreviewCine()
{
  const char * functionName = "MiroCamera::updatePreviewCine";
  asynStatus status = asynSuccess;
  std::string param = "";

  // Read out the preview cine status
  status = getCameraDataStruc("c0", paramMap_);

  if (status == asynSuccess){
    // Setup the preview cine width and height
    param = paramMap_["c0.res"].getValue();
    // This will contain a string like 1200 x 800, split by the x
    if (param.find_first_of("x") != std::string::npos){
      int width = 0;
      int height = 0;
      std::string sw = param.substr(0, param.find_first_of("x"));
      std::string sh = param.substr(param.find_first_of("x")+1);
      cleanString(sw, " ");
      cleanString(sh, " ");
      debug(functionName, "Preview width", sw);
      debug(functionName, "Preview height", sh);
      status = stringToInteger(sw, width);
      previewWidth_ = width;
      status = stringToInteger(sh, height);
      previewHeight_ = height;
    }
  }
  return status;
}

asynStatus MiroCamera::updateCine(int cine)
{
  const char * functionName = "MiroCamera::updateCine";
  asynStatus status = asynSuccess;
  std::string param = "";
  char cmd[MAX_STRING_SIZE];

  // Prepare the cine string
  sprintf(cmd, "c%d", cine);
  // Read out the preview cine status
  status = getCameraDataStruc(cmd, paramMap_);

  if (status == asynSuccess){
    // Update the cine last frame
    sprintf(cmd, "c%d.meta.name", cine);
    std::string sname = paramMap_[cmd].getValue();
    cleanString(sname, " ");
    setStringParam(MIRO_CnName_[cine], sname.c_str());
  }

  if (status == asynSuccess){
    // Setup the preview cine width and height
    sprintf(cmd, "c%d.res", cine);
    param = paramMap_[cmd].getValue();
    // This will contain a string like 1200 x 800, split by the x
    if (param.find_first_of("x") != std::string::npos){
      int width = 0;
      int height = 0;
      std::string sw = param.substr(0, param.find_first_of("x"));
      std::string sh = param.substr(param.find_first_of("x")+1);
      cleanString(sw, " ");
      cleanString(sh, " ");
      debug(functionName, "Cine", cine);
      debug(functionName, "   Width", sw);
      debug(functionName, "   Height", sh);
      status = stringToInteger(sw, width);
      status = stringToInteger(sh, height);
      setIntegerParam(MIRO_CnWidth_[cine], width);
      setIntegerParam(MIRO_CnHeight_[cine], height);
    }
  }
  if (status == asynSuccess){
    // Read out the cine status
    int cineState = 0;
    sprintf(cmd, "c%d.state", cine);
    // Decode the status
    debug(functionName, paramMap_[cmd].getValue().c_str());
    cineStates(paramMap_[cmd].getValue(), cineState);
    setIntegerParam(MIRO_CnStatus_[cine], cineState);
  }

  if (status == asynSuccess){
    // Update the cine frame count
    int frCount = 0;
    sprintf(cmd, "c%d.frcount", cine);
    std::string sfrCount = paramMap_[cmd].getValue();
    cleanString(sfrCount, " ");
    status = stringToInteger(sfrCount, frCount);
    setIntegerParam(MIRO_CnFrameCount_[cine], frCount);
  }

  if (status == asynSuccess){
    // Update the cine first frame
    int firstFr = 0;
    sprintf(cmd, "c%d.firstfr", cine);
    std::string sfirstFr = paramMap_[cmd].getValue();
    cleanString(sfirstFr, " ");
    status = stringToInteger(sfirstFr, firstFr);
    setIntegerParam(MIRO_CnFirstFrame_[cine], firstFr);
  }

  if (status == asynSuccess){
    // Update the cine last frame
    int lastFr = 0;
    sprintf(cmd, "c%d.lastfr", cine);
    std::string slastFr = paramMap_[cmd].getValue();
    cleanString(slastFr, " ");
    status = stringToInteger(slastFr, lastFr);
    setIntegerParam(MIRO_CnLastFrame_[cine], lastFr);
  }

  callParamCallbacks();

  return status;
}

asynStatus MiroCamera::selectCine(int cine)
{
  const char * functionName = "MiroCamera::selectCine";
  asynStatus status = asynSuccess;
  char command[256];
  std::string param = "";
  int maxCines = 1;

  // Get the number of cines available
  getIntegerParam(MIRO_GetCineCount_, &maxCines);
  if (cine < 1){
    setStringParam(ADStatusMessage, "Cannot select cine 0");
    setIntegerParam(ADStatus, ADStatusError);
    status = asynError;
  }
  if (cine > maxCines){
    setStringParam(ADStatusMessage, "Invalid cine cannot be selected");
    setIntegerParam(ADStatus, ADStatusError);
    status = asynError;
  }

  if (status == asynSuccess){
    // Create the cine string
    sprintf(command, "c%d", cine);
    // Read out the cine status
    status = getCameraDataStruc(command, paramMap_);

    // Now setup the selected cine width, height, frame count, start and end frames
    sprintf(command, "c%d.res", cine);
    param = paramMap_[command].getValue();
    // This will contain a string like 1200 x 800, split by the x
    if (param.find_first_of("x") != std::string::npos){
      int width = 0;
      int height = 0;
      std::string sw = param.substr(0, param.find_first_of("x"));
      std::string sh = param.substr(param.find_first_of("x")+1);
      cleanString(sw, " ");
      cleanString(sh, " ");
      debug(functionName, "Cine width", sw);
      debug(functionName, "Cine height", sh);
      status = stringToInteger(sw, width);
      setIntegerParam(MIRO_CineWidth_, width);
      status = stringToInteger(sh, height);
      setIntegerParam(MIRO_CineHeight_, height);
    }

    // Update the cine frame count
    sprintf(command, "c%d.frcount", cine);
    std::string sfrCount = paramMap_[command].getValue();
    int frCount = 0;
    cleanString(sfrCount, " ");
    status = stringToInteger(sfrCount, frCount);
    setIntegerParam(MIRO_CineFrameCount_, frCount);

    // Update the cine first frame
    sprintf(command, "c%d.firstfr", cine);
    std::string sfirstFr = paramMap_[command].getValue();
    //std::cout<<"sfirstFr: "<<sfirstFr<<std::endl;
    int firstFr = 0;
    cleanString(sfirstFr, " ");
    status = stringToInteger(sfirstFr, firstFr);
    //std::cout<<"Setting MIRO_CineFirstFrame_ to "<<firstFr<<std::endl;
    setIntegerParam(MIRO_CineFirstFrame_, firstFr);

    // Update the cine last frame
    sprintf(command, "c%d.lastfr", cine);
    std::string slastFr = paramMap_[command].getValue();
    int lastFr = 0;
    cleanString(slastFr, " ");
    status = stringToInteger(slastFr, lastFr);
    setIntegerParam(MIRO_CineLastFrame_, lastFr);
  }

  return status;
}

asynStatus MiroCamera::setPartition(int count)
{
  const char * functionName = "MiroCamera::setPartition";
  asynStatus status = asynSuccess;
  char command[256];
  std::string response = "";
  int cCine = 1;

  // Get the current partition size
  getIntegerParam(MIRO_SelectedCine_, &cCine);

  // Create the cine string
  sprintf(command, "%s %d", MIRO_CMD_PARTITION, count);
  // Read out the cine status
  status = sendSimpleCommand(command, &response);
  debug(functionName, "Response", response);

  if (status == asynSuccess){
    // If the new partition is less than the selected cine
    // set a new selected cine
    if (count < cCine){
      status = selectCine(count);
      setIntegerParam(MIRO_SelectedCine_, count);
    }
  }
  return status;
}

asynStatus MiroCamera::updateFlash()
{
  const char * functionName = "MiroCamera::updateFlash";
  asynStatus status = asynSuccess;
  std::string data;
  std::vector<std::string> names;
  std::vector<miroVal> values;

  debug(functionName, "Method called");

  // Read out the flash status
  status = getCameraDataStruc("cf", paramMap_);

  if (status == asynSuccess){
    // Update the flash state
    int state = 0;
    std::string sstate = paramMap_["cf.state"].getValue();
    cleanString(sstate, " ");
    status = stringToInteger(sstate, state);
    setIntegerParam(MIRO_CFState_, state);
  }

  if (status == asynSuccess){
    // Update the flash action
    int action = 0;
    std::string saction = paramMap_["cf.action"].getValue();
    cleanString(saction, " ");
    status = stringToInteger(saction, action);
    setIntegerParam(MIRO_CFAction_, action);
  }

  if (status == asynSuccess){
    // Update the flash size
    int size = 0;
    std::string ssize = paramMap_["cf.size"].getValue();
    cleanString(ssize, " ");
    status = stringToInteger(ssize, size);
    setIntegerParam(MIRO_CFSize_, size);
  }

  if (status == asynSuccess){
    // Update the flash used memory
    int used = 0;
    std::string sused = paramMap_["cf.used"].getValue();
    cleanString(sused, " ");
    status = stringToInteger(sused, used);
    setIntegerParam(MIRO_CFUsed_, used);
  }

  if (status == asynSuccess){
    // Update the flash progress
    int prog = 0;
    std::string sprog = paramMap_["cf.progress"].getValue();
    cleanString(sprog, " ");
    status = stringToInteger(sprog, prog);
    setIntegerParam(MIRO_CFProgress_, prog);
  }

  if (status == asynSuccess){
    // Update the flash error code
    int err = 0;
    std::string serr = paramMap_["cf.errcode"].getValue();
    cleanString(serr, " ");
    status = stringToInteger(serr, err);
    setIntegerParam(MIRO_CFError_, err);
  }

  // Require vector of file set information
  fileInfoSet_.clear();
  std::vector<std::string> fileInfo;
  int item = 0;
  // Read out the file list
  status = sendSimpleCommand(MIRO_CMD_CFLS, &data);
  // Strip out unwanted characters
  std::string iline = stripControl(data);
  iline = deleteParen(iline);
  // Parse the structure
  parseDataStruc(iline, names, values);
  while (iline.find(",") != std::string::npos){
    std::string value = iline.substr(0, iline.find(","));
    fileInfo.push_back(stripControl(value, " \""));
    item++;
    if (item == 3){
      item = 0;
      fileInfoSet_.push_back(fileInfo);
      fileInfo.clear();
    }
    iline = iline.substr(iline.find(",")+1);
  }
  if (item == 2){
    fileInfo.push_back(stripControl(iline, " \""));
    fileInfoSet_.push_back(fileInfo);
  }
  updateFlashFileTable();

  callParamCallbacks();

  return status;
}

asynStatus MiroCamera::updateFlashFileTable()
{
  const char * functionName = "MiroCamera::updateFlashFileTable";
  asynStatus status = asynSuccess;

  debug(functionName, "Number of files", (int)fileInfoSet_.size());
  setIntegerParam(MIRO_CFNumFiles_, fileInfoSet_.size());
  int max_pages = (fileInfoSet_.size() / 8) + (fileInfoSet_.size() % 8 == 0?0:1);
  if (max_pages == 0){
    max_pages = 1;
  }
  setIntegerParam(MIRO_CFMaxPages_, max_pages);
  int current_page = 0;
  // Check the page number
  getIntegerParam(MIRO_CFCurPage_, &current_page);
  if (current_page > max_pages){
    current_page = max_pages;
  }
  if (current_page == 0){
    current_page = 1;
  }
  setIntegerParam(MIRO_CFCurPage_, current_page);

  for (int index=0; index < 8; index++ ){
    int pindex = ((current_page - 1) * 8) + index;
    if (pindex < (int)fileInfoSet_.size()){
      setStringParam(MIRO_CfFileName_[index], (fileInfoSet_[pindex][0]).c_str());
      setStringParam(MIRO_CfFileSize_[index], (fileInfoSet_[pindex][1]).c_str());
      setStringParam(MIRO_CfFileDate_[index], (fileInfoSet_[pindex][2]).c_str());
    } else {
      setStringParam(MIRO_CfFileName_[index], "");
      setStringParam(MIRO_CfFileSize_[index], "");
      setStringParam(MIRO_CfFileDate_[index], "");
    }
  }
  return status;
}

asynStatus MiroCamera::updateAutoStatus()
{
  const char * functionName = "MiroCamera::updateAutotatus";
  asynStatus status = asynSuccess;

  debug(functionName, "Method called");

  // Read out the flash status
  status = getCameraDataStruc("auto", paramMap_);

  if (status == asynSuccess){
    // Update the sensor temperature
    status = this->updateIntegerParameter("auto.filesave", MIRO_AutoSave_);
  }
  if (status == asynSuccess){
    // Update the sensor temperature
    status = this->updateIntegerParameter("auto.acqrestart", MIRO_AutoRestart_);
  }
  if (status == asynSuccess){
    // Update the sensor temperature
    status = this->updateIntegerParameter("auto.bref", MIRO_AutoCSR_);
  }
  if (status == asynSuccess){
    // Update the sensor temperature
    status = this->updateIntegerParameter("auto.bref_progress", MIRO_CSRCount_);
  }
  return status;
}

asynStatus MiroCamera::updateInfoStatus()
{
  const char * functionName = "MiroCamera::updateInfoStatus";
  asynStatus status = asynSuccess;

  debug(functionName, "Method called");

  // Read out the flash status
  status = getCameraDataStruc("info", paramMap_);

  if (status == asynSuccess){
    // Update the sensor temperature
    status = this->updateIntegerParameter("info.snstemp", MIRO_InfoSensorTemp_);
  }
  if (status == asynSuccess){
    // Update the thermo power
    status = this->updateIntegerParameter("info.tepower", MIRO_InfoThermoPower_);
  }
  if (status == asynSuccess){
    // Update the camera temperature
    status = this->updateIntegerParameter("info.camtemp", MIRO_InfoCameraTemp_);
  }
  if (status == asynSuccess){
    // Update the fan power
    status = this->updateIntegerParameter("info.fanpower", MIRO_InfoFanPower_);
  }

  return status;
}

asynStatus MiroCamera::updateCameraStatus()
{
  const char * functionName = "MiroCamera::updateCameraStatus";
  asynStatus status = asynSuccess;

  debug(functionName, "Method called");

  // Read out the camera status
  status = getCameraDataStruc("cam", paramMap_);

  if (status == asynSuccess){
    // Update the sync image value
    status = this->updateIntegerParameter("cam.syncimg", MIRO_CamExtSync_);
  }
  if (status == asynSuccess){
    // Update the frame delay
    status = this->updateIntegerParameter("cam.frdelay", MIRO_CamFrameDelay_);
  }
  if (status == asynSuccess){
    // Update the trigger edge
    status = this->updateIntegerParameter("cam.trigpol", MIRO_CamTriggerEdge_);
  }
  if (status == asynSuccess){
    // Update the trigger filter
    status = this->updateIntegerParameter("cam.trigfilt", MIRO_CamTriggerFilter_);
  }
  if (status == asynSuccess){
    // Update the ready signal
    status = this->updateIntegerParameter("cam.longready", MIRO_CamReadySignal_);
  }
  if (status == asynSuccess){
    // Update the aux pin
    status = this->updateIntegerParameter("cam.aux1mode", MIRO_CamAuxPin_);
  }

  return status;
}

asynStatus MiroCamera::updateDefcStatus()
{
  const char * functionName = "MiroCamera::updateDefcStatus";
  std::string param = "";
  asynStatus status = asynSuccess;

  // Read out the camera status
  status = getCameraDataStruc("defc", paramMap_);

  if (status == asynSuccess){
    // Update the post trigger frame count
    status = this->updateIntegerParameter("defc.ptframes", MIRO_PostTrigCount_);
  }

  if (status == asynSuccess){
    // Update the post trigger frame count
    status = this->updateIntegerParameter("defc.frcount", MIRO_MaxFrameCount_);
  }

  if (status == asynSuccess){
    // Update the extended dynamic range
    status = this->updateIntegerParameter("defc.edrexp", MIRO_EDR_);
  }

  if (status == asynSuccess){
    // Update the acquire time
    int exposure = 0;
    double value = 0.0;
    stringToInteger(paramMap_["defc.exp"].getValue(), exposure);
    value = (double)exposure/1000000000.0;
    setDoubleParam(ADAcquireTime, (double)exposure/1000000000.0);
  }

  if (status == asynSuccess){
    // Update the number of frames per second
    double fps = 0;
    double value = 0.0;
    stringToDouble(paramMap_["defc.rate"].getValue(), fps);
    value = (double)1.0/(double)(fps);
    setDoubleParam(ADAcquirePeriod, value);
  }

  // Now parse the resolution
  if (status == asynSuccess){
    // Setup the preview cine width and height
    param = paramMap_["defc.res"].getValue();
    // This will contain a string like 1200 x 800, split by the x
    if (param.find_first_of("x") != std::string::npos){
      int width = 0;
      int height = 0;
      std::string sw = param.substr(0, param.find_first_of("x"));
      std::string sh = param.substr(param.find_first_of("x")+1);
      cleanString(sw, " ");
      cleanString(sh, " ");
      debug(functionName, "Selected Width", sw);
      debug(functionName, "Selected Height", sh);
      status = stringToInteger(sw, width);
      status = stringToInteger(sh, height);
      setIntegerParam(ADSizeX, width);
      setIntegerParam(ADSizeY, height);
    }
  }
  return status;
}

asynStatus MiroCamera::updateMetaStatus()
{
  const char * functionName = "MiroCamera::updateMetaStatus";
  std::string param = "";
  asynStatus status = asynSuccess;

  debug(functionName, "Method called");

  // Read out the camera status
  status = getCameraDataStruc("meta", paramMap_);

  if (status == asynSuccess){
    // Update the cine name prefix
    status = this->updateStringParameter("meta.name", MIRO_CineName_);
  }

  return status;
}

asynStatus MiroCamera::updateIntegerParameter(const std::string& name, int paramID)
{
  const char * functionName = "MiroCamera::updateIntegerParameter";
  asynStatus status = asynSuccess;
  int value = 0;

  debug(functionName, "Name", name);
  debug(functionName, "paramID", paramID);

  std::string svalue = paramMap_[name].getValue();
  cleanString(svalue, " ");
  status = stringToInteger(svalue, value);
  setIntegerParam(paramID, value);
  return status;
}

asynStatus MiroCamera::updateStringParameter(const std::string& name, int paramID)
{
  const char * functionName = "MiroCamera::updateStringParameter";
  asynStatus status = asynSuccess;

  debug(functionName, "Name", name);
  debug(functionName, "paramID", paramID);
  std::string svalue = paramMap_[name].getValue();
  setStringParam(paramID, svalue.c_str());
  return status;
}

asynStatus MiroCamera::getCameraDataStruc(const std::string& strucName, std::map<std::string, miroVal>& params)
{
  const char * functionName = "MiroCamera::getCameraDataStruc";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_GET_VALUE;
  std::vector<std::string> names;
  std::vector<miroVal> values;
  unsigned int j;
  
  debug(functionName, "Method called");

  data.resize(8192);
  status = sendSimpleCommand(cmd + " " + strucName, &data);
  std::string iline = stripControl(data);          // Delete unwanted chars from the received data
  j = 0;
  parseDataStruc(iline, names, values);
  //std::cout << "getCameraDataStruc. Total " << names.size() << " data items." << '\n';
  for (j=0; j < names.size(); j++ ) {
    //std::cout << "getCameraDataStruc. " << names[j] << " = " << values[j].getValue() << '\n';
      params[names[j]] = values[j];  // Store in a Map structure
  }
  return status;  
}

asynStatus MiroCamera::getCameraParameter(const std::string& name, int &value)
{
  const char * functionName = "MiroCamera::getCameraParameter";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_GET_VALUE;
  
  debug(functionName, "Parameter", name);
  status = sendSimpleCommand(cmd + " ParameterName:\"" + name + "\"", &data);
  if (status == asynSuccess){
    if (data == "\"false\""){
      value = 0;
    } else if (data == "\"true\""){
      value = 1;
    } else {
//      status = readIntegerData(data, "Value", value);
    }
  }
  return status;
}

asynStatus MiroCamera::getCameraParameter(const std::string& name, double &value)
{
  const char * functionName = "MiroCamera::getCameraParameter";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_GET_VALUE;

  debug(functionName, "Parameter", name);
  status = sendSimpleCommand(cmd + " ParameterName:\"" + name + "\"", &data);
  if (status == asynSuccess){
//    status = readDoubleData(data, "Value", value);
  }
  return status;
}

asynStatus MiroCamera::getCameraParameter(const std::string& name, std::string &value)
{
  const char * functionName = "MiroCamera::getCameraParameter";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_GET_VALUE;

  debug(functionName, "Parameter", name);
  status = sendSimpleCommand(cmd + " ParameterName:\"" + name + "\"", &data);
  if (status == asynSuccess){
    value = data;
    cleanString(value, "\"");
  }
  return status;
}

asynStatus MiroCamera::getCameraParameter(const std::string& name, bool &value)
{
  const char * functionName = "MiroCamera::getCameraParameter (bool)";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_GET_VALUE;

  debug(functionName, "Parameter", name);
  status = sendSimpleCommand(cmd + " ParameterName:\"" + name + "\"", &data);
  if (status == asynSuccess){
      if (data == "\"false\""){
        value = true;
      } else if (data == "\"true\""){
        value = false;
      } else {
	debug(functionName, "Invalid value returned for bool parameter: ", data);
	status = asynError;
      }
  }
  return status;
}

asynStatus MiroCamera::setCameraParameter(const std::string& name, int value)
{
  const char * functionName = "MiroCamera::setCameraParameter";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_SET_VALUE;
  std::stringstream svalue;
  
  debug(functionName, "Parameter", name);
  debug(functionName, "Value", value);
  svalue << value;
  status = sendSimpleCommand(cmd + " " + name + " " + svalue.str(), &data);
  return status;
}

asynStatus MiroCamera::setCameraParameter(const std::string& name, double value)
{
  const char * functionName = "MiroCamera::setCameraParameter";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_SET_VALUE;
  std::stringstream svalue;
  
  debug(functionName, "Parameter", name);
  debug(functionName, "Value", value);
  svalue << value;
  status = sendSimpleCommand(cmd + " ParameterName:\"" + name + "\"" + " Value:" + svalue.str(), &data);
  return status;
}

asynStatus MiroCamera::setCameraParameter(const std::string& name, std::string value)
{
  const char * functionName = "MiroCamera::setCameraParameter";
  asynStatus status = asynSuccess;
  std::string data;
  std::string cmd = MIRO_CMD_SET_VALUE;
  
  debug(functionName, "Parameter", name);
  debug(functionName, "Value", value);
  status = sendSimpleCommand(cmd + " " + name + " \"" + value + "\"", &data);
  return status;
}

asynStatus MiroCamera::cineStates(const std::string& states, int &mask)
{
  const char * functionName = "MiroCamera::cineStates";
  asynStatus status = asynSuccess;
  mask = 0;

  if (checkState(states, "INV")){
    mask += MIRO_CINE_STATE_INV;
  }
  if (checkState(states, "STR")){
    mask += MIRO_CINE_STATE_STR;
  }
  if (checkState(states, "WTR")){
    mask += MIRO_CINE_STATE_WTR;
  }
  if (checkState(states, "TRG")){
    mask += MIRO_CINE_STATE_TRG;
  }
  if (checkState(states, "RDY")){
    mask += MIRO_CINE_STATE_RDY;
  }
  if (checkState(states, "DEF")){
    mask += MIRO_CINE_STATE_DEF;
  }
  if (checkState(states, "ABL")){
    mask += MIRO_CINE_STATE_ABL;
  }
  if (checkState(states, "PRE")){
    mask += MIRO_CINE_STATE_PRE;
  }
  if (checkState(states, "ACT")){
    mask += MIRO_CINE_STATE_ACT;
  }
  if (checkState(states, "REU")){
    mask += MIRO_CINE_STATE_REU;
  }
  debug(functionName, "State value", mask);
  return status;
}

bool MiroCamera::checkState(const std::string &state, const std::string &item)
{
  bool found = false;
  // Clean up from the front of the string
  if (state.find(item) != std::string::npos){
    found = true;
  }
  return found;
}

asynStatus MiroCamera::stringToInteger(const std::string& name, int &value)
{
  const char * functionName = "MiroCamera::stringToInteger";
  asynStatus status = asynSuccess;

  std::stringstream integerValueStream(name);
  integerValueStream >> value;
  if (integerValueStream.fail()){
    status = asynError;
    debug(functionName, "Failed to decode stream into integer", integerValueStream.str());
  }
  return status;
}

asynStatus MiroCamera::stringToDouble(const std::string& name, double &value)
{
  const char * functionName = "MiroCamera::stringToDouble";
  asynStatus status = asynSuccess;

  std::stringstream doubleValueStream(name);
  doubleValueStream >> value;
  if (doubleValueStream.fail()){
    status = asynError;
    debug(functionName, "Failed to decode stream into integer", doubleValueStream.str());
  }
  return status;
}

asynStatus MiroCamera::readIntegerData(std::map<std::string, std::string> data, const std::string& name, int &value)
{
  const char * functionName = "MiroCamera::readIntegerData";
  asynStatus status = asynSuccess;

  std::stringstream integerValueStream(data[name]);
  integerValueStream >> value;
  if (integerValueStream.fail()){
    status = asynError;
    debug(functionName, "Failed to decode stream into integer", integerValueStream.str());
  }
  return status;
}

asynStatus MiroCamera::readDoubleData(std::map<std::string, std::string> data, const std::string& name, double &value)
{
  const char * functionName = "MiroCamera::readDoubleData";
  asynStatus status = asynSuccess;

  std::stringstream doubleValueStream(data[name]);
  doubleValueStream >> value;
  if (doubleValueStream.fail()){
    status = asynError;
    debug(functionName, "Failed to decode stream into double", doubleValueStream.str());
  }
  return status;
}


asynStatus MiroCamera::initDebugger(int initDebug)
{
  // Set all debugging levels to initialised value
  debugLevel("all", initDebug);
  return asynSuccess;
}

asynStatus MiroCamera::debugLevel(const std::string& method, int onOff)
{
  if (method == "all"){
    debugMap_["MiroCamera::MiroCamera"]               = onOff;
    debugMap_["MiroCamera::miroCameraTask"]           = onOff;
    debugMap_["MiroCamera::miroPreviewTask"]          = onOff;
    debugMap_["MiroCamera::readoutPreviewData"]       = onOff;
    debugMap_["MiroCamera::readFrame"]                = onOff;
    debugMap_["MiroCamera::downloadFlashFile"]        = onOff;
    debugMap_["MiroCamera::connect"]                  = onOff;    
    debugMap_["MiroCamera::readEnum"]                 = onOff;
    debugMap_["MiroCamera::writeInt32"]               = onOff;
    debugMap_["MiroCamera::writeFloat64"]             = onOff;
    debugMap_["MiroCamera::validateSpectrum"]         = onOff;
    debugMap_["MiroCamera::defineSpectrumFAT"]        = onOff;
    debugMap_["MiroCamera::defineSpectrumSFAT"]       = onOff;
    debugMap_["MiroCamera::defineSpectrumFRR"]        = onOff;
    debugMap_["MiroCamera::defineSpectrumFE"]         = onOff;
    debugMap_["MiroCamera::readAcquisitionData"]      = onOff;
    debugMap_["MiroCamera::sendSimpleCommand"]        = onOff;
    debugMap_["MiroCamera::getCameraDataStruc"]       = onOff;
    debugMap_["MiroCamera::setupEPICSParameters"]     = onOff;
    debugMap_["MiroCamera::readoutDataStream"]        = onOff;
    debugMap_["MiroCamera::getCameraParameterType"]   = onOff;
    debugMap_["MiroCamera::getCameraParameter"]       = onOff;
    debugMap_["MiroCamera::readIntegerData"]          = onOff;
    debugMap_["MiroCamera::readDoubleData"]           = onOff;
    debugMap_["MiroCamera::readRunModes"]             = onOff;
    debugMap_["MiroCamera::asynPortConnect"]          = onOff;
    debugMap_["MiroCamera::commandResponse"]          = onOff;
    debugMap_["MiroCamera::asynWriteRead"]            = onOff;
    debugMap_["MiroCamera::cineStates"]               = onOff;
  } else {
    debugMap_[method] = onOff;
  }
  return asynSuccess;
}

asynStatus MiroCamera::debug(const std::string& method, const std::string& msg)
{
  // First check for the debug entry in the debug map
  if (debugMap_.count(method) == 1){
    // Now check if debug is turned on
    if (debugMap_[method] == 1){
      // Print out the debug message
      std::cout << method << ": " << msg << std::endl;
    }
  }
  return asynSuccess;
}

asynStatus MiroCamera::debug(const std::string& method, const std::string& msg, int value)
{
  // First check for the debug entry in the debug map
  if (debugMap_.count(method) == 1){
    // Now check if debug is turned on
    if (debugMap_[method] == 1){
      // Print out the debug message
      std::cout << method << ": " << msg << " [" << value << "]" << std::endl;
    }
  }
  return asynSuccess;
}

asynStatus MiroCamera::debug(const std::string& method, const std::string& msg, double value)
{
  // First check for the debug entry in the debug map
  if (debugMap_.count(method) == 1){
    // Now check if debug is turned on
    if (debugMap_[method] == 1){
      // Print out the debug message
      std::cout << method << ": " << msg << " [" << value << "]" << std::endl;
    }
  }
  return asynSuccess;
}

asynStatus MiroCamera::debug(const std::string& method, const std::string& msg, const std::string& value)
{
  // First check for the debug entry in the debug map
  if (debugMap_.count(method) == 1){
    // Now check if debug is turned on
    if (debugMap_[method] == 1){
      // Copy the string
      std::string val = value;
      // Trim the output
      val.erase(val.find_last_not_of("\n")+1);
      // Print out the debug message
      std::cout << method << ": " << msg << " [" << val << "]" << std::endl;
    }
  }
  return asynSuccess;
}

asynStatus MiroCamera::debug(const std::string& method, const std::string& msg, std::map<std::string, std::string> value)
{
  std::map<std::string, std::string>::iterator iter;

  // First check for the debug entry in the debug map
  if (debugMap_.count(method) == 1){
    // Now check if debug is turned on
    if (debugMap_[method] == 1){
      // Print out the debug message
      std::cout << method << ": " << msg << " [std::map" << std::endl;
      // This is a map of data, so log the entire map
      for (iter = value.begin(); iter != value.end(); ++iter) {
        std::cout << "     " << iter->first << " => " << iter->second << std::endl;
      }
      std::cout << "]" << std::endl;
    }
  }
  return asynSuccess;
}

// Code required for iocsh registration of the MIRO camera
static const iocshArg miroCameraConfigArg0 = {"portName", iocshArgString};
static const iocshArg miroCameraConfigArg1 = {"Control Port Name", iocshArgString};
static const iocshArg miroCameraConfigArg2 = {"Data Port Name", iocshArgString};
static const iocshArg miroCameraConfigArg3 = {"Max number of NDArray buffers", iocshArgInt};
static const iocshArg miroCameraConfigArg4 = {"maxMemory", iocshArgInt};
static const iocshArg miroCameraConfigArg5 = {"priority", iocshArgInt};
static const iocshArg miroCameraConfigArg6 = {"stackSize", iocshArgInt};

static const iocshArg * const miroCameraConfigArgs[] =  {&miroCameraConfigArg0,
                                                            &miroCameraConfigArg1,
                                                            &miroCameraConfigArg2,
                                                            &miroCameraConfigArg3,
                                                            &miroCameraConfigArg4,
                                                            &miroCameraConfigArg5,
                                                            &miroCameraConfigArg6};

static const iocshFuncDef configMiroCamera = {"miroCameraConfig", 7, miroCameraConfigArgs};

static void configMiroCameraCallFunc(const iocshArgBuf *args)
{
    miroCameraConfig(args[0].sval, args[1].sval, args[2].sval, args[3].ival, args[4].ival, args[5].ival, args[6].ival);
}

// Code required for setting the debug level of the MIRO camera
static const iocshArg miroCameraDebugArg0 = {"port name", iocshArgString};
static const iocshArg miroCameraDebugArg1 = {"method name", iocshArgString};
static const iocshArg miroCameraDebugArg2 = {"debug on or off", iocshArgInt};

static const iocshArg * const miroCameraDebugArgs[] =  {&miroCameraDebugArg0,
                                                           &miroCameraDebugArg1,
                                                           &miroCameraDebugArg2};

static const iocshFuncDef debugMiroCamera = {"miroCameraDebug", 3, miroCameraDebugArgs};

static void debugMiroCameraCallFunc(const iocshArgBuf *args)
{
    miroSetDebugLevel(args[0].sval, args[1].sval, args[2].ival);
}

static void miroCameraRegister(void)
{
    iocshRegister(&configMiroCamera, configMiroCameraCallFunc);
    iocshRegister(&debugMiroCamera, debugMiroCameraCallFunc);
}

epicsExportRegistrar(miroCameraRegister);

