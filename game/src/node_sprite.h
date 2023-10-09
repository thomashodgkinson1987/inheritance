#ifndef NODE_SPRITE_H
#define NODE_SPRITE_H

#include "node_2d.h"

#include "raylib.h"

struct node_sprite
{
    struct node_2d base;

    //

    enum node_type type;

    //

    Texture2D texture;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
    float rotation;
    Color tint;

    //

    void(*on_tick)(struct node_sprite * node_sprite);

    void(*fp_tick)(struct node_sprite * node_sprite);

    //

    struct node_sprite(*fp_create)(char * name, float x, float y, Texture2D texture);
    void(*fp_free)(struct node_sprite * node_sprite);

    //

    enum node_type(*fp_get_type)(struct node_sprite * node_sprite);
    char * (*fp_get_name)(struct node_sprite * node_sprite);

    void(*fp_set_name)(struct node_sprite * node_sprite, char * name);

    //

    float(*fp_get_x)(struct node_sprite * node_sprite);
    float(*fp_get_y)(struct node_sprite * node_sprite);

    void(*fp_set_x)(struct node_sprite * node_sprite, float x);
    void(*fp_set_y)(struct node_sprite * node_sprite, float y);

    //

    Texture2D(*fp_get_texture)(struct node_sprite * node_sprite);
    Rectangle(*fp_get_source)(struct node_sprite * node_sprite);
    Rectangle(*fp_get_dest)(struct node_sprite * node_sprite);
    Vector2(*fp_get_origin)(struct node_sprite * node_sprite);
    float(*fp_get_rotation)(struct node_sprite * node_sprite);
    Color(*fp_get_tint)(struct node_sprite * node_sprite);

    void(*fp_set_texture)(struct node_sprite * node_sprite, Texture2D texture);
    void(*fp_set_source)(struct node_sprite * node_sprite, Rectangle source);
    void(*fp_set_dest)(struct node_sprite * node_sprite, Rectangle dest);
    void(*fp_set_origin)(struct node_sprite * node_sprite, Vector2 origin);
    void(*fp_set_rotation)(struct node_sprite * node_sprite, float rotation);
    void(*fp_set_tint)(struct node_sprite * node_sprite, Color tint);
};

struct node_sprite node_sprite_create(char * name, float x, float y, Texture2D texture);
void node_sprite_free(struct node_sprite * node_sprite);

//

void node_sprite_register_callback_on_tick(struct node_sprite * node_sprite, void(*on_tick)(struct node_sprite * node_sprite));

void node_sprite_tick(struct node_sprite * node_sprite);

//

enum node_type node_sprite_get_type(struct node_sprite * node_sprite);
char * node_sprite_get_name(struct node_sprite * node_sprite);

void node_sprite_set_name(struct node_sprite * node_sprite, char * name);

//

float node_sprite_get_x(struct node_sprite * node_sprite);
float node_sprite_get_y(struct node_sprite * node_sprite);

void node_sprite_set_x(struct node_sprite * node_sprite, float x);
void node_sprite_set_y(struct node_sprite * node_sprite, float y);

//

Texture2D node_sprite_get_texture(struct node_sprite * node_sprite);
Rectangle node_sprite_get_source(struct node_sprite * node_sprite);
Rectangle node_sprite_get_dest(struct node_sprite * node_sprite);
Vector2 node_sprite_get_origin(struct node_sprite * node_sprite);
float node_sprite_get_rotation(struct node_sprite * node_sprite);
Color node_sprite_get_tint(struct node_sprite * node_sprite);

void node_sprite_set_texture(struct node_sprite * node_sprite, Texture2D texture);
void node_sprite_set_source(struct node_sprite * node_sprite, Rectangle source);
void node_sprite_set_dest(struct node_sprite * node_sprite, Rectangle dest);
void node_sprite_set_origin(struct node_sprite * node_sprite, Vector2 origin);
void node_sprite_set_rotation(struct node_sprite * node_sprite, float rotation);
void node_sprite_set_tint(struct node_sprite * node_sprite, Color tint);

#endif
