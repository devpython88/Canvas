#include "Canvas/Window"
#include "Canvas/Input"
#include "Canvas/Graphics"
#include "Canvas/UI"
#include "Canvas/Audio"

class Game : public Canvas::Window {
    public:

    Canvas::Rect2D rect1;
    Canvas::Circle2D circle1;
    Canvas::Image2D image1;
    Canvas::TextLabel textLabel1;
    Canvas::LoopingSound sfx;

    Game(): Window("My Game"), rect1(10, 20, 50, 50, RED), circle1(10, 140, 25, BLUE), image1(300, 300, "car.png"),
        textLabel1(0, 0, 16, "HEllo!"), sfx("pickupCoin.ogg"){
        sfx.play();
    }

    void update();
};


void Game::update()
{
    if (Canvas::Mouse::buttonPressed(Canvas::Mouse::MiddleButton)){
        rect1.y += 10;
    }

    if (circle1 & rect1){
        return;
    }

    sfx.update();

    startDraw();
    startCam();
    rect1.draw();
    circle1.draw();
    image1.draw();
    textLabel1.draw();
    endCam();
    endDraw();
}

CREATE_GAME(Game);