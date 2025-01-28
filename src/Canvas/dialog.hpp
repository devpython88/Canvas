#pragma once
#include "Window"
#include "UI"
#include "Math"

namespace Canvas {
    class Dialog;
}


class Canvas::Dialog {
    public:
    Canvas::Button button;
    Canvas::TextLabel titleBar;
    Canvas::Object2D titleBox;
    bool visible;
    float x, y, width, height;
    Color color;


    Dialog(float x, float y, std::string titleBarText, float width, float height, Color color):
        titleBar(x + 10, y + 10, 16, titleBarText, WHITE),
        button(width - 12, y, TextLabel(0, 0, 14, "X", WHITE), [this]() { visible = false; }),
        visible(false), x(x), y(y), width(width), height(height), color(color), titleBox(x, y, width, 30){}
    

    void draw();

    void recalculateContentLayout();
    Vector2f calculateRelativePosition(Object2D obj, int xIndex, int yIndex);
};

