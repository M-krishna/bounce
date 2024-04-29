#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Color pickRandomColor() {
    Color colorsArray[5] = {WHITE, GREEN, RED, BLUE, YELLOW};

    srand(time(NULL));
    int randomIndex = rand() % 5;
    return colorsArray[randomIndex];
}

int main(void) {
    InitWindow(1280, 720, "Bounce");
    SetTargetFPS(60);

    int rect_x = 0;
    int rect_y = 0;

    int velocity_x = 2;
    int velocity_y = 2;

    Color squareColor;

    while(!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(BLACK);

            if (rect_x < 0 || rect_x > 1280 - 100) {
                velocity_x *= -1;
                squareColor = pickRandomColor();
            }
            if (rect_y < 0 || rect_y > 720 - 100) {
                velocity_y *= -1;
                squareColor = pickRandomColor();
            }
            
            rect_x += velocity_x;
            rect_y += velocity_y;

            DrawRectangle(rect_x, rect_y, 100, 100, squareColor);
        EndDrawing();

    }
    return 0;
}