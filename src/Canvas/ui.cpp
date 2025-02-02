#include "ui.hpp"

void Canvas::TextLabel::draw()
{
    DrawText(text.c_str(), x, y, fontSize, color);
}

void Canvas::RichLabel::draw()
{
    DrawTextEx(font, text.c_str(), (Vector2) { x, y }, fontSize, spacing, color);
}

void Canvas::Button::draw()
{
    rect.color = BLACK;

    if (Mouse::isHovering(rect)){
        rect.color = GRAY;
    }

    if (Mouse::isClicking(rect)){
        rect.color = LIGHTGRAY;
        event();
    }

    
    label.x = rect.x + (rect.w / 2) - (label.w / 2);
    label.y = rect.y + (rect.h / 2) - (label.h / 2);

    rect.draw();
    label.draw();
}

void Canvas::Menu::toggleOptions()
{
    showOptions = !showOptions;
}

void Canvas::Menu::arrangeItems()
{
    if (options.empty()) return;

    float yPos;
    yPos = options[0].rect.y;

    for(Button& btn : options){
        btn.rect.x = options[0].rect.x;
        btn.rect.y = yPos + options[0].rect.h + spacing;

        yPos = btn.rect.y;
    }
}

void Canvas::Menu::draw()
{
    arrangeItems();
    if (visible) button.draw();
    if (showOptions) for (Button btn : options) btn.draw();
}
