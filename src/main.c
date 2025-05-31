#include <raylib.h>

#define WIN_WIDTH 200
#define WIN_HEIGHT 200


int main(const int argc, const char** argv) {
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Hello, World!");

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        const char* text = "Hello, World!";
        const int size = MeasureText(text, 16);
        
        DrawText("Hello, World", WIN_WIDTH / 2 - size / 2, WIN_HEIGHT / 2 - 8, 16, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
