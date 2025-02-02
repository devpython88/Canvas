#include "graphics.hpp"

/* OBJECT 2D */

bool Canvas::Object2D::collidingWith(Object2D with) const
{
    return CheckCollisionRecs({ x, y, w, h}, { with.x, with.y, with.w, with.h });
}

void Canvas::Object2D::draw()
{
}

void Canvas::Line2D::draw(){
    DrawLine(start.x, start.y, end.x, end.y, color);
}

void Canvas::Line2D::drawPro()
{
    DrawLineEx(start.toRaylibVector(), end.toRaylibVector(), width, color);
}

void Canvas::Object2D::pool()
{
    oldPos.x = x;
    oldPos.y = y;

    x = -125000;
    y = -125000;
}

void Canvas::Object2D::unpool()
{
    x = oldPos.x;
    y = oldPos.y;
}

/* OBJ2D.RECT2D */

void Canvas::Rect2D::draw()
{
    if (visible) DrawRectanglePro(Rectangle{ x, y, w, h }, Vector2{ 0, 0 }, rotation, color);
}

/* OBJ2D.CIRCLE2D */

bool Canvas::Circle2D::collidingWith(Circle2D with) const
{
    return CheckCollisionCircles(Vector2{ x, y }, w, Vector2{ with.x, with.y }, with.w);
}

bool Canvas::Circle2D::collidingWith(Object2D with) const
{
    return CheckCollisionCircleRec(Vector2{ x, y }, w, Rectangle{ with.x, with.y, with.w, with.h });
}

void Canvas::Circle2D::draw()
{
    if (visible) DrawCircle(x, y, w, color);
}

/* OBJ2D.Triangle2D */
bool Canvas::Triangle2D::collidingWith(Triangle2D with) const
{
    return !(
        x + radius > with.x ||
        y + radius > with.y ||
        x < with.x + with.radius ||
        y < with.y + with.radius
    );
}

void Canvas::Triangle2D::draw()
{
    if (visible) DrawPoly(Vector2{x, y}, 3, radius, rotation, color);
}

bool Canvas::Triangle2D::collidingWith(Object2D with) const
{
    return !(
        x + radius > with.x ||
        y + radius > with.y ||
        x < with.x + with.w ||
        y < with.y + with.w
    );
}

/* OBJ2D.Poly2D */
void Canvas::Poly2D::draw()
{
    if (visible) DrawPoly(Vector2{x, y}, sides, radius, rotation, color);
}

bool Canvas::Poly2D::collidingWith(Poly2D with) const
{
    return !(
        x + radius > with.x ||
        y + radius > with.y ||
        x < with.x + with.radius ||
        y < with.y + with.radius
    );
}

bool Canvas::Poly2D::collidingWith(Object2D with) const
{
    return !(
        x + radius > with.x ||
        y + radius > with.y ||
        x < with.x + with.w ||
        y < with.y + with.w
    );
}

    

/* OBJ2D.IMAGE2D*/

bool Canvas::Image2D::isLoaded()
{
    return texture.id != 0;
}

void Canvas::Image2D::draw()
{
    if (visible) DrawTextureEx(texture, Vector2{ x, y }, rotation, scale, tint);
}

void Canvas::Image2D::unload()
{
    if (!isLoaded()){
        UnloadTexture(texture);
    }
}

// spritesheet

void Canvas::SpriteSheet2D::nextColumn()
{
    // Make sure frame isnt the end frame
    if (frameRect.x >= texture.width) return;
    frameRect.x += frameWidth;
}

void Canvas::SpriteSheet2D::nextRow()
{
    // make sure row isnt at the last
    if (frameRect.y >= texture.height) return;
    frameRect.y += frameHeight;
}

void Canvas::SpriteSheet2D::prevColumn()
{
    // make sure the frame aint at the start
    if (frameRect.x <= 0) return;
    frameRect.x -= frameWidth;
}

void Canvas::SpriteSheet2D::prevRow()
{
    // make sure row isnt at the first
    if (frameRect.y <= texture.height) return;
    frameRect.y -= frameHeight;
}

void Canvas::SpriteSheet2D::setColumn(int index)
{
    frameRect.x = frameWidth * index;
}

void Canvas::SpriteSheet2D::setRow(int index)
{
    frameRect.y = frameHeight * index;
}

bool Canvas::SpriteSheet2D::isAtFirstRow()
{
    return frameRect.y <= 0;
}

bool Canvas::SpriteSheet2D::isAtLastRow()
{
    return frameRect.y >= texture.height - frameHeight;
}

bool Canvas::SpriteSheet2D::isAtFirstColumn()
{
    return frameRect.x <= 0;
}

bool Canvas::SpriteSheet2D::isAtLastColumn()
{
    return frameRect.x >= texture.width;
}

void Canvas::SpriteSheet2D::draw()
{
    if (visible) DrawTextureRec(texture, Rectangle{ frameRect.x, frameRect.y, frameRect.w, frameRect.h }, Vector2{ x, y }, tint);
}

// animation

void Canvas::Animation2D::play()
{
    if (timer >= 0.0f){
        timer -= 0.1f;
        return;
    }

    nextColumn();
    timer = animationDelay;
}
