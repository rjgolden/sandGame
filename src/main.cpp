#include "grid.h"

int main()
{

    // Sets up window
    InitWindow(WIDTH, HEIGHT, "Sand Game");
    
    // FPS
    SetTargetFPS(60);

    // initializes the object that runs the game
    Grid sandGame(WIDTH, HEIGHT);

    // Main Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

            // draws background and calls updateGrid function
            ClearBackground(Color{20, 160, 133, 255});
            sandGame.updateGrid();

        EndDrawing();
    }

    // closes window and ends program
    CloseWindow();
    return 0;
}