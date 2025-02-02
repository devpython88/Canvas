#include "graphics3d.hpp"

bool Canvas3D::Object3D::collidingWith(Object3D obj)
{
    return !(
            position.x + size.x > obj.position.x ||
            position.x < obj.position.x + obj.size.x ||
            position.y + size.y > obj.position.y ||
            position.y < obj.position.y + obj.size.y ||
            position.z + size.z > obj.position.z ||
            position.z < obj.position.z + obj.size.z
            );
}

void Canvas3D::Object3D::draw()
{
}

/*
3D:
x + width
y + height
z + depth
*/

void Canvas3D::Cube3D::draw()
{
    DrawCube(position.toRaylibVector(), size.x, size.y, size.z, color);
}

void Canvas3D::Model3D::draw()
{
    DrawModelEx(model, position.toRaylibVector(), rotation.toRaylibVector(), angle, size.toRaylibVector(), WHITE);
}

bool Canvas3D::Model3D::isLoaded()
{
    return model.meshCount > 0 || model.materialCount > 0;
}

void Canvas3D::Model3D::unload()
{
    if (isLoaded()) UnloadModel(model);
}

void Canvas3D::drawGrid(int slices, int spacing)
{
    DrawGrid(slices, spacing);
}
