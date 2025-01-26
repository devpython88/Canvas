#pragma once
#include "raylib.h"
#include <string>
#include "Math"

namespace Canvas {
    class Object2D;
    class Rect2D;
    class Circle2D;

    class Image2D;
    class SpriteSheet2D;
    class Animation2D;
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
    protected:

    public:
    Color tint;
    Texture2D texture;

    Image2D(float x, float y, std::string file_path, Color tint = WHITE): Object2D(x, y, 0, 0), texture(LoadTexture(file_path.c_str())), tint(tint){
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