#include "node_sprite.h"

struct node_sprite node_sprite_create(char * name, float x, float y, Texture2D texture)
{
    struct node_sprite node_sprite = (struct node_sprite){ 0 };

    //

    node_sprite.base = node_2d_create(name, x, y);

    //

    node_sprite.type = NODE_TYPES_SPRITE;

    //

    node_sprite.texture = texture;
    node_sprite.source = (Rectangle){ 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    node_sprite.dest = (Rectangle){ x, y, (float)texture.width, (float)texture.height };
    node_sprite.origin = (Vector2){ 0.0f, 0.0f };
    node_sprite.rotation = 0.0f;
    node_sprite.tint = WHITE;

    //

    node_sprite.on_tick = NULL;

    node_sprite.fp_tick = node_sprite_tick;

    //

    node_sprite.fp_create = node_sprite_create;
    node_sprite.fp_free = node_sprite_free;

    //

    node_sprite.fp_get_type = node_sprite_get_type;
    node_sprite.fp_get_name = node_sprite_get_name;

    node_sprite.fp_set_name = node_sprite_set_name;

    //

    node_sprite.fp_get_x = node_sprite_get_x;
    node_sprite.fp_get_y = node_sprite_get_y;

    node_sprite.fp_set_x = node_sprite_set_x;
    node_sprite.fp_set_y = node_sprite_set_y;

    //

    node_sprite.fp_get_texture = node_sprite_get_texture;
    node_sprite.fp_get_source = node_sprite_get_source;
    node_sprite.fp_get_dest = node_sprite_get_dest;
    node_sprite.fp_get_origin = node_sprite_get_origin;
    node_sprite.fp_get_rotation = node_sprite_get_rotation;
    node_sprite.fp_get_tint = node_sprite_get_tint;

    node_sprite.fp_set_texture = node_sprite_set_texture;
    node_sprite.fp_set_source = node_sprite_set_source;
    node_sprite.fp_set_dest = node_sprite_set_dest;
    node_sprite.fp_set_origin = node_sprite_set_origin;
    node_sprite.fp_set_rotation = node_sprite_set_rotation;
    node_sprite.fp_set_tint = node_sprite_set_tint;

    //

    return node_sprite;
}

void node_sprite_free(struct node_sprite * node_sprite)
{
    node_sprite->base.fp_free(&node_sprite->base);

    //

    node_sprite->type = 0;

    //

    node_sprite->texture = (Texture2D){ 0 };
    node_sprite->source = (Rectangle){ 0.0f, 0.0f, 0.0f, 0.0f };
    node_sprite->dest = (Rectangle){ 0.0f, 0.0f, 0.0f, 0.0f };
    node_sprite->origin = (Vector2){ 0.0f, 0.0f };
    node_sprite->rotation = 0.0f;
    node_sprite->tint = BLANK;

    //

    node_sprite->fp_create = NULL;
    node_sprite->fp_free = NULL;

    //

    node_sprite->fp_get_type = NULL;
    node_sprite->fp_get_name = NULL;

    node_sprite->fp_set_name = NULL;

    //

    node_sprite->fp_get_x = NULL;
    node_sprite->fp_get_y = NULL;

    node_sprite->fp_set_x = NULL;
    node_sprite->fp_set_y = NULL;

    //

    node_sprite->fp_get_texture = NULL;
    node_sprite->fp_get_source = NULL;
    node_sprite->fp_get_dest = NULL;
    node_sprite->fp_get_origin = NULL;
    node_sprite->fp_get_rotation = NULL;
    node_sprite->fp_get_tint = NULL;

    node_sprite->fp_set_texture = NULL;
    node_sprite->fp_set_source = NULL;
    node_sprite->fp_set_dest = NULL;
    node_sprite->fp_set_origin = NULL;
    node_sprite->fp_set_rotation = NULL;
    node_sprite->fp_set_tint = NULL;
}

//

void node_sprite_register_callback_on_tick(struct node_sprite * node_sprite, void(*on_tick)(struct node_sprite * node_sprite))
{
    node_sprite->on_tick = on_tick;
}

void node_sprite_tick(struct node_sprite * node_sprite)
{
    node_sprite->base.fp_tick(&node_sprite->base);

    if (node_sprite->on_tick != NULL)
    {
        node_sprite->on_tick(node_sprite);
    }
}

//

enum node_type node_sprite_get_type(struct node_sprite * node_sprite)
{
    return node_sprite->type;
}

char * node_sprite_get_name(struct node_sprite * node_sprite)
{
    return node_sprite->base.fp_get_name(&node_sprite->base);
}



void node_sprite_set_name(struct node_sprite * node_sprite, char * name)
{
    node_sprite->base.fp_set_name(&node_sprite->base, name);
}

//

float node_sprite_get_x(struct node_sprite * node_sprite)
{
    return node_sprite->base.fp_get_x(&node_sprite->base);
}

float node_sprite_get_y(struct node_sprite * node_sprite)
{
    return node_sprite->base.fp_get_y(&node_sprite->base);
}



void node_sprite_set_x(struct node_sprite * node_sprite, float x)
{
    node_sprite->base.fp_set_x(&node_sprite->base, x);
    node_sprite->dest.x = x;
}

void node_sprite_set_y(struct node_sprite * node_sprite, float y)
{
    node_sprite->base.fp_set_y(&node_sprite->base, y);
    node_sprite->dest.y = y;
}

//

Texture2D node_sprite_get_texture(struct node_sprite * node_sprite)
{
    return node_sprite->texture;
}

Rectangle node_sprite_get_source(struct node_sprite * node_sprite)
{
    return node_sprite->source;
}

Rectangle node_sprite_get_dest(struct node_sprite * node_sprite)
{
    return node_sprite->dest;
}

Vector2 node_sprite_get_origin(struct node_sprite * node_sprite)
{
    return node_sprite->origin;
}

float node_sprite_get_rotation(struct node_sprite * node_sprite)
{
    return node_sprite->rotation;
}

Color node_sprite_get_tint(struct node_sprite * node_sprite)
{
    return node_sprite->tint;
}



void node_sprite_set_texture(struct node_sprite * node_sprite, Texture2D texture)
{
    node_sprite->texture = texture;
    node_sprite->source = (Rectangle){ 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    node_sprite->dest = (Rectangle){ node_sprite->dest.x, node_sprite->dest.y, (float)texture.width, (float)texture.height };
}

void node_sprite_set_source(struct node_sprite * node_sprite, Rectangle source)
{
    node_sprite->source = source;
}

void node_sprite_set_dest(struct node_sprite * node_sprite, Rectangle dest)
{
    node_sprite->dest = dest;
    node_sprite->base.fp_set_x(&node_sprite->base, dest.x);
    node_sprite->base.fp_set_y(&node_sprite->base, dest.y);
}

void node_sprite_set_origin(struct node_sprite * node_sprite, Vector2 origin)
{
    node_sprite->origin = origin;
}

void node_sprite_set_rotation(struct node_sprite * node_sprite, float rotation)
{
    node_sprite->rotation = rotation;
}

void node_sprite_set_tint(struct node_sprite * node_sprite, Color tint)
{
    node_sprite->tint = tint;
}
