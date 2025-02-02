#pragma once
#include "raylib.h"
#include "Graphics"
#include "raymath.h"
#include <vector>
#include <sstream>

namespace Canvas {
    class Lighting;
    class TextStuff;
    class Gravity;
    class TopdownController;
}


class Canvas::Lighting : public Canvas::Object2D {
    protected:
    
    Circle2D layer1;
    Circle2D layer2;
    Circle2D layer3;

    public:
    float intensity;
    float x, y;
    

    Lighting(float x, float y, float radius, int intensity, Color color):
        layer1(x, y, radius, Color{ color.r, color.g, color.b, static_cast<unsigned char>(intensity)}),
        layer2(x, y, radius + 10, Color{ color.r, color.g, color.b, static_cast<unsigned char>(intensity - 20)}),
        layer3(x, y, radius + 20, Color{ color.r, color.g, color.b, static_cast<unsigned char>(intensity - 40)}), Object2D(0, 0, 0, 0, 0){}
    

    void draw();
};



class Canvas::TextStuff {
    public:

    static std::vector<std::string> split(std::string text, char delimiter);
};


class Canvas::Gravity {
    protected:
    float velocity;
    float acceleration, jumpPower;
    int jumpKey;

    public:
    Object2D* object;

    Gravity(Object2D* object, float acceleration, float jumpPower, int jumpKey = KEY_SPACE):
        velocity(0.0f), acceleration(acceleration), jumpPower(jumpPower), jumpKey(jumpKey), object(object){}

    
    void update();
    void jump();
};



class Canvas::TopdownController {
    public:
    Object2D *host;
    std::vector<Object2D> collidables;

    int keyUp, keyDown, keyLeft, keyRight;
    float speed;
    bool mustBeHeld;

    TopdownController(Object2D *host, int keyUp, int keyDown, int keyLeft, int keyRight, float speed, bool mustBeHeld = true, std::vector<Object2D> collidables = std::vector<Object2D>()):
        host(host), keyUp(keyUp), keyDown(keyDown), keyLeft(keyLeft), keyRight(keyRight), speed(speed), mustBeHeld(mustBeHeld), collidables(collidables){}
    

    void check();

    /// @brief Checks if the player will collide when the new delta is added
    bool willCollide(float deltaX, float deltaY);
};