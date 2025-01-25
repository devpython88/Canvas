#include "graphics.hpp"

bool Canvas::Object2D::collidingWith(Object2D with) const
{
    return CheckCollisionRecs({ x, y, w, h}, { with.x, with.y, with.w, with.h });
}

void Canvas::Rect2D::draw()
{
    DrawRectangle(x, y, w, h, color);
}

bool Canvas::Circle2D::collidingWith(Circle2D with) const
{
    return CheckCollisionCircles({ x, y }, w, { with.x, with.y }, with.w);
}

bool Canvas::Circle2D::collidingWith(Object2D with) const
{
    return CheckCollisionCircleRec({ x, y }, w, { with.x, with.y, with.w, with.h });
}

void Canvas::Circle2D::draw()
{
    DrawCircle(x, y, w, color);
}

bool Canvas::Image2D::isLoaded()
{
    return texture.id != 0;
}

void Canvas::Image2D::draw()
{
    DrawTexture(texture, x, y, tint);
}

void Canvas::Image2D::unload()
{
    if (!isLoaded()){
        UnloadTexture(texture);
    }
}
