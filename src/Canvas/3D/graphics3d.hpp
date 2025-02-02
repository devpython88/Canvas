#pragma once

#include "../raylib.h"
#include "../Math"
#include <string>

namespace Canvas3D {
    class Object3D;
    class Cube3D;
    class Model3D;

    void drawGrid(int slices, int spacing);
}

class Canvas3D::Object3D {
    public:
    Canvas::Vector3f position, size;

    Object3D(Canvas::Vector3f position, Canvas::Vector3f size): size(size), position(position){}
    
    bool collidingWith(Object3D obj);
    void draw();
};


class Canvas3D::Cube3D : public Canvas3D::Object3D {
    public:
    Color color;

    Cube3D(Canvas::Vector3f position, Canvas::Vector3f size, Color color):
        Object3D(position, size), color(color){}

    void draw();
};



class Canvas3D::Model3D : public Canvas3D::Object3D {
    protected:
    Model model;

    public:
    std::string file;
    Canvas::Vector3f rotation;
    float angle;
    
    Model3D(std::string file, Canvas::Vector3f position, Canvas::Vector3f size, Canvas::Vector3f rotation = Canvas::Vector3f(0.0f, 0.0f, 0.0f), float angle = 0.0f): Object3D(position, size), file(file), rotation(rotation), angle(angle){
        model = LoadModel(file.c_str());
    }


    void draw();
    bool isLoaded();
    void unload();

};