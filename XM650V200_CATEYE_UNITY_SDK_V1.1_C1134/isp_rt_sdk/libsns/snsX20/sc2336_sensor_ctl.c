#include "isp_type.h"
#include "isp_print.h"
#include "isp_i2c.h"
#include "isp_sns_ctrl.h"
#include "XAx_cmos.h"


//Mclk: 27M
//Pclk: 74.25M
//Active:1928*1088
//Total:3300*1125*30 fps
//mipi 10bit 2lane
static const ISP_U16 gau16SnsInit_sc2336[][2] = {
	{0x0100,0x00},
	{0x36e9,0x80},
	{0x37f9,0x80},
	{0x301f,0x0c},
	{0x3106,0x05},
	{0x3200,0x00},
	{0x3201,0x00},
	{0x3202,0x00},
	{0x3203,0x00},
	{0x3204,0x07},
	{0x3205,0x8b},
	{0x3206,0x04},
	{0x3207,0x43},
	{0x3208,0x07},
	{0x3209,0x88},
	{0x320a,0x04},
	{0x320b,0x40},
	{0x320c,0x0a},
	{0x320d,0x50},
	{0x3210,0x00},
	{0x3211,0x02},
	{0x3212,0x00},
	{0x3213,0x02},
	{0x3248,0x04},
	{0x3249,0x0b},
	{0x3253,0x08},
	{0x3301,0x09},
	{0x3302,0xff},
	{0x3303,0x10},
	{0x3306,0x60},
	{0x3307,0x02},
	{0x330a,0x01},
	{0x330b,0x10},
	{0x330c,0x16},
	{0x330d,0x90},
	{0x3318,0x02},
	{0x3321,0x0a},
	{0x3327,0x0e},
	{0x332b,0x12},
	{0x3333,0x10},
	{0x3334,0x40},
	{0x335e,0x06},
	{0x335f,0x0a},
	{0x3364,0x1f},
	{0x337c,0x02},
	{0x337d,0x0e},
	{0x3390,0x09},
	{0x3391,0x0f},
	{0x3392,0x1f},
	{0x3393,0x20},
	{0x3394,0x20},
	{0x3395,0xff},
	{0x33a2,0x04},
	{0x33b1,0x80},
	{0x33b2,0x68},
	{0x33b3,0x42},
	{0x33f9,0x70},
	{0x33fb,0xd0},
	{0x33fc,0x0f},
	{0x33fd,0x1f},
	{0x349f,0x03},
	{0x34a6,0x0f},
	{0x34a7,0x1f},
	{0x34a8,0x42},
	{0x34a9,0x06},
	{0x34aa,0x01},
	{0x34ab,0x23},
	{0x34ac,0x01},
	{0x34ad,0x84},
	{0x3630,0xf4},
	{0x3633,0x22},
	{0x3639,0xf4},
	{0x363c,0x47},
	{0x3670,0x09},
	{0x3674,0xf8},
	{0x3675,0xfb},
	{0x3676,0xed},
	{0x367c,0x09},
	{0x367d,0x0f},
	{0x3690,0x22},
	{0x3691,0x32},
	{0x3692,0x33},
	{0x3698,0x89},
	{0x3699,0x95},
	{0x369a,0xbb},
	{0x369b,0xbb},
	{0x369c,0x09},
	{0x369d,0x0f},
	{0x36a2,0x09},
	{0x36a3,0x0f},
	{0x36a4,0x1f},
	{0x36d0,0x01},
	{0x3722,0xe1},
	{0x3724,0x11},
	{0x3725,0x91},
	{0x3728,0x20},
	{0x3900,0x0d},
	{0x3905,0x98},
	{0x391b,0x81},
	{0x391c,0x10},
	{0x3933,0x81},
	{0x3934,0xc9},
	{0x3940,0x6d},
	{0x3942,0x01},
	{0x3943,0xcb},
	{0x3952,0x02},
	{0x3953,0x0f},
	{0x3e01,0x20},
	{0x3e03,0x0b},
	{0x3e00,0x00},
	{0x3e08,0x1f},
	{0x3e1b,0x14},
	{0x440e,0x02},
	{0x4509,0x38},
	{0x5799,0x06},
	{0x5ae0,0xfe},
	{0x5ae1,0x40},
	{0x5ae2,0x30},
	{0x5ae3,0x28},
	{0x5ae4,0x20},
	{0x5ae5,0x30},
	{0x5ae6,0x28},
	{0x5ae7,0x20},
	{0x5ae8,0x3c},
	{0x5ae9,0x30},
	{0x5aea,0x28},
	{0x5aeb,0x3c},
	{0x5aec,0x30},
	{0x5aed,0x28},
	{0x5aee,0xfe},
	{0x5aef,0x40},
	{0x5af4,0x30},
	{0x5af5,0x28},
	{0x5af6,0x20},
	{0x5af7,0x30},
	{0x5af8,0x28},
	{0x5af9,0x20},
	{0x5afa,0x3c},
	{0x5afb,0x30},
	{0x5afc,0x28},
	{0x5afd,0x3c},
	{0x5afe,0x30},
	{0x5aff,0x28},
	{0x36e9,0x20},
	{0x37f9,0x27},
	{0x4800,0x44},		// mipiʼ������
		//{0x4501,0xcc},
	{0x0100,0x01},
};

//Mclk: 27M
//Pclk: 74.25M
//Active:1928*1088
//Total:3300*1125*30 fps
//mipi 10bit 2lane
static const ISP_U16 gau16SnsInit_sc2336_8bit[][2] = {
	{0x0100,0x00},
	{0x36e9,0x80},
	{0x37f9,0x80},
	{0x301f,0x6e},
	{0x3031,0x08},
	{0x3037,0x00},
	{0x3106,0x05},
	{0x3200,0x00},
	{0x3201,0x00},
	{0x3202,0x00},
	{0x3203,0x00},
	{0x3204,0x07},
	{0x3205,0x8b},
	{0x3206,0x04},
	{0x3207,0x43},
	{0x3208,0x07},
	{0x3209,0x88},
	{0x320a,0x04},
	{0x320b,0x40},
	{0x320c,0x0a},
	{0x320d,0x50},
	{0x3210,0x00},
	{0x3211,0x02},
	{0x3212,0x00},
	{0x3213,0x02},
		{0x3222,0x02},
		{0x322e,0x04},
		{0x322f,0x61},
	{0x3248,0x04},
	{0x3249,0x0b},
	{0x3250,0x40},
	{0x3253,0x08},
	{0x3301,0x09},
	{0x3302,0xff},
	{0x3303,0x10},
	{0x3306,0x60},
	{0x3307,0x02},
	{0x330a,0x01},
	{0x330b,0x10},
	{0x330c,0x16},
	{0x330d,0xff},
	{0x3318,0x02},
	{0x3321,0x0a},
	{0x3327,0x0e},
	{0x332b,0x12},
	{0x3333,0x10},
	{0x3334,0x40},
	{0x335e,0x06},
	{0x335f,0x0a},
	{0x3364,0x1f},
	{0x337c,0x02},
	{0x337d,0x0e},
	{0x3390,0x09},
	{0x3391,0x0f},
	{0x3392,0x1f},
	{0x3393,0x20},
	{0x3394,0x20},
	{0x3395,0xff},
	{0x33a2,0x04},
	{0x33b1,0x80},
	{0x33b2,0x68},
	{0x33b3,0x42},
	{0x33f9,0x70},
	{0x33fb,0xd0},
	{0x33fc,0x0f},
	{0x33fd,0x1f},
	{0x349f,0x03},
	{0x34a6,0x0f},
	{0x34a7,0x1f},
	{0x34a8,0x42},
	{0x34a9,0x06},
	{0x34aa,0x01},
	{0x34ab,0x23},
	{0x34ac,0x01},
	{0x34ad,0x84},
	{0x3630,0xf4},
	{0x3633,0x22},
	{0x3639,0xf4},
	{0x363c,0x47},
	{0x3670,0x09},
	{0x3674,0xf4},
	{0x3675,0xfb},
	{0x3676,0xed},
	{0x367c,0x09},
	{0x367d,0x0f},
	{0x3690,0x33},
	{0x3691,0x33},
	{0x3692,0x43},
	{0x3698,0x89},
	{0x3699,0x96},
	{0x369a,0xd0},
	{0x369b,0xd0},
	{0x369c,0x09},
	{0x369d,0x0f},
	{0x36a2,0x09},
	{0x36a3,0x0f},
	{0x36a4,0x1f},
	{0x36d0,0x01},
	{0x36ea,0x0b},
	{0x36eb,0x0a},
	{0x36ec,0x1a},
	{0x36ed,0x08},
	{0x3722,0xe1},
	{0x3724,0x41},
	{0x3725,0xc1},
	{0x3728,0x20},
	{0x37fa,0x0b},
	{0x37fb,0x32},
	{0x37fc,0x11},
	{0x37fd,0x07},
	{0x3900,0x0d},
	{0x3905,0x98},
	{0x391b,0x81},
	{0x391c,0x10},
	{0x3933,0x81},
	{0x3934,0xc5},
	{0x3940,0x68},
	{0x3941,0x00},
	{0x3942,0x01},
	{0x3943,0xc6},
	{0x3952,0x02},
	{0x3953,0x0f},
	{0x3e01,0x13},
	{0x3e02,0x00},
	{0x3e03,0x0b},
	{0x3e08,0x1f},
	{0x3e1b,0x14},
	{0x440e,0x02},
	{0x4509,0x38},
	{0x4800,0x44},
	{0x4819,0x05},
	{0x481b,0x03},
	{0x481d,0x0a},
	{0x481f,0x02},
	{0x4821,0x09},
	{0x4823,0x03},
	{0x4825,0x02},
	{0x4827,0x03},
	{0x4829,0x04},
	{0x5799,0x06},
	{0x5ae0,0xfe},
	{0x5ae1,0x40},
	{0x5ae2,0x30},
	{0x5ae3,0x28},
	{0x5ae4,0x20},
	{0x5ae6,0x28},
	{0x5ae5,0x30},
	{0x5ae7,0x20},
	{0x5ae8,0x3c},
	{0x5ae9,0x30},
	{0x5aea,0x28},
	{0x5aeb,0x3c},
	{0x5aec,0x30},
	{0x5aed,0x28},
	{0x5aee,0xfe},
	{0x5aef,0x40},
	{0x5af4,0x30},
	{0x5af5,0x28},
	{0x5af6,0x20},
	{0x5af7,0x30},
	{0x5af8,0x28},
	{0x5af9,0x20},
	{0x5afa,0x3c},
	{0x5afb,0x30},
	{0x5afc,0x28},
	{0x5afd,0x3c},
	{0x5afe,0x30},
	{0x5aff,0x28},
	{0x36e9,0x04},
	{0x37f9,0x27},
		//{0x4501,0xcc},
	{0x0100,0x01},
};

//Mclk: 27M
//Pclk: 74.25M
//Active:1928*1088
//Total:2640*1125*30 fps
//DVP
static const ISP_U16 gau16SnsInit_sc2336_Dvp[][2] = {
	{0x0100,0x00},
	{0x36e9,0x80},
	{0x37f9,0x80},
	{0x3000,0xff},
	{0x3001,0xff},
	{0x3002,0xf0},
	{0x300a,0x24},
	{0x3018,0x0f},
	{0x301a,0xf8},
	{0x301c,0x94},
	{0x301f,0x1f},
	{0x3030,0x01},
	{0x303f,0x81},
	{0x3106,0x05},
	{0x3200,0x00},
	{0x3201,0x00},
	{0x3202,0x00},
	{0x3203,0x00},
	{0x3204,0x07},
	{0x3205,0x8b},
	{0x3206,0x04},
	{0x3207,0x43},
	{0x3208,0x07},
	{0x3209,0x88},
	{0x320a,0x04},
	{0x320b,0x40},
	{0x320c,0x0a},
	{0x320d,0x50},
	{0x3210,0x00},
	{0x3211,0x02},
	{0x3212,0x00},
	{0x3213,0x02},
	{0x3248,0x04},
	{0x3249,0x0b},
	{0x3253,0x08},
	{0x3301,0x09},
	{0x3302,0xff},
	{0x3303,0x10},
	{0x3306,0x60},
	{0x3307,0x02},
	{0x330a,0x01},
	{0x330b,0x10},
	{0x330c,0x16},
	{0x330d,0xff},
	{0x3318,0x02},
	{0x3321,0x0a},
	{0x3327,0x0e},
	{0x332b,0x12},
	{0x3333,0x10},
	{0x3334,0x40},
	{0x335e,0x06},
	{0x335f,0x0a},
	{0x3364,0x1f},
	{0x337c,0x02},
	{0x337d,0x0e},
	{0x3390,0x09},
	{0x3391,0x0f},
	{0x3392,0x1f},
	{0x3393,0x20},
	{0x3394,0x20},
	{0x3395,0xff},
	{0x33a2,0x04},
	{0x33b1,0x80},
	{0x33b2,0x68},
	{0x33b3,0x42},
	{0x33f9,0x70},
	{0x33fb,0xd0},
	{0x33fc,0x0f},
	{0x33fd,0x1f},
	{0x349f,0x03},
	{0x34a6,0x0f},
	{0x34a7,0x1f},
	{0x34a8,0x42},
	{0x34a9,0x06},
	{0x34aa,0x01},
	{0x34ab,0x23},
	{0x34ac,0x01},
	{0x34ad,0x84},
	{0x3630,0xf4},
	{0x3633,0x22},
	{0x3639,0xf4},
	{0x363c,0x47},
	{0x3641,0x01},
	{0x3670,0x09},
	{0x3674,0xf4},
	{0x3675,0xfb},
	{0x3676,0xed},
	{0x367c,0x09},
	{0x367d,0x0f},
	{0x3690,0x33},
	{0x3691,0x33},
	{0x3692,0x43},
	{0x3698,0x89},
	{0x3699,0x96},
	{0x369a,0xd0},
	{0x369b,0xd0},
	{0x369c,0x09},
	{0x369d,0x0f},
	{0x36a2,0x09},
	{0x36a3,0x0f},
	{0x36a4,0x1f},
	{0x36d0,0x01},
	{0x3722,0xe1},
	{0x3724,0x41},
	{0x3725,0xc1},
	{0x3728,0x20},
	{0x3900,0x0d},
	{0x3905,0x98},
	{0x391b,0x81},
	{0x391c,0x10},
	{0x3933,0x81},
	{0x3934,0xc5},
	{0x3940,0x68},
	{0x3941,0x00},
	{0x3942,0x01},
	{0x3943,0xc6},
	{0x3952,0x02},
	{0x3953,0x0f},
	{0x3e01,0x30},
	{0x3e02,0x00},
	{0x3e03,0x0b},
	{0x3e08,0x1f},
	{0x3e1b,0x14},
	{0x440e,0x02},
	{0x4509,0x38},
	{0x4603,0x09},
	{0x5799,0x06},
	{0x5ae0,0xfe},
	{0x5ae1,0x40},
	{0x5ae2,0x30},
	{0x5ae3,0x28},
	{0x5ae4,0x20},
	{0x5ae5,0x30},
	{0x5ae6,0x28},
	{0x5ae7,0x20},
	{0x5ae8,0x3c},
	{0x5ae9,0x30},
	{0x5aea,0x28},
	{0x5aeb,0x3c},
	{0x5aec,0x30},
	{0x5aed,0x28},
	{0x5aee,0xfe},
	{0x5aef,0x40},
	{0x5af4,0x30},
	{0x5af5,0x28},
	{0x5af6,0x20},
	{0x5af7,0x30},
	{0x5af8,0x28},
	{0x5af9,0x20},
	{0x5afa,0x3c},
	{0x5afb,0x30},
	{0x5afc,0x28},
	{0x5afd,0x3c},
	{0x5afe,0x30},
	{0x5aff,0x28},
	{0x3d08,0x03},	// Lycai
	{0x36e9,0x20},
	{0x37f9,0x27},
	{0x0100,0x01}
};

static const ISP_U16 gau16SnsInit_sc2336_VGA[][2] = 
{
#if 0
{0x0103,0x01},
{0x0100,0x00},
{0x36e9,0x80},
{0x37f9,0x80},
{0x301f,0x59},
{0x3106,0x05},
{0x3200,0x02},
{0x3201,0x74},
{0x3202,0x01},
{0x3203,0x2c},
{0x3204,0x05},
{0x3205,0x13},
{0x3206,0x03},
{0x3207,0x13},
{0x3208,0x02},
{0x3209,0x80},
{0x320a,0x01},
{0x320b,0xe0},
{0x320c,0x08},
{0x320d,0x98},
{0x320e,0x05},
{0x320f,0x1c},
{0x3210,0x00},
{0x3211,0x10},
{0x3212,0x00},
{0x3213,0x03},
{0x3248,0x04},
{0x3249,0x0b},
{0x3250,0x40},
{0x3253,0x08},
{0x3301,0x09},
{0x3302,0xff},
{0x3303,0x10},
{0x3306,0x50},
{0x3307,0x02},
{0x330a,0x01},
{0x330b,0x10},
{0x330c,0x16},
{0x330d,0xff},
{0x3318,0x02},
{0x3321,0x0a},
{0x3327,0x0e},
{0x332b,0x12},
{0x3333,0x10},
{0x3334,0x40},
{0x335e,0x06},
{0x335f,0x0a},
{0x3364,0x1f},
{0x337c,0x02},
{0x337d,0x0e},
{0x3390,0x09},
{0x3391,0x0f},
{0x3392,0x1f},
{0x3393,0x12},
{0x3394,0x12},
{0x3395,0x18},
{0x33a2,0x04},
{0x33b1,0x80},
{0x33b2,0x68},
{0x33b3,0x42},
{0x33f9,0x70},
{0x33fb,0xc6},
{0x33fc,0x0f},
{0x33fd,0x1f},
{0x349f,0x03},
{0x34a6,0x0f},
{0x34a7,0x1f},
{0x34a8,0x42},
{0x34a9,0x06},
{0x34aa,0x01},
{0x34ab,0x23},
{0x34ac,0x01},
{0x34ad,0x84},
{0x3630,0xf4},
{0x3633,0x22},
{0x3639,0xf4},
{0x363c,0x47},
{0x3670,0x09},
{0x3674,0xf4},
{0x3675,0xfb},
{0x3676,0xed},
{0x367c,0x09},
{0x367d,0x0f},
{0x3690,0x33},
{0x3691,0x33},
{0x3692,0x43},
{0x3698,0x89},
{0x3699,0x96},
{0x369a,0xd0},
{0x369b,0xd0},
{0x369c,0x09},
{0x369d,0x0f},
{0x36a2,0x09},
{0x36a3,0x0f},
{0x36a4,0x1f},
{0x36d0,0x01},
{0x36ea,0x0a},
{0x36eb,0x0c},
{0x36ec,0x1c},
{0x36ed,0x38},
{0x3722,0xe1},
{0x3724,0x41},
{0x3725,0xc1},
{0x3728,0x20},
{0x37fa,0x0c},
{0x37fb,0x32},
{0x37fc,0x11},
{0x37fd,0x17},
{0x3900,0x0d},
{0x3905,0x98},
{0x391b,0x81},
{0x391c,0x10},
{0x3933,0x81},
{0x3934,0xc5},
{0x3940,0x68},
{0x3941,0x00},
{0x3942,0x01},
{0x3943,0xc6},
{0x3952,0x02},
{0x3953,0x0f},
{0x3e01,0x51},
{0x3e02,0x60},
{0x3e03,0x0b},
{0x3e08,0x1f},
{0x3e1b,0x14},
{0x440e,0x02},
{0x4509,0x38},
{0x4800,0x44},
{0x4819,0x05},
{0x481b,0x03},
{0x481d,0x0a},
{0x481f,0x02},
{0x4821,0x08},
{0x4823,0x03},
{0x4825,0x02},
{0x4827,0x03},
{0x4829,0x04},
{0x5799,0x06},
{0x5ae0,0xfe},
{0x5ae1,0x40},
{0x5ae2,0x30},
{0x5ae3,0x28},
{0x5ae4,0x20},
{0x5ae5,0x30},
{0x5ae6,0x28},
{0x5ae7,0x20},
{0x5ae8,0x3c},
{0x5ae9,0x30},
{0x5aea,0x28},
{0x5aeb,0x3c},
{0x5aec,0x30},
{0x5aed,0x28},
{0x5aee,0xfe},
{0x5aef,0x40},
{0x5af4,0x30},
{0x5af5,0x28},
{0x5af6,0x20},
{0x5af7,0x30},
{0x5af8,0x28},
{0x5af9,0x20},
{0x5afa,0x3c},
{0x5afb,0x30},
{0x5afc,0x28},
{0x5afd,0x3c},
{0x5afe,0x30},
{0x5aff,0x28},
{0x36e9,0x54},
{0x37f9,0x53},
{0x0100,0x01},
#else
{0x0103,0x01},
{0x0100,0x00},
{0x36e9,0x80},
{0x37f9,0x80},
{0x3018,0x32},
{0x3019,0x0c},
{0x301f,0x63},
{0x3031,0x08},
{0x3037,0x00},
{0x3106,0x05},
{0x3200,0x02},
{0x3201,0x4c},
{0x3202,0x00},
{0x3203,0x3c},
{0x3204,0x05},
{0x3205,0x3b},
{0x3206,0x04},
{0x3207,0x03},
{0x3208,0x02},
{0x3209,0xd0},
{0x320a,0x03},
{0x320b,0xc0},
{0x320c,0x07},
{0x320d,0xd0},
{0x320e,0x05},
{0x320f,0xdc},
{0x3210,0x00},
{0x3211,0x10},
{0x3212,0x00},
{0x3213,0x04},
	{0x3222,0x02},
	{0x322e,0x05},
	{0x322f,0xd8},
{0x3248,0x04},
{0x3249,0x0b},
{0x3250,0x40},
{0x3253,0x08},
{0x3301,0x09},
{0x3302,0xff},
{0x3303,0x10},
{0x3306,0x60},
{0x3307,0x02},
{0x330a,0x01},
{0x330b,0x10},
{0x330c,0x16},
{0x330d,0xff},
{0x3318,0x02},
{0x3321,0x0a},
{0x3327,0x0e},
{0x332b,0x12},
{0x3333,0x10},
{0x3334,0x40},
{0x335e,0x06},
{0x335f,0x0a},
{0x3364,0x1f},
{0x337c,0x02},
{0x337d,0x0e},
{0x3390,0x09},
{0x3391,0x0f},
{0x3392,0x1f},
{0x3393,0x20},
{0x3394,0x20},
{0x3395,0xff},
{0x33a2,0x04},
{0x33b1,0x80},
{0x33b2,0x68},
{0x33b3,0x42},
{0x33f9,0x70},
{0x33fb,0xb7},
{0x33fc,0x0f},
{0x33fd,0x1f},
{0x349f,0x03},
{0x34a6,0x0f},
{0x34a7,0x1f},
{0x34a8,0x42},
{0x34a9,0x06},
{0x34aa,0x01},
{0x34ab,0x23},
{0x34ac,0x01},
{0x34ad,0x74},
{0x3630,0xf4},
{0x3633,0x22},
{0x3639,0xf4},
{0x363c,0x47},
{0x3670,0x09},
{0x3674,0xf4},
{0x3675,0xfb},
{0x3676,0xed},
{0x367c,0x09},
{0x367d,0x0f},
{0x3690,0x33},
{0x3691,0x33},
{0x3692,0x43},
{0x3698,0x89},
{0x3699,0x96},
{0x369a,0xd0},
{0x369b,0xd0},
{0x369c,0x09},
{0x369d,0x0f},
{0x36a2,0x09},
{0x36a3,0x0f},
{0x36a4,0x1f},
{0x36d0,0x01},
{0x36ea,0x06},
{0x36eb,0x0b},
{0x36ec,0x2a},
{0x36ed,0x28},
{0x3722,0xe1},
{0x3724,0x41},
{0x3725,0xc1},
{0x3728,0x20},
{0x37fa,0x09},
{0x37fb,0x32},
{0x37fc,0x11},
{0x37fd,0x27},
{0x3900,0x0d},
	//{0x3902,0x85},
	//{0x3909,0x01},
	//{0x390a,0xc2},
{0x3905,0x98},
{0x391b,0x81},
{0x391c,0x10},
{0x3933,0x81},
{0x3934,0xc5},
{0x3940,0x68},
{0x3941,0x00},
{0x3942,0x01},
{0x3943,0xc6},
{0x3952,0x02},
{0x3953,0x0f},
{0x3e01,0x40},
{0x3e02,0x00},
{0x3e03,0x0b},
{0x3e08,0x1f},
{0x3e1b,0x14},
{0x440e,0x02},
{0x4509,0x38},
{0x4800,0x44},
{0x4819,0x04},
{0x481b,0x02},
{0x481d,0x06},
{0x481f,0x02},
{0x4821,0x07},
{0x4823,0x02},
{0x4825,0x02},
{0x4827,0x02},
{0x4829,0x03},
{0x5799,0x06},
{0x5ae0,0xfe},
{0x5ae1,0x40},
{0x5ae2,0x30},
{0x5ae3,0x28},
{0x5ae4,0x20},
{0x5ae5,0x30},
{0x5ae6,0x28},
{0x5ae7,0x20},
{0x5ae8,0x3c},
{0x5ae9,0x30},
{0x5aea,0x28},
{0x5aeb,0x3c},
{0x5aec,0x30},
{0x5aed,0x28},
{0x5aee,0xfe},
{0x5aef,0x40},
{0x5af4,0x30},
{0x5af5,0x28},
{0x5af6,0x20},
{0x5af7,0x30},
{0x5af8,0x28},
{0x5af9,0x20},
{0x5afa,0x3c},
{0x5afb,0x30},
{0x5afc,0x28},
{0x5afd,0x3c},
{0x5afe,0x30},
{0x5aff,0x28},
{0x36e9,0x24},
{0x37f9,0x20},
{0x0100,0x01},
#endif
};

static const ISP_U16 gau16SnsInit_sc2336_Dvp_VGA[][2] = 
{
#if 0
{0x0103,0x01},
{0x0100,0x00},
{0x36e9,0x80},
{0x37f9,0x80},
{0x3001,0xff},
{0x3002,0xf0},
{0x300a,0x24},
{0x3018,0x0f},
{0x301a,0xf8},
{0x301c,0x94},
{0x301f,0x5b},
{0x3030,0x01},
{0x303f,0x81},
{0x3106,0x05},
{0x3200,0x02},
{0x3201,0x74},
{0x3202,0x01},
{0x3203,0x2c},
{0x3204,0x05},
{0x3205,0x13},
{0x3206,0x03},
{0x3207,0x13},
{0x3208,0x02},
{0x3209,0x80},
{0x320a,0x01},
{0x320b,0xe0},
{0x320c,0x08},
{0x320d,0x98},
{0x320e,0x05},
{0x320f,0x1c},
{0x3210,0x00},
{0x3211,0x10},
{0x3212,0x00},
{0x3213,0x04},
{0x3248,0x04},
{0x3249,0x0b},
{0x3253,0x08},
{0x3301,0x09},
{0x3302,0xff},
{0x3303,0x10},
{0x3306,0x60},
{0x3307,0x02},
{0x330a,0x01},
{0x330b,0x10},
{0x330c,0x16},
{0x330d,0x90},
{0x3318,0x02},
{0x3321,0x0a},
{0x3327,0x0e},
{0x332b,0x12},
{0x3333,0x10},
{0x3334,0x40},
{0x335e,0x06},
{0x335f,0x0a},
{0x3364,0x1f},
{0x337c,0x02},
{0x337d,0x0e},
{0x3390,0x09},
{0x3391,0x0f},
{0x3392,0x1f},
{0x3393,0x20},
{0x3394,0x20},
{0x3395,0x30},
{0x33a2,0x04},
{0x33b1,0x80},
{0x33b2,0x68},
{0x33b3,0x42},
{0x33f9,0x70},
{0x33fb,0xd0},
{0x33fc,0x0f},
{0x33fd,0x1f},
{0x349f,0x03},
{0x34a6,0x0f},
{0x34a7,0x1f},
{0x34a8,0x42},
{0x34a9,0x06},
{0x34aa,0x01},
{0x34ab,0x23},
{0x34ac,0x01},
{0x34ad,0x84},
{0x3630,0xf4},
{0x3633,0x22},
{0x3639,0xf4},
{0x363c,0x47},
{0x3641,0x03},
{0x3670,0x09},
{0x3674,0xf4},
{0x3675,0xfb},
{0x3676,0xed},
{0x367c,0x09},
{0x367d,0x0f},
{0x3690,0x33},
{0x3691,0x33},
{0x3692,0x43},
{0x3698,0x89},
{0x3699,0x96},
{0x369a,0xd0},
{0x369b,0xd0},
{0x369c,0x09},
{0x369d,0x0f},
{0x36a2,0x09},
{0x36a3,0x0f},
{0x36a4,0x1f},
{0x36d0,0x01},
{0x36ea,0x09},
{0x36eb,0x0c},
{0x36ec,0x1c},
{0x36ed,0x28},
{0x3722,0xe1},
{0x3724,0x41},
{0x3725,0xc1},
{0x3728,0x20},
{0x37fa,0x09},
{0x37fb,0x32},
{0x37fc,0x11},
{0x37fd,0x37},
{0x3900,0x0d},
{0x3905,0x98},
{0x391b,0x81},
{0x391c,0x10},
{0x3933,0x81},
{0x3000,0xff},
{0x3934,0xc5},
{0x3940,0x68},
{0x3941,0x00},
{0x3942,0x01},
{0x3943,0xc6},
{0x3952,0x02},
{0x3953,0x0f},
{0x3e01,0x51},
{0x3e02,0x60},
{0x3e03,0x0b},
{0x3e08,0x1f},
{0x3e1b,0x14},
{0x440e,0x02},
{0x4509,0x38},
{0x4603,0x09},
{0x5799,0x06},
{0x5ae0,0xfe},
{0x5ae1,0x40},
{0x5ae2,0x30},
{0x5ae3,0x28},
{0x5ae4,0x20},
{0x5ae5,0x30},
{0x5ae6,0x28},
{0x5ae7,0x20},
{0x5ae8,0x3c},
{0x5ae9,0x30},
{0x5aea,0x28},
{0x5aeb,0x3c},
{0x5aec,0x30},
{0x5aed,0x28},
{0x5aee,0xfe},
{0x5aef,0x40},
{0x5af4,0x30},
{0x5af5,0x28},
{0x5af6,0x20},
{0x5af7,0x30},
{0x5af8,0x28},
{0x5af9,0x20},
{0x5afa,0x3c},
{0x5afb,0x30},
{0x5afc,0x28},
{0x5afd,0x3c},
{0x5afe,0x30},
{0x5aff,0x28},
{0x36e9,0x44},
{0x37f9,0x44},
{0x0100,0x01},
#else
{0x0103,0x01},
{0x0100,0x00},
{0x36e9,0x80},
{0x37f9,0x80},
{0x3001,0xff},
{0x3002,0xf0},
{0x300a,0x24},
{0x3018,0x0f},
{0x301a,0xf8},
{0x301c,0x94},
{0x301f,0x64},
{0x3030,0x01},
{0x303f,0x81},
{0x3106,0x05},
{0x3200,0x02},
{0x3201,0x4c},
{0x3202,0x00},
{0x3203,0x3c},
{0x3204,0x05},
{0x3205,0x3b},
{0x3206,0x04},
{0x3207,0x03},
{0x3208,0x02},
{0x3209,0xd0},
{0x320a,0x03},
{0x320b,0xc0},
{0x320c,0x07},
{0x320d,0xd0},
{0x320e,0x05},
{0x320f,0xdc},
{0x3210,0x00},
{0x3211,0x10},
{0x3212,0x00},
{0x3213,0x04},
{0x3248,0x04},
{0x3249,0x0b},
{0x3253,0x08},
{0x3301,0x09},
{0x3302,0xff},
{0x3303,0x10},
{0x3306,0x60},
{0x3307,0x02},
{0x330a,0x01},
{0x330b,0x10},
{0x330c,0x16},
{0x330d,0x90},
{0x3318,0x02},
{0x3321,0x0a},
{0x3327,0x0e},
{0x332b,0x12},
{0x3333,0x10},
{0x3334,0x40},
{0x335e,0x06},
{0x335f,0x0a},
{0x3364,0x1f},
{0x337c,0x02},
{0x337d,0x0e},
{0x3390,0x09},
{0x3391,0x0f},
{0x3392,0x1f},
{0x3393,0x20},
{0x3394,0x20},
{0x3395,0x30},
{0x33a2,0x04},
{0x33b1,0x80},
{0x33b2,0x68},
{0x33b3,0x42},
{0x33f9,0x70},
{0x33fb,0xd0},
{0x33fc,0x0f},
{0x33fd,0x1f},
{0x349f,0x03},
{0x34a6,0x0f},
{0x34a7,0x1f},
{0x34a8,0x42},
{0x34a9,0x06},
{0x34aa,0x01},
{0x34ab,0x23},
{0x34ac,0x01},
{0x34ad,0x84},
{0x3630,0xf4},
{0x3633,0x22},
{0x3639,0xf4},
{0x363c,0x47},
{0x3641,0x03},
{0x3670,0x09},
{0x3674,0xf4},
{0x3675,0xfb},
{0x3676,0xed},
{0x367c,0x09},
{0x367d,0x0f},
{0x3690,0x33},
{0x3691,0x33},
{0x3692,0x43},
{0x3698,0x89},
{0x3699,0x96},
{0x369a,0xd0},
{0x369b,0xd0},
{0x369c,0x09},
{0x369d,0x0f},
{0x36a2,0x09},
{0x36a3,0x0f},
{0x36a4,0x1f},
{0x36d0,0x01},
{0x36ea,0x06},
{0x36eb,0x0b},
{0x36ec,0x2a},
{0x36ed,0x28},
{0x3722,0xe1},
{0x3724,0x41},
{0x3725,0xc1},
{0x3728,0x20},
{0x37fa,0x09},
{0x37fb,0x32},
{0x37fc,0x11},
{0x37fd,0x27},
{0x3900,0x0d},
{0x3905,0x98},
{0x391b,0x81},
{0x391c,0x10},
{0x3933,0x81},
{0x3000,0xff},
	//{0x3902,0x85},
	//{0x3909,0x01},
	//{0x390a,0xc2},
{0x3934,0xc5},
{0x3940,0x68},
{0x3941,0x00},
{0x3942,0x01},
{0x3943,0xc6},
{0x3952,0x02},
{0x3953,0x0f},
{0x3e01,0x40},
{0x3e02,0x00},
{0x3e03,0x0b},
{0x3e08,0x1f},
{0x3e1b,0x14},
{0x440e,0x02},
{0x4509,0x38},
{0x4603,0x09},
{0x4819,0x04},
{0x481b,0x02},
{0x481d,0x06},
{0x481f,0x02},
{0x4821,0x07},
{0x4823,0x02},
{0x4825,0x02},
{0x4827,0x02},
{0x4829,0x03},
{0x5799,0x06},
{0x5ae0,0xfe},
{0x5ae1,0x40},
{0x5ae2,0x30},
{0x5ae3,0x28},
{0x5ae4,0x20},
{0x5ae5,0x30},
{0x5ae6,0x28},
{0x5ae7,0x20},
{0x5ae8,0x3c},
{0x5ae9,0x30},
{0x5aea,0x28},
{0x5aeb,0x3c},
{0x5aec,0x30},
{0x5aed,0x28},
{0x5aee,0xfe},
{0x5aef,0x40},
{0x5af4,0x30},
{0x5af5,0x28},
{0x5af6,0x20},
{0x5af7,0x30},
{0x5af8,0x28},
{0x5af9,0x20},
{0x5afa,0x3c},
{0x5afb,0x30},
{0x5afc,0x28},
{0x5afd,0x3c},
{0x5afe,0x30},
{0x5aff,0x28},
{0x36e9,0x24},
{0x37f9,0x20},
{0x0100,0x01},
#endif
};

// MCLK: 27M
// PCLK: 45M
// Fps: 25fps
// totalSize: 2400*750
// Acitve: 1288*728
// mipi_2lane_10bit
static const ISP_U16 gau16SnsInit_SC2336_720P[][2] = {
	{0x0103,0x01},
	{0x0100,0x00},
	{0x36e9,0x80},
	{0x37f9,0x80},
	{0x301f,0x62},
	{0x3106,0x05},
	{0x3200,0x01},
	{0x3201,0x2c},
	{0x3202,0x00},
	{0x3203,0xb2},
	{0x3204,0x06},
	{0x3205,0x5b},
	{0x3206,0x03},
	{0x3207,0x8d},
	{0x3208,0x05},
	{0x3209,0x10},
	{0x320a,0x02},
	{0x320b,0xd8},
	{0x320c,0x09},
	{0x320d,0x60},
	{0x320e,0x02},
	{0x320f,0xee},
	{0x3210,0x00},
	{0x3211,0x10},
	{0x3212,0x00},
	{0x3213,0x02},
	{0x3248,0x04},
	{0x3249,0x0b},
	{0x3250,0x40},
	{0x3253,0x08},
	{0x3301,0x09},
	{0x3302,0xff},
	{0x3303,0x10},
	{0x3306,0x60},
	{0x3307,0x02},
	{0x330a,0x01},
	{0x330b,0x10},
	{0x330c,0x16},
	{0x330d,0xff},
	{0x3318,0x02},
	{0x3321,0x0a},
	{0x3327,0x0e},
	{0x332b,0x12},
	{0x3333,0x10},
	{0x3334,0x40},
	{0x335e,0x06},
	{0x335f,0x0a},
	{0x3364,0x1f},
	{0x337c,0x02},
	{0x337d,0x0e},
	{0x3390,0x09},
	{0x3391,0x0f},
	{0x3392,0x1f},
	{0x3393,0x20},
	{0x3394,0x20},
	{0x3395,0x30},
	{0x33a2,0x04},
	{0x33b1,0x80},
	{0x33b2,0x68},
	{0x33b3,0x42},
	{0x33f9,0x70},
	{0x33fb,0xd0},
	{0x33fc,0x0f},
	{0x33fd,0x1f},
	{0x349f,0x03},
	{0x34a6,0x0f},
	{0x34a7,0x1f},
	{0x34a8,0x42},
	{0x34a9,0x06},
	{0x34aa,0x01},
	{0x34ab,0x23},
	{0x34ac,0x01},
	{0x34ad,0x80},
	{0x3630,0xf4},
	{0x3633,0x22},
	{0x3639,0xf4},
	{0x363c,0x47},
	{0x3670,0x09},
	{0x3674,0xf4},
	{0x3675,0xfb},
	{0x3676,0xed},
	{0x367c,0x09},
	{0x367d,0x0f},
	{0x3690,0x33},
	{0x3691,0x33},
	{0x3692,0x43},
	{0x3698,0x89},
	{0x3699,0x96},
	{0x369a,0xd0},
	{0x369b,0xd0},
	{0x369c,0x09},
	{0x369d,0x0f},
	{0x36a2,0x09},
	{0x36a3,0x0f},
	{0x36a4,0x1f},
	{0x36d0,0x01},
	{0x36ea,0x0a},
	{0x36eb,0x1c},
	{0x36ec,0x1c},
	{0x36ed,0x28},
	{0x3722,0xe1},
	{0x3724,0x41},
	{0x3725,0xc1},
	{0x3728,0x20},
	{0x37fa,0x04},
	{0x37fb,0x32},
	{0x37fc,0x11},
	{0x37fd,0x27},
	{0x3900,0x0d},
	{0x3905,0x98},
	{0x391b,0x81},
	{0x391c,0x10},
	{0x3933,0x81},
	{0x3934,0xc5},
	{0x3940,0x68},
	{0x3941,0x00},
	{0x3942,0x01},
	{0x3943,0xc6},
	{0x3952,0x02},
	{0x3953,0x0f},
	{0x3e01,0x2e},
	{0x3e02,0x80},
	{0x3e03,0x0b},
	{0x3e08,0x1f},
	{0x3e1b,0x14},
	{0x440e,0x02},
	{0x4509,0x38},
	{0x4800,0x44},
	{0x4819,0x04},
	{0x481b,0x02},
	{0x481d,0x06},
	{0x481f,0x02},
	{0x4821,0x07},
	{0x4823,0x02},
	{0x4825,0x02},
	{0x4827,0x02},
	{0x4829,0x03},
	{0x5799,0x06},
	{0x5ae0,0xfe},
	{0x5ae1,0x40},
	{0x5ae2,0x30},
	{0x5ae3,0x28},
	{0x5ae4,0x20},
	{0x5ae5,0x30},
	{0x5ae6,0x28},
	{0x5ae7,0x20},
	{0x5ae8,0x3c},
	{0x5ae9,0x30},
	{0x5aea,0x28},
	{0x5aeb,0x3c},
	{0x5aec,0x30},
	{0x5aed,0x28},
	{0x5aee,0xfe},
	{0x5aef,0x40},
	{0x5af4,0x30},
	{0x5af5,0x28},
	{0x5af6,0x20},
	{0x5af7,0x30},
	{0x5af8,0x28},
	{0x5af9,0x20},
	{0x5afa,0x3c},
	{0x5afb,0x30},
	{0x5afc,0x28},
	{0x5afd,0x3c},
	{0x5afe,0x30},
	{0x5aff,0x28},
	{0x36e9,0x44},
	{0x37f9,0x24},
	{0x0100,0x01},
};



void sensor_init_sc2336(ISP_DEV IspDev)
{
#if 1
	ISP_U16 u16Num,u16i;
	if(P960P_ == gstSnsAttr[IspDev].enRsltType)
	{
		if(	gstSnsAttr[IspDev].u8FunExt == FUN_EXT_DOOR_LOCK_FACE_USED ||
		gstSnsAttr[IspDev].u8FunExt == FUN_EXT_DOOR_LOCK_FACE)
		{
			if(IspDev == 0)
			{
				u16Num = sizeof(gau16SnsInit_sc2336_8bit)/sizeof(gau16SnsInit_sc2336_8bit[0]);
				for(u16i=0; u16i < u16Num; u16i++)
				{
					sensor_write_register(0,(ISP_U32)gau16SnsInit_sc2336_8bit[u16i][0], (ISP_U32)gau16SnsInit_sc2336_8bit[u16i][1]);
				}
				u16Num = sizeof(gau16SnsInit_sc2336_Dvp)/sizeof(gau16SnsInit_sc2336_Dvp[0]);
				for(u16i=0; u16i < u16Num; u16i++)
				{
					sensor_write_register(1,(ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][0], (ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][1]);
				}
			}
		}
		else
		{
			u16Num = sizeof(gau16SnsInit_sc2336)/sizeof(gau16SnsInit_sc2336[0]);
			for(u16i=0; u16i < u16Num; u16i++)
			{
				sensor_write_register(0,(ISP_U32)gau16SnsInit_sc2336[u16i][0], (ISP_U32)gau16SnsInit_sc2336[u16i][1]);
			}
		}
	}
	else
	{
		if(SENSCONT_DVP == gstSnsAttr[IspDev].enCmosIF)
		{
			u16Num = sizeof(gau16SnsInit_sc2336_Dvp)/sizeof(gau16SnsInit_sc2336_Dvp[0]);
			for(u16i=0; u16i < u16Num; u16i++)
			{
				sensor_write_register(IspDev,(ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][0], (ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][1]);
			}
			DEBUG("------------- SC2336 (@202207_dvp) ----------------\n");
		}
		else
		{
			if(gstSnsAttr[IspDev].enRsltType == P720_)
			{
				u16Num = sizeof(gau16SnsInit_SC2336_720P)/sizeof(gau16SnsInit_SC2336_720P[0]);
				for(u16i=0; u16i < u16Num; u16i++)
				{
					sensor_write_register(IspDev,(ISP_U32)gau16SnsInit_SC2336_720P[u16i][0], (ISP_U32)gau16SnsInit_SC2336_720P[u16i][1]);
				}
				DEBUG("------------- sc2336_720P mipi 25fps  init ok!----------------\n");
			}
			else
			{
				u16Num = sizeof(gau16SnsInit_sc2336)/sizeof(gau16SnsInit_sc2336[0]);
				for(u16i=0; u16i < u16Num; u16i++)
				{
					sensor_write_register(IspDev,(ISP_U32)gau16SnsInit_sc2336[u16i][0], (ISP_U32)gau16SnsInit_sc2336[u16i][1]);
				}
				DEBUG("------------- SC2336_1080P  (@202106_mipi) ----------------\n");
			}
		}
		XM_MPI_ISP_USleep(20000);
	}
#else
	ISP_U16 u16Num,u16i;
	if(IspDev == 0)
	{
		#if 1
		u16Num = sizeof(gau16SnsInit_sc2336)/sizeof(gau16SnsInit_sc2336[0]);
		for(u16i=0; u16i < u16Num; u16i++)
		{
			sensor_write_register(0,(ISP_U32)gau16SnsInit_sc2336[u16i][0], (ISP_U32)gau16SnsInit_sc2336[u16i][1]);
		}
		u16Num = sizeof(gau16SnsInit_sc2336_Dvp)/sizeof(gau16SnsInit_sc2336_Dvp[0]);
		for(u16i=0; u16i < u16Num; u16i++)
		{
			sensor_write_register(1,(ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][0], (ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][1]);
		}
		#else
		u16Num = sizeof(gau16SnsInit_sc2336_VGA)/sizeof(gau16SnsInit_sc2336_VGA[0]);
		for(u16i=0; u16i < u16Num; u16i++)
		{
			sensor_write_register(0,(ISP_U32)gau16SnsInit_sc2336_VGA[u16i][0], (ISP_U32)gau16SnsInit_sc2336_VGA[u16i][1]);
		}
		u16Num = sizeof(gau16SnsInit_sc2336_Dvp_VGA)/sizeof(gau16SnsInit_sc2336_Dvp_VGA[0]);
		for(u16i=0; u16i < u16Num; u16i++)
		{
			sensor_write_register(1,(ISP_U32)gau16SnsInit_sc2336_Dvp_VGA[u16i][0], (ISP_U32)gau16SnsInit_sc2336_Dvp_VGA[u16i][1]);
		}
		#endif
	}
	else
	{
		#if 0
		u16Num = sizeof(gau16SnsInit_sc2336_Dvp)/sizeof(gau16SnsInit_sc2336_Dvp[0]);
		for(u16i=0; u16i < u16Num; u16i++)
		{
			sensor_write_register(1,(ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][0], (ISP_U32)gau16SnsInit_sc2336_Dvp[u16i][1]);
		}
		#endif
	}
#endif
}



