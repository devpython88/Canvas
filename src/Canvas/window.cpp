#include "window.hpp"

void Canvas::Window::startDraw(Color color)
{
    BeginDrawing();
    clear(color);
}

void Canvas::Window::clear(Color color)
{
    ClearBackground(color);
}

void Canvas::Window::startCam()
{
    BeginMode2D(cam);
}

void Canvas::Window::endCam()
{
    EndMode2D();
}

void Canvas::Window::endDraw()
{
    EndDrawing();
}

void Canvas::Window::close()
{
    closing();
    if (IsWindowReady()) CloseWindow();
}

void Canvas::Window::update()
{
}

void Canvas::Window::closing()
{
}
