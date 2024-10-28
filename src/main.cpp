#include "grid.h"

int main()
{

    // Sets up window
    InitWindow(WIDTH, HEIGHT, "Sand Game");
    
    // FPS
    SetTargetFPS(60);

    Grid sandGrid(WIDTH, HEIGHT);

    // Main Game Loop
    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(Color{20, 160, 133, 255});
            sandGrid.nextIteration();
            sandGrid.handleMouseInput();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}