#include <raylib.h>
#include <stdlib.h>

#include "config.h"


Vector2 winDimensions;


void parseArguments(const char** argv) {
    const int width = atoi(argv[1]);
    const int height = atoi(argv[2]);

    if (!width || !height) {
        TraceLog(LOG_FATAL, "Invalid Dimensions!\n");
    }

    winDimensions = (Vector2) {
        .x = width,
        .y = height,
    };
}

int main(const int argc, const char** argv) {
    if (argc != 3) {
        TraceLog(LOG_FATAL, "Not enough arguments! Expected: ./pong <width> <height>\n");
    }

    parseArguments(argv);    
    
    InitWindow(winDimensions.x, winDimensions.y, "C-Pong");

    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
