<img src="/CanvasLogo.png" />

# Canvas
Canvas is a lightweight, DLL-free game development library licensed under the libpng license

The tutorial guide is available [here](/GUIDE.md)


Here is a example obstacle dodging game.
Code: 
```cpp
#include <Canvas/Window>
#include <Canvas/Graphics>
#include <Canvas/Misc>
#include <Canvas/Input>
#include <Canvas/UI>
#include <Canvas/Dialog>

using namespace Canvas;

class Game : public Window {
    public:
    Rect2D player;
    Rect2D obstacle;
    Gravity playerGravity;
    Dialog loseDialog;
    TextLabel loseDialogText;
    TextLabel scoreCounter;
    int score;

    Game(): Window("Canvy Bird"), player(20, 30, 50, 50, RED), obstacle(800, 0, 50, 300, GREEN),
        playerGravity(&player, 0.1f, 5.0f), loseDialog(0, 0, "Lose screen", 800, 600, BLACK),
        loseDialogText(20, 40, 22, "You lose bozo", WHITE), score(0), scoreCounter(0, 0, 140, "", (Color) { 255, 140, 182, 255 }) {
        loseDialog.visible = false;
    }

    void update();
};

void Game::update()
{
    scoreCounter.text = std::to_string(score);
    scoreCounter.x = (width / 2) - (MeasureText(scoreCounter.text.c_str(), 140) / 2);
    scoreCounter.y = (height / 2) - 70;
    if (!loseDialog.visible) obstacle.x -= 5.0f;

    if (obstacle.x < -50){
        obstacle.x = 800;
        obstacle.y = GetRandomValue(0, 300);
        score++;
    }

    if (player & obstacle){
        if (!loseDialog.visible) { 
            loseDialog.visible = true;
            obstacle.x = -50;
        }
    }

    if (!loseDialog.visible) playerGravity.update();

    startDraw((Color) { 255, 179, 207, 255 });
    startCam();
    scoreCounter.draw();
    player.draw();
    obstacle.draw();
    endCam();
    loseDialog.draw();
    if (loseDialog.visible) loseDialogText.draw();
    endDraw();
}


CREATE_GAME(Game);
```

The build command is: `g++ -o main main.cpp -Ix -Ly -lcanvas -lraylib` The x is the path to the canvas include dir, the y is the path to the canvas lib dir

Some photos of this example:
<img src="/.exph1" width="256"/>
<img src="/.exph2" width="256"/>
