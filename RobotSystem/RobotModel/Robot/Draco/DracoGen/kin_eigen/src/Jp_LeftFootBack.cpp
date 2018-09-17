/*
 * Automatically Generated from Mathematica.
 * Thu 23 Aug 2018 15:50:32 GMT-05:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "RobotSystem/RobotModel/Robot/Draco/DracoGen/kin_eigen/include/Jp_LeftFootBack.h"

#ifdef _MSC_VER
  #define INLINE __forceinline /* use __forceinline (VC++ specific) */
#else
  #define INLINE inline        /* use standard inline */
#endif

/**
 * Copied from Wolfram Mathematica C Definitions file mdefs.hpp
 * Changed marcos to inline functions (Eric Cousineau)
 */
INLINE double Power(double x, double y) { return pow(x, y); }
INLINE double Sqrt(double x) { return sqrt(x); }

INLINE double Abs(double x) { return fabs(x); }

INLINE double Exp(double x) { return exp(x); }
INLINE double Log(double x) { return log(x); }

INLINE double Sin(double x) { return sin(x); }
INLINE double Cos(double x) { return cos(x); }
INLINE double Tan(double x) { return tan(x); }

INLINE double Csc(double x) { return 1.0/sin(x); }
INLINE double Sec(double x) { return 1.0/cos(x); }

INLINE double ArcSin(double x) { return asin(x); }
INLINE double ArcCos(double x) { return acos(x); }
//INLINE double ArcTan(double x) { return atan(x); }

/* update ArcTan function to use atan2 instead. */
INLINE double ArcTan(double x, double y) { return atan2(y,x); }

INLINE double Sinh(double x) { return sinh(x); }
INLINE double Cosh(double x) { return cosh(x); }
INLINE double Tanh(double x) { return tanh(x); }

#define E 2.71828182845904523536029
#define Pi 3.14159265358979323846264
#define Degree 0.01745329251994329576924

/*
 * Sub functions
 */
static void output1(Eigen::Matrix<double,3,16> &p_output1, const Eigen::Matrix<double,16,1> &var1)
{
  double t363;
  double t488;
  double t491;
  double t492;
  double t718;
  double t204;
  double t273;
  double t283;
  double t424;
  double t438;
  double t460;
  double t465;
  double t922;
  double t1215;
  double t1360;
  double t1451;
  double t1497;
  double t1169;
  double t1204;
  double t1211;
  double t1675;
  double t1693;
  double t1749;
  double t2159;
  double t2222;
  double t2259;
  double t2265;
  double t2088;
  double t2091;
  double t2105;
  double t2434;
  double t2545;
  double t2564;
  double t2832;
  double t2857;
  double t2897;
  double t2991;
  double t3123;
  double t3126;
  double t3146;
  double t3255;
  double t3279;
  double t3291;
  double t3329;
  double t3409;
  double t3442;
  double t3483;
  double t3571;
  double t3585;
  double t3592;
  double t3744;
  double t3799;
  double t3833;
  double t628;
  double t783;
  double t852;
  double t1073;
  double t1076;
  double t1150;
  double t4243;
  double t4258;
  double t4339;
  double t1477;
  double t1543;
  double t1574;
  double t1767;
  double t1777;
  double t1798;
  double t4400;
  double t4597;
  double t4640;
  double t4648;
  double t4679;
  double t4754;
  double t2262;
  double t2320;
  double t2332;
  double t2590;
  double t2687;
  double t2759;
  double t2970;
  double t3021;
  double t3062;
  double t4860;
  double t4862;
  double t4873;
  double t4917;
  double t4931;
  double t4933;
  double t3193;
  double t3214;
  double t3218;
  double t3463;
  double t3493;
  double t3533;
  double t4952;
  double t4954;
  double t4957;
  double t5007;
  double t5016;
  double t5027;
  double t3614;
  double t3620;
  double t3710;
  double t5083;
  double t5088;
  double t5097;
  double t5124;
  double t5131;
  double t5182;
  double t5381;
  double t5395;
  double t5408;
  double t5480;
  double t5490;
  double t5492;
  double t5498;
  double t5511;
  double t5512;
  double t5529;
  double t5578;
  double t5626;
  double t5635;
  double t5650;
  double t5651;
  double t5665;
  double t5676;
  double t5685;
  double t5712;
  double t5716;
  double t5724;
  double t5966;
  double t5981;
  double t6025;
  double t6115;
  double t6120;
  double t6127;
  double t6135;
  double t6182;
  double t6207;
  double t6238;
  double t6253;
  double t6293;
  double t6324;
  double t6326;
  double t6344;
  double t6404;
  double t6428;
  double t6466;
  double t6492;
  double t6494;
  double t6530;
  double t6666;
  double t6672;
  double t6680;
  double t6726;
  double t6730;
  double t6734;
  double t6745;
  double t6756;
  double t6766;
  double t6783;
  double t6798;
  double t6806;
  double t6831;
  double t6837;
  double t6842;
  double t6855;
  double t6856;
  double t6870;
  double t6885;
  double t6887;
  double t6901;
  double t7035;
  double t7067;
  double t7073;
  double t7110;
  double t7124;
  double t7133;
  double t7143;
  double t7153;
  double t7156;
  double t7162;
  double t7164;
  double t7174;
  double t7189;
  double t7197;
  double t7216;
  double t7240;
  double t7244;
  double t7247;
  double t7352;
  double t7353;
  double t7356;
  double t7417;
  double t7422;
  double t7423;
  double t7434;
  double t7439;
  double t7443;
  double t7447;
  double t7448;
  double t7449;
  double t7476;
  double t7488;
  double t7492;
  double t7512;
  double t7518;
  double t7520;
  double t7648;
  double t7653;
  double t7656;
  double t7679;
  double t7684;
  double t7685;
  double t7700;
  double t7707;
  double t7709;
  double t7722;
  double t7735;
  double t7742;
  double t7760;
  double t7767;
  double t7769;
  double t7879;
  double t7880;
  double t7883;
  double t7926;
  double t7938;
  double t7946;
  double t7952;
  double t7963;
  double t7964;
  double t7985;
  double t7998;
  double t8001;
  double t8012;
  double t8015;
  double t8016;
  double t7854;
  double t7855;
  double t7857;
  double t7865;
  double t7868;
  double t8052;
  double t8056;
  double t8065;
  double t8077;
  double t8079;
  double t8127;
  double t8137;
  double t8143;
  double t8153;
  double t8160;
  double t8161;
  double t8166;
  double t8171;
  double t8176;
  double t8187;
  double t8211;
  double t8215;
  double t8234;
  double t8242;
  double t8245;
  double t8316;
  double t8341;
  double t8346;
  double t8363;
  double t8371;
  double t8376;
  double t8385;
  double t8393;
  double t8394;
  double t8398;
  double t8413;
  double t8429;
  double t8432;
  double t8446;
  double t8447;
  double t8451;
  double t8452;
  double t8453;
  double t8546;
  double t8547;
  double t8573;
  double t8594;
  double t8596;
  double t8599;
  double t8618;
  double t8623;
  double t8629;
  double t8506;
  double t8519;
  double t8533;
  double t8534;
  double t8541;
  double t8703;
  double t8715;
  double t8717;
  double t8762;
  double t8764;
  double t8766;
  double t8783;
  double t8792;
  double t8794;
  double t8887;
  double t8896;
  double t8900;
  double t8964;
  double t8975;
  double t8999;
  double t9013;
  double t9022;
  double t9025;
  double t9155;
  double t9159;
  double t9174;
  double t9186;
  double t9204;
  double t9216;
  double t9217;
  double t9223;
  double t8730;
  double t8739;
  double t8743;
  double t9096;
  double t9105;
  double t9107;
  double t9118;
  double t9122;
  double t9289;
  double t9299;
  double t9303;
  double t9314;
  double t9317;
  double t9320;
  double t9334;
  double t9336;
  double t9345;
  double t9365;
  double t9379;
  double t9380;
  double t9391;
  double t9403;
  double t9406;
  double t8916;
  double t8921;
  double t8928;
  double t9520;
  double t9521;
  double t9523;
  double t9532;
  double t9533;
  double t9543;
  double t9555;
  double t9556;
  double t9558;
  double t9570;
  double t9572;
  double t9575;
  double t9581;
  double t9594;
  double t9597;
  double t9734;
  double t9737;
  double t5271;
  double t9685;
  double t9716;
  double t9724;
  double t9727;
  double t9730;
  double t9765;
  double t9768;
  double t9775;
  double t9779;
  double t9780;
  double t9783;
  double t9784;
  double t9803;
  double t9804;
  double t9805;
  double t9810;
  double t9811;
  double t9817;
  double t9818;
  double t9739;
  double t5289;
  double t5321;
  double t9831;
  double t9832;
  double t9834;
  double t9835;
  double t9836;
  double t9787;
  double t9845;
  double t9846;
  double t9847;
  double t9794;
  double t9821;
  double t9858;
  double t9859;
  double t9860;
  double t9826;
  t363 = Sin(var1[3]);
  t488 = Cos(var1[6]);
  t491 = -1.*t488;
  t492 = 1. + t491;
  t718 = Sin(var1[6]);
  t204 = Cos(var1[3]);
  t273 = Cos(var1[5]);
  t283 = -1.*t204*t273;
  t424 = Sin(var1[4]);
  t438 = Sin(var1[5]);
  t460 = -1.*t363*t424*t438;
  t465 = t283 + t460;
  t922 = Cos(var1[4]);
  t1215 = Cos(var1[7]);
  t1360 = -1.*t1215;
  t1451 = 1. + t1360;
  t1497 = Sin(var1[7]);
  t1169 = t488*t465;
  t1204 = t922*t363*t718;
  t1211 = t1169 + t1204;
  t1675 = -1.*t273*t363*t424;
  t1693 = t204*t438;
  t1749 = t1675 + t1693;
  t2159 = Cos(var1[8]);
  t2222 = -1.*t2159;
  t2259 = 1. + t2222;
  t2265 = Sin(var1[8]);
  t2088 = t1215*t1749;
  t2091 = -1.*t1211*t1497;
  t2105 = t2088 + t2091;
  t2434 = -1.*t922*t488*t363;
  t2545 = t465*t718;
  t2564 = t2434 + t2545;
  t2832 = Cos(var1[9]);
  t2857 = -1.*t2832;
  t2897 = 1. + t2857;
  t2991 = Sin(var1[9]);
  t3123 = t2159*t2105;
  t3126 = t2564*t2265;
  t3146 = t3123 + t3126;
  t3255 = t2159*t2564;
  t3279 = -1.*t2105*t2265;
  t3291 = t3255 + t3279;
  t3329 = Cos(var1[10]);
  t3409 = -1.*t3329;
  t3442 = 1. + t3409;
  t3483 = Sin(var1[10]);
  t3571 = -1.*t2991*t3146;
  t3585 = t2832*t3291;
  t3592 = t3571 + t3585;
  t3744 = t2832*t3146;
  t3799 = t2991*t3291;
  t3833 = t3744 + t3799;
  t628 = 0.087*t492;
  t783 = 0.0222*t718;
  t852 = 0. + t628 + t783;
  t1073 = -0.0222*t492;
  t1076 = 0.087*t718;
  t1150 = 0. + t1073 + t1076;
  t4243 = -1.*t273*t363;
  t4258 = t204*t424*t438;
  t4339 = t4243 + t4258;
  t1477 = 0.157*t1451;
  t1543 = -0.3151*t1497;
  t1574 = 0. + t1477 + t1543;
  t1767 = -0.3151*t1451;
  t1777 = -0.157*t1497;
  t1798 = 0. + t1767 + t1777;
  t4400 = t488*t4339;
  t4597 = -1.*t204*t922*t718;
  t4640 = t4400 + t4597;
  t4648 = t204*t273*t424;
  t4679 = t363*t438;
  t4754 = t4648 + t4679;
  t2262 = -0.3801*t2259;
  t2320 = -0.0222*t2265;
  t2332 = 0. + t2262 + t2320;
  t2590 = -0.0222*t2259;
  t2687 = 0.3801*t2265;
  t2759 = 0. + t2590 + t2687;
  t2970 = -0.8601*t2897;
  t3021 = -0.0222*t2991;
  t3062 = 0. + t2970 + t3021;
  t4860 = t1215*t4754;
  t4862 = -1.*t4640*t1497;
  t4873 = t4860 + t4862;
  t4917 = t204*t922*t488;
  t4931 = t4339*t718;
  t4933 = t4917 + t4931;
  t3193 = -0.0222*t2897;
  t3214 = 0.8601*t2991;
  t3218 = 0. + t3193 + t3214;
  t3463 = -0.0211*t3442;
  t3493 = 1.3401*t3483;
  t3533 = 0. + t3463 + t3493;
  t4952 = t2159*t4873;
  t4954 = t4933*t2265;
  t4957 = t4952 + t4954;
  t5007 = t2159*t4933;
  t5016 = -1.*t4873*t2265;
  t5027 = t5007 + t5016;
  t3614 = -1.3401*t3442;
  t3620 = -0.0211*t3483;
  t3710 = 0. + t3614 + t3620;
  t5083 = -1.*t2991*t4957;
  t5088 = t2832*t5027;
  t5097 = t5083 + t5088;
  t5124 = t2832*t4957;
  t5131 = t2991*t5027;
  t5182 = t5124 + t5131;
  t5381 = t204*t922*t488*t438;
  t5395 = t204*t424*t718;
  t5408 = t5381 + t5395;
  t5480 = t204*t922*t273*t1215;
  t5490 = -1.*t5408*t1497;
  t5492 = t5480 + t5490;
  t5498 = -1.*t204*t488*t424;
  t5511 = t204*t922*t438*t718;
  t5512 = t5498 + t5511;
  t5529 = t2159*t5492;
  t5578 = t5512*t2265;
  t5626 = t5529 + t5578;
  t5635 = t2159*t5512;
  t5650 = -1.*t5492*t2265;
  t5651 = t5635 + t5650;
  t5665 = -1.*t2991*t5626;
  t5676 = t2832*t5651;
  t5685 = t5665 + t5676;
  t5712 = t2832*t5626;
  t5716 = t2991*t5651;
  t5724 = t5712 + t5716;
  t5966 = t922*t488*t363*t438;
  t5981 = t363*t424*t718;
  t6025 = t5966 + t5981;
  t6115 = t922*t273*t1215*t363;
  t6120 = -1.*t6025*t1497;
  t6127 = t6115 + t6120;
  t6135 = -1.*t488*t363*t424;
  t6182 = t922*t363*t438*t718;
  t6207 = t6135 + t6182;
  t6238 = t2159*t6127;
  t6253 = t6207*t2265;
  t6293 = t6238 + t6253;
  t6324 = t2159*t6207;
  t6326 = -1.*t6127*t2265;
  t6344 = t6324 + t6326;
  t6404 = -1.*t2991*t6293;
  t6428 = t2832*t6344;
  t6466 = t6404 + t6428;
  t6492 = t2832*t6293;
  t6494 = t2991*t6344;
  t6530 = t6492 + t6494;
  t6666 = -1.*t488*t424*t438;
  t6672 = t922*t718;
  t6680 = t6666 + t6672;
  t6726 = -1.*t273*t1215*t424;
  t6730 = -1.*t6680*t1497;
  t6734 = t6726 + t6730;
  t6745 = -1.*t922*t488;
  t6756 = -1.*t424*t438*t718;
  t6766 = t6745 + t6756;
  t6783 = t2159*t6734;
  t6798 = t6766*t2265;
  t6806 = t6783 + t6798;
  t6831 = t2159*t6766;
  t6837 = -1.*t6734*t2265;
  t6842 = t6831 + t6837;
  t6855 = -1.*t2991*t6806;
  t6856 = t2832*t6842;
  t6870 = t6855 + t6856;
  t6885 = t2832*t6806;
  t6887 = t2991*t6842;
  t6901 = t6885 + t6887;
  t7035 = t273*t363;
  t7067 = -1.*t204*t424*t438;
  t7073 = t7035 + t7067;
  t7110 = t1215*t7073;
  t7124 = -1.*t488*t4754*t1497;
  t7133 = t7110 + t7124;
  t7143 = t2159*t7133;
  t7153 = t4754*t718*t2265;
  t7156 = t7143 + t7153;
  t7162 = t2159*t4754*t718;
  t7164 = -1.*t7133*t2265;
  t7174 = t7162 + t7164;
  t7189 = -1.*t2991*t7156;
  t7197 = t2832*t7174;
  t7216 = t7189 + t7197;
  t7240 = t2832*t7156;
  t7244 = t2991*t7174;
  t7247 = t7240 + t7244;
  t7352 = t273*t363*t424;
  t7353 = -1.*t204*t438;
  t7356 = t7352 + t7353;
  t7417 = t1215*t465;
  t7422 = -1.*t488*t7356*t1497;
  t7423 = t7417 + t7422;
  t7434 = t2159*t7423;
  t7439 = t7356*t718*t2265;
  t7443 = t7434 + t7439;
  t7447 = t2159*t7356*t718;
  t7448 = -1.*t7423*t2265;
  t7449 = t7447 + t7448;
  t7476 = -1.*t2991*t7443;
  t7488 = t2832*t7449;
  t7492 = t7476 + t7488;
  t7512 = t2832*t7443;
  t7518 = t2991*t7449;
  t7520 = t7512 + t7518;
  t7648 = -1.*t922*t1215*t438;
  t7653 = -1.*t922*t273*t488*t1497;
  t7656 = t7648 + t7653;
  t7679 = t2159*t7656;
  t7684 = t922*t273*t718*t2265;
  t7685 = t7679 + t7684;
  t7700 = t922*t273*t2159*t718;
  t7707 = -1.*t7656*t2265;
  t7709 = t7700 + t7707;
  t7722 = -1.*t2991*t7685;
  t7735 = t2832*t7709;
  t7742 = t7722 + t7735;
  t7760 = t2832*t7685;
  t7767 = t2991*t7709;
  t7769 = t7760 + t7767;
  t7879 = -1.*t204*t922*t488;
  t7880 = -1.*t4339*t718;
  t7883 = t7879 + t7880;
  t7926 = -1.*t2159*t7883*t1497;
  t7938 = t4640*t2265;
  t7946 = t7926 + t7938;
  t7952 = t2159*t4640;
  t7963 = t7883*t1497*t2265;
  t7964 = t7952 + t7963;
  t7985 = -1.*t2991*t7946;
  t7998 = t2832*t7964;
  t8001 = t7985 + t7998;
  t8012 = t2832*t7946;
  t8015 = t2991*t7964;
  t8016 = t8012 + t8015;
  t7854 = 0.087*t488;
  t7855 = -0.0222*t718;
  t7857 = t7854 + t7855;
  t7865 = 0.0222*t488;
  t7868 = t7865 + t1076;
  t8052 = t204*t273;
  t8056 = t363*t424*t438;
  t8065 = t8052 + t8056;
  t8077 = -1.*t8065*t718;
  t8079 = t2434 + t8077;
  t8127 = t488*t8065;
  t8137 = -1.*t922*t363*t718;
  t8143 = t8127 + t8137;
  t8153 = -1.*t2159*t8079*t1497;
  t8160 = t8143*t2265;
  t8161 = t8153 + t8160;
  t8166 = t2159*t8143;
  t8171 = t8079*t1497*t2265;
  t8176 = t8166 + t8171;
  t8187 = -1.*t2991*t8161;
  t8211 = t2832*t8176;
  t8215 = t8187 + t8211;
  t8234 = t2832*t8161;
  t8242 = t2991*t8176;
  t8245 = t8234 + t8242;
  t8316 = t488*t424;
  t8341 = -1.*t922*t438*t718;
  t8346 = t8316 + t8341;
  t8363 = t922*t488*t438;
  t8371 = t424*t718;
  t8376 = t8363 + t8371;
  t8385 = -1.*t2159*t8346*t1497;
  t8393 = t8376*t2265;
  t8394 = t8385 + t8393;
  t8398 = t2159*t8376;
  t8413 = t8346*t1497*t2265;
  t8429 = t8398 + t8413;
  t8432 = -1.*t2991*t8394;
  t8446 = t2832*t8429;
  t8447 = t8432 + t8446;
  t8451 = t2832*t8394;
  t8452 = t2991*t8429;
  t8453 = t8451 + t8452;
  t8546 = -1.*t1215*t4640;
  t8547 = -1.*t4754*t1497;
  t8573 = t8546 + t8547;
  t8594 = -1.*t2159*t2991*t8573;
  t8596 = -1.*t2832*t8573*t2265;
  t8599 = t8594 + t8596;
  t8618 = t2832*t2159*t8573;
  t8623 = -1.*t2991*t8573*t2265;
  t8629 = t8618 + t8623;
  t8506 = -0.157*t1215;
  t8519 = t8506 + t1543;
  t8533 = -0.3151*t1215;
  t8534 = 0.157*t1497;
  t8541 = t8533 + t8534;
  t8703 = -1.*t1215*t8143;
  t8715 = -1.*t7356*t1497;
  t8717 = t8703 + t8715;
  t8762 = -1.*t2159*t2991*t8717;
  t8764 = -1.*t2832*t8717*t2265;
  t8766 = t8762 + t8764;
  t8783 = t2832*t2159*t8717;
  t8792 = -1.*t2991*t8717*t2265;
  t8794 = t8783 + t8792;
  t8887 = -1.*t1215*t8376;
  t8896 = -1.*t922*t273*t1497;
  t8900 = t8887 + t8896;
  t8964 = -1.*t2159*t2991*t8900;
  t8975 = -1.*t2832*t8900*t2265;
  t8999 = t8964 + t8975;
  t9013 = t2832*t2159*t8900;
  t9022 = -1.*t2991*t8900*t2265;
  t9025 = t9013 + t9022;
  t9155 = -1.*t2159*t4873;
  t9159 = -1.*t4933*t2265;
  t9174 = t9155 + t9159;
  t9186 = t2991*t9174;
  t9204 = t9186 + t5088;
  t9216 = t2832*t9174;
  t9217 = -1.*t2991*t5027;
  t9223 = t9216 + t9217;
  t8730 = t1215*t7356;
  t8739 = -1.*t8143*t1497;
  t8743 = t8730 + t8739;
  t9096 = -0.0222*t2159;
  t9105 = -0.3801*t2265;
  t9107 = t9096 + t9105;
  t9118 = 0.3801*t2159;
  t9122 = t9118 + t2320;
  t9289 = t922*t488*t363;
  t9299 = t8065*t718;
  t9303 = t9289 + t9299;
  t9314 = -1.*t2159*t8743;
  t9317 = -1.*t9303*t2265;
  t9320 = t9314 + t9317;
  t9334 = t2159*t9303;
  t9336 = -1.*t8743*t2265;
  t9345 = t9334 + t9336;
  t9365 = t2991*t9320;
  t9379 = t2832*t9345;
  t9380 = t9365 + t9379;
  t9391 = t2832*t9320;
  t9403 = -1.*t2991*t9345;
  t9406 = t9391 + t9403;
  t8916 = t922*t273*t1215;
  t8921 = -1.*t8376*t1497;
  t8928 = t8916 + t8921;
  t9520 = -1.*t488*t424;
  t9521 = t922*t438*t718;
  t9523 = t9520 + t9521;
  t9532 = -1.*t2159*t8928;
  t9533 = -1.*t9523*t2265;
  t9543 = t9532 + t9533;
  t9555 = t2159*t9523;
  t9556 = -1.*t8928*t2265;
  t9558 = t9555 + t9556;
  t9570 = t2991*t9543;
  t9572 = t2832*t9558;
  t9575 = t9570 + t9572;
  t9581 = t2832*t9543;
  t9594 = -1.*t2991*t9558;
  t9597 = t9581 + t9594;
  t9734 = -1.*t2832*t4957;
  t9737 = t9734 + t9217;
  t5271 = t3329*t5097;
  t9685 = -0.0222*t2832;
  t9716 = -0.8601*t2991;
  t9724 = t9685 + t9716;
  t9727 = 0.8601*t2832;
  t9730 = t9727 + t3021;
  t9765 = t2159*t8743;
  t9768 = t9303*t2265;
  t9775 = t9765 + t9768;
  t9779 = -1.*t2991*t9775;
  t9780 = t9779 + t9379;
  t9783 = -1.*t2832*t9775;
  t9784 = t9783 + t9403;
  t9803 = t2159*t8928;
  t9804 = t9523*t2265;
  t9805 = t9803 + t9804;
  t9810 = -1.*t2991*t9805;
  t9811 = t9810 + t9572;
  t9817 = -1.*t2832*t9805;
  t9818 = t9817 + t9594;
  t9739 = -1.*t3483*t5097;
  t5289 = -1.*t3483*t5182;
  t5321 = t5271 + t5289;
  t9831 = 1.3401*t3329;
  t9832 = t9831 + t3620;
  t9834 = -0.0211*t3329;
  t9835 = -1.3401*t3483;
  t9836 = t9834 + t9835;
  t9787 = -1.*t3483*t9780;
  t9845 = t2832*t9775;
  t9846 = t2991*t9345;
  t9847 = t9845 + t9846;
  t9794 = t3329*t9780;
  t9821 = -1.*t3483*t9811;
  t9858 = t2832*t9805;
  t9859 = t2991*t9558;
  t9860 = t9858 + t9859;
  t9826 = t3329*t9811;

  p_output1(0)=1.;
  p_output1(1)=0;
  p_output1(2)=0;
  p_output1(3)=0;
  p_output1(4)=1.;
  p_output1(5)=0;
  p_output1(6)=0;
  p_output1(7)=0;
  p_output1(8)=1.;
  p_output1(9)=t1211*t1574 + 0.092*(t1211*t1215 + t1497*t1749) + t1749*t1798 + t2105*t2332 + t2564*t2759 + t3062*t3146 + t3218*t3291 + t3533*t3592 + t3710*t3833 - 1.325152*(t3483*t3592 + t3329*t3833) + 0.043912*(t3329*t3592 - 1.*t3483*t3833) + t465*t852 - 1.*t1150*t363*t922;
  p_output1(10)=t1574*t4640 + t1798*t4754 + 0.092*(t1215*t4640 + t1497*t4754) + t2332*t4873 + t2759*t4933 + t3062*t4957 + t3218*t5027 + t3533*t5097 + t3710*t5182 - 1.325152*(t3483*t5097 + t3329*t5182) + 0.043912*t5321 + t4339*t852 + t1150*t204*t922;
  p_output1(11)=0;
  p_output1(12)=-1.*t1150*t204*t424 + t1574*t5408 + t2332*t5492 + t2759*t5512 + t3062*t5626 + t3218*t5651 + t3533*t5685 + t3710*t5724 - 1.325152*(t3483*t5685 + t3329*t5724) + 0.043912*(t3329*t5685 - 1.*t3483*t5724) + t1798*t204*t273*t922 + t204*t438*t852*t922 + 0.092*(t1215*t5408 + t1497*t204*t273*t922);
  p_output1(13)=-1.*t1150*t363*t424 + t1574*t6025 + t2332*t6127 + t2759*t6207 + t3062*t6293 + t3218*t6344 + t3533*t6466 + t3710*t6530 - 1.325152*(t3483*t6466 + t3329*t6530) + 0.043912*(t3329*t6466 - 1.*t3483*t6530) + t1798*t273*t363*t922 + t363*t438*t852*t922 + 0.092*(t1215*t6025 + t1497*t273*t363*t922);
  p_output1(14)=-1.*t1798*t273*t424 + t1574*t6680 + 0.092*(-1.*t1497*t273*t424 + t1215*t6680) + t2332*t6734 + t2759*t6766 + t3062*t6806 + t3218*t6842 + t3533*t6870 + t3710*t6901 - 1.325152*(t3483*t6870 + t3329*t6901) + 0.043912*(t3329*t6870 - 1.*t3483*t6901) - 1.*t424*t438*t852 - 1.*t1150*t922;
  p_output1(15)=t1574*t4754*t488 + t1798*t7073 + 0.092*(t1215*t4754*t488 + t1497*t7073) + t2332*t7133 + t3062*t7156 + t3218*t7174 + t2759*t4754*t718 + t3533*t7216 + t3710*t7247 - 1.325152*(t3483*t7216 + t3329*t7247) + 0.043912*(t3329*t7216 - 1.*t3483*t7247) + t4754*t852;
  p_output1(16)=t1798*t465 + t1574*t488*t7356 + t2759*t718*t7356 + 0.092*(t1497*t465 + t1215*t488*t7356) + t2332*t7423 + t3062*t7443 + t3218*t7449 + t3533*t7492 + t3710*t7520 - 1.325152*(t3483*t7492 + t3329*t7520) + 0.043912*(t3329*t7492 - 1.*t3483*t7520) + t7356*t852;
  p_output1(17)=t2332*t7656 + t3062*t7685 + t3218*t7709 + t3533*t7742 + t3710*t7769 - 1.325152*(t3483*t7742 + t3329*t7769) + 0.043912*(t3329*t7742 - 1.*t3483*t7769) - 1.*t1798*t438*t922 + t1574*t273*t488*t922 + t273*t2759*t718*t922 + t273*t852*t922 + 0.092*(-1.*t1497*t438*t922 + t1215*t273*t488*t922);
  p_output1(18)=t2759*t4640 + t4339*t7868 + 0.092*t1215*t7883 + t1574*t7883 - 1.*t1497*t2332*t7883 + t3062*t7946 + t3218*t7964 + t3533*t8001 + t3710*t8016 - 1.325152*(t3483*t8001 + t3329*t8016) + 0.043912*(t3329*t8001 - 1.*t3483*t8016) + t204*t7857*t922;
  p_output1(19)=t7868*t8065 + 0.092*t1215*t8079 + t1574*t8079 - 1.*t1497*t2332*t8079 + t2759*t8143 + t3062*t8161 + t3218*t8176 + t3533*t8215 + t3710*t8245 - 1.325152*(t3483*t8215 + t3329*t8245) + 0.043912*(t3329*t8215 - 1.*t3483*t8245) + t363*t7857*t922;
  p_output1(20)=-1.*t424*t7857 + 0.092*t1215*t8346 + t1574*t8346 - 1.*t1497*t2332*t8346 + t2759*t8376 + t3062*t8394 + t3218*t8429 + t3533*t8447 + t3710*t8453 - 1.325152*(t3483*t8447 + t3329*t8453) + 0.043912*(t3329*t8447 - 1.*t3483*t8453) + t438*t7868*t922;
  p_output1(21)=0.092*t4873 + t4754*t8519 + t4640*t8541 + t2332*t8573 + t2159*t3062*t8573 - 1.*t2265*t3218*t8573 + t3533*t8599 + t3710*t8629 - 1.325152*(t3483*t8599 + t3329*t8629) + 0.043912*(t3329*t8599 - 1.*t3483*t8629);
  p_output1(22)=t7356*t8519 + t8143*t8541 + t2332*t8717 + t2159*t3062*t8717 - 1.*t2265*t3218*t8717 + 0.092*t8743 + t3533*t8766 + t3710*t8794 - 1.325152*(t3483*t8766 + t3329*t8794) + 0.043912*(t3329*t8766 - 1.*t3483*t8794);
  p_output1(23)=t8376*t8541 + t2332*t8900 + t2159*t3062*t8900 - 1.*t2265*t3218*t8900 + 0.092*t8928 + t3533*t8999 + t3710*t9025 - 1.325152*(t3483*t8999 + t3329*t9025) + 0.043912*(t3329*t8999 - 1.*t3483*t9025) + t273*t8519*t922;
  p_output1(24)=t3062*t5027 + t4873*t9107 + t4933*t9122 + t3218*t9174 + t3710*t9204 + t3533*t9223 + 0.043912*(-1.*t3483*t9204 + t3329*t9223) - 1.325152*(t3329*t9204 + t3483*t9223);
  p_output1(25)=t8743*t9107 + t9122*t9303 + t3218*t9320 + t3062*t9345 + t3710*t9380 + t3533*t9406 + 0.043912*(-1.*t3483*t9380 + t3329*t9406) - 1.325152*(t3329*t9380 + t3483*t9406);
  p_output1(26)=t8928*t9107 + t9122*t9523 + t3218*t9543 + t3062*t9558 + t3710*t9575 + t3533*t9597 + 0.043912*(-1.*t3483*t9575 + t3329*t9597) - 1.325152*(t3329*t9575 + t3483*t9597);
  p_output1(27)=t3710*t5097 + t4957*t9724 + t5027*t9730 + t3533*t9737 - 1.325152*(t5271 + t3483*t9737) + 0.043912*(t3329*t9737 + t9739);
  p_output1(28)=t9345*t9730 + t9724*t9775 + t3710*t9780 + t3533*t9784 + 0.043912*(t3329*t9784 + t9787) - 1.325152*(t3483*t9784 + t9794);
  p_output1(29)=t9558*t9730 + t9724*t9805 + t3710*t9811 + t3533*t9818 + 0.043912*(t3329*t9818 + t9821) - 1.325152*(t3483*t9818 + t9826);
  p_output1(30)=-1.325152*t5321 + 0.043912*(-1.*t3329*t5182 + t9739) + t5097*t9832 + t5182*t9836;
  p_output1(31)=t9780*t9832 + t9836*t9847 + 0.043912*(t9787 - 1.*t3329*t9847) - 1.325152*(t9794 - 1.*t3483*t9847);
  p_output1(32)=t9811*t9832 + t9836*t9860 + 0.043912*(t9821 - 1.*t3329*t9860) - 1.325152*(t9826 - 1.*t3483*t9860);
  p_output1(33)=0;
  p_output1(34)=0;
  p_output1(35)=0;
  p_output1(36)=0;
  p_output1(37)=0;
  p_output1(38)=0;
  p_output1(39)=0;
  p_output1(40)=0;
  p_output1(41)=0;
  p_output1(42)=0;
  p_output1(43)=0;
  p_output1(44)=0;
  p_output1(45)=0;
  p_output1(46)=0;
  p_output1(47)=0;
}


       
void Jp_LeftFootBack(Eigen::Matrix<double,3,16> &p_output1, const Eigen::Matrix<double,16,1> &var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
