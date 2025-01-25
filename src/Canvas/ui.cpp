#include "ui.hpp"

void Canvas::TextLabel::draw()
{
    DrawText(text.c_str(), x, y, fontSize, color);
}