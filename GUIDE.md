# Welcome to the Canvas Guide
## this will guide you through all of canvas's game development tools


# Table of contents
[Downloading Canvas](#downloading)

[Basic Game](#basic-game)

[KeyBoard and mouse](#keyboard--mouse)

[Shapes](#shapes)

[Sounds](#sounds)

[Text labels](#text-labels)

[Textures](#textures)

[What comes next?](#whats-coming-next)



# Downloading
Even though you can install the prebuilt library for MSYS64.
I'll still show you through how to build Canvas from source.

1. Install these tools using your package manager

    git
    cmake
    ninja
    libraylib
2. Clone the Canvas repository

    ```bash
    git clone https://github.com/devpython88/Canvas.git
    cd Canvas
    cd build
    ```
3. Build Canvas
    ```bash
    cmake -G Ninja ..
    ninja
    ```
4. Copy the files
    ```bash
    # copy header directory
    cp ../src/Canvas /path/to/gcc/include/dir
    # copy the library
    cp libcanvas.a /path/to/gcc/lib/dir
    ```


# Basic Game
Now that you've built and installed Canvas from source.
Let's get to creating a game.

Rules to create a Canvas game:
1. The game must be compiled in c++17
2. The game must not have a main function (You'll understand this later)
3. Raylib must be linked with the game alongside canvas

Example code:
```cpp
// Canvas uses Qt5 styled header naming
#include <Canvas/Window>


// Main game class
class Game : public Canvas::Window {
    public:
    // Constructor mustn't have any arguments
    // The window takes many arguments but execpt for the title (arg1) others are optional.
    // Im just gonna add all the argsa
    // (title, w, h, camera, fps)

    Game(): Canvas::Window("My WIndow", 1024, 600, Canvas::Camera(), 60){}


    /* There are two functions that must be overriden
    
    1. closing()
        This function is called when the program is closing
        You can use this to unload game assets
    
    2. update()
        This function is called every frame.
        You add the game logic here
    */

   void update();
};

void Game::update(){
    // Clear renderer
    startDraw(RED); // This argument is optional, you can also manually clear the bg using the clear function
    startCam(); // To make the camera work, Useful when you want a infinite area
    // Draw game world things here
    endCam();
    // Draw GUI here, Because here the gui wont be affected by the camera and will always be on top
    endDraw();
}

// Remember "(You will understand this later)"? Well this macro automatically creates the main function
CREATE_GAME(Game)
```

Now to compile, `g++ -o game game.cpp -lraylib -lcanvas`

# Shapes
In Canvas, there are shapes like Rect2D, Circle2D

All shapes and objects (and even ui components) are subclasses of the `Object2D` class.
All of them (except Object2D and UIComponent) have draw functions

Collision can be detected using the & operator or the function.
Syntax A: `obj.collidingWith(obj2)`
Syntax B: `obj & obj2`


Note: The Object2D class and its subclasses all have their properties (such as x and y) public, Meaning you dont need to use setters and getters, This is the same for almost all classes in Canvas because i was too lazy to create stters and getters

These are the constructors
Rect2D(float x, float y, float w, float h, Color color);
Circle2D(float x, float y, float rad, Color color);

### Note: ALL THE THINGS ARE IN DIFFERENT MODULES, Such as UI components in <Canvas/UI>, Audio in <Canvas/Audio>, Graphics (shapes and stuff) in <Canvas/Graphics>, Math in <Canvas/Math> and Input in <Canvas/Input>

# Keyboard & Mouse
Both these Canvas:: classes are in Canvas/Input
Canvas uses raylib key constants such as KEY_A, KEY_LCTRL

Gamepad support will be added in predev 2
### Keyboard
    keyHeld(int key); Is key held
    keyPressed(int key); is kye pressed
    keyRelease(int key); is key released

In the Mouse class, The constants are made by Canvas.
Left click: Canvas::LeftButton
Middle click: Canvas::MiddleButton
Right click: Canvas::RightButton

### Mouse
    x(); get x (float)
    y(); get y (float)
    buttonHeld(int button); button held
    buttonPressed(int button); button pressed
    buttonReleased(int button); button release
    scrollAmount(bool windowAlike = true):
        with windowAlike set to true: Windows scrolling (scroll up = up, scroll down = down)
        without windowAlike set to true: macOS scrolling (scroll up = down, scroll down = up)
    
    scrollAmountV(): Returns a vector containing the scroll amount 

    isHidden(); Is the cursor hidden

    hide(); Hide the cursor
    show(); Show the cursor

# Textures
sprites in predev 2

In canvas you can use the Image2D class (also a subclass of Object2D) to create sprites

Image2D(float x, float y, std::string filePath, Color tint = WHITE);
the x, y, filePath, and tint are availaible publicly
the tint is set to white and default, white tint means no tint

You can use the isLoaded func from this class to check if the image is loaded or not
Make sure to override the `closing` function and use this class's `unload` function to free the image

# Sounds
Sounds are located in Canvas/Audio

There are two classes for Sounds
Canvas::SoundEffect for short sounds, Onlu accepts .wav files

Canvas::LoopingSound for long musics, Only accepts .ogg and .mp3

both have there file path publicly availaible

SoundEffect cannot be looped
LoopingSound can be looped

SoundEffect(std::string path)
LoopingSound(std::string path)

Both have these functions:
    isPlaying(): Self explanatory
    unload(): Frees the sound/music
    play(): Self explanatory

LoopingSound has the `update` function to loop it.

How to play a loopingsound as a music.
calls its play function in the Game class constructor.
Then in the update function call its update function.
congrats the music will now loop till the end of time

# Text labels
These are in the Canvas/UI module

All UI components (such as this one) are subclasses of Canvas::UiCOmponent which is a subclass of Object2D

Make sure draw the UI components in between endCam and endDraw

The text label (TextLabel) class has its text, fontsize, and color publicly availaible
You can get its width using itsd 'w' field
TextLabel(float x, float y, int fontSize, std::string text, Color color = BLACK)

All UI COmponents can also be drawn with there `draw` functions

There are also RichLabel, Which can have spacing and fonts

RichLabel(float x, float y, int fontSize, std::string text, std::string fontFile, int spacing = 1, Color color = BLACK)

these are subclasses of TextLabels meaning they hve all funcs from them

# Buttons
Located in Canvas/UI

Buttons are just rectangles that calculate the positiions are stuff and make a button


Button(float x, float y, TextLabel label, ButtonEvent event)
Example:
Button(20, 30, TextLabel(0, 0, 16, "Hello!", BLACK), [this](){ functionToCallOnButtonClick(); })

The class arranges the label automatically so you can just put 0,0 in the label, You can also use RichLabel instead.
The clicking, hovering are automatically handled

# DIalogs
Located in Canvas/Dialog

A dialog is also just a rectangle that arranges the title and close button.
The close button is automatically handled.

Dialog(float x, float y, std::string titleBarText, float width, float height, Color color)
You can use the Dialog.visible field to control whether the dialog should be visible or no.

Now dialogs have a function called calculateRelativePosition.
calculateRelativePosition(Object2D obj, int xIndex, int yIndex);
You can set xIndex and yIndex (starting from 0) to arrange the object youre trying to put in the dialog.
This returns a Vector2 containing the calculated position for the object.

# Spritsheets
These are located in Canvas/Graphics

In canvas spritesheets are used to store animations in a png file.
There are two type of spritesheets in canvas,

1. SpriteSheet2D: This spritesheet needs to be manually animated using its functions
2. Animation2D: This spritesheet is automatically animated with its play function.

Spritesheet2d is a subclass of Image2D, meaning it has all functions from Image2D
Animation2D is a subclass of Spritesheet2D, meaning it has all functions from Image2D and Spritesheet2D

How to use,
To create a spritesheet, You use its constructor
SpriteSheet2D(nt frameWidth, int frameHeight,
        float x, float y, std::string file_path,
        Color tint = WHITE)

SpriteSheet2D uses the frameWIdth and frameHeight to calculate frames.
Both spritesheet2d and animation2d have these functions:
nextColumn, nextRow, prevColumn, prevRow, setRow(index), setColumn(index)

These functions are used to manage the spritesheet, they automaticlly check if the frame is the end frame/row and only manage if it isnt.
Meaning if you call nextColumn but the column is already at the end, it wont continue
the set functions use a index (starting from 0) to set the column/row.

How to create a animation2d:
Animation2D(float animationDelay, Vector2f frameSize, Vector2f position, std::string file, Color tint = WHITE)

Just to make the constructor shorter, I used Canvas/Math Vector2f instead of seperate xy wh

The animation2d class has a default animationDelay (customizable)
And a timer to control the delay
Every time you call its `play` function, It checks if the timer isnt 0
If yes, decrement the timer and exit the function
If no, move to next frame (only if the current frame isnt the lastt frame) and set the timer to the default delay

Because of this you can make a single png file for all your animations for a single entity and seperae the animations for the entity in rows.

Thats the whole spriehseet thing done

# Keybindings and Mousebindings
Located in Canvas/Input

In canvas, You have two classes you can use to have key and mouse bindings, Particularly useful in games where you need customizable keybindings.


KeyBinding(int key, int modifier):
    The modifier is optional. You can set it to something like KEY_LEFT_ALT, then when you press the modifier with the key specfiied, the keybinding will trigger

    held(): the keybinding is held
    pressed(): the keybinding is being pressed

MouseBinding(int button):
    held(): The button is held
    pressed(): The button is pressed


# Lighting
Located in Canvas/Misc

Though the built in lighting is questionable its still something.
i tried raycasted lighting but it didnt work.

Lighting(float x, float y, float radius, unsigned char intensity, Color color)

You can draw this lighting using .draw()


# Gravity
Located in Canvas/Misc

Gravity class is designed to be simple gravity, it has a built in jump mechanism

It handles jumps automatically

Gravity(Object2D* object, float acceleration, float jumpPower, int jumpKey = KEY_SPACE)
object is the object you'll be applying the gravity to.
acceleration is the acceleration of the fall, low = slow fall, high = quick fall
jumpPower is self-explanatory
jumpKey is the key to jump

You can update the gravity using .update()


# What's Coming Next
Well in alpha 2, these will come:
1. levels
2. idk