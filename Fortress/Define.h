#pragma once

#define WINSIZEX  1920
#define WINSIZEY  1080

#define PLAYER_SCALE 256
#define PLAYER_SCALEF 256.0f
#define PLAYER_RADIUS (PLAYER_SCALE / 2)
#define PLAYER_RADIUSF (PLAYER_SCALEF / 2)

#define GROUND_WIDTH 512
#define GROUND_HEIGHT 256

#define BULLET_SCALE_X 48
#define BULLET_SCALE_Y 84


#define PI 3.141592f


extern HWND g_hWnd;


const DWORD KEY_UP				= 0x00001;			// 00000001
const DWORD KEY_DOWN		= 0x00002;			// 00000010
const DWORD KEY_LEFT			= 0x00004;			// 00000100
const DWORD KEY_RIGHT		= 0x00008;			// 00001000
const DWORD KEY_SPACE		= 0x00010;			// 00010000
const DWORD KEY_RETURN	= 0x00020;			// 00100000
const DWORD KEY_MENU		= 0x00040;			// 01000000

const DWORD KEY_RBUTTON = 0x00080;			// ���콺 ��Ŭ��
const DWORD KEY_LBUTTON = 0x00100;			// ���콺 ��Ŭ��
const DWORD KEY_ESCAPE = 0x00200;			// ����Ű
const DWORD KEY_TAB = 0x00400;				// ��Ű



//		 00000001
//	|	 00000100
//------------------
//       00000101
//	&	 00000001
//------------------
//		 00000001



//       00000101
//	&	 00000100
//------------------
//		 00000100


// 00000100
// 00001000
// 00010000
// 00100000
// 01000000









