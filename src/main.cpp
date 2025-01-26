#include "Canvas/Window"
#include "Canvas/Input"
#include "Canvas/Graphics"
#include "Canvas/UI"
#include "Canvas/Audio"

class Game : public Canvas::Window {
    public:

    Canvas::Rect2D rect1;
    Canvas::Circle2D circle1;
    Canvas::Animation2D image1;
    Canvas::TextLabel textLabel1;

    Game(): Window("My Game"), rect1(10, 20, 50, 50, RED), circle1(10, 140, 25, BLUE),
        image1(3.0f, Canvas::Vector2f(32 , 32), Canvas::Vector2f(300, 300), "abc.png"),
        textLabel1(0, 0, 16, "HEllo!"){
    }

    void update();
    void closing();
};


void Game::update()
{
    image1.play();

    if (Canvas::Mouse::buttonPressed(Canvas::Mouse::LeftButton)){
        rect1.y += 10;
        image1.nextRow();
    }

    if (circle1 & rect1){
        return;
    }

    if (image1.isAtLastColumn()){ image1.setColumn(0); }
    startDraw();
    startCam();
    rect1.draw();
    circle1.draw();
    image1.draw();
    textLabel1.draw();
    endCam();
    endDraw();
}

void Game::closing()
{
    image1.unload();
}

CREATE_GAME(Game);