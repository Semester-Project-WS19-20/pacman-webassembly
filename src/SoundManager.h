#ifndef __SoundManager__
#define __SoundManager__

#include <iostream>
#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


enum sound_type
{
  SOUND_MUSIC = 0,
  SOUND_SFX = 1
};

class SoundManager
{
public:
  static SoundManager *Instance()
  {
    if (s_pInstance == nullptr)
    {
      s_pInstance = new SoundManager();
      return s_pInstance;
    }
    return s_pInstance;
  }

  bool load(std::string fileName, std::string id, sound_type type);

  void playSound(std::string id, int loop);
  void playMusic(std::string id, int loop);
	bool isSoundOn() { return m_bSounds; }

private:
  static SoundManager *s_pInstance;

	bool m_bSounds;

  std::map<std::string, Mix_Chunk *> m_sfxs;
  std::map<std::string, Mix_Music *> m_music;

  SoundManager();
  ~SoundManager();

  SoundManager(const SoundManager &);
  SoundManager &operator=(const SoundManager &);
};

typedef SoundManager TheSoundManager;

#endif
