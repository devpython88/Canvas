#include "input.hpp"

bool Canvas::Keyboard::keyPressed(int key)
{
    return IsKeyPressed(key);
}

bool Canvas::Keyboard::keyHeld(int key)
{
    return IsKeyDown(key);
}

bool Canvas::Keyboard::KeyReleased(int key)
{
    return IsKeyReleased(key);
}

bool Canvas::Mouse::buttonPressed(int btn)
{
    return IsMouseButtonPressed(btn);
}

bool Canvas::Mouse::buttonReleased(int btn)
{
    return IsMouseButtonReleased(btn);
}

bool Canvas::Mouse::buttonHeld(int btn)
{
    return IsMouseButtonDown(btn);
}

float Canvas::Mouse::scrollAmount(bool windowAlike)
{
    if (windowAlike){
        return -GetMouseWheelMove();
    }
    
    return GetMouseWheelMove();
}

Vector2 Canvas::Mouse::scrollAmountV()
{
    return GetMouseWheelMoveV();
}

bool Canvas::Mouse::isHidden()
{
    return IsCursorHidden();
}

bool Canvas::Mouse::isHovering(Object2D obj)
{
    return Object2D(x(), y(), 10, 10).collidingWith(obj);
}

bool Canvas::Mouse::isClicking(Object2D obj)
{
    return isHovering(obj) && buttonHeld(LeftButton);
}

void Canvas::Mouse::hide()
{
    HideCursor();
}

void Canvas::Mouse::show()
{
    ShowCursor();
}

bool Canvas::KeyBinding::held()
{
    if (modifier != -128){
        return Keyboard::keyHeld(modifier) && Keyboard::keyHeld(key);
    }

    return Keyboard::keyHeld(key);
}

bool Canvas::KeyBinding::pressed()
{
    if (modifier != -128){
        return Keyboard::keyHeld(modifier) && Keyboard::keyPressed(key);
    }

    return Keyboard::keyPressed(key);
}

bool Canvas::MouseBinding::held()
{
    return Mouse::buttonHeld(button);
}

bool Canvas::MouseBinding::pressed()
{
    return Mouse::buttonPressed(button);
}

void Canvas::InputManager::addBinding(std::string name, int key, int mod)
{
   keyBindings[name] = KeyBinding(key, mod);
}

void Canvas::InputManager::addBinding(std::string name, int button)
{
    mouseBindings[name] = MouseBinding(button);
}

bool Canvas::InputManager::checkMouseBinding(std::string name, bool held)
{
    if (held) return mouseBindings[name].held();
    return mouseBindings[name].pressed();
}

bool Canvas::InputManager::checkKeyBinding(std::string name, bool held)
{
    if (held) return keyBindings[name].held();
    return mouseBindings[name].pressed();
}
