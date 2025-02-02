#include "dialog.hpp"

void Canvas::Dialog::draw()
{
    if (!visible) return;

    recalculateContentLayout();

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{ 0, 0, 0, 150 });
    DrawRectangle(x, y, width, height, color);
    titleBar.draw();
    button.draw();
}

void Canvas::Dialog::recalculateContentLayout()
{
    titleBar.x = x + 10;
    titleBar.y = y + 10;
    
    button.rect.x = (x + width) - button.rect.w;
    button.rect.y = y;
}

Canvas::Vector2f Canvas::Dialog::calculateRelativePosition(Object2D obj, int xIndex, int yIndex)
{
    Vector2f newPos(obj.x, obj.y);
    newPos.x = (x + 20) * xIndex;
    newPos.y = (y + 20) * yIndex;

    return newPos;
}
