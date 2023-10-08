#include "node.h"
#include "node_2d.h"
#include "node_circle.h"

#include "raylib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void node_on_tick_0000(struct node * node);
void node_2d_on_tick_0000(struct node_2d * node_2d);
void node_circle_on_tick_0000(struct node_circle * node_circle);

int main(void)
{
    struct node_circle * node_circle = node_circle_create("circle", 256, 256, 8, 0, 255, 0, 255);

    node_register_callback_on_tick(node_circle->base->base, node_on_tick_0000);
    node_2d_register_callback_on_tick(node_circle->base, node_2d_on_tick_0000);
    node_circle_register_callback_on_tick(node_circle, node_circle_on_tick_0000);

    node_circle_tick(node_circle);

    node_circle_free(node_circle);

    exit(EXIT_SUCCESS);

    InitWindow(512, 512, "inheritance");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void node_on_tick_0000(struct node * node)
{
    printf("node_on_tick_0000 called by %s\n", node_get_name(node));
}

void node_2d_on_tick_0000(struct node_2d * node_2d)
{
    printf("node_2d_on_tick_0000 called by %s\n", node_2d_get_name(node_2d));
}

void node_circle_on_tick_0000(struct node_circle * node_circle)
{
    printf("node_circle_on_tick_0000 called by %s\n", node_circle_get_name(node_circle));
}
