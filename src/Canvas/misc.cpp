#include "misc.hpp"

void Canvas::Lighting::draw()
{
    layer3.draw();
    layer2.draw();
    layer1.draw();
}

std::vector<std::string> Canvas::TextStuff::split(std::string text, char delimiter)
{
    std::stringstream ss(text);
    std::vector<std::string> toks;
    std::string token;


    while (std::getline(ss, token, delimiter)){
        toks.push_back(token);
    }

    return toks;
}

void Canvas::Gravity::update()
{
    if (IsKeyPressed(jumpKey)){
        jump();
    }

    velocity += acceleration;
    object->y += velocity;
}

void Canvas::Gravity::jump()
{
    velocity = -jumpPower;
}

void Canvas::TopdownController::check()
{
    if (mustBeHeld){
        if (IsKeyDown(keyUp) && !willCollide(0, -speed)) host->y -= speed;
        if (IsKeyDown(keyDown) && !willCollide(0, speed)) host->y += speed;
        if (IsKeyDown(keyRight) && !willCollide(speed, 0)) host->x += speed;
        if (IsKeyDown(keyLeft) && !willCollide(-speed, 0)) host->x -= speed;
        return;
    }
    
    if (IsKeyPressed(keyUp) && !willCollide(0, -speed)) host->y -= speed;
    if (IsKeyPressed(keyDown) && !willCollide(0, speed)) host->y += speed;
    if (IsKeyPressed(keyRight) && !willCollide(speed, 0)) host->x += speed;
    if (IsKeyPressed(keyLeft) && !willCollide(-speed, 0)) host->x -= speed;
}

bool Canvas::TopdownController::willCollide(float deltaX, float deltaY)
{
    for (Object2D &obj : collidables){
        if (obj.collidingWith(Object2D(host->x + deltaX, host->y + deltaY, host->w, host->h))) return true;
    }

    return false;
}
