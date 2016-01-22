/*
 * iLBC - a library for the iLBC codec
 *
 * constant.c - The iLBC low bit rate speech codec.
 *
 * Adapted by Steve Underwood <steveu@coppice.org> from the reference
 * iLBC code supplied in RFC3951.
 *
 * Original code Copyright (C) The Internet Society (2004).
 * All changes to produce this version Copyright (C) 2008 by Steve Underwood
 * All Rights Reserved.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * $Id: constants.c,v 1.2 2008/03/06 12:27:38 steveu Exp $
 */

/*! \file */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <inttypes.h>

#include "ilbc.h"
#include "constants.h"

/* ULP bit allocation */

/* 20 ms frame */
const ilbc_ulp_inst_t ULP_20msTbl =
{
    /* LSF */
    {
        {6, 0, 0, 0, 0}, {7, 0, 0, 0, 0}, {7, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}
    },
    /* Start state location, gain and samples */
    {2, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {6, 0, 0, 0, 0},
    {0, 1, 2, 0, 0},
    /* extra CB index and extra CB gain */
    {{6, 0, 1, 0, 0}, {0, 0, 7, 0, 0}, {0, 0, 7, 0, 0}},
    {{2, 0, 3, 0, 0}, {1, 1, 2, 0, 0}, {0, 0, 3, 0, 0}},
    /* CB index and CB gain */
    {
        {{7, 0, 1, 0, 0}, {0, 0, 7, 0, 0}, {0, 0, 7, 0, 0}},
        {{0, 0, 8, 0, 0}, {0, 0, 8, 0, 0}, {0, 0, 8, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}
    },
    {
        {{1, 2, 2, 0, 0}, {1, 1, 2, 0, 0}, {0, 0, 3, 0, 0}},
        {{1, 1, 3, 0, 0}, {0, 2, 2, 0, 0}, {0, 0, 3, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}
    }
};

/* 30 ms frame */
const ilbc_ulp_inst_t ULP_30msTbl =
{
    /* LSF */
    {
        {6, 0, 0, 0, 0}, {7, 0, 0, 0, 0}, {7, 0, 0, 0, 0},
        {6, 0, 0, 0, 0}, {7, 0, 0, 0, 0}, {7, 0, 0, 0, 0}
    },
    /* Start state location, gain and samples */
    {3, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {6, 0, 0, 0, 0},
    {0, 1, 2, 0, 0},
    /* extra CB index and extra CB gain */
    {{4, 2, 1, 0, 0}, {0, 0, 7, 0, 0}, {0, 0, 7, 0, 0}},
    {{1, 1, 3, 0, 0}, {1, 1, 2, 0, 0}, {0, 0, 3, 0, 0}},
    /* CB index and CB gain */
    {
        {{6, 1, 1, 0, 0}, {0, 0, 7, 0, 0}, {0, 0,7, 0, 0}},
        {{0, 7, 1, 0, 0}, {0, 0, 8, 0, 0}, {0, 0,8, 0, 0}},
        {{0, 7, 1, 0, 0}, {0, 0, 8, 0, 0}, {0, 0,8, 0, 0}},
        {{0, 7, 1, 0, 0}, {0, 0, 8, 0, 0}, {0, 0,8, 0, 0}}
    },
    {
        {{1, 2, 2, 0, 0}, {1, 2, 1, 0, 0}, {0, 0, 3, 0, 0}},
        {{0, 2, 3, 0, 0}, {0, 2, 2, 0, 0}, {0, 0, 3, 0, 0}},
        {{0, 1, 4, 0, 0}, {0, 1, 3, 0, 0}, {0, 0, 3, 0, 0}},
        {{0, 1, 4, 0, 0}, {0, 1, 3, 0, 0}, {0, 0, 3, 0, 0}}
    }
};

/* HP Filters */

const float hpi_zero_coefsTbl[3] =
{
    0.92727436f, -1.8544941f, 0.92727436f
};

const float hpi_pole_coefsTbl[3] =
{
    1.0f, -1.9059465f, 0.9114024f
};

const float hpo_zero_coefsTbl[3] =
{
    0.93980581f, -1.8795834f, 0.93980581f
};

const float hpo_pole_coefsTbl[3] =
{
    1.0f, -1.9330735f, 0.93589199f
};

/* LP Filter */

const float lpFilt_coefsTbl[FILTERORDER_DS] =
{
    -0.066650f,  0.125000f, 0.316650f,
     0.414063f,  0.316650f,
     0.125000f, -0.066650f
};

/* State quantization tables */

const float state_sq3Tbl[8] =
{
    -3.719849f, -2.177490f, -1.130005f,
    -0.309692f,  0.444214f,  1.329712f,
     2.436279f,  3.983887f
};

const float state_frgqTbl[64] =
{
    1.000085f, 1.071695f, 1.140395f,
    1.206868f, 1.277188f, 1.351503f,
    1.429380f, 1.500727f, 1.569049f,
    1.639599f, 1.707071f, 1.781531f,
    1.840799f, 1.901550f, 1.956695f,
    2.006750f, 2.055474f, 2.102787f,
    2.142819f, 2.183592f, 2.217962f,
    2.257177f, 2.295739f, 2.332967f,
    2.369248f, 2.402792f, 2.435080f,
    2.468598f, 2.503394f, 2.539284f,
    2.572944f, 2.605036f, 2.636331f,
    2.668939f, 2.698780f, 2.729101f,
    2.759786f, 2.789834f, 2.818679f,
    2.848074f, 2.877470f, 2.906899f,
    2.936655f, 2.967804f, 3.000115f,
    3.033367f, 3.066355f, 3.104231f,
    3.141499f, 3.183012f, 3.222952f,
    3.265433f, 3.308441f, 3.350823f,
    3.395275f, 3.442793f, 3.490801f,
    3.542514f, 3.604064f, 3.666050f,
    3.740994f, 3.830749f, 3.938770f,
    4.101764f
};

/* CB tables */

const int search_rangeTbl[5][CB_NSTAGES] =
{
    {58, 58, 58},
    {108, 44, 44},
    {108, 108, 108},
    {108, 108, 108},
    {108, 108, 108}
};

const int stMemLTbl = 85;
const int memLfTbl[NASUB_MAX] = {147, 147, 147, 147};

/* expansion filter(s) */

const float cbfiltersTbl[CB_FILTERLEN] =
{
    -0.034180f, 0.108887f, -0.184326f,
    0.806152f,  0.713379f, -0.144043f,
    0.083740f,  -0.033691f
};

/* Gain Quantization */

const float gain_sq3Tbl[8] =
{
    -1.000000f, -0.659973f, -0.330017f,
     0.000000f,  0.250000f,  0.500000f,
     0.750000f,  1.00000f
};

const float gain_sq4Tbl[16] =
{
    -1.049988f, -0.900024f, -0.750000f,
    -0.599976f, -0.450012f, -0.299988f,
    -0.150024f,  0.000000f,  0.150024f,
     0.299988f,  0.450012f,  0.599976f,
     0.750000f,  0.900024f,  1.049988f,
     1.200012f
};

const float gain_sq5Tbl[32]=
{
    0.037476f, 0.075012f, 0.112488f,
    0.150024f, 0.187500f, 0.224976f,
    0.262512f, 0.299988f, 0.337524f,
    0.375000f, 0.412476f, 0.450012f,
    0.487488f, 0.525024f, 0.562500f,
    0.599976f, 0.637512f, 0.674988f,
    0.712524f, 0.750000f, 0.787476f,
    0.825012f, 0.862488f, 0.900024f,
    0.937500f, 0.974976f, 1.012512f,
    1.049988f, 1.087524f, 1.125000f,
    1.162476f, 1.200012f
};

/* Enhancer - Upsamling a factor 4 (ENH_UPS0 = 4) */
const float polyphaserTbl[ENH_UPS0*(2*ENH_FL0+1)] =
{
     0.000000f,  0.000000f,  0.000000f,
     1.000000f,
     0.000000f,  0.000000f,  0.000000f,
     0.015625f, -0.076904f,  0.288330f,
     0.862061f, 
    -0.106445f,  0.018799f, -0.015625f,
     0.023682f, -0.124268f,  0.601563f,
     0.601563f,
    -0.124268f,  0.023682f, -0.023682f,
     0.018799f, -0.106445f,  0.862061f,
     0.288330f,
    -0.076904f,  0.015625f, -0.018799f
};

const float enh_plocsTbl[ENH_NBLOCKS_TOT] =
{
    40.0f, 120.0f,
    200.0f, 280.0f, 360.0f,
    440.0f, 520.0f, 600.0f
};

/* LPC analysis and quantization */

const int dim_lsfCbTbl[LSF_NSPLIT] = {3, 3, 4};
const int size_lsfCbTbl[LSF_NSPLIT] = {64, 128, 128};

const float lsfmeanTbl[ILBC_LPC_FILTERORDER] =
{
    0.281738f, 0.445801f, 0.663330f,
    0.962524f, 1.251831f, 1.533081f,
    1.850586f, 2.137817f, 2.481445f,
    2.777344f
};

const float lsf_weightTbl_30ms[6] =
{
    1.0f/2.0f, 1.0f,
    2.0f/3.0f,
    1.0f/3.0f, 0.0f, 0.0f
};

const float lsf_weightTbl_20ms[4] =
{
    3.0f/4.0f, 2.0f/4.0f,
    1.0f/4.0f, 0.0f
};

/* Hanning LPC window */
const float lpc_winTbl[ILBC_BLOCK_LEN_MAX] =
{
    0.000183f, 0.000671f, 0.001526f,
    0.002716f, 0.004242f, 0.006104f,
    0.008301f, 0.010834f, 0.013702f,
    0.016907f, 0.020416f, 0.024261f,
    0.028442f, 0.032928f, 0.037750f,
    0.042877f, 0.048309f, 0.054047f,
    0.060089f, 0.066437f, 0.073090f,
    0.080017f, 0.087219f, 0.094727f,
    0.102509f, 0.110535f, 0.118835f,
    0.127411f, 0.136230f, 0.145294f,
    0.154602f, 0.164154f, 0.173920f,
    0.183899f, 0.194122f, 0.204529f,
    0.215149f, 0.225952f, 0.236938f,
    0.248108f, 0.259460f, 0.270966f,
    0.282654f, 0.294464f, 0.306396f,
    0.318481f, 0.330688f, 0.343018f,
    0.355438f, 0.367981f, 0.380585f,
    0.393280f, 0.406067f, 0.418884f,
    0.431763f, 0.444702f, 0.457672f,
    0.470673f, 0.483704f, 0.496735f,
    0.509766f, 0.522797f, 0.535828f,
    0.548798f, 0.561768f, 0.574677f,
    0.587524f, 0.600342f, 0.613068f,
    0.625732f, 0.638306f, 0.650787f,
    0.663147f, 0.675415f, 0.687561f,
    0.699585f, 0.711487f, 0.723206f,
    0.734802f, 0.746216f, 0.757477f,
    0.768585f, 0.779480f, 0.790192f,
    0.800720f, 0.811005f, 0.821106f,
    0.830994f, 0.840668f, 0.850067f,
    0.859253f, 0.868225f, 0.876892f,
    0.885345f, 0.893524f, 0.901428f,
    0.909058f, 0.916412f, 0.923492f,
    0.930267f, 0.936768f, 0.942963f,
    0.948853f, 0.954437f, 0.959717f,
    0.964691f, 0.969360f, 0.973694f,
    0.977692f, 0.981384f, 0.984741f,
    0.987762f, 0.990479f, 0.992828f,
    0.994873f, 0.996552f, 0.997925f,
    0.998932f, 0.999603f, 0.999969f,
    0.999969f, 0.999603f, 0.998932f,
    0.997925f, 0.996552f, 0.994873f,
    0.992828f, 0.990479f, 0.987762f,
    0.984741f, 0.981384f, 0.977692f,
    0.973694f, 0.969360f, 0.964691f,
    0.959717f, 0.954437f, 0.948853f,
    0.942963f, 0.936768f, 0.930267f,
    0.923492f, 0.916412f, 0.909058f,
    0.901428f, 0.893524f, 0.885345f,
    0.876892f, 0.868225f, 0.859253f,
    0.850067f, 0.840668f, 0.830994f,
    0.821106f, 0.811005f, 0.800720f,
    0.790192f, 0.779480f, 0.768585f,
    0.757477f, 0.746216f, 0.734802f,
    0.723206f, 0.711487f, 0.699585f,
    0.687561f, 0.675415f, 0.663147f,
    0.650787f, 0.638306f, 0.625732f,
    0.613068f, 0.600342f, 0.587524f,
    0.574677f, 0.561768f, 0.548798f,
    0.535828f, 0.522797f, 0.509766f,
    0.496735f, 0.483704f, 0.470673f,
    0.457672f, 0.444702f, 0.431763f,
    0.418884f, 0.406067f, 0.393280f,
    0.380585f, 0.367981f, 0.355438f,
    0.343018f, 0.330688f, 0.318481f,
    0.306396f, 0.294464f, 0.282654f,
    0.270966f, 0.259460f, 0.248108f,
    0.236938f, 0.225952f, 0.215149f,
    0.204529f, 0.194122f, 0.183899f,
    0.173920f, 0.164154f, 0.154602f,
    0.145294f, 0.136230f, 0.127411f,
    0.118835f, 0.110535f, 0.102509f,
    0.094727f, 0.087219f, 0.080017f,
    0.073090f, 0.066437f, 0.060089f,
    0.054047f, 0.048309f, 0.042877f,
    0.037750f, 0.032928f, 0.028442f,
    0.024261f, 0.020416f, 0.016907f,
    0.013702f, 0.010834f, 0.008301f,
    0.006104f, 0.004242f, 0.002716f,
    0.001526f, 0.000671f, 0.000183f
};

/* Asymmetric LPC window */
const float lpc_asymwinTbl[ILBC_BLOCK_LEN_MAX] =
{
    0.000061f, 0.000214f, 0.000458f,
    0.000824f, 0.001282f, 0.001831f,
    0.002472f, 0.003235f, 0.004120f,
    0.005066f, 0.006134f, 0.007294f,
    0.008545f, 0.009918f, 0.011383f,
    0.012939f, 0.014587f, 0.016357f,
    0.018219f, 0.020172f, 0.022217f,
    0.024353f, 0.026611f, 0.028961f,
    0.031372f, 0.033905f, 0.036530f,
    0.039276f, 0.042084f, 0.044983f,
    0.047974f, 0.051086f, 0.054260f,
    0.057526f, 0.060883f, 0.064331f,
    0.067871f, 0.071503f, 0.075226f,
    0.079010f, 0.082916f, 0.086884f,
    0.090942f, 0.095062f, 0.099304f,
    0.103607f, 0.107971f, 0.112427f,
    0.116974f, 0.121582f, 0.126282f,
    0.131073f, 0.135895f, 0.140839f,
    0.145813f, 0.150879f, 0.156006f,
    0.161224f, 0.166504f, 0.171844f,
    0.177246f, 0.182709f, 0.188263f,
    0.193848f, 0.199524f, 0.205231f,
    0.211029f, 0.216858f, 0.222778f,
    0.228729f, 0.234741f, 0.240814f,
    0.246918f, 0.253082f, 0.259308f,
    0.265564f, 0.271881f, 0.278259f,
    0.284668f, 0.291107f, 0.297607f,
    0.304138f, 0.310730f, 0.317322f,
    0.323975f, 0.330658f, 0.337372f,
    0.344147f, 0.350922f, 0.357727f,
    0.364594f, 0.371460f, 0.378357f,
    0.385284f, 0.392212f, 0.399170f,
    0.406158f, 0.413177f, 0.420197f,
    0.427246f, 0.434296f, 0.441376f,
    0.448456f, 0.455536f, 0.462646f,
    0.469757f, 0.476868f, 0.483978f,
    0.491089f, 0.498230f, 0.505341f,
    0.512451f, 0.519592f, 0.526703f,
    0.533813f, 0.540924f, 0.548004f,
    0.555084f, 0.562164f, 0.569244f,
    0.576294f, 0.583313f, 0.590332f,
    0.597321f, 0.604309f, 0.611267f,
    0.618195f, 0.625092f, 0.631989f,
    0.638855f, 0.645660f, 0.652466f,
    0.659241f, 0.665985f, 0.672668f,
    0.679352f, 0.685974f, 0.692566f,
    0.699127f, 0.705658f, 0.712128f,
    0.718536f, 0.724945f, 0.731262f,
    0.737549f, 0.743805f, 0.750000f,
    0.756134f, 0.762238f, 0.768280f,
    0.774261f, 0.780182f, 0.786072f,
    0.791870f, 0.797638f, 0.803314f,
    0.808960f, 0.814514f, 0.820038f,
    0.825470f, 0.830841f, 0.836151f,
    0.841400f, 0.846558f, 0.851654f,
    0.856689f, 0.861633f, 0.866516f,
    0.871338f, 0.876068f, 0.880737f,
    0.885315f, 0.889801f, 0.894226f,
    0.898560f, 0.902832f, 0.907013f,
    0.911102f, 0.915100f, 0.919037f,
    0.922882f, 0.926636f, 0.930328f,
    0.933899f, 0.937408f, 0.940796f,
    0.944122f, 0.947357f, 0.950470f,
    0.953522f, 0.956482f, 0.959351f,
    0.962097f, 0.964783f, 0.967377f,
    0.969849f, 0.972229f, 0.974518f,
    0.976715f, 0.978821f, 0.980835f,
    0.982727f, 0.984528f, 0.986237f,
    0.987854f, 0.989380f, 0.990784f,
    0.992096f, 0.993317f, 0.994415f,
    0.995422f, 0.996338f, 0.997162f,
    0.997864f, 0.998474f, 0.998962f,
    0.999390f, 0.999695f, 0.999878f,
    0.999969f, 0.999969f, 0.996918f,
    0.987701f, 0.972382f, 0.951050f,
    0.923889f, 0.891022f, 0.852631f,
    0.809021f, 0.760406f, 0.707092f,
    0.649445f, 0.587799f, 0.522491f,
    0.453979f, 0.382690f, 0.309021f,
    0.233459f, 0.156433f, 0.078461f
};

/* Lag window for LPC */
const float lpc_lagwinTbl[ILBC_LPC_FILTERORDER + 1] =
{
    1.000100f, 0.998890f, 0.995569f,
    0.990057f, 0.982392f,
    0.972623f, 0.960816f, 0.947047f,
    0.931405f, 0.913989f, 0.894909f
};

/* LSF quantization*/
const float lsfCbTbl[64 * 3 + 128 * 3 + 128 * 4] =
{
    0.155396f, 0.273193f, 0.451172f,
    0.390503f, 0.648071f, 1.002075f,
    0.440186f, 0.692261f, 0.955688f,
    0.343628f, 0.642334f, 1.071533f,
    0.318359f, 0.491577f, 0.670532f,
    0.193115f, 0.375488f, 0.725708f,
    0.364136f, 0.510376f, 0.658691f,
    0.297485f, 0.527588f, 0.842529f,
    0.227173f, 0.365967f, 0.563110f,
    0.244995f, 0.396729f, 0.636475f,
    0.169434f, 0.300171f, 0.520264f,
    0.312866f, 0.464478f, 0.643188f,
    0.248535f, 0.429932f, 0.626099f,
    0.236206f, 0.491333f, 0.817139f,
    0.334961f, 0.625122f, 0.895752f,
    0.343018f, 0.518555f, 0.698608f,
    0.372803f, 0.659790f, 0.945435f,
    0.176880f, 0.316528f, 0.581421f,
    0.416382f, 0.625977f, 0.805176f,
    0.303223f, 0.568726f, 0.915039f,
    0.203613f, 0.351440f, 0.588135f,
    0.221191f, 0.375000f, 0.614746f,
    0.199951f, 0.323364f, 0.476074f,
    0.300781f, 0.433350f, 0.566895f,
    0.226196f, 0.354004f, 0.507568f,
    0.300049f, 0.508179f, 0.711670f,
    0.312012f, 0.492676f, 0.763428f,
    0.329956f, 0.541016f, 0.795776f,
    0.373779f, 0.604614f, 0.928833f,
    0.210571f, 0.452026f, 0.755249f,
    0.271118f, 0.473267f, 0.662476f,
    0.285522f, 0.436890f, 0.634399f,
    0.246704f, 0.565552f, 0.859009f,
    0.270508f, 0.406250f, 0.553589f,
    0.361450f, 0.578491f, 0.813843f,
    0.342651f, 0.482788f, 0.622437f,
    0.340332f, 0.549438f, 0.743164f,
    0.200439f, 0.336304f, 0.540894f,
    0.407837f, 0.644775f, 0.895142f,
    0.294678f, 0.454834f, 0.699097f,
    0.193115f, 0.344482f, 0.643188f,
    0.275757f, 0.420776f, 0.598755f,
    0.380493f, 0.608643f, 0.861084f,
    0.222778f, 0.426147f, 0.676514f,
    0.407471f, 0.700195f, 1.053101f,
    0.218384f, 0.377197f, 0.669922f,
    0.313232f, 0.454102f, 0.600952f,
    0.347412f, 0.571533f, 0.874146f,
    0.238037f, 0.405396f, 0.729492f,
    0.223877f, 0.412964f, 0.822021f,
    0.395264f, 0.582153f, 0.743896f,
    0.247925f, 0.485596f, 0.720581f,
    0.229126f, 0.496582f, 0.907715f,
    0.260132f, 0.566895f, 1.012695f,
    0.337402f, 0.611572f, 0.978149f,
    0.267822f, 0.447632f, 0.769287f,
    0.250610f, 0.381714f, 0.530029f,
    0.430054f, 0.805054f, 1.221924f,
    0.382568f, 0.544067f, 0.701660f,
    0.383545f, 0.710327f, 1.149170f,
    0.271362f, 0.529053f, 0.775513f,
    0.246826f, 0.393555f, 0.588623f,
    0.266846f, 0.422119f, 0.676758f,
    0.311523f, 0.580688f, 0.838623f,
    1.331177f, 1.576782f, 1.779541f,
    1.160034f, 1.401978f, 1.768188f,
    1.161865f, 1.525146f, 1.715332f,
    0.759521f, 0.913940f, 1.119873f,
    0.947144f, 1.121338f, 1.282471f,
    1.015015f, 1.557007f, 1.804932f,
    1.172974f, 1.402100f, 1.692627f,
    1.087524f, 1.474243f, 1.665405f,
    0.899536f, 1.105225f, 1.406250f,
    1.148438f, 1.484741f, 1.796265f,
    0.785645f, 1.209839f, 1.567749f,
    0.867798f, 1.166504f, 1.450684f,
    0.922485f, 1.229858f, 1.420898f,
    0.791260f, 1.123291f, 1.409546f,
    0.788940f, 0.966064f, 1.340332f,
    1.051147f, 1.272827f, 1.556641f,
    0.866821f, 1.181152f, 1.538818f,
    0.906738f, 1.373535f, 1.607910f,
    1.244751f, 1.581421f, 1.933838f,
    0.913940f, 1.337280f, 1.539673f,
    0.680542f, 0.959229f, 1.662720f,
    0.887207f, 1.430542f, 1.800781f,
    0.912598f, 1.433594f, 1.683960f,
    0.860474f, 1.060303f, 1.455322f,
    1.005127f, 1.381104f, 1.706909f,
    0.800781f, 1.363892f, 1.829102f,
    0.781860f, 1.124390f, 1.505981f,
    1.003662f, 1.471436f, 1.684692f,
    0.981323f, 1.309570f, 1.618042f,
    1.228760f, 1.554321f, 1.756470f,
    0.734375f, 0.895752f, 1.225586f,
    0.841797f, 1.055664f, 1.249268f,
    0.920166f, 1.119385f, 1.486206f,
    0.894409f, 1.539063f, 1.828979f,
    1.283691f, 1.543335f, 1.858276f,
    0.676025f, 0.933105f, 1.490845f,
    0.821289f, 1.491821f, 1.739868f,
    0.923218f, 1.144653f, 1.580566f,
    1.057251f, 1.345581f, 1.635864f,
    0.888672f, 1.074951f, 1.353149f,
    0.942749f, 1.195435f, 1.505493f,
    1.492310f, 1.788086f, 2.039673f,
    1.070313f, 1.634399f, 1.860962f,
    1.253296f, 1.488892f, 1.686035f,
    0.647095f, 0.864014f, 1.401855f,
    0.866699f, 1.254883f, 1.453369f,
    1.063965f, 1.532593f, 1.731323f,
    1.167847f, 1.521484f, 1.884033f,
    0.956055f, 1.502075f, 1.745605f,
    0.928711f, 1.288574f, 1.479614f,
    1.088013f, 1.380737f, 1.570801f,
    0.905029f, 1.186768f, 1.371948f,
    1.057861f, 1.421021f, 1.617432f,
    1.108276f, 1.312500f, 1.501465f,
    0.979492f, 1.416992f, 1.624268f,
    1.276001f, 1.661011f, 2.007935f,
    0.993042f, 1.168579f, 1.331665f,
    0.778198f, 0.944946f, 1.235962f,
    1.223755f, 1.491333f, 1.815674f,
    0.852661f, 1.350464f, 1.722290f,
    1.134766f, 1.593140f, 1.787354f,
    1.051392f, 1.339722f, 1.531006f,
    0.803589f, 1.271240f, 1.652100f,
    0.755737f, 1.143555f, 1.639404f,
    0.700928f, 0.837280f, 1.130371f,
    0.942749f, 1.197876f, 1.669800f,
    0.993286f, 1.378296f, 1.566528f,
    0.801025f, 1.095337f, 1.298950f,
    0.739990f, 1.032959f, 1.383667f,
    0.845703f, 1.072266f, 1.543823f,
    0.915649f, 1.072266f, 1.224487f,
    1.021973f, 1.226196f, 1.481323f,
    0.999878f, 1.204102f, 1.555908f,
    0.722290f, 0.913940f, 1.340210f,
    0.673340f, 0.835938f, 1.259521f,
    0.832397f, 1.208374f, 1.394165f,
    0.962158f, 1.576172f, 1.912842f,
    1.166748f, 1.370850f, 1.556763f,
    0.946289f, 1.138550f, 1.400391f,
    1.035034f, 1.218262f, 1.386475f,
    1.393799f, 1.717773f, 2.000244f,
    0.972656f, 1.260986f, 1.760620f,
    1.028198f, 1.288452f, 1.484619f,
    0.773560f, 1.258057f, 1.756714f,
    1.080322f, 1.328003f, 1.742676f,
    0.823975f, 1.450806f, 1.917725f,
    0.859009f, 1.016602f, 1.191895f,
    0.843994f, 1.131104f, 1.645020f,
    1.189697f, 1.702759f, 1.894409f,
    1.346680f, 1.763184f, 2.066040f,
    0.980469f, 1.253784f, 1.441650f,
    1.338135f, 1.641968f, 1.932739f,
    1.223267f, 1.424194f, 1.626465f,
    0.765747f, 1.004150f, 1.579102f,
    1.042847f, 1.269165f, 1.647461f,
    0.968750f, 1.257568f, 1.555786f,
    0.826294f, 0.993408f, 1.275146f,
    0.742310f, 0.950439f, 1.430542f,
    1.054321f, 1.439819f, 1.828003f,
    1.072998f, 1.261719f, 1.441895f,
    0.859375f, 1.036377f, 1.314819f,
    0.895752f, 1.267212f, 1.605591f,
    0.805420f, 0.962891f, 1.142334f,
    0.795654f, 1.005493f, 1.468506f,
    1.105347f, 1.313843f, 1.584839f,
    0.792236f, 1.221802f, 1.465698f,
    1.170532f, 1.467651f, 1.664063f,
    0.838257f, 1.153198f, 1.342163f,
    0.968018f, 1.198242f, 1.391235f,
    1.250122f, 1.623535f, 1.823608f,
    0.711670f, 1.058350f, 1.512085f,
    1.204834f, 1.454468f, 1.739136f,
    1.137451f, 1.421753f, 1.620117f,
    0.820435f, 1.322754f, 1.578247f,
    0.798706f, 1.005005f, 1.213867f,
    0.980713f, 1.324951f, 1.512939f,
    1.112305f, 1.438843f, 1.735596f,
    1.135498f, 1.356689f, 1.635742f,
    1.101318f, 1.387451f, 1.686523f,
    0.849854f, 1.276978f, 1.523438f,
    1.377930f, 1.627563f, 1.858154f,
    0.884888f, 1.095459f, 1.287476f,
    1.289795f, 1.505859f, 1.756592f,
    0.817505f, 1.384155f, 1.650513f,
    1.446655f, 1.702148f, 1.931885f,
    0.835815f, 1.023071f, 1.385376f,
    0.916626f, 1.139038f, 1.335327f,
    0.980103f, 1.174072f, 1.453735f,
    1.705688f, 2.153809f, 2.398315f, 2.743408f,
    1.797119f, 2.016846f, 2.445679f, 2.701904f,
    1.990356f, 2.219116f, 2.576416f, 2.813477f,
    1.849365f, 2.190918f, 2.611572f, 2.835083f,
    1.657959f, 1.854370f, 2.159058f, 2.726196f,
    1.437744f, 1.897705f, 2.253174f, 2.655396f,
    2.028687f, 2.247314f, 2.542358f, 2.875854f,
    1.736938f, 1.922119f, 2.185913f, 2.743408f,
    1.521606f, 1.870972f, 2.526855f, 2.786987f,
    1.841431f, 2.050659f, 2.463623f, 2.857666f,
    1.590088f, 2.067261f, 2.427979f, 2.794434f,
    1.746826f, 2.057373f, 2.320190f, 2.800781f,
    1.734619f, 1.940552f, 2.306030f, 2.826416f,
    1.786255f, 2.204468f, 2.457520f, 2.795288f,
    1.861084f, 2.170532f, 2.414551f, 2.763672f,
    2.001465f, 2.307617f, 2.552734f, 2.811890f,
    1.784424f, 2.124146f, 2.381592f, 2.645508f,
    1.888794f, 2.135864f, 2.418579f, 2.861206f,
    2.301147f, 2.531250f, 2.724976f, 2.913086f,
    1.837769f, 2.051270f, 2.261963f, 2.553223f,
    2.012939f, 2.221191f, 2.440186f, 2.678101f,
    1.429565f, 1.858276f, 2.582275f, 2.845703f,
    1.622803f, 1.897705f, 2.367310f, 2.621094f,
    1.581543f, 1.960449f, 2.515869f, 2.736450f,
    1.419434f, 1.933960f, 2.394653f, 2.746704f,
    1.721924f, 2.059570f, 2.421753f, 2.769653f,
    1.911011f, 2.220703f, 2.461060f, 2.740723f,
    1.581177f, 1.860840f, 2.516968f, 2.874634f,
    1.870361f, 2.098755f, 2.432373f, 2.656494f,
    2.059692f, 2.279785f, 2.495605f, 2.729370f,
    1.815674f, 2.181519f, 2.451538f, 2.680542f,
    1.407959f, 1.768311f, 2.343018f, 2.668091f,
    2.168701f, 2.394653f, 2.604736f, 2.829346f,
    1.636230f, 1.865723f, 2.329102f, 2.824219f,
    1.878906f, 2.139526f, 2.376709f, 2.679810f,
    1.765381f, 1.971802f, 2.195435f, 2.586914f,
    2.164795f, 2.410889f, 2.673706f, 2.903198f,
    2.071899f, 2.331055f, 2.645874f, 2.907104f,
    2.026001f, 2.311523f, 2.594849f, 2.863892f,
    1.948975f, 2.180786f, 2.514893f, 2.797852f,
    1.881836f, 2.130859f, 2.478149f, 2.804199f,
    2.238159f, 2.452759f, 2.652832f, 2.868286f,
    1.897949f, 2.101685f, 2.524292f, 2.880127f,
    1.856445f, 2.074585f, 2.541016f, 2.791748f,
    1.695557f, 2.199097f, 2.506226f, 2.742676f,
    1.612671f, 1.877075f, 2.435425f, 2.732910f,
    1.568848f, 1.786499f, 2.194580f, 2.768555f,
    1.953369f, 2.164551f, 2.486938f, 2.874023f,
    1.388306f, 1.725342f, 2.384521f, 2.771851f,
    2.115356f, 2.337769f, 2.592896f, 2.864014f,
    1.905762f, 2.111328f, 2.363525f, 2.789307f,
    1.882568f, 2.332031f, 2.598267f, 2.827637f,
    1.683594f, 2.088745f, 2.361938f, 2.608643f,
    1.874023f, 2.182129f, 2.536133f, 2.766968f,
    1.861938f, 2.070435f, 2.309692f, 2.700562f,
    1.722168f, 2.107422f, 2.477295f, 2.837646f,
    1.926880f, 2.184692f, 2.442627f, 2.663818f,
    2.123901f, 2.337280f, 2.553101f, 2.777466f,
    1.588135f, 1.911499f, 2.212769f, 2.543945f,
    2.053955f, 2.370850f, 2.712158f, 2.939941f,
    2.210449f, 2.519653f, 2.770386f, 2.958618f,
    2.199463f, 2.474731f, 2.718262f, 2.919922f,
    1.960083f, 2.175415f, 2.608032f, 2.888794f,
    1.953735f, 2.185181f, 2.428223f, 2.809570f,
    1.615234f, 2.036499f, 2.576538f, 2.834595f,
    1.621094f, 2.028198f, 2.431030f, 2.664673f,
    1.824951f, 2.267456f, 2.514526f, 2.747925f,
    1.994263f, 2.229126f, 2.475220f, 2.833984f,
    1.746338f, 2.011353f, 2.588257f, 2.826904f,
    1.562866f, 2.135986f, 2.471680f, 2.687256f,
    1.748901f, 2.083496f, 2.460938f, 2.686279f,
    1.758057f, 2.131470f, 2.636597f, 2.891602f,
    2.071289f, 2.299072f, 2.550781f, 2.814331f,
    1.839600f, 2.094360f, 2.496460f, 2.723999f,
    1.882202f, 2.088257f, 2.636841f, 2.923096f,
    1.957886f, 2.153198f, 2.384399f, 2.615234f,
    1.992920f, 2.351196f, 2.654419f, 2.889771f,
    2.012817f, 2.262451f, 2.643799f, 2.903076f,
    2.025635f, 2.254761f, 2.508423f, 2.784058f,
    2.316040f, 2.589355f, 2.794189f, 2.963623f,
    1.741211f, 2.279541f, 2.578491f, 2.816284f,
    1.845337f, 2.055786f, 2.348511f, 2.822021f,
    1.679932f, 1.926514f, 2.499756f, 2.835693f,
    1.722534f, 1.946899f, 2.448486f, 2.728760f,
    1.829834f, 2.043213f, 2.580444f, 2.867676f,
    1.676636f, 2.071655f, 2.322510f, 2.704834f,
    1.791504f, 2.113525f, 2.469727f, 2.784058f,
    1.977051f, 2.215088f, 2.497437f, 2.726929f,
    1.800171f, 2.106689f, 2.357788f, 2.738892f,
    1.827759f, 2.170166f, 2.525879f, 2.852417f,
    1.918335f, 2.132813f, 2.488403f, 2.728149f,
    1.916748f, 2.225098f, 2.542603f, 2.857666f,
    1.761230f, 1.976074f, 2.507446f, 2.884521f,
    2.053711f, 2.367432f, 2.608032f, 2.837646f,
    1.595337f, 2.000977f, 2.307129f, 2.578247f,
    1.470581f, 2.031250f, 2.375854f, 2.647583f,
    1.801392f, 2.128052f, 2.399780f, 2.822876f,
    1.853638f, 2.066650f, 2.429199f, 2.751465f,
    1.956299f, 2.163696f, 2.394775f, 2.734253f,
    1.963623f, 2.275757f, 2.585327f, 2.865234f,
    1.887451f, 2.105469f, 2.331787f, 2.587402f,
    2.120117f, 2.443359f, 2.733887f, 2.941406f,
    1.506348f, 1.766968f, 2.400513f, 2.851807f,
    1.664551f, 1.981079f, 2.375732f, 2.774414f,
    1.720703f, 1.978882f, 2.391479f, 2.640991f,
    1.483398f, 1.814819f, 2.434448f, 2.722290f,
    1.769043f, 2.136597f, 2.563721f, 2.774414f,
    1.810791f, 2.049316f, 2.373901f, 2.613647f,
    1.788330f, 2.005981f, 2.359131f, 2.723145f,
    1.785156f, 1.993164f, 2.399780f, 2.832520f,
    1.695313f, 2.022949f, 2.522583f, 2.745117f,
    1.584106f, 1.965576f, 2.299927f, 2.715576f,
    1.894897f, 2.249878f, 2.655884f, 2.897705f,
    1.720581f, 1.995728f, 2.299438f, 2.557007f,
    1.619385f, 2.173950f, 2.574219f, 2.787964f,
    1.883179f, 2.220459f, 2.474365f, 2.825073f,
    1.447632f, 2.045044f, 2.555542f, 2.744873f,
    1.502686f, 2.156616f, 2.653320f, 2.846558f,
    1.711548f, 1.944092f, 2.282959f, 2.685791f,
    1.499756f, 1.867554f, 2.341064f, 2.578857f,
    1.916870f, 2.135132f, 2.568237f, 2.826050f,
    1.498047f, 1.711182f, 2.223267f, 2.755127f,
    1.808716f, 1.997559f, 2.256470f, 2.758545f,
    2.088501f, 2.402710f, 2.667358f, 2.890259f,
    1.545044f, 1.819214f, 2.324097f, 2.692993f,
    1.796021f, 2.012573f, 2.505737f, 2.784912f,
    1.786499f, 2.041748f, 2.290405f, 2.650757f,
    1.938232f, 2.264404f, 2.529053f, 2.796143f
};
