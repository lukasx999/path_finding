#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "./path_finding.h"

#include "raylib.h"


#define WIDTH  1920
#define HEIGHT 1080



void render(Vertex *vertices, size_t vertices_size) {


    InitWindow(WIDTH, HEIGHT, "PathFinding");

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            for (size_t i=0; i < vertices_size; ++i) {
                int radius = 50.0f;
                DrawCircle(i*radius*2 + radius, 500, radius, BLUE);
            }




        }
        EndDrawing();
    }

    CloseWindow();

    for (size_t i=0; i < vertices_size; ++i) {
        vertex_destroy(&vertices[i]);
    }
    free(vertices);

}
