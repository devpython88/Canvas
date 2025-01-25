#pragma once
#include "Graphics"


namespace Canvas {
    class UIComponent;
    class TextLabel;
    class TextLabelF;
}


class Canvas::UIComponent : public Canvas::Object2D {
    public:
    Color color;

    UIComponent(float x, float y, float w, float h, Color color):
        Canvas::Object2D(x, y, w, h), color(color){}
};


class Canvas::TextLabel : public Canvas::UIComponent {
    public:
    int fontSize;
    std::string text;

    TextLabel(float x, float y, int fontSize, std::string text, Color color = BLACK): UIComponent(x, y, MeasureText(text.c_str(), fontSize), fontSize, color), text(text){
    }

    void draw();

};