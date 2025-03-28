#include "../include/settings.h"
#include <stdio.h>
#include <raylib.h>


int main(void) {
    if (init_settings()) {
        fprintf(stderr, "Unable to handle \"settings.h\"\n");
        return 1;
    }

    InitWindow(settings.screen_resolution.x, settings.screen_resolution.y, "C-Pong");
    SetTargetFPS(settings.fps);
    if (settings.fullscreen && !IsWindowFullscreen())
        ToggleFullscreen();


    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
