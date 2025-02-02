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

bool Canvas::Window::focused()
{
    return IsWindowFocused();
}

WindowState Canvas::Window::getWindowState()
{
    if (IsWindowFullscreen) return WindowState::Fullscreen;
    if (IsWindowMaximized) return WindowState::Maximized;
    if (IsWindowMinimized) return WindowState::Minimized;
    return WindowState::Fullscreen;
    
}


void Canvas::Window3D::startCam()
{
    BeginMode3D(camera3d);
}

void Canvas::Window3D::endCam()
{
    EndMode3D();
}

void Canvas::PerspectiveCamera::moveCamera(float deltaX, float deltaY)
{
    position.x += deltaX;
    position.y += deltaY;
}

void Canvas::PerspectiveCamera::moveCameraEx(float deltaX, float deltaY)
{
    moveCamera(deltaX, deltaY);
    target.x += deltaX;
    target.y += deltaY;
}
