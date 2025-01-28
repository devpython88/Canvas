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
