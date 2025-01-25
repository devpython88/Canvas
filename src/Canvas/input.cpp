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

bool Canvas::Mouse::isHidden()
{
    return IsCursorHidden();
}

void Canvas::Mouse::hide()
{
    HideCursor();
}

void Canvas::Mouse::show()
{
    ShowCursor();
}
