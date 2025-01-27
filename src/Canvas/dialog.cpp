#include "dialog.hpp"

void Canvas::Dialog::draw()
{
    if (!visible) return;

    DrawRectangle(x, y, width, height, color);
    titleBar.draw();
    button.draw();
}