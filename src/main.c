#include "utils/settings.h"
#include "state-manager.h"
#include <stdio.h>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main(void) {
    if (init_settings()) {
        fprintf(stderr, "Unable to handle \"settings.h\"\n");
        return 1;
    }

    InitWindow(settings.screen_resolution.x, settings.screen_resolution.y, "C-Pong");
    SetTargetFPS(settings.fps);
    if (settings.fullscreen && !IsWindowFullscreen())
        ToggleFullscreen();
        
    init_state_manager();
    
    while (!WindowShouldClose() && state_manager.is_running) {
        BeginDrawing();

        ClearBackground(BLACK);

        state_manager.draw();
        state_manager.update();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
