/*
 * Automatically Generated from Mathematica.
 * Thu 23 Aug 2018 15:50:36 GMT-05:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "RobotSystem/RobotModel/Robot/Draco/DracoGen/kin_eigen/include/Jp_RightFootFront.h"

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
  double t776;
  double t84;
  double t297;
  double t321;
  double t576;
  double t1362;
  double t1159;
  double t1252;
  double t1388;
  double t861;
  double t885;
  double t988;
  double t1060;
  double t22;
  double t1677;
  double t1686;
  double t1690;
  double t1350;
  double t1468;
  double t1503;
  double t1863;
  double t1886;
  double t1889;
  double t2040;
  double t2068;
  double t2069;
  double t2183;
  double t2522;
  double t2558;
  double t2641;
  double t2890;
  double t2982;
  double t2986;
  double t3033;
  double t3085;
  double t3188;
  double t3225;
  double t3316;
  double t3361;
  double t3367;
  double t3451;
  double t3458;
  double t3505;
  double t3521;
  double t3524;
  double t3643;
  double t3704;
  double t3808;
  double t3831;
  double t3838;
  double t3932;
  double t3939;
  double t3942;
  double t421;
  double t692;
  double t770;
  double t1046;
  double t1087;
  double t1097;
  double t1593;
  double t1613;
  double t1655;
  double t1806;
  double t1817;
  double t1833;
  double t4259;
  double t4264;
  double t4361;
  double t2182;
  double t2429;
  double t2473;
  double t4201;
  double t4206;
  double t4224;
  double t4393;
  double t4463;
  double t4508;
  double t2815;
  double t2821;
  double t2883;
  double t3220;
  double t3234;
  double t3236;
  double t4555;
  double t4604;
  double t4618;
  double t4703;
  double t4713;
  double t4773;
  double t3386;
  double t3405;
  double t3447;
  double t3689;
  double t3714;
  double t3747;
  double t4812;
  double t4877;
  double t4914;
  double t4924;
  double t4943;
  double t4961;
  double t3905;
  double t3915;
  double t3930;
  double t5019;
  double t5074;
  double t5079;
  double t5108;
  double t5152;
  double t5156;
  double t5341;
  double t5344;
  double t5360;
  double t5368;
  double t5396;
  double t5398;
  double t5480;
  double t5483;
  double t5496;
  double t5526;
  double t5534;
  double t5556;
  double t5575;
  double t5584;
  double t5610;
  double t5627;
  double t5635;
  double t5640;
  double t5676;
  double t5682;
  double t5698;
  double t5880;
  double t5905;
  double t5915;
  double t5934;
  double t5938;
  double t5961;
  double t5999;
  double t6008;
  double t6017;
  double t6054;
  double t6058;
  double t6085;
  double t6099;
  double t6125;
  double t6144;
  double t6169;
  double t6179;
  double t6183;
  double t6220;
  double t6222;
  double t6225;
  double t6393;
  double t6406;
  double t6411;
  double t6419;
  double t6428;
  double t6432;
  double t6462;
  double t6463;
  double t6469;
  double t6474;
  double t6475;
  double t6476;
  double t6486;
  double t6490;
  double t6492;
  double t6502;
  double t6513;
  double t6518;
  double t6520;
  double t6525;
  double t6539;
  double t6630;
  double t6635;
  double t6642;
  double t6664;
  double t6672;
  double t6677;
  double t6744;
  double t6747;
  double t6768;
  double t6786;
  double t6799;
  double t6816;
  double t6820;
  double t6831;
  double t6832;
  double t6879;
  double t6886;
  double t6889;
  double t6977;
  double t6983;
  double t6994;
  double t7019;
  double t7026;
  double t7029;
  double t7053;
  double t7055;
  double t7057;
  double t7060;
  double t7064;
  double t7073;
  double t7077;
  double t7078;
  double t7080;
  double t7087;
  double t7094;
  double t7101;
  double t7187;
  double t7193;
  double t7196;
  double t7233;
  double t7236;
  double t7238;
  double t7249;
  double t7259;
  double t7273;
  double t7284;
  double t7286;
  double t7287;
  double t7303;
  double t7306;
  double t7331;
  double t7458;
  double t7475;
  double t7502;
  double t7515;
  double t7524;
  double t7530;
  double t7541;
  double t7544;
  double t7552;
  double t7565;
  double t7571;
  double t7590;
  double t7596;
  double t7609;
  double t7612;
  double t7419;
  double t7428;
  double t7430;
  double t7447;
  double t7449;
  double t7663;
  double t7666;
  double t7669;
  double t7719;
  double t7735;
  double t7695;
  double t7696;
  double t7704;
  double t7753;
  double t7764;
  double t7767;
  double t7789;
  double t7795;
  double t7805;
  double t7808;
  double t7814;
  double t7816;
  double t7823;
  double t7829;
  double t7830;
  double t7919;
  double t7938;
  double t7940;
  double t7867;
  double t7872;
  double t7890;
  double t7979;
  double t7986;
  double t7998;
  double t8019;
  double t8031;
  double t8032;
  double t8040;
  double t8042;
  double t8044;
  double t8053;
  double t8056;
  double t8061;
  double t8221;
  double t8225;
  double t8242;
  double t8284;
  double t8291;
  double t8300;
  double t8307;
  double t8309;
  double t8311;
  double t8164;
  double t8165;
  double t8169;
  double t8181;
  double t8183;
  double t8367;
  double t8368;
  double t8371;
  double t8449;
  double t8455;
  double t8460;
  double t8467;
  double t8471;
  double t8477;
  double t8559;
  double t8567;
  double t8572;
  double t8680;
  double t8681;
  double t8685;
  double t8705;
  double t8718;
  double t8719;
  double t8892;
  double t8893;
  double t8916;
  double t8932;
  double t8942;
  double t8970;
  double t9000;
  double t9002;
  double t8795;
  double t8817;
  double t8869;
  double t8870;
  double t8881;
  double t8400;
  double t8404;
  double t8416;
  double t9059;
  double t9066;
  double t9072;
  double t9107;
  double t9111;
  double t9118;
  double t9127;
  double t9129;
  double t9130;
  double t9139;
  double t9143;
  double t9158;
  double t9174;
  double t9182;
  double t9183;
  double t8619;
  double t8636;
  double t8661;
  double t9247;
  double t9253;
  double t9256;
  double t9278;
  double t9290;
  double t9315;
  double t9326;
  double t9327;
  double t9328;
  double t9334;
  double t9337;
  double t9355;
  double t9376;
  double t9379;
  double t9411;
  double t9555;
  double t9564;
  double t5230;
  double t9501;
  double t9502;
  double t9515;
  double t9521;
  double t9522;
  double t9584;
  double t9586;
  double t9609;
  double t9624;
  double t9629;
  double t9651;
  double t9652;
  double t9776;
  double t9778;
  double t9784;
  double t9799;
  double t9803;
  double t9822;
  double t9824;
  double t9567;
  double t5238;
  double t5284;
  double t9839;
  double t9840;
  double t9842;
  double t9845;
  double t9846;
  double t9672;
  double t9859;
  double t9861;
  double t9862;
  double t9716;
  double t9828;
  double t9873;
  double t9874;
  double t9875;
  double t9834;
  t776 = Sin(var1[3]);
  t84 = Cos(var1[11]);
  t297 = -1.*t84;
  t321 = 1. + t297;
  t576 = Sin(var1[11]);
  t1362 = Cos(var1[3]);
  t1159 = Cos(var1[5]);
  t1252 = Sin(var1[4]);
  t1388 = Sin(var1[5]);
  t861 = Cos(var1[12]);
  t885 = -1.*t861;
  t988 = 1. + t885;
  t1060 = Sin(var1[12]);
  t22 = Cos(var1[4]);
  t1677 = -1.*t1362*t1159;
  t1686 = -1.*t776*t1252*t1388;
  t1690 = t1677 + t1686;
  t1350 = -1.*t1159*t776*t1252;
  t1468 = t1362*t1388;
  t1503 = t1350 + t1468;
  t1863 = t22*t576*t776;
  t1886 = t84*t1690;
  t1889 = t1863 + t1886;
  t2040 = Cos(var1[13]);
  t2068 = -1.*t2040;
  t2069 = 1. + t2068;
  t2183 = Sin(var1[13]);
  t2522 = -1.*t84*t22*t776;
  t2558 = t576*t1690;
  t2641 = t2522 + t2558;
  t2890 = t861*t1503;
  t2982 = -1.*t1060*t1889;
  t2986 = t2890 + t2982;
  t3033 = Cos(var1[14]);
  t3085 = -1.*t3033;
  t3188 = 1. + t3085;
  t3225 = Sin(var1[14]);
  t3316 = t2183*t2641;
  t3361 = t2040*t2986;
  t3367 = t3316 + t3361;
  t3451 = t2040*t2641;
  t3458 = -1.*t2183*t2986;
  t3505 = t3451 + t3458;
  t3521 = Cos(var1[15]);
  t3524 = -1.*t3521;
  t3643 = 1. + t3524;
  t3704 = Sin(var1[15]);
  t3808 = -1.*t3225*t3367;
  t3831 = t3033*t3505;
  t3838 = t3808 + t3831;
  t3932 = t3033*t3367;
  t3939 = t3225*t3505;
  t3942 = t3932 + t3939;
  t421 = -0.0222*t321;
  t692 = -0.087*t576;
  t770 = 0. + t421 + t692;
  t1046 = -0.3151*t988;
  t1087 = 0.157*t1060;
  t1097 = 0. + t1046 + t1087;
  t1593 = -0.087*t321;
  t1613 = 0.0222*t576;
  t1655 = 0. + t1593 + t1613;
  t1806 = -0.157*t988;
  t1817 = -0.3151*t1060;
  t1833 = 0. + t1806 + t1817;
  t4259 = -1.*t1159*t776;
  t4264 = t1362*t1252*t1388;
  t4361 = t4259 + t4264;
  t2182 = -0.0222*t2069;
  t2429 = 0.3801*t2183;
  t2473 = 0. + t2182 + t2429;
  t4201 = t1362*t1159*t1252;
  t4206 = t776*t1388;
  t4224 = t4201 + t4206;
  t4393 = -1.*t1362*t22*t576;
  t4463 = t84*t4361;
  t4508 = t4393 + t4463;
  t2815 = -0.3801*t2069;
  t2821 = -0.0222*t2183;
  t2883 = 0. + t2815 + t2821;
  t3220 = -0.8601*t3188;
  t3234 = -0.0222*t3225;
  t3236 = 0. + t3220 + t3234;
  t4555 = t84*t1362*t22;
  t4604 = t576*t4361;
  t4618 = t4555 + t4604;
  t4703 = t861*t4224;
  t4713 = -1.*t1060*t4508;
  t4773 = t4703 + t4713;
  t3386 = -0.0222*t3188;
  t3405 = 0.8601*t3225;
  t3447 = 0. + t3386 + t3405;
  t3689 = -0.0211*t3643;
  t3714 = 1.3401*t3704;
  t3747 = 0. + t3689 + t3714;
  t4812 = t2183*t4618;
  t4877 = t2040*t4773;
  t4914 = t4812 + t4877;
  t4924 = t2040*t4618;
  t4943 = -1.*t2183*t4773;
  t4961 = t4924 + t4943;
  t3905 = -1.3401*t3643;
  t3915 = -0.0211*t3704;
  t3930 = 0. + t3905 + t3915;
  t5019 = -1.*t3225*t4914;
  t5074 = t3033*t4961;
  t5079 = t5019 + t5074;
  t5108 = t3033*t4914;
  t5152 = t3225*t4961;
  t5156 = t5108 + t5152;
  t5341 = t1362*t576*t1252;
  t5344 = t84*t1362*t22*t1388;
  t5360 = t5341 + t5344;
  t5368 = -1.*t84*t1362*t1252;
  t5396 = t1362*t22*t576*t1388;
  t5398 = t5368 + t5396;
  t5480 = t861*t1362*t22*t1159;
  t5483 = -1.*t1060*t5360;
  t5496 = t5480 + t5483;
  t5526 = t2183*t5398;
  t5534 = t2040*t5496;
  t5556 = t5526 + t5534;
  t5575 = t2040*t5398;
  t5584 = -1.*t2183*t5496;
  t5610 = t5575 + t5584;
  t5627 = -1.*t3225*t5556;
  t5635 = t3033*t5610;
  t5640 = t5627 + t5635;
  t5676 = t3033*t5556;
  t5682 = t3225*t5610;
  t5698 = t5676 + t5682;
  t5880 = t576*t776*t1252;
  t5905 = t84*t22*t776*t1388;
  t5915 = t5880 + t5905;
  t5934 = -1.*t84*t776*t1252;
  t5938 = t22*t576*t776*t1388;
  t5961 = t5934 + t5938;
  t5999 = t861*t22*t1159*t776;
  t6008 = -1.*t1060*t5915;
  t6017 = t5999 + t6008;
  t6054 = t2183*t5961;
  t6058 = t2040*t6017;
  t6085 = t6054 + t6058;
  t6099 = t2040*t5961;
  t6125 = -1.*t2183*t6017;
  t6144 = t6099 + t6125;
  t6169 = -1.*t3225*t6085;
  t6179 = t3033*t6144;
  t6183 = t6169 + t6179;
  t6220 = t3033*t6085;
  t6222 = t3225*t6144;
  t6225 = t6220 + t6222;
  t6393 = t22*t576;
  t6406 = -1.*t84*t1252*t1388;
  t6411 = t6393 + t6406;
  t6419 = -1.*t84*t22;
  t6428 = -1.*t576*t1252*t1388;
  t6432 = t6419 + t6428;
  t6462 = -1.*t861*t1159*t1252;
  t6463 = -1.*t1060*t6411;
  t6469 = t6462 + t6463;
  t6474 = t2183*t6432;
  t6475 = t2040*t6469;
  t6476 = t6474 + t6475;
  t6486 = t2040*t6432;
  t6490 = -1.*t2183*t6469;
  t6492 = t6486 + t6490;
  t6502 = -1.*t3225*t6476;
  t6513 = t3033*t6492;
  t6518 = t6502 + t6513;
  t6520 = t3033*t6476;
  t6525 = t3225*t6492;
  t6539 = t6520 + t6525;
  t6630 = t1159*t776;
  t6635 = -1.*t1362*t1252*t1388;
  t6642 = t6630 + t6635;
  t6664 = -1.*t84*t1060*t4224;
  t6672 = t861*t6642;
  t6677 = t6664 + t6672;
  t6744 = t576*t2183*t4224;
  t6747 = t2040*t6677;
  t6768 = t6744 + t6747;
  t6786 = t2040*t576*t4224;
  t6799 = -1.*t2183*t6677;
  t6816 = t6786 + t6799;
  t6820 = -1.*t3225*t6768;
  t6831 = t3033*t6816;
  t6832 = t6820 + t6831;
  t6879 = t3033*t6768;
  t6886 = t3225*t6816;
  t6889 = t6879 + t6886;
  t6977 = t1159*t776*t1252;
  t6983 = -1.*t1362*t1388;
  t6994 = t6977 + t6983;
  t7019 = -1.*t84*t1060*t6994;
  t7026 = t861*t1690;
  t7029 = t7019 + t7026;
  t7053 = t576*t2183*t6994;
  t7055 = t2040*t7029;
  t7057 = t7053 + t7055;
  t7060 = t2040*t576*t6994;
  t7064 = -1.*t2183*t7029;
  t7073 = t7060 + t7064;
  t7077 = -1.*t3225*t7057;
  t7078 = t3033*t7073;
  t7080 = t7077 + t7078;
  t7087 = t3033*t7057;
  t7094 = t3225*t7073;
  t7101 = t7087 + t7094;
  t7187 = -1.*t84*t22*t1159*t1060;
  t7193 = -1.*t861*t22*t1388;
  t7196 = t7187 + t7193;
  t7233 = t22*t1159*t576*t2183;
  t7236 = t2040*t7196;
  t7238 = t7233 + t7236;
  t7249 = t2040*t22*t1159*t576;
  t7259 = -1.*t2183*t7196;
  t7273 = t7249 + t7259;
  t7284 = -1.*t3225*t7238;
  t7286 = t3033*t7273;
  t7287 = t7284 + t7286;
  t7303 = t3033*t7238;
  t7306 = t3225*t7273;
  t7331 = t7303 + t7306;
  t7458 = -1.*t84*t1362*t22;
  t7475 = -1.*t576*t4361;
  t7502 = t7458 + t7475;
  t7515 = t2183*t4508;
  t7524 = -1.*t2040*t1060*t7502;
  t7530 = t7515 + t7524;
  t7541 = t2040*t4508;
  t7544 = t1060*t2183*t7502;
  t7552 = t7541 + t7544;
  t7565 = -1.*t3225*t7530;
  t7571 = t3033*t7552;
  t7590 = t7565 + t7571;
  t7596 = t3033*t7530;
  t7609 = t3225*t7552;
  t7612 = t7596 + t7609;
  t7419 = -0.087*t84;
  t7428 = -0.0222*t576;
  t7430 = t7419 + t7428;
  t7447 = 0.0222*t84;
  t7449 = t7447 + t692;
  t7663 = t1362*t1159;
  t7666 = t776*t1252*t1388;
  t7669 = t7663 + t7666;
  t7719 = -1.*t576*t7669;
  t7735 = t2522 + t7719;
  t7695 = -1.*t22*t576*t776;
  t7696 = t84*t7669;
  t7704 = t7695 + t7696;
  t7753 = t2183*t7704;
  t7764 = -1.*t2040*t1060*t7735;
  t7767 = t7753 + t7764;
  t7789 = t2040*t7704;
  t7795 = t1060*t2183*t7735;
  t7805 = t7789 + t7795;
  t7808 = -1.*t3225*t7767;
  t7814 = t3033*t7805;
  t7816 = t7808 + t7814;
  t7823 = t3033*t7767;
  t7829 = t3225*t7805;
  t7830 = t7823 + t7829;
  t7919 = t84*t1252;
  t7938 = -1.*t22*t576*t1388;
  t7940 = t7919 + t7938;
  t7867 = t576*t1252;
  t7872 = t84*t22*t1388;
  t7890 = t7867 + t7872;
  t7979 = t2183*t7890;
  t7986 = -1.*t2040*t1060*t7940;
  t7998 = t7979 + t7986;
  t8019 = t2040*t7890;
  t8031 = t1060*t2183*t7940;
  t8032 = t8019 + t8031;
  t8040 = -1.*t3225*t7998;
  t8042 = t3033*t8032;
  t8044 = t8040 + t8042;
  t8053 = t3033*t7998;
  t8056 = t3225*t8032;
  t8061 = t8053 + t8056;
  t8221 = -1.*t1060*t4224;
  t8225 = -1.*t861*t4508;
  t8242 = t8221 + t8225;
  t8284 = -1.*t3033*t2183*t8242;
  t8291 = -1.*t2040*t3225*t8242;
  t8300 = t8284 + t8291;
  t8307 = t2040*t3033*t8242;
  t8309 = -1.*t2183*t3225*t8242;
  t8311 = t8307 + t8309;
  t8164 = 0.157*t861;
  t8165 = t8164 + t1817;
  t8169 = -0.3151*t861;
  t8181 = -0.157*t1060;
  t8183 = t8169 + t8181;
  t8367 = -1.*t1060*t6994;
  t8368 = -1.*t861*t7704;
  t8371 = t8367 + t8368;
  t8449 = -1.*t3033*t2183*t8371;
  t8455 = -1.*t2040*t3225*t8371;
  t8460 = t8449 + t8455;
  t8467 = t2040*t3033*t8371;
  t8471 = -1.*t2183*t3225*t8371;
  t8477 = t8467 + t8471;
  t8559 = -1.*t22*t1159*t1060;
  t8567 = -1.*t861*t7890;
  t8572 = t8559 + t8567;
  t8680 = -1.*t3033*t2183*t8572;
  t8681 = -1.*t2040*t3225*t8572;
  t8685 = t8680 + t8681;
  t8705 = t2040*t3033*t8572;
  t8718 = -1.*t2183*t3225*t8572;
  t8719 = t8705 + t8718;
  t8892 = -1.*t2183*t4618;
  t8893 = -1.*t2040*t4773;
  t8916 = t8892 + t8893;
  t8932 = t3225*t8916;
  t8942 = t8932 + t5074;
  t8970 = t3033*t8916;
  t9000 = -1.*t3225*t4961;
  t9002 = t8970 + t9000;
  t8795 = 0.3801*t2040;
  t8817 = t8795 + t2821;
  t8869 = -0.0222*t2040;
  t8870 = -0.3801*t2183;
  t8881 = t8869 + t8870;
  t8400 = t861*t6994;
  t8404 = -1.*t1060*t7704;
  t8416 = t8400 + t8404;
  t9059 = t84*t22*t776;
  t9066 = t576*t7669;
  t9072 = t9059 + t9066;
  t9107 = -1.*t2183*t9072;
  t9111 = -1.*t2040*t8416;
  t9118 = t9107 + t9111;
  t9127 = t2040*t9072;
  t9129 = -1.*t2183*t8416;
  t9130 = t9127 + t9129;
  t9139 = t3225*t9118;
  t9143 = t3033*t9130;
  t9158 = t9139 + t9143;
  t9174 = t3033*t9118;
  t9182 = -1.*t3225*t9130;
  t9183 = t9174 + t9182;
  t8619 = t861*t22*t1159;
  t8636 = -1.*t1060*t7890;
  t8661 = t8619 + t8636;
  t9247 = -1.*t84*t1252;
  t9253 = t22*t576*t1388;
  t9256 = t9247 + t9253;
  t9278 = -1.*t2183*t9256;
  t9290 = -1.*t2040*t8661;
  t9315 = t9278 + t9290;
  t9326 = t2040*t9256;
  t9327 = -1.*t2183*t8661;
  t9328 = t9326 + t9327;
  t9334 = t3225*t9315;
  t9337 = t3033*t9328;
  t9355 = t9334 + t9337;
  t9376 = t3033*t9315;
  t9379 = -1.*t3225*t9328;
  t9411 = t9376 + t9379;
  t9555 = -1.*t3033*t4914;
  t9564 = t9555 + t9000;
  t5230 = t3521*t5079;
  t9501 = -0.0222*t3033;
  t9502 = -0.8601*t3225;
  t9515 = t9501 + t9502;
  t9521 = 0.8601*t3033;
  t9522 = t9521 + t3234;
  t9584 = t2183*t9072;
  t9586 = t2040*t8416;
  t9609 = t9584 + t9586;
  t9624 = -1.*t3225*t9609;
  t9629 = t9624 + t9143;
  t9651 = -1.*t3033*t9609;
  t9652 = t9651 + t9182;
  t9776 = t2183*t9256;
  t9778 = t2040*t8661;
  t9784 = t9776 + t9778;
  t9799 = -1.*t3225*t9784;
  t9803 = t9799 + t9337;
  t9822 = -1.*t3033*t9784;
  t9824 = t9822 + t9379;
  t9567 = -1.*t3704*t5079;
  t5238 = -1.*t3704*t5156;
  t5284 = t5230 + t5238;
  t9839 = 1.3401*t3521;
  t9840 = t9839 + t3915;
  t9842 = -0.0211*t3521;
  t9845 = -1.3401*t3704;
  t9846 = t9842 + t9845;
  t9672 = -1.*t3704*t9629;
  t9859 = t3033*t9609;
  t9861 = t3225*t9130;
  t9862 = t9859 + t9861;
  t9716 = t3521*t9629;
  t9828 = -1.*t3704*t9803;
  t9873 = t3033*t9784;
  t9874 = t3225*t9328;
  t9875 = t9873 + t9874;
  t9834 = t3521*t9803;

  p_output1(0)=1.;
  p_output1(1)=0;
  p_output1(2)=0;
  p_output1(3)=0;
  p_output1(4)=1.;
  p_output1(5)=0;
  p_output1(6)=0;
  p_output1(7)=0;
  p_output1(8)=1.;
  p_output1(9)=t1097*t1503 + t1655*t1690 + t1833*t1889 + t2473*t2641 + t2883*t2986 + t3236*t3367 + t3447*t3505 + t3747*t3838 + t3930*t3942 - 1.325152*(t3704*t3838 + t3521*t3942) + 0.043912*(t3521*t3838 - 1.*t3704*t3942) - 1.*t22*t770*t776 - 0.09205*(t1060*t1503 + t1889*t861);
  p_output1(10)=t1097*t4224 + t1655*t4361 + t1833*t4508 + t2473*t4618 + t2883*t4773 + t3236*t4914 + t3447*t4961 + t3747*t5079 + t3930*t5156 - 1.325152*(t3704*t5079 + t3521*t5156) + 0.043912*t5284 + t1362*t22*t770 - 0.09205*(t1060*t4224 + t4508*t861);
  p_output1(11)=0;
  p_output1(12)=t1097*t1159*t1362*t22 + t1362*t1388*t1655*t22 + t1833*t5360 + t2473*t5398 + t2883*t5496 + t3236*t5556 + t3447*t5610 + t3747*t5640 + t3930*t5698 - 1.325152*(t3704*t5640 + t3521*t5698) + 0.043912*(t3521*t5640 - 1.*t3704*t5698) - 1.*t1252*t1362*t770 - 0.09205*(t1060*t1159*t1362*t22 + t5360*t861);
  p_output1(13)=t1833*t5915 + t2473*t5961 + t2883*t6017 + t3236*t6085 + t3447*t6144 + t3747*t6183 + t3930*t6225 - 1.325152*(t3704*t6183 + t3521*t6225) + 0.043912*(t3521*t6183 - 1.*t3704*t6225) + t1097*t1159*t22*t776 + t1388*t1655*t22*t776 - 1.*t1252*t770*t776 - 0.09205*(t1060*t1159*t22*t776 + t5915*t861);
  p_output1(14)=-1.*t1097*t1159*t1252 - 1.*t1252*t1388*t1655 + t1833*t6411 + t2473*t6432 + t2883*t6469 + t3236*t6476 + t3447*t6492 + t3747*t6518 + t3930*t6539 - 1.325152*(t3704*t6518 + t3521*t6539) + 0.043912*(t3521*t6518 - 1.*t3704*t6539) - 1.*t22*t770 - 0.09205*(-1.*t1060*t1159*t1252 + t6411*t861);
  p_output1(15)=t1655*t4224 + t2473*t4224*t576 + t1097*t6642 + t2883*t6677 + t3236*t6768 + t3447*t6816 + t3747*t6832 + t3930*t6889 - 1.325152*(t3704*t6832 + t3521*t6889) + 0.043912*(t3521*t6832 - 1.*t3704*t6889) + t1833*t4224*t84 - 0.09205*(t1060*t6642 + t4224*t84*t861);
  p_output1(16)=t1097*t1690 + t1655*t6994 + t2473*t576*t6994 + t2883*t7029 + t3236*t7057 + t3447*t7073 + t3747*t7080 + t3930*t7101 - 1.325152*(t3704*t7080 + t3521*t7101) + 0.043912*(t3521*t7080 - 1.*t3704*t7101) + t1833*t6994*t84 - 0.09205*(t1060*t1690 + t6994*t84*t861);
  p_output1(17)=-1.*t1097*t1388*t22 + t1159*t1655*t22 + t1159*t22*t2473*t576 + t2883*t7196 + t3236*t7238 + t3447*t7273 + t3747*t7287 + t3930*t7331 - 1.325152*(t3704*t7287 + t3521*t7331) + 0.043912*(t3521*t7287 - 1.*t3704*t7331) + t1159*t1833*t22*t84 - 0.09205*(-1.*t1060*t1388*t22 + t1159*t22*t84*t861);
  p_output1(18)=0;
  p_output1(19)=0;
  p_output1(20)=0;
  p_output1(21)=0;
  p_output1(22)=0;
  p_output1(23)=0;
  p_output1(24)=0;
  p_output1(25)=0;
  p_output1(26)=0;
  p_output1(27)=0;
  p_output1(28)=0;
  p_output1(29)=0;
  p_output1(30)=0;
  p_output1(31)=0;
  p_output1(32)=0;
  p_output1(33)=t2473*t4508 + t1362*t22*t7430 + t4361*t7449 + t1833*t7502 - 1.*t1060*t2883*t7502 + t3236*t7530 + t3447*t7552 + t3747*t7590 + t3930*t7612 - 1.325152*(t3704*t7590 + t3521*t7612) + 0.043912*(t3521*t7590 - 1.*t3704*t7612) - 0.09205*t7502*t861;
  p_output1(34)=t7449*t7669 + t2473*t7704 + t1833*t7735 - 1.*t1060*t2883*t7735 + t22*t7430*t776 + t3236*t7767 + t3447*t7805 + t3747*t7816 + t3930*t7830 - 1.325152*(t3704*t7816 + t3521*t7830) + 0.043912*(t3521*t7816 - 1.*t3704*t7830) - 0.09205*t7735*t861;
  p_output1(35)=-1.*t1252*t7430 + t1388*t22*t7449 + t2473*t7890 + t1833*t7940 - 1.*t1060*t2883*t7940 + t3236*t7998 + t3447*t8032 + t3747*t8044 + t3930*t8061 - 1.325152*(t3704*t8044 + t3521*t8061) + 0.043912*(t3521*t8044 - 1.*t3704*t8061) - 0.09205*t7940*t861;
  p_output1(36)=-0.09205*t4773 + t4224*t8165 + t4508*t8183 + t2883*t8242 + t2040*t3236*t8242 - 1.*t2183*t3447*t8242 + t3747*t8300 + t3930*t8311 - 1.325152*(t3704*t8300 + t3521*t8311) + 0.043912*(t3521*t8300 - 1.*t3704*t8311);
  p_output1(37)=t6994*t8165 + t7704*t8183 + t2883*t8371 + t2040*t3236*t8371 - 1.*t2183*t3447*t8371 - 0.09205*t8416 + t3747*t8460 + t3930*t8477 - 1.325152*(t3704*t8460 + t3521*t8477) + 0.043912*(t3521*t8460 - 1.*t3704*t8477);
  p_output1(38)=t1159*t22*t8165 + t7890*t8183 + t2883*t8572 + t2040*t3236*t8572 - 1.*t2183*t3447*t8572 - 0.09205*t8661 + t3747*t8685 + t3930*t8719 - 1.325152*(t3704*t8685 + t3521*t8719) + 0.043912*(t3521*t8685 - 1.*t3704*t8719);
  p_output1(39)=t3236*t4961 + t4618*t8817 + t4773*t8881 + t3447*t8916 + t3930*t8942 + t3747*t9002 + 0.043912*(-1.*t3704*t8942 + t3521*t9002) - 1.325152*(t3521*t8942 + t3704*t9002);
  p_output1(40)=t8416*t8881 + t8817*t9072 + t3447*t9118 + t3236*t9130 + t3930*t9158 + t3747*t9183 + 0.043912*(-1.*t3704*t9158 + t3521*t9183) - 1.325152*(t3521*t9158 + t3704*t9183);
  p_output1(41)=t8661*t8881 + t8817*t9256 + t3447*t9315 + t3236*t9328 + t3930*t9355 + t3747*t9411 + 0.043912*(-1.*t3704*t9355 + t3521*t9411) - 1.325152*(t3521*t9355 + t3704*t9411);
  p_output1(42)=t3930*t5079 + t4914*t9515 + t4961*t9522 + t3747*t9564 - 1.325152*(t5230 + t3704*t9564) + 0.043912*(t3521*t9564 + t9567);
  p_output1(43)=t9130*t9522 + t9515*t9609 + t3930*t9629 + t3747*t9652 + 0.043912*(t3521*t9652 + t9672) - 1.325152*(t3704*t9652 + t9716);
  p_output1(44)=t9328*t9522 + t9515*t9784 + t3930*t9803 + t3747*t9824 + 0.043912*(t3521*t9824 + t9828) - 1.325152*(t3704*t9824 + t9834);
  p_output1(45)=-1.325152*t5284 + 0.043912*(-1.*t3521*t5156 + t9567) + t5079*t9840 + t5156*t9846;
  p_output1(46)=t9629*t9840 + t9846*t9862 + 0.043912*(t9672 - 1.*t3521*t9862) - 1.325152*(t9716 - 1.*t3704*t9862);
  p_output1(47)=t9803*t9840 + t9846*t9875 + 0.043912*(t9828 - 1.*t3521*t9875) - 1.325152*(t9834 - 1.*t3704*t9875);
}


       
void Jp_RightFootFront(Eigen::Matrix<double,3,16> &p_output1, const Eigen::Matrix<double,16,1> &var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
