#include "Canvas/Window"
#include "Canvas/Graphics"
#include "Canvas/Input"
#include "Canvas/Misc"
#include "Canvas/UI"
#include "Canvas/3D/Graphics3D"

using namespace Canvas;


class Game : public Window {
    public:

    Poly2D triangle;
    Menu menu;

    Game(): Window("Unit Test 2"), triangle(300, 300, 7, 20, 0, RED), menu(TextLabel(100, 100, 18, "Menu"), 20, 20, RED, 2.0f){
        Button btn1(50, 20, TextLabel(0, 0, 18, "Hello", WHITE), [this](){});

        btn1.rect.x = (width / 2) - (btn1.rect.w / 2);
        btn1.rect.y = (height / 2) - (btn1.rect.h / 2);
        

        menu.options.push_back(btn1);
        menu.options.push_back(Button(50, 20, TextLabel(0, 0, 18, "Hello", WHITE), [this](){}));
        menu.arrangeItems();
        
    }
    void update(){
        startDraw();
        startCam();

        triangle.draw();
        menu.draw();
        
        endCam();
        endDraw();
    }
};

CREATE_GAME(Game);