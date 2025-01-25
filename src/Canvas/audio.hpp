#pragma once
#include "raylib.h"
#include <string>

namespace Canvas {
    class SoundEffect;
    class LoopingSound;
};

class Canvas::SoundEffect {
    private:
    Sound sound;

    public:
    std::string file;


    SoundEffect(std::string file): file(file){
        if (!IsAudioDeviceReady()){
            InitAudioDevice();
        }

        sound = LoadSound(file.c_str());
    }

    void unload();
    bool isPlaying();
    void play();
};


class Canvas::LoopingSound {
    private:
    Music music;

    public:
    std::string file;

    LoopingSound(std::string file): file(file){
        if (!IsAudioDeviceReady()){
            InitAudioDevice();
        }

        music = LoadMusicStream(file.c_str());
    }

    void unload();
    bool isPlaying();
    void play();
    void update();
};