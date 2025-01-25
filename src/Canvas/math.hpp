#pragma once


namespace Canvas {
    class Vector2f;
    class Vector3f;
};


class Canvas::Vector2f {
    public:
    float x, y;

    Vector2f(float x, float y): x(x), y(y){}
};


class Canvas::Vector3f {
    public:
    float x, y, z;

    Vector3f(float x, float y, float z): x(x), y(y), z(z){}
};

