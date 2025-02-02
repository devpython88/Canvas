#include "Canvas/Window"
#include "Canvas/Graphics"
#include "Canvas/Input"
#include "Canvas/Misc"
#include "Canvas/UI"
#include "Canvas/3D/Graphics3D"

using namespace Canvas;
using namespace Canvas3D;


class Game : public Window3D {
    public:
    Model3D model;

    Game(): Window3D("Game", 1024, 600, PerspectiveCamera(
        Vector3f(0.0f, 0.0f, 0.0f),
        Vector3f(0.0f, 30.0f, 30.0f),
        Vector3f(0.0f, 1.0f, 0.0f),
        25
    )), model("dck.obj", Vector3f(0.0f, 0.0f, 0.0f), Vector3f(5.0f, 5.0f, 5.0f)){}


    void update(){
        if (Keyboard::keyHeld(KEY_A)){
            camera3d.moveCameraEx(-1.0f, 0.0f);
        }

        if (Keyboard::keyHeld(KEY_D)){
            camera3d.moveCameraEx(1.0f, 0.0f);
        }

        if (Keyboard::keyHeld(KEY_W)){
            camera3d.moveCameraEx(0.0f, -1.0f);
        }

        if (Keyboard::keyHeld(KEY_S)){
            camera3d.moveCameraEx(0.0f, 1.0f);
        }
        
        

        startDraw();
        startCam();
        drawGrid(10, 0);
        model.draw();
        endCam();
        endDraw();
    }

    void closing(){
        model.unload();
    }
};


CREATE_GAME(Game)