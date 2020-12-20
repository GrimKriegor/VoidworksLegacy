#include <voidworks/sound.h>

MusicPlayer* MusicPlayer::instance_ = 0;

MusicPlayer::MusicPlayer()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "MusicPlayer initialized\n" ANSI_RESET);
#endif
}

void MusicPlayer::PlaySongFilename(std::string filename, bool loop, bool async)
{
  uint32_t options = 0;
  if (loop)  { options |= SND_LOOP;  }
  if (async) { options |= SND_ASYNC; }
  else       { options |= SND_SYNC;  }
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG
      "Playing: \"%s\", loop: %d, async: %d\n"
      ANSI_RESET,
      filename.c_str(),
      loop?"true":"false",
      async?"true":"false"
    );
#endif
  PlaySound(filename.c_str(), NULL, options);
}

MusicPlayer::~MusicPlayer()
{
  Stop();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "MusicPlayer terminated\n" ANSI_RESET);
#endif
}

MusicPlayer* MusicPlayer::GetInstance()
{
  if (!instance_)
  {
    instance_ = new MusicPlayer();
  }
  return instance_;
}

void MusicPlayer::Play()
{
  return;
}

void MusicPlayer::Stop()
{
  PlaySound(NULL, NULL, 0);
}

void MusicPlayer::Next()
{
  playlist_position++;
  Play();
}

void MusicPlayer::Previous()
{
  playlist_position--;
  Play();
}

void MusicPlayer::PlayAsync(std::string filename, bool loop)
{
  PlaySongFilename(filename, loop, true);
}
