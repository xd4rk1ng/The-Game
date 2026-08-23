#include <raylib.h>
#include <Atlas.hpp>
#include "src/entities/Starship.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "The Game");
    auto *atlas = Atlas::instance();
    auto *player = new Starship();
    auto *player = new Starship();
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    float deltaT;
    float deltaT;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        deltaT = GetFrameTime();
        player->update(deltaT);
        deltaT = GetFrameTime();
        player->update(deltaT);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        player->draw(); // TODO: testing purposes
        // DrawTexturePro(atlas->getTexture(), atlas->getSourceRectangle(Atlas::SourceType::SPACESHIP), (Rectangle){0, 0, 200, 200}, (Vector2){8, 8}, 0, WHITE);
        // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}