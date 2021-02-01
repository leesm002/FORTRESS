#include "SoundManager.h"

SoundManager* SoundManager::m_pInstance = NULL;

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}



void SoundManager::Initialize()
{
	FMOD_System_Create(&m_pSystem);
	FMOD_System_Init(m_pSystem, 32, FMOD_INIT_NORMAL, NULL);

	/*****************************************************
	*   ** FMOD API 출력 가능한 사운드 포맷 정보 **
	* AIFF, ASF, ASX, DLS,DLAC, FSB, IT, M3U, MID, MOD, MP2
	* MP3, OGG, PLS, RAW, S3M, VAG, WAV, WMA, XM, XMA
	******************************************************/

	for (int i = 0; i < SOUND_CHANNE_MAX; ++i)
		FMOD_Channel_SetVolume(m_pChannel[i], 0.5f);
}

void SoundManager::AddSound(const char* name_or_data, string _Ksy)
{
	FMOD_SOUND* Sound;

	FMOD_System_CreateSound(m_pSystem, name_or_data, FMOD_DEFAULT, 0, &Sound);

	/****************************************************************
	* FMOD_DEFAULT = FMOD_LOOP_OFF, FMOD_2D, FMOD_HARDWARE 와 같음.
	* FMOD_LOOP_OFF
	* FMOD_2D
	* FMOD_HARDWARE
	* FMOD_LOOP_NORMAL
	*****************************************************************/

	m_pSoundList.insert(make_pair(_Ksy, Sound));
}

void SoundManager::StreamingUpdate()
{
	FMOD_System_Update(m_pSystem);
}

void SoundManager::OnPlaySound(string _Ksy, SOUND_CHANNEL_IDS _SoundState)
{
	map<string, FMOD_SOUND*>::iterator iter = m_pSoundList.find(_Ksy);

	FMOD_System_PlaySound(m_pSystem, iter->second, NULL, false, &m_pChannel[_SoundState]);
}

void SoundManager::OnCloseSound(SOUND_CHANNEL_IDS _SoundState)
{
	FMOD_Channel_Stop(m_pChannel[_SoundState]);
}

void SoundManager::SetSoundVolume(SOUND_CHANNEL_IDS _SoundState, int _Percent)
{
	FMOD_Channel_SetVolume(m_pChannel[_SoundState], float(_Percent / 100));
}


void SoundManager::Release()
{
	for (map<string, FMOD_SOUND*>::iterator iter = m_pSoundList.begin();
		iter != m_pSoundList.end(); ++iter)
	{
		FMOD_Sound_Release(iter->second);
	}
	m_pSoundList.clear();

	FMOD_System_Close(m_pSystem);
	FMOD_System_Release(m_pSystem);
}


