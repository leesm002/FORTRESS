#pragma once
#include "Include.h"

class SoundManager
{
private:
	static SoundManager* m_pInstance;
public:
	static SoundManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new SoundManager;
		return m_pInstance;
	}
private:
	FMOD_SYSTEM* m_pSystem;
	map<string, FMOD_SOUND*> m_pSoundList;

	FMOD_CHANNEL* m_pChannel[SOUND_CHANNE_MAX];
public:
	void Initialize();
	void AddSound(const char* name_or_data, string _Ksy);
	void StreamingUpdate();
	void OnPlaySound(string _Ksy, SOUND_CHANNEL_IDS _SoundState);
	void OnCloseSound(SOUND_CHANNEL_IDS _SoundState);
	void SetSoundVolume(SOUND_CHANNEL_IDS _SoundState, int _Percent);

	void Release();
private:
	SoundManager();
public:
	~SoundManager();
};

