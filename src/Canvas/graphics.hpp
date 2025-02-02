#pragma once
#include "raylib.h"
#include <string>
#include "Math"

namespace Canvas {
    class Object2D;
    class Rect2D;
    class Circle2D;
    class Line2D;
    class Triangle2D;
    class Poly2D;

    class Image2D;
    class SpriteSheet2D;
    class Animation2D;
}
    

class Canvas::Object2D {
    protected:
    Vector2f oldPos;

    public:
    float w, h;
    float x, y;
    int rotation;
    bool visible;

    Object2D(float x, float y, float w, float h, int rotation = 0): x(x), y(y), w(w), h(h), rotation(rotation), oldPos(x, y){
        visible = true;
    }

    bool collidingWith(Object2D with) const;
    void draw();
    inline bool operator &(Object2D obj){
        return collidingWith(obj);
    }

    void pool();
    void unpool();
};


class Canvas::Rect2D : public Canvas::Object2D {
    public:
    Color color;

    Rect2D(float x, float y, float w, float h, Color color, int rotation = 0): Object2D(x, y, w, h, rotation), color(color){}


    void draw(); 
};

class Canvas::Triangle2D : public Canvas::Object2D {
    public:
    Color color;
    float radius;

    Triangle2D(float x, float y, float radius, int rotation, Color color): Object2D(x, y, radius, radius, rotation), radius(radius), color(color){}

    bool collidingWith(Triangle2D with) const;
    bool collidingWith(Object2D with) const;
    
    void draw();
};

class Canvas::Poly2D : public Object2D {
    public:
    Color color;
    int sides;
    float radius;


    Poly2D(float x, float y, int sides, float radius, int rotation, Color color): Object2D(x, y, radius, radius, rotation), radius(radius), sides(sides), color(color){}

    bool collidingWith(Poly2D with) const;
    bool collidingWith(Object2D with) const;
    
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


class Canvas::Line2D {
    public:
    Vector2f start, end;
    float width;
    Color color;
    bool visible;


    Line2D(Vector2f start, Vector2f end, float width, Color color = BLACK): color(color), start(start), end(end), width(width){ visible = true; }

    void draw();
    void drawPro();
};

/**************************************/
/*              IMAGE                 */
/**************************************/

class Canvas::Image2D : public Canvas::Object2D {
    protected:

    public:
    Color tint;
    Texture2D texture;
    int scale;

    Image2D(float x, float y, std::string file_path, Color tint = WHITE, int scale = 1): Object2D(x, y, 0, 0), texture(LoadTexture(file_path.c_str())), scale(scale), tint(tint){
        w = texture.width;
        h = texture.height;
    }

    bool isLoaded();
    void draw();
    void unload();
};

class Canvas::SpriteSheet2D : public Canvas::Image2D {
    public:
    int frameWidth, frameHeight;

    // using object2d so framerect dont ask for color
    Object2D frameRect;

    SpriteSheet2D(int frameWidth, int frameHeight,
        float x, float y, std::string file_path,
        Color tint = WHITE): Image2D(x, y, file_path, tint), frameHeight(frameHeight), frameWidth(frameWidth), frameRect(0, 0, frameWidth, frameHeight){

        // gotta do this otherwise, KABOOM collision is messed up
        w = frameWidth;
        h = frameHeight;
    }


    void nextColumn();
    void nextRow();
    void prevColumn();
    void prevRow();
    void setColumn(int index);
    void setRow(int index);
    bool isAtFirstRow();
    bool isAtLastRow();
    bool isAtFirstColumn();
    bool isAtLastColumn();
    void draw();
};


// Animated sprite sheet
class Canvas::Animation2D : public Canvas::SpriteSheet2D {
    private:
    float timer;

    public:
    float animationDelay;

    Animation2D(float animationDelay, Vector2f frameSize, Vector2f position, std::string file, Color tint = WHITE):
        SpriteSheet2D(frameSize.x, frameSize.y, position.x, position.y, file, tint), animationDelay(animationDelay), timer(animationDelay){}
    
    void play();
};