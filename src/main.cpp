#include "Canvas/Window"
#include "Canvas/Input"
#include "Canvas/Graphics"
#include "Canvas/UI"
#include "Canvas/Audio"
#include "Canvas/Dialog"
#include "Canvas/Misc"

class Game : public Canvas::Window {
    public:

    Canvas::Rect2D rect1;
    Canvas::Circle2D circle1;
    Canvas::Animation2D image1;
    Canvas::RichLabel textLabel1;
    Canvas::KeyBinding keyBinding1;
    Canvas::Button button1;
    Canvas::Dialog dialog;
    Canvas::Lighting light;
    Canvas::Gravity gravity;

    void btnClicked();
    void update();
    void closing();

    Game(): Window("My Game"), rect1(10, 20, 50, 50, RED), circle1(10, 140, 25, BLUE),
        image1(3.0f, Canvas::Vector2f(32 , 32), Canvas::Vector2f(300, 300), "abc.png"),
        textLabel1(0, 0, 16, "HEllo!", "Consola.ttf", 2), keyBinding1(KEY_A, KEY_LEFT_CONTROL),
        button1(200, 10, Canvas::TextLabel(0, 0, 16, "Hello!", WHITE), [this](){ btnClicked(); }),
        dialog(20, 20, "Hllo!", 300, 200, GRAY), light(20, 20, 50, 80, RED), gravity(&rect1, 0.1f, 3.0f){
            dialog.visible = true;
            rect1.x = dialog.calculateRelativePosition(rect1).x;
            rect1.y = dialog.calculateRelativePosition(rect1).y;
    
    }
};

void Game::btnClicked()
{
    dialog.visible = true;
    textLabel1.text = "CLICKED";
}

void Game::update()
{
    image1.play();

    if (keyBinding1.pressed()){
        rect1.y += 10;
        // image1.nextRow();
        dialog.x += 10;
        dialog.y += 10;
    }

    if (circle1 & rect1){
        return;
    }

    if (Canvas::Mouse::isClicking(circle1)){
        circle1.color = GREEN;
    }

    if (image1.isAtLastColumn()){ image1.setColumn(0); }

    gravity.update();

    startDraw();
    startCam();
    light.draw();
    circle1.draw();
    image1.draw();
    textLabel1.draw();
    button1.draw();
    endCam();
    dialog.draw();
    rect1.draw();
    endDraw();
}

void Game::closing()
{
    image1.unload();
}

CREATE_GAME(Game);