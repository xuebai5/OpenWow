#pragma once

const vec2 VECTOR_ZERO = vec2(0.0f, 0.0f);

#define MAX_FRAMES_PER_SEC 60

#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define PI 3.14159265359f

// Pi / 4 * x
#define M_1_PI_4 0.78539816339
#define M_3_PI_4 2.35619449019
#define M_5_PI_4 3.92699081699
#define M_7_PI_4 5.49778714378
#define M_9_PI_4 7.06858347058

#define M_1_PI_6 0.52359877559
#define M_1_PI_12 0.26179938779

#define M_2_PI 6.28318530718

enum TextAlignW
{
	TEXT_ALIGNW_LEFT = 0,
	TEXT_ALIGNW_CENTER,
	TEXT_ALIGNW_RIGHT
};

enum TextAlignH
{
	TEXT_ALIGNH_TOP = 0,
	TEXT_ALIGNH_CENTER,
	TEXT_ALIGNH_BOTTOM
};

enum InputMode
{
	MODE_CHARACTERS = 0,
	MODE_NUMBERS,
	MODE_ANY
};
