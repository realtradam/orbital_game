#include "raylib.h"
#include "resources.hpp"
#include "renderer.hpp"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
	
	auto ship = Renderer::Sprite("kenneySpaceShooter", (Rectangle){1365,1696,198,188}, (Vector2){19.80/2,18.80/2});
	auto rock = Renderer::Sprite("kenneySpaceShooter", (Rectangle){0,800,440,442}, (Vector2){44.00/2, 44.20/2});

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("Space!", 190, 200, 20, LIGHTGRAY);
            //DrawTexture(Resources::useTexture("ship"), 0, 0, WHITE);
			ship.draw(100,100, 0.1);
			rock.draw(750,750, 0.1);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
