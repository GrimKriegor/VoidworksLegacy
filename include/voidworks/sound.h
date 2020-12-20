#ifndef SOUND_H_
#define SOUND_H_

#include <vector>
#include <string>
#include <windows.h>
#include <voidworks/common.h>

struct PlaylistEntry
{
  std::string filename;
  std::string name;
  bool loop;
};

using Playlist = std::vector<PlaylistEntry>;

class MusicPlayer
{
  private:
    static MusicPlayer* instance_;
    MusicPlayer();
    Playlist playlist;
    uint16_t playlist_position = 0;
    void PlaySongFilename(std::string, bool, bool=false);
  public:
    ~MusicPlayer();
    static MusicPlayer* GetInstance();
    void Play();
    void Stop();
    void Next();
    void Previous();
    void PlayAsync(std::string, bool=false);
};

#endif
