#include "audio.hpp"

void Canvas::SoundEffect::unload()
{
    UnloadSound(sound);
}

bool Canvas::SoundEffect::isPlaying()
{
    return IsSoundPlaying(sound);;
}

void Canvas::SoundEffect::play()
{
    PlaySound(sound);
}

void Canvas::LoopingSound::unload()
{
    UnloadMusicStream(music);
}

bool Canvas::LoopingSound::isPlaying()
{
    return IsMusicStreamPlaying(music);
}

void Canvas::LoopingSound::play()
{
    PlayMusicStream(music);
}

void Canvas::LoopingSound::update()
{
    UpdateMusicStream(music);
}
