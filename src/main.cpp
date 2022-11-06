#include "raylib.h"
#include "raymath.h"
#include "resources.hpp"
#include "renderer.hpp"
#include "physics.hpp"
#include <iostream>

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

	auto ship_sprite = Renderer::Sprite("kenneySpaceShooter", (Rectangle){1365,1696,198,188}, (Vector2){19.80/2,18.80/2});
	auto rock_sprite = Renderer::Sprite("kenneySpaceShooter", (Rectangle){0,800,440,442}, (Vector2){44.00/2, 44.20/2});

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
        Physics::step(0.001,50000);
		std::cout << std::to_string(Vector2Distance(Physics::ship.position, Physics::rock.position)) << std::endl;
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("Space!", 190, 200, 20, LIGHTGRAY);
		//DrawTexture(Resources::useTexture("ship"), 0, 0, WHITE);
		ship_sprite.draw(Physics::ship.position.x,Physics::ship.position.y, 0.1);
		rock_sprite.draw(Physics::rock.position.x,Physics::rock.position.y, 0.1);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
