#include "node.h"
#include "node_2d.h"
#include "node_circle.h"

#include "raylib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nodes_count = 0;
    int nodes_size = 8;
    struct node ** nodes = malloc(sizeof(struct node *) * nodes_size);
    assert(nodes != NULL);

    for (int i = 0; i < nodes_size; ++i)
    {
        nodes[i] = node_create(TextFormat("node_%i", i));
        ++nodes_count;
    }

    for (int i = 0; i < nodes_count; ++i)
    {
        struct node * node = nodes[i];
        printf("%s\n", node_get_name(node));
    }

    /*for (int i = 0; i < nodes_count; ++i)
    {
        struct node * node = nodes[i];
        node_tick(node);
    }*/

    for (int i = 0; i < nodes_count; ++i)
    {
        struct node * node = nodes[i];
        node_free(node);
    }

    nodes_count = 0;
    nodes_size = 0;
    free(nodes);
    nodes = NULL;

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
