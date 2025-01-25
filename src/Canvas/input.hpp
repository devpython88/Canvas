#pragma once
#include "raylib.h"

namespace Canvas {
    class Keyboard;
    class Mouse;
}


class Canvas::Keyboard {
    public:

    static bool keyPressed(int key);
    static bool keyHeld(int key);
    static bool KeyReleased(int key);
};


class Canvas::Mouse {
    public:

    static const int LeftButton = MOUSE_BUTTON_LEFT;
    static const int MiddleButton = MOUSE_BUTTON_MIDDLE;
    static const int RightButton = MOUSE_BUTTON_RIGHT;

    static int x(){ return GetMouseX(); }
    static int y(){ return GetMouseY(); }

    static bool buttonPressed(int btn);
    static bool buttonReleased(int btn);
    static bool buttonHeld(int btn);
    static bool isHidden();


    static void hide();
    static void show();
};