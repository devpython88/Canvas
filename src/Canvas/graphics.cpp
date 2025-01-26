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
    DrawTextureRec(texture, (Rectangle) { frameRect.x, frameRect.y, frameRect.w, frameRect.h }, (Vector2) { x, y }, tint);
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
