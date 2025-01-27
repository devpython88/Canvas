#pragma once
#include "Window"
#include "UI"

namespace Canvas {
    class Dialog;
}


class Canvas::Dialog {
    public:
    Canvas::Button button;
    Canvas::TextLabel titleBar;
    bool visible;
    float x, y, width, height;
    Color color;


    Dialog(float x, float y, std::string titleBarText, float width, float height, Color color):
        titleBar(x + 10, y + 10, 16, titleBarText, WHITE),
        button(width - 12, y, TextLabel(0, 0, 14, "X", WHITE), [this]() { visible = false; }),
        visible(false), x(x), y(y), width(width), height(height), color(color){}
    

    void draw();
};