#pragma once
#include "raylib.h"
#include "Math"
#include <string>
#include <vector>

enum class WindowState {
    Maximized,
    Minimized,
    Normal,
    Fullscreen
};

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
    class PerspectiveCamera;
    class Window;
    class Window3D;
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


class Canvas::PerspectiveCamera {
    protected:
    Vector3f target;

    public:
    Vector3f position, rotationTowardsTarget;
    float fov;

    PerspectiveCamera(Vector3f target, Vector3f position, Vector3f rotationTowardsTarget, float fov):
        target(target), position(position), rotationTowardsTarget(rotationTowardsTarget), fov(fov){}

    operator Camera3D(){
        Camera3D cam = { 0 };
        cam.position = position.toRaylibVector();
        cam.target = target.toRaylibVector();
        cam.up = rotationTowardsTarget.toRaylibVector();
        cam.fovy = fov;
        cam.projection = CAMERA_PERSPECTIVE;
        return cam;
    }

    /* Move camera locked*/
    void moveCamera(float deltaX, float deltaY);
    /* Move camera unlocked */
    void moveCameraEx(float deltaX, float deltaY);
    
};


/* WINDOW */

class Canvas::Window {

    public:
    int width, height;
    std::string title;
    int fps;
    Camera cam;

    Window(std::string title, int width = 800, int height = 600, Camera cam = Camera(), int fps = 60):
    title(title), width(width), height(height), fps(fps), cam(cam){
        InitWindow(width, height, title.c_str());
        SetTargetFPS(fps);
    }

    void startDraw(Color color = WHITE);
    void clear(Color color);
    void startCam();
    void endCam();
    void endDraw();
    void close();
    
    // OVERRIDE FUNCTIONS

    void update();
    void closing();


    // OPERANDS
    operator bool(){
        return !WindowShouldClose();
    }


    // miscellaneous

    bool focused();
    WindowState getWindowState();

};

class Canvas::Window3D : public Canvas::Window {
    public:
    PerspectiveCamera camera3d;

    Window3D(std::string title, int width, int height, PerspectiveCamera camera, int fps = 60): Window(title, width, height, Camera(), fps), camera3d(camera){
    }

    void startCam();
    void endCam();
};