#pragma once
#include "raylib.h"
#include "Graphics"

namespace Canvas {
    class Keyboard;
    class Mouse;
    class KeyBinding;
    class MouseBinding;
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

    static bool isHovering(Object2D obj);
    static bool isClicking(Object2D obj);

    static void hide();
    static void show();
};


class Canvas::KeyBinding {
    public:
    int key, modifier;


    KeyBinding(int key, int mod = -128): key(key), modifier(mod){
    }

    bool held();
    bool pressed();
};


class Canvas::MouseBinding {
    public:
    int button;


    MouseBinding(int button): button(button){}

    bool held();
    bool pressed();
};