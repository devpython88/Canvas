#pragma once
#include "Graphics"
#include <functional>
#include "Input"


namespace Canvas {
    class UIComponent;
    class TextLabel;
    class RichLabel;
    class Button;
    class Menu;
}

typedef std::function<void(void)> ButtonEvent;

// UI Component

class Canvas::UIComponent : public Canvas::Object2D {
    public:
    Color color;
    bool visible;

    UIComponent(float x, float y, float w, float h, Color color):
        Canvas::Object2D(x, y, w, h), color(color), visible(true){}
};

// Text label

class Canvas::TextLabel : public Canvas::UIComponent {
    public:
    int fontSize;
    std::string text;

    TextLabel(float x, float y, int fontSize, std::string text, Color color = BLACK): UIComponent(x, y, MeasureText(text.c_str(), fontSize), fontSize, color), fontSize(fontSize), text(text){
    }

    void draw();
};


class Canvas::RichLabel : public Canvas::TextLabel {
    protected:
    Font font;

    public:
    std::string fontPath;
    int spacing;

    RichLabel(float x, float y, int fontSize, std::string text, std::string fontPath, int spacing = 1, Color color = BLACK): 
        TextLabel(x, y, fontSize, text, color), fontPath(fontPath), spacing(spacing){
        font = LoadFont(fontPath.c_str());
    }

    void draw();
}; 

// Buton

class Canvas::Button {
    public:
    TextLabel label;
    Rect2D rect;
    ButtonEvent event;


    Button(float x, float y, TextLabel label, ButtonEvent event): label(label),
        rect(x, y, label.w * 4, label.h * 2, BLACK), event(event){
    }

    void draw();
};

    


class Canvas::Menu {
    public:

    std::vector<Button> options;
    Button button;
    float spacing;
    bool showOptions, visible;
    
    Menu(TextLabel label, float x, float y, Color color, float spacing = 0.0f): button(x, y, label, [this]() { toggleOptions(); }), spacing(spacing){
        showOptions = false;
        visible = true;
    }
    
    void toggleOptions();
    void arrangeItems();
    void draw();
};