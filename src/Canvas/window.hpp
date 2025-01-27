#pragma once
#include "raylib.h"
#include "Math"
#include <string>
#include <vector>

#define CREATE_GAME(gameClass) int main(int argc, const char *argv[]){\
    gameClass game;\
    while (game){\
        if (IsWindowReady()) game.update();\
    }\
    game.close();\
    if (IsAudioDeviceReady()){\
        CloseAudioDevice();\
    }\
}

namespace Canvas {
    class Camera;
    class Window;
};


class Canvas::Camera {
    public:
    Vector2f target;
    Vector2f offset;
    int rotation;
    float zoom;

    float *targetX, *targetY;

    Camera(Vector2f target = Vector2f(0, 0), Vector2f offset = Vector2f(0, 0), int rotation = 0, float zoom = 1.0f):
        target(target), offset(offset), rotation(rotation), zoom(zoom){
        targetX = &target.x;
        targetY = &target.y;
    }
    

    operator Camera2D(){
        Vector2 t = { target.x, target.y };
        Vector2 o = { offset.x, offset.y };

        Camera2D cam = { 0 };
        cam.target = t;
        cam.offset = o;
        cam.rotation = rotation;
        cam.zoom = zoom;

        return cam;
    }

};

/* WINDOW */

class Canvas::Window {
    public:
    Camera cam;
    int width, height;
    std::string title;
    int fps;

    Window(std::string title, int width = 800, int height = 600, Camera cam = Camera(), int fps = 60):
    title(title), width(width), height(height), cam(cam), fps(fps){
        InitWindow(width, height, title.c_str());
        SetTargetFPS(fps);
    }

    void startDraw(Color color = WHITE);
    void clear(Color color);
    void startCam();
    void endCam();
    void endDraw();
    void close();

    // OVERRIDED FUNCTIONS
    void update();
    void closing();


    // OPERANDS
    operator bool(){
        return !WindowShouldClose();
    }
};