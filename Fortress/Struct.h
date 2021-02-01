#pragma once


typedef struct tagVector3
{
	float fX, fY, fZ;

	tagVector3() {};

	tagVector3(float _fX, float _fY) : fX(_fX), fY(_fY), fZ(0) {};

	tagVector3(float _fX, float _fY, float _fZ) 
		 : fX(_fX), fY(_fY), fZ(_fZ) {};

}Vector3;


typedef struct tagTransform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;

}Transform;


typedef struct tagFrame
{
	int StartFrame;
	int Count;
	int LastFrame;
	int Scene;
	DWORD FrameTime;

	tagFrame() {};

	tagFrame(int _StartFrame, 
		int _Count, 
		int _LastFrame, 
		int _Scene,
		DWORD _FrameTime)
		: StartFrame(_StartFrame),
		Count(_Count),
		LastFrame(_LastFrame),
		Scene(_Scene),
		FrameTime(_FrameTime) {};

}Frame;



typedef struct tagSoundInfo
{
	string Ksy;
	SOUND_CHANNEL_IDS SoundState;

}SOUNDINFO;