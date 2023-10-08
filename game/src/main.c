#include "node.h"
#include "node_2d.h"
#include "node_circle.h"

#include "raylib.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void game_init(void);
void game_free(void);

void game_tick(void);
void game_draw(void);

void tick_node_circle(struct node_circle * node_circle);
void draw_node_circle(struct node_circle * node_circle);

void node_circle_on_tick_0000(struct node_circle * node_circle);

int circles_count;
int circles_size;
struct node_circle ** circles;

int main(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(512, 512, "inheritance");
    SetTargetFPS(60);
    //ToggleBorderlessWindowed();
    //ToggleFullscreen();

    game_init();

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_R))
        {
            game_free();
            game_init();
        }

        game_tick();
        game_draw();
    }

    game_free();

    CloseWindow();

    return 0;
}

void game_init(void)
{
    circles_count = 0;
    circles_size = 16;
    circles = malloc(sizeof(struct node_circle *) * circles_size);
    assert(circles != NULL);

    for (int i = 0; i < circles_size; ++i)
    {
        float x = (float)GetRandomValue(0, GetScreenWidth());
        float y = (float)GetRandomValue(0, GetScreenHeight());
        float radius = 16.0f + GetRandomValue(0, 48);
        /*unsigned char color_r = 255;
        unsigned char color_g = 255;
        unsigned char color_b = 255;*/
        unsigned char color_r = GetRandomValue(0, 255);
        unsigned char color_g = GetRandomValue(0, 255);
        unsigned char color_b = GetRandomValue(0, 255);
        unsigned char color_a = 127;
        circles[i] = node_circle_create((char *)TextFormat("circle_%i", i), x, y, radius, color_r, color_g, color_b, color_a);
        node_circle_register_callback_on_tick(circles[i], node_circle_on_tick_0000);
        ++circles_count;
    }
}

void game_free(void)
{
    for (int i = 0; i < circles_count; ++i)
    {
        node_circle_free(circles[i]);
    }

    circles_count = 0;
    circles_size = 0;
    free(circles);
    circles = NULL;
}

void game_tick(void)
{
    for (int i = 0; i < circles_count; ++i)
    {
        tick_node_circle(circles[i]);
    }
}

void game_draw(void)
{
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < circles_count; ++i)
    {
        draw_node_circle(circles[i]);
    }

    DrawRectangle(0, 0, 80, 16, BLACK);
    DrawFPS(0, 0);

    EndDrawing();
}

void tick_node_circle(struct node_circle * node_circle)
{
    node_circle_tick(node_circle);
}

void draw_node_circle(struct node_circle * node_circle)
{
    int x = (int)node_circle_get_x(node_circle);
    int y = (int)node_circle_get_y(node_circle);
    float radius = node_circle_get_radius(node_circle);
    unsigned char color_r = node_circle_get_color_r(node_circle);
    unsigned char color_g = node_circle_get_color_g(node_circle);
    unsigned char color_b = node_circle_get_color_b(node_circle);
    unsigned char color_a = node_circle_get_color_a(node_circle);

    Color color = (Color){ color_r, color_g, color_b, color_a };

    DrawCircle(x, y, radius, color);
}

void node_circle_on_tick_0000(struct node_circle * node_circle)
{
    float x = node_circle_get_x(node_circle) + GetRandomValue(-4, 4);
    float y = node_circle_get_y(node_circle) + GetRandomValue(-4, 4);

    float min_x = node_circle_get_radius(node_circle);
    float min_y = node_circle_get_radius(node_circle);
    float max_x = GetScreenWidth() - node_circle_get_radius(node_circle);
    float max_y = GetScreenHeight() - node_circle_get_radius(node_circle);

    x = x < min_x ? min_x : x > max_x ? max_x : x;
    y = y < min_y ? min_y : y > max_y ? max_y : y;

    node_circle_set_x(node_circle, x);
    node_circle_set_y(node_circle, y);
}
