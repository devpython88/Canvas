#pragma once
#include "raylib.h"
#include <string>

namespace Canvas {
    class Object2D;
    class Rect2D;
    class Circle2D;

    class Image2D;
}


class Canvas::Object2D {
    public:
    float w, h;
    float x, y;

    Object2D(float x, float y, float w, float h): x(x), y(y), w(w), h(h){}

    bool collidingWith(Object2D with) const;
    inline bool operator &(Object2D obj){
        return collidingWith(obj);
    }
};


class Canvas::Rect2D : public Canvas::Object2D {
    public:
    Color color;

    Rect2D(float x, float y, float w, float h, Color color): Object2D(x, y, w, h), color(color){}


    void draw(); 
};


class Canvas::Circle2D : public Canvas::Object2D {
    public:
    Color color;

    Circle2D(float x, float y, float rad, Color color): Object2D(x, y, rad, rad), color(color){}

    bool collidingWith(Circle2D with) const;
    bool collidingWith(Object2D with) const;


    void draw();
};

/**************************************/
/*              IMAGE                 */
/**************************************/

class Canvas::Image2D : public Canvas::Object2D {
    private:
    Texture2D texture;

    public:
    Color tint;

    Image2D(float x, float y, std::string file_path, Color tint = WHITE): Object2D(x, y, 0, 0), texture(LoadTexture(file_path.c_str())), tint(tint){
        w = texture.width;
        h = texture.height;
    }

    bool isLoaded();
    void draw();
    void unload();
};