/*
 * Automatically Generated from Mathematica.
 * Thu 23 Aug 2018 15:52:35 GMT-05:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "RobotSystem/RobotModel/Robot/Draco/DracoGen/dyn_eigen/include/Ge_Draco.h"

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
static void output1(Eigen::Matrix<double,16,1> &p_output1, const Eigen::Matrix<double,16,1> &var1)
{
  double t728;
  double t75;
  double t471;
  double t5544;
  double t6303;
  double t6589;
  double t7334;
  double t960;
  double t6745;
  double t7408;
  double t7436;
  double t7639;
  double t22947;
  double t23579;
  double t23712;
  double t25026;
  double t25383;
  double t25389;
  double t25397;
  double t25464;
  double t25040;
  double t25110;
  double t25133;
  double t25225;
  double t25229;
  double t25233;
  double t25343;
  double t25414;
  double t25507;
  double t25519;
  double t25536;
  double t25541;
  double t25569;
  double t25588;
  double t25596;
  double t25611;
  double t25648;
  double t25686;
  double t25867;
  double t25873;
  double t25879;
  double t25899;
  double t25806;
  double t25821;
  double t25837;
  double t25885;
  double t25933;
  double t25941;
  double t25947;
  double t25985;
  double t25995;
  double t26011;
  double t26237;
  double t26260;
  double t26291;
  double t26300;
  double t26508;
  double t26513;
  double t26533;
  double t26554;
  double t26453;
  double t26469;
  double t26474;
  double t26497;
  double t26547;
  double t26566;
  double t26571;
  double t26575;
  double t26579;
  double t26584;
  double t26589;
  double t26647;
  double t26652;
  double t26668;
  double t26869;
  double t27444;
  double t27502;
  double t27564;
  double t27587;
  double t26881;
  double t26917;
  double t27090;
  double t7675;
  double t29772;
  double t29783;
  double t29794;
  double t29863;
  double t29805;
  double t29884;
  double t29910;
  double t29934;
  double t29956;
  double t29978;
  double t30003;
  double t30025;
  double t30140;
  double t30162;
  double t30185;
  double t30198;
  double t30046;
  double t30071;
  double t30093;
  double t30264;
  double t30266;
  double t30267;
  double t30270;
  double t30268;
  double t30271;
  double t30272;
  double t30273;
  double t30274;
  double t30282;
  double t30283;
  double t30287;
  double t30288;
  double t30289;
  double t30290;
  double t30292;
  double t30293;
  double t30294;
  double t30299;
  double t30300;
  double t30301;
  double t30303;
  double t30302;
  double t30304;
  double t30305;
  double t30309;
  double t30310;
  double t30330;
  double t30353;
  double t30376;
  double t30398;
  double t30409;
  double t30420;
  double t30536;
  double t30539;
  double t30540;
  double t30542;
  double t30442;
  double t30453;
  double t30463;
  double t30541;
  double t30545;
  double t30546;
  double t30547;
  double t30549;
  double t30550;
  double t30553;
  double t30554;
  double t30555;
  double t30560;
  double t30562;
  double t30572;
  double t30573;
  double t30574;
  double t30576;
  double t30564;
  double t30566;
  double t30567;
  double t30843;
  double t30844;
  double t30852;
  double t30853;
  double t30854;
  double t30856;
  double t30857;
  double t30859;
  double t30860;
  double t30861;
  double t30865;
  double t30866;
  double t30868;
  double t30869;
  double t30870;
  double t30872;
  double t30881;
  double t30883;
  double t30896;
  double t30897;
  double t30898;
  double t27584;
  double t27926;
  double t27933;
  double t30900;
  double t30905;
  double t30909;
  double t28095;
  double t28121;
  double t28543;
  double t30933;
  double t30939;
  double t30940;
  double t30845;
  double t30970;
  double t30971;
  double t30975;
  double t30980;
  double t30997;
  double t31017;
  double t31031;
  double t30981;
  double t30982;
  double t30987;
  double t31067;
  double t31075;
  double t31083;
  double t31090;
  double t31095;
  double t31120;
  double t31124;
  double t31130;
  double t31148;
  double t31152;
  double t30575;
  double t30577;
  double t30578;
  double t31156;
  double t31163;
  double t31168;
  double t30588;
  double t30610;
  double t30635;
  double t31172;
  double t31173;
  double t31185;
  double t31310;
  double t31318;
  double t31319;
  double t31325;
  double t31328;
  double t31330;
  double t31334;
  double t31337;
  double t31339;
  double t31343;
  double t31346;
  double t31348;
  double t31355;
  double t31356;
  double t31399;
  double t31430;
  double t31431;
  double t31447;
  double t31451;
  double t31455;
  double t31467;
  double t31474;
  double t31475;
  double t31508;
  double t31509;
  double t31510;
  double t31511;
  double t31512;
  double t31515;
  double t31516;
  double t31517;
  double t31547;
  double t31549;
  double t31552;
  double t31553;
  double t31554;
  double t31556;
  double t31557;
  double t31558;
  double t31563;
  double t31565;
  double t31567;
  double t31569;
  double t31570;
  double t31576;
  double t31580;
  double t31582;
  double t31583;
  double t31584;
  double t31586;
  double t31595;
  double t31596;
  double t31599;
  double t31630;
  double t31631;
  double t31632;
  double t31626;
  double t31627;
  double t31628;
  double t31629;
  double t31633;
  double t31635;
  double t31638;
  double t31644;
  double t31649;
  double t31650;
  double t31669;
  double t31670;
  double t31676;
  double t31686;
  double t31687;
  double t31688;
  double t31689;
  double t31699;
  double t31702;
  double t31703;
  double t31704;
  double t31773;
  double t31775;
  double t31776;
  double t31769;
  double t31771;
  double t31772;
  double t31781;
  double t31789;
  double t31790;
  double t31791;
  double t31792;
  double t31793;
  double t31795;
  double t31796;
  double t31831;
  double t31848;
  double t31849;
  double t31850;
  double t31835;
  double t31860;
  double t31861;
  double t31862;
  double t31863;
  double t31864;
  double t31865;
  double t31866;
  double t31867;
  double t31868;
  double t31869;
  double t31870;
  double t31871;
  double t31872;
  double t31873;
  double t31878;
  double t31882;
  double t31884;
  double t31885;
  double t31886;
  double t31887;
  double t31889;
  double t31890;
  double t31891;
  double t31895;
  double t31896;
  double t31897;
  double t31898;
  double t31899;
  double t31900;
  double t31902;
  double t31903;
  double t31904;
  double t31921;
  double t31922;
  double t31923;
  double t31924;
  double t31925;
  double t31926;
  double t31927;
  double t31928;
  double t31929;
  double t31930;
  double t31932;
  double t31933;
  double t31934;
  double t31939;
  double t31944;
  double t31945;
  double t31946;
  double t31947;
  double t31948;
  double t31949;
  double t31951;
  double t31952;
  double t31953;
  double t31972;
  double t31973;
  double t31974;
  double t31970;
  double t31971;
  double t31975;
  double t31976;
  double t31977;
  double t31978;
  double t31979;
  double t31980;
  double t31981;
  double t31982;
  double t31984;
  double t31986;
  double t31987;
  double t31992;
  double t31993;
  double t31994;
  double t31995;
  double t31996;
  double t31998;
  double t31999;
  double t32009;
  double t32062;
  double t32066;
  double t32067;
  double t32056;
  double t32060;
  double t32061;
  double t32068;
  double t32072;
  double t32075;
  double t32076;
  double t32077;
  double t32081;
  double t32083;
  double t32087;
  double t32113;
  double t32130;
  double t32131;
  double t32132;
  double t32117;
  t728 = Sin(var1[4]);
  t75 = Cos(var1[4]);
  t471 = Cos(var1[5]);
  t5544 = Cos(var1[11]);
  t6303 = -1.*t5544;
  t6589 = 1. + t6303;
  t7334 = Sin(var1[11]);
  t960 = Sin(var1[5]);
  t6745 = -0.0222*t6589;
  t7408 = -0.087*t7334;
  t7436 = t6745 + t7408;
  t7639 = -1.*t75*t7436;
  t22947 = -0.087*t6589;
  t23579 = 0.0222*t7334;
  t23712 = t22947 + t23579;
  t25026 = -1.*t23712*t728*t960;
  t25383 = Cos(var1[12]);
  t25389 = -1.*t25383;
  t25397 = 1. + t25389;
  t25464 = Sin(var1[12]);
  t25040 = t75*t7334;
  t25110 = -1.*t5544*t728*t960;
  t25133 = t25040 + t25110;
  t25225 = -1.*t5544*t75;
  t25229 = -1.*t7334*t728*t960;
  t25233 = t25225 + t25229;
  t25343 = -0.0222*t25233;
  t25414 = -0.3151*t25397;
  t25507 = 0.157*t25464;
  t25519 = t25414 + t25507;
  t25536 = -1.*t471*t25519*t728;
  t25541 = -0.157*t25397;
  t25569 = -0.3151*t25464;
  t25588 = t25541 + t25569;
  t25596 = t25588*t25133;
  t25611 = -1.*t471*t25464*t728;
  t25648 = t25383*t25133;
  t25686 = t25611 + t25648;
  t25867 = Cos(var1[13]);
  t25873 = -1.*t25867;
  t25879 = 1. + t25873;
  t25899 = Sin(var1[13]);
  t25806 = -1.*t25383*t471*t728;
  t25821 = -1.*t25464*t25133;
  t25837 = t25806 + t25821;
  t25885 = -0.0222*t25879;
  t25933 = 0.3801*t25899;
  t25941 = t25885 + t25933;
  t25947 = t25941*t25233;
  t25985 = -0.3801*t25879;
  t25995 = -0.0222*t25899;
  t26011 = t25985 + t25995;
  t26237 = t26011*t25837;
  t26260 = t25899*t25233;
  t26291 = t25867*t25837;
  t26300 = t26260 + t26291;
  t26508 = Cos(var1[14]);
  t26513 = -1.*t26508;
  t26533 = 1. + t26513;
  t26554 = Sin(var1[14]);
  t26453 = t25867*t25233;
  t26469 = -1.*t25899*t25837;
  t26474 = t26453 + t26469;
  t26497 = -0.16705*t25686;
  t26547 = -0.8601*t26533;
  t26566 = -0.0222*t26554;
  t26571 = t26547 + t26566;
  t26575 = t26571*t26300;
  t26579 = -0.0222*t26533;
  t26584 = 0.8601*t26554;
  t26589 = t26579 + t26584;
  t26647 = t26589*t26474;
  t26652 = -1.*t26554*t26300;
  t26668 = t26508*t26474;
  t26869 = t26652 + t26668;
  t27444 = Cos(var1[15]);
  t27502 = -1.*t27444;
  t27564 = 1. + t27502;
  t27587 = Sin(var1[15]);
  t26881 = t26508*t26300;
  t26917 = t26554*t26474;
  t27090 = t26881 + t26917;
  t7675 = 0.2451*t471*t728;
  t29772 = Cos(var1[6]);
  t29783 = -1.*t29772;
  t29794 = 1. + t29783;
  t29863 = Sin(var1[6]);
  t29805 = 0.087*t29794;
  t29884 = 0.0222*t29863;
  t29910 = t29805 + t29884;
  t29934 = -1.*t728*t960*t29910;
  t29956 = -0.0222*t29794;
  t29978 = 0.087*t29863;
  t30003 = t29956 + t29978;
  t30025 = -1.*t75*t30003;
  t30140 = -1.*t75*t29772;
  t30162 = -1.*t728*t960*t29863;
  t30185 = t30140 + t30162;
  t30198 = -0.0222*t30185;
  t30046 = -1.*t29772*t728*t960;
  t30071 = t75*t29863;
  t30093 = t30046 + t30071;
  t30264 = Cos(var1[7]);
  t30266 = -1.*t30264;
  t30267 = 1. + t30266;
  t30270 = Sin(var1[7]);
  t30268 = 0.157*t30267;
  t30271 = -0.3151*t30270;
  t30272 = t30268 + t30271;
  t30273 = t30093*t30272;
  t30274 = -0.3151*t30267;
  t30282 = -0.157*t30270;
  t30283 = t30274 + t30282;
  t30287 = -1.*t471*t728*t30283;
  t30288 = t30264*t30093;
  t30289 = -1.*t471*t728*t30270;
  t30290 = t30288 + t30289;
  t30292 = -1.*t471*t30264*t728;
  t30293 = -1.*t30093*t30270;
  t30294 = t30292 + t30293;
  t30299 = Cos(var1[8]);
  t30300 = -1.*t30299;
  t30301 = 1. + t30300;
  t30303 = Sin(var1[8]);
  t30302 = -0.3801*t30301;
  t30304 = -0.0222*t30303;
  t30305 = t30302 + t30304;
  t30309 = t30294*t30305;
  t30310 = -0.0222*t30301;
  t30330 = 0.3801*t30303;
  t30353 = t30310 + t30330;
  t30376 = t30185*t30353;
  t30398 = t30299*t30294;
  t30409 = t30185*t30303;
  t30420 = t30398 + t30409;
  t30536 = Cos(var1[9]);
  t30539 = -1.*t30536;
  t30540 = 1. + t30539;
  t30542 = Sin(var1[9]);
  t30442 = t30299*t30185;
  t30453 = -1.*t30294*t30303;
  t30463 = t30442 + t30453;
  t30541 = -0.8601*t30540;
  t30545 = -0.0222*t30542;
  t30546 = t30541 + t30545;
  t30547 = t30546*t30420;
  t30549 = -0.0222*t30540;
  t30550 = 0.8601*t30542;
  t30553 = t30549 + t30550;
  t30554 = t30553*t30463;
  t30555 = -1.*t30542*t30420;
  t30560 = t30536*t30463;
  t30562 = t30555 + t30560;
  t30572 = Cos(var1[10]);
  t30573 = -1.*t30572;
  t30574 = 1. + t30573;
  t30576 = Sin(var1[10]);
  t30564 = t30536*t30420;
  t30566 = t30542*t30463;
  t30567 = t30564 + t30566;
  t30843 = t75*t471*t23712;
  t30844 = -0.0222*t75*t471*t7334;
  t30852 = t5544*t75*t471*t25588;
  t30853 = -1.*t75*t25519*t960;
  t30854 = -1.*t5544*t75*t471*t25464;
  t30856 = -1.*t25383*t75*t960;
  t30857 = t30854 + t30856;
  t30859 = t5544*t25383*t75*t471;
  t30860 = -1.*t75*t25464*t960;
  t30861 = t30859 + t30860;
  t30865 = t75*t471*t7334*t25941;
  t30866 = t26011*t30857;
  t30868 = t75*t471*t7334*t25899;
  t30869 = t25867*t30857;
  t30870 = t30868 + t30869;
  t30872 = t25867*t75*t471*t7334;
  t30881 = -1.*t25899*t30857;
  t30883 = t30872 + t30881;
  t30896 = -0.16705*t30861;
  t30897 = t26571*t30870;
  t30898 = t26589*t30883;
  t27584 = -0.0211*t27564;
  t27926 = 1.3401*t27587;
  t27933 = t27584 + t27926;
  t30900 = -1.*t26554*t30870;
  t30905 = t26508*t30883;
  t30909 = t30900 + t30905;
  t28095 = -1.3401*t27564;
  t28121 = -0.0211*t27587;
  t28543 = t28095 + t28121;
  t30933 = t26508*t30870;
  t30939 = t26554*t30883;
  t30940 = t30933 + t30939;
  t30845 = 0.2451*t75*t960;
  t30970 = t75*t471*t29910;
  t30971 = -0.0222*t75*t471*t29863;
  t30975 = t75*t471*t29772*t30272;
  t30980 = -1.*t75*t960*t30283;
  t30997 = t75*t471*t29772*t30264;
  t31017 = -1.*t75*t960*t30270;
  t31031 = t30997 + t31017;
  t30981 = -1.*t75*t30264*t960;
  t30982 = -1.*t75*t471*t29772*t30270;
  t30987 = t30981 + t30982;
  t31067 = t30987*t30305;
  t31075 = t75*t471*t29863*t30353;
  t31083 = t30299*t30987;
  t31090 = t75*t471*t29863*t30303;
  t31095 = t31083 + t31090;
  t31120 = t75*t471*t30299*t29863;
  t31124 = -1.*t30987*t30303;
  t31130 = t31120 + t31124;
  t31148 = t30546*t31095;
  t31152 = t30553*t31130;
  t30575 = -0.0211*t30574;
  t30577 = 1.3401*t30576;
  t30578 = t30575 + t30577;
  t31156 = -1.*t30542*t31095;
  t31163 = t30536*t31130;
  t31168 = t31156 + t31163;
  t30588 = -1.3401*t30574;
  t30610 = -0.0211*t30576;
  t30635 = t30588 + t30610;
  t31172 = t30536*t31095;
  t31173 = t30542*t31130;
  t31185 = t31172 + t31173;
  t31310 = 0.087*t29772;
  t31318 = -0.0222*t29863;
  t31319 = t31310 + t31318;
  t31325 = -1.*t728*t31319;
  t31328 = 0.0222*t29772;
  t31330 = t31328 + t29978;
  t31334 = t75*t960*t31330;
  t31337 = t75*t29772*t960;
  t31339 = t728*t29863;
  t31343 = t31337 + t31339;
  t31346 = -0.0222*t31343;
  t31348 = t29772*t728;
  t31355 = -1.*t75*t960*t29863;
  t31356 = t31348 + t31355;
  t31399 = t31356*t30272;
  t31430 = -1.*t31356*t30270*t30305;
  t31431 = t31343*t30353;
  t31447 = -1.*t30299*t31356*t30270;
  t31451 = t31343*t30303;
  t31455 = t31447 + t31451;
  t31467 = t30299*t31343;
  t31474 = t31356*t30270*t30303;
  t31475 = t31467 + t31474;
  t31508 = t30546*t31455;
  t31509 = t30553*t31475;
  t31510 = -1.*t30542*t31455;
  t31511 = t30536*t31475;
  t31512 = t31510 + t31511;
  t31515 = t30536*t31455;
  t31516 = t30542*t31475;
  t31517 = t31515 + t31516;
  t31547 = -0.157*t30264;
  t31549 = t31547 + t30271;
  t31552 = t75*t471*t31549;
  t31553 = -0.3151*t30264;
  t31554 = 0.157*t30270;
  t31556 = t31553 + t31554;
  t31557 = t31343*t31556;
  t31558 = -1.*t30264*t31343;
  t31563 = -1.*t75*t471*t30270;
  t31565 = t31558 + t31563;
  t31567 = t75*t471*t30264;
  t31569 = -1.*t31343*t30270;
  t31570 = t31567 + t31569;
  t31576 = t31565*t30305;
  t31580 = t30299*t30546*t31565;
  t31582 = -1.*t30553*t31565*t30303;
  t31583 = -1.*t30299*t30542*t31565;
  t31584 = -1.*t30536*t31565*t30303;
  t31586 = t31583 + t31584;
  t31595 = t30536*t30299*t31565;
  t31596 = -1.*t30542*t31565*t30303;
  t31599 = t31595 + t31596;
  t31630 = -1.*t29772*t728;
  t31631 = t75*t960*t29863;
  t31632 = t31630 + t31631;
  t31626 = -0.0222*t30299;
  t31627 = -0.3801*t30303;
  t31628 = t31626 + t31627;
  t31629 = t31570*t31628;
  t31633 = 0.3801*t30299;
  t31635 = t31633 + t30304;
  t31638 = t31632*t31635;
  t31644 = -1.*t30299*t31570;
  t31649 = -1.*t31632*t30303;
  t31650 = t31644 + t31649;
  t31669 = t30299*t31632;
  t31670 = -1.*t31570*t30303;
  t31676 = t31669 + t31670;
  t31686 = t30553*t31650;
  t31687 = t30546*t31676;
  t31688 = t30542*t31650;
  t31689 = t30536*t31676;
  t31699 = t31688 + t31689;
  t31702 = t30536*t31650;
  t31703 = -1.*t30542*t31676;
  t31704 = t31702 + t31703;
  t31773 = t30299*t31570;
  t31775 = t31632*t30303;
  t31776 = t31773 + t31775;
  t31769 = -0.0222*t30536;
  t31771 = -0.8601*t30542;
  t31772 = t31769 + t31771;
  t31781 = t31772*t31776;
  t31789 = 0.8601*t30536;
  t31790 = t31789 + t30545;
  t31791 = t31790*t31676;
  t31792 = -1.*t30542*t31776;
  t31793 = t31792 + t31689;
  t31795 = -1.*t30536*t31776;
  t31796 = t31795 + t31703;
  t31831 = -1.*t30576*t31793;
  t31848 = t30536*t31776;
  t31849 = t30542*t31676;
  t31850 = t31848 + t31849;
  t31835 = t30572*t31793;
  t31860 = -0.087*t5544;
  t31861 = -0.0222*t7334;
  t31862 = t31860 + t31861;
  t31863 = -1.*t31862*t728;
  t31864 = 0.0222*t5544;
  t31865 = t31864 + t7408;
  t31866 = t75*t31865*t960;
  t31867 = t7334*t728;
  t31868 = t5544*t75*t960;
  t31869 = t31867 + t31868;
  t31870 = -0.0222*t31869;
  t31871 = t5544*t728;
  t31872 = -1.*t75*t7334*t960;
  t31873 = t31871 + t31872;
  t31878 = t25588*t31873;
  t31882 = t25941*t31869;
  t31884 = -1.*t25464*t26011*t31873;
  t31885 = t25899*t31869;
  t31886 = -1.*t25867*t25464*t31873;
  t31887 = t31885 + t31886;
  t31889 = t25867*t31869;
  t31890 = t25464*t25899*t31873;
  t31891 = t31889 + t31890;
  t31895 = -0.16705*t25383*t31873;
  t31896 = t26571*t31887;
  t31897 = t26589*t31891;
  t31898 = -1.*t26554*t31887;
  t31899 = t26508*t31891;
  t31900 = t31898 + t31899;
  t31902 = t26508*t31887;
  t31903 = t26554*t31891;
  t31904 = t31902 + t31903;
  t31921 = 0.157*t25383;
  t31922 = t31921 + t25569;
  t31923 = t75*t471*t31922;
  t31924 = -0.3151*t25383;
  t31925 = -0.157*t25464;
  t31926 = t31924 + t31925;
  t31927 = t31926*t31869;
  t31928 = -1.*t75*t471*t25464;
  t31929 = -1.*t25383*t31869;
  t31930 = t31928 + t31929;
  t31932 = t25383*t75*t471;
  t31933 = -1.*t25464*t31869;
  t31934 = t31932 + t31933;
  t31939 = t26011*t31930;
  t31944 = t25867*t26571*t31930;
  t31945 = -1.*t25899*t26589*t31930;
  t31946 = -0.16705*t31934;
  t31947 = -1.*t26508*t25899*t31930;
  t31948 = -1.*t25867*t26554*t31930;
  t31949 = t31947 + t31948;
  t31951 = t25867*t26508*t31930;
  t31952 = -1.*t25899*t26554*t31930;
  t31953 = t31951 + t31952;
  t31972 = -1.*t5544*t728;
  t31973 = t75*t7334*t960;
  t31974 = t31972 + t31973;
  t31970 = 0.3801*t25867;
  t31971 = t31970 + t25995;
  t31975 = t31971*t31974;
  t31976 = -0.0222*t25867;
  t31977 = -0.3801*t25899;
  t31978 = t31976 + t31977;
  t31979 = t31978*t31934;
  t31980 = -1.*t25899*t31974;
  t31981 = -1.*t25867*t31934;
  t31982 = t31980 + t31981;
  t31984 = t25867*t31974;
  t31986 = -1.*t25899*t31934;
  t31987 = t31984 + t31986;
  t31992 = t26589*t31982;
  t31993 = t26571*t31987;
  t31994 = t26554*t31982;
  t31995 = t26508*t31987;
  t31996 = t31994 + t31995;
  t31998 = t26508*t31982;
  t31999 = -1.*t26554*t31987;
  t32009 = t31998 + t31999;
  t32062 = t25899*t31974;
  t32066 = t25867*t31934;
  t32067 = t32062 + t32066;
  t32056 = -0.0222*t26508;
  t32060 = -0.8601*t26554;
  t32061 = t32056 + t32060;
  t32068 = t32061*t32067;
  t32072 = 0.8601*t26508;
  t32075 = t32072 + t26566;
  t32076 = t32075*t31987;
  t32077 = -1.*t26554*t32067;
  t32081 = t32077 + t31995;
  t32083 = -1.*t26508*t32067;
  t32087 = t32083 + t31999;
  t32113 = -1.*t27587*t32081;
  t32130 = t26508*t32067;
  t32131 = t26554*t31987;
  t32132 = t32130 + t32131;
  t32117 = t27444*t32081;

  p_output1(0)=0;
  p_output1(1)=0;
  p_output1(2)=361.1061;
  p_output1(3)=0;
  p_output1(4)=4.00248*(t29934 + t30025 + t30198 + t30273 + t30287 + 0.179*t30290 - 0.3351*t30294) + 58.86*(t29934 + t30025 + t30273 + t30287 + 0.1736*t30290 + t30309 + t30376 - 0.6201*t30420 - 0.0213*t30463) + 34.335*(t29934 + t30025 + t30273 + t30287 + 0.1669*t30290 + t30309 + t30376 + t30547 + t30554 - 0.0061*t30562 - 1.1351*t30567) + 6.867*(t29934 + t30025 + t30273 + t30287 + 0.167*t30290 + t30309 + t30376 + t30547 + t30554 - 1.329335*(t30567*t30572 + t30562*t30576) + 0.023209*(t30562*t30572 - 1.*t30567*t30576) + t30562*t30578 + t30567*t30635) + 4.00248*(t25026 + t25343 + t25536 + t25596 - 0.179*t25686 - 0.3351*t25837 + t7639) + 58.86*(t25026 + t25536 + t25596 - 0.1604*t25686 + t25947 + t26237 - 0.6201*t26300 - 0.0213*t26474 + t7639) + 34.335*(t25026 + t25536 + t25596 + t25947 + t26237 + t26497 + t26575 + t26647 - 0.0383*t26869 - 1.1351*t27090 + t7639) + 6.867*(t25026 + t25536 + t25596 + t25947 + t26237 + t26497 + t26575 + t26647 - 1.329335*(t27090*t27444 + t26869*t27587) + 0.023209*(t26869*t27444 - 1.*t27090*t27587) + t26869*t27933 + t27090*t28543 + t7639) + 29.057220000000004*(t29934 + t30025 + 0.157*t30093 + t30198 + t7675) + 29.057220000000004*(t25026 - 0.157*t25133 + t25343 + t7639 + t7675) + 94.8627*(0.187273*t471*t728 + 0.013391*t75 - 0.000754*t728*t960);
  p_output1(5)=4.00248*(t30843 + t30844 + t30852 + t30853 - 0.3351*t30857 - 0.179*t30861) + 58.86*(t30843 + t30852 + t30853 - 0.1604*t30861 + t30865 + t30866 - 0.6201*t30870 - 0.0213*t30883) + 34.335*(t30843 + t30852 + t30853 + t30865 + t30866 + t30896 + t30897 + t30898 - 0.0383*t30909 - 1.1351*t30940) + 6.867*(t30843 + t30852 + t30853 + t30865 + t30866 + t30896 + t30897 + t30898 + t27933*t30909 + t28543*t30940 - 1.329335*(t27587*t30909 + t27444*t30940) + 0.023209*(t27444*t30909 - 1.*t27587*t30940)) + 4.00248*(t30970 + t30971 + t30975 + t30980 - 0.3351*t30987 + 0.179*t31031) + 58.86*(t30970 + t30975 + t30980 + 0.1736*t31031 + t31067 + t31075 - 0.6201*t31095 - 0.0213*t31130) + 34.335*(t30970 + t30975 + t30980 + 0.1669*t31031 + t31067 + t31075 + t31148 + t31152 - 0.0061*t31168 - 1.1351*t31185) + 6.867*(t30970 + t30975 + t30980 + 0.167*t31031 + t31067 + t31075 + t31148 + t31152 + t30578*t31168 + t30635*t31185 - 1.329335*(t30576*t31168 + t30572*t31185) + 0.023209*(t30572*t31168 - 1.*t30576*t31185)) + 29.057220000000004*(t30845 + t30970 + t30971 + 0.157*t29772*t471*t75) + 29.057220000000004*(t30843 + t30844 + t30845 - 0.157*t471*t5544*t75) + 94.8627*(0.000754*t471*t75 + 0.187273*t75*t960);
  p_output1(6)=29.057220000000004*(t31325 + t31334 + t31346 + 0.157*t31356) + 4.00248*(t31325 + t31334 + t31346 + 0.179*t30264*t31356 + 0.3351*t30270*t31356 + t31399) + 58.86*(t31325 + t31334 + 0.1736*t30264*t31356 + t31399 + t31430 + t31431 - 0.6201*t31455 - 0.0213*t31475) + 34.335*(t31325 + t31334 + 0.1669*t30264*t31356 + t31399 + t31430 + t31431 + t31508 + t31509 - 0.0061*t31512 - 1.1351*t31517) + 6.867*(t31325 + t31334 + 0.167*t30264*t31356 + t31399 + t31430 + t31431 + t31508 + t31509 + t30578*t31512 + t30635*t31517 - 1.329335*(t30576*t31512 + t30572*t31517) + 0.023209*(t30572*t31512 - 1.*t30576*t31517));
  p_output1(7)=4.00248*(t31552 + t31557 - 0.3351*t31565 + 0.179*t31570) + 58.86*(t31552 + t31557 - 0.6201*t30299*t31565 + 0.0213*t30303*t31565 + 0.1736*t31570 + t31576) + 34.335*(t31552 + t31557 + 0.1669*t31570 + t31576 + t31580 + t31582 - 0.0061*t31586 - 1.1351*t31599) + 6.867*(t31552 + t31557 + 0.167*t31570 + t31576 + t31580 + t31582 + t30578*t31586 + t30635*t31599 - 1.329335*(t30576*t31586 + t30572*t31599) + 0.023209*(t30572*t31586 - 1.*t30576*t31599));
  p_output1(8)=58.86*(t31629 + t31638 - 0.0213*t31650 - 0.6201*t31676) + 34.335*(t31629 + t31638 + t31686 + t31687 - 1.1351*t31699 - 0.0061*t31704) + 6.867*(t31629 + t31638 + t31686 + t31687 + t30635*t31699 + t30578*t31704 + 0.023209*(-1.*t30576*t31699 + t30572*t31704) - 1.329335*(t30572*t31699 + t30576*t31704));
  p_output1(9)=34.335*(t31781 + t31791 - 1.1351*t31793 - 0.0061*t31796) + 6.867*(t31781 + t31791 + t30635*t31793 + t30578*t31796 + 0.023209*(t30572*t31796 + t31831) - 1.329335*(t30576*t31796 + t31835));
  p_output1(10)=6.867*((1.3401*t30572 + t30610)*t31793 + (-0.0211*t30572 - 1.3401*t30576)*t31850 + 0.023209*(t31831 - 1.*t30572*t31850) - 1.329335*(t31835 - 1.*t30576*t31850));
  p_output1(11)=29.057220000000004*(t31863 + t31866 + t31870 - 0.157*t31873) + 4.00248*(t31863 + t31866 + t31870 - 0.179*t25383*t31873 + 0.3351*t25464*t31873 + t31878) + 58.86*(t31863 + t31866 - 0.1604*t25383*t31873 + t31878 + t31882 + t31884 - 0.6201*t31887 - 0.0213*t31891) + 34.335*(t31863 + t31866 + t31878 + t31882 + t31884 + t31895 + t31896 + t31897 - 0.0383*t31900 - 1.1351*t31904) + 6.867*(t31863 + t31866 + t31878 + t31882 + t31884 + t31895 + t31896 + t31897 + t27933*t31900 + t28543*t31904 - 1.329335*(t27587*t31900 + t27444*t31904) + 0.023209*(t27444*t31900 - 1.*t27587*t31904));
  p_output1(12)=4.00248*(t31923 + t31927 - 0.3351*t31930 - 0.179*t31934) + 58.86*(t31923 + t31927 - 0.6201*t25867*t31930 + 0.0213*t25899*t31930 - 0.1604*t31934 + t31939) + 34.335*(t31923 + t31927 + t31939 + t31944 + t31945 + t31946 - 0.0383*t31949 - 1.1351*t31953) + 6.867*(t31923 + t31927 + t31939 + t31944 + t31945 + t31946 + t27933*t31949 + t28543*t31953 - 1.329335*(t27587*t31949 + t27444*t31953) + 0.023209*(t27444*t31949 - 1.*t27587*t31953));
  p_output1(13)=58.86*(t31975 + t31979 - 0.0213*t31982 - 0.6201*t31987) + 34.335*(t31975 + t31979 + t31992 + t31993 - 1.1351*t31996 - 0.0383*t32009) + 6.867*(t31975 + t31979 + t31992 + t31993 + t28543*t31996 + t27933*t32009 + 0.023209*(-1.*t27587*t31996 + t27444*t32009) - 1.329335*(t27444*t31996 + t27587*t32009));
  p_output1(14)=34.335*(t32068 + t32076 - 1.1351*t32081 - 0.0383*t32087) + 6.867*(t32068 + t32076 + t28543*t32081 + t27933*t32087 + 0.023209*(t27444*t32087 + t32113) - 1.329335*(t27587*t32087 + t32117));
  p_output1(15)=6.867*((1.3401*t27444 + t28121)*t32081 + (-0.0211*t27444 - 1.3401*t27587)*t32132 + 0.023209*(t32113 - 1.*t27444*t32132) - 1.329335*(t32117 - 1.*t27587*t32132));
}


       
void Ge_Draco(Eigen::Matrix<double,16,1> &p_output1, const Eigen::Matrix<double,16,1> &var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
