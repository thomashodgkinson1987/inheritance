#include "node.h"
#include "node_2d.h"
#include "node_circle.h"
#include "node_sprite.h"

#include "raylib.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void game_init(void);
void game_free(void);

void game_tick(void);
void game_draw(void);

void tick_node_sprite(struct node_sprite * node_sprite);
void draw_node_sprite(struct node_sprite * node_sprite);

void node_sprite_on_tick_0000(struct node_sprite * node_sprite);

int sprites_count;
int sprites_size;
struct node_sprite * sprites;

Texture2D texture;

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
    sprites_count = 0;
    sprites_size = 8;
    sprites = malloc(sizeof(struct node_sprite) * sprites_size);
    assert(sprites != NULL);

    texture = LoadTexture("resources/texture.png");

    for (int i = 0; i < sprites_size; ++i)
    {
        float x = (float)GetRandomValue(0, GetScreenWidth());
        float y = (float)GetRandomValue(0, GetScreenHeight());

        sprites[i] = node_sprite_create((char *)TextFormat("sprite_%i", i), x, y, texture);

        Color tint = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 127 };
        node_sprite_set_tint(&sprites[i], tint);

        Vector2 origin = (Vector2){ (float)texture.width / 2, (float)texture.height / 2 };
        node_sprite_set_origin(&sprites[i], origin);

        node_sprite_register_callback_on_tick(&sprites[i], node_sprite_on_tick_0000);

        ++sprites_count;
    }
}

void game_free(void)
{
    for (int i = 0; i < sprites_count; ++i)
    {
        node_sprite_free(&sprites[i]);
    }

    sprites_count = 0;
    sprites_size = 0;
    free(sprites);
    sprites = NULL;

    UnloadTexture(texture);
}

void game_tick(void)
{
    for (int i = 0; i < sprites_count; ++i)
    {
        tick_node_sprite(&sprites[i]);
    }
}

void game_draw(void)
{
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < sprites_count; ++i)
    {
        draw_node_sprite(&sprites[i]);
    }

    DrawRectangle(0, 0, 74, 20, BLACK);
    DrawFPS(0, 0);

    EndDrawing();
}

void tick_node_sprite(struct node_sprite * node_sprite)
{
    node_sprite_tick(node_sprite);
}

void draw_node_sprite(struct node_sprite * node_sprite)
{
    Texture texture = node_sprite_get_texture(node_sprite);
    Rectangle source = node_sprite_get_source(node_sprite);
    Rectangle dest = node_sprite_get_dest(node_sprite);
    Vector2 origin = node_sprite_get_origin(node_sprite);
    float rotation = node_sprite_get_rotation(node_sprite);
    Color tint = node_sprite_get_tint(node_sprite);

    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void node_sprite_on_tick_0000(struct node_sprite * node_sprite)
{
    float x = node_sprite_get_x(node_sprite) + GetRandomValue(-4, 4);
    float y = node_sprite_get_y(node_sprite) + GetRandomValue(-4, 4);
    float rotation = node_sprite_get_rotation(node_sprite) + 1.0f;

    float min_x = 0.0f;
    float min_y = 0.0f;
    float max_x = GetScreenWidth() - node_sprite_get_dest(node_sprite).width;
    float max_y = GetScreenHeight() - node_sprite_get_dest(node_sprite).height;

    x = x < min_x ? min_x : x > max_x ? max_x : x;
    y = y < min_y ? min_y : y > max_y ? max_y : y;

    if (rotation > 360.0f) rotation -= 360.0f;

    node_sprite_set_x(node_sprite, x);
    node_sprite_set_y(node_sprite, y);
    node_sprite_set_rotation(node_sprite, rotation);
}
