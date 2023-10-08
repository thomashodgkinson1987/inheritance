#include "node_circle.h"

#include "node_2d.h"

#include <assert.h>
#include <stdlib.h>

struct node_circle * node_circle_create(char * name, float x, float y, float radius, unsigned char color_r, unsigned char color_g, unsigned char color_b, unsigned char color_a)
{
    struct node_circle * node_circle = malloc(sizeof(struct node_circle));
    assert(node_circle != NULL);

    //

    node_circle->base = node_2d_create(name, x, y);

    //

    node_circle->type = NODE_TYPES_CIRCLE;

    //

    node_circle->radius = radius;
    node_circle->color_r = color_r;
    node_circle->color_g = color_g;
    node_circle->color_b = color_b;
    node_circle->color_a = color_a;

    //

    node_circle->fp_create = node_circle_create;
    node_circle->fp_free = node_circle_free;

    //

    node_circle->fp_get_node_type = node_circle_get_type;
    node_circle->fp_get_name = node_circle_get_name;

    node_circle->fp_set_name = node_circle_set_name;

    //

    node_circle->fp_get_x = node_circle_get_x;
    node_circle->fp_get_y = node_circle_get_y;

    node_circle->fp_set_x = node_circle_set_x;
    node_circle->fp_set_y = node_circle_set_y;

    //

    node_circle->fp_get_radius = node_circle_get_radius;
    node_circle->fp_get_color_r = node_circle_get_color_r;
    node_circle->fp_get_color_g = node_circle_get_color_g;
    node_circle->fp_get_color_b = node_circle_get_color_b;
    node_circle->fp_get_color_a = node_circle_get_color_a;

    node_circle->fp_set_radius = node_circle_set_radius;
    node_circle->fp_set_color_r = node_circle_set_color_r;
    node_circle->fp_set_color_g = node_circle_set_color_g;
    node_circle->fp_set_color_b = node_circle_set_color_b;
    node_circle->fp_set_color_a = node_circle_set_color_a;
    node_circle->fp_set_color = node_circle_set_color;

    //

    return node_circle;
}

void node_circle_free(struct node_circle * node_circle)
{
    node_circle->base->fp_free(node_circle->base);
    node_circle->base = NULL;

    //

    node_circle->type = 0;

    //

    node_circle->radius = 0.0f;
    node_circle->color_r = 0;
    node_circle->color_g = 0;
    node_circle->color_b = 0;
    node_circle->color_a = 0;

    //

    node_circle->fp_create = NULL;
    node_circle->fp_free = NULL;

    //

    node_circle->fp_get_node_type = NULL;
    node_circle->fp_get_name = NULL;

    node_circle->fp_set_name = NULL;

    //

    node_circle->fp_get_x = NULL;
    node_circle->fp_get_y = NULL;

    node_circle->fp_set_x = NULL;
    node_circle->fp_set_y = NULL;

    //

    node_circle->fp_get_radius = NULL;
    node_circle->fp_get_color_r = NULL;
    node_circle->fp_get_color_g = NULL;
    node_circle->fp_get_color_b = NULL;
    node_circle->fp_get_color_a = NULL;

    node_circle->fp_set_radius = NULL;
    node_circle->fp_set_color_r = NULL;
    node_circle->fp_set_color_g = NULL;
    node_circle->fp_set_color_b = NULL;
    node_circle->fp_set_color_a = NULL;
    node_circle->fp_set_color = NULL;

    //

    free(node_circle);
    node_circle = NULL;
}

//

enum node_type node_circle_get_type(struct node_circle * node_circle)
{
    return node_circle->type;
}

char * node_circle_get_name(struct node_circle * node_circle)
{
    return node_circle->base->fp_get_name(node_circle->base);
}



void node_circle_set_name(struct node_circle * node_circle, char * name)
{
    node_circle->base->fp_set_name(node_circle->base, name);
}

//

float node_circle_get_x(struct node_circle * node_circle)
{
    return node_circle->base->fp_get_x(node_circle->base);
}

float node_circle_get_y(struct node_circle * node_circle)
{
    return node_circle->base->fp_get_y(node_circle->base);
}



void node_circle_set_x(struct node_circle * node_circle, float x)
{
    node_circle->base->fp_set_x(node_circle->base, x);
}

void node_circle_set_y(struct node_circle * node_circle, float y)
{
    node_circle->base->fp_set_y(node_circle->base, y);
}

//

float node_circle_get_radius(struct node_circle * node_circle)
{
    return node_circle->radius;
}

unsigned char node_circle_get_color_r(struct node_circle * node_circle)
{
    return node_circle->color_r;
}

unsigned char node_circle_get_color_g(struct node_circle * node_circle)
{
    return node_circle->color_g;
}

unsigned char node_circle_get_color_b(struct node_circle * node_circle)
{
    return node_circle->color_b;
}

unsigned char node_circle_get_color_a(struct node_circle * node_circle)
{
    return node_circle->color_a;
}



void node_circle_set_radius(struct node_circle * node_circle, float radius)
{
    node_circle->radius = radius;
}

void node_circle_set_color_r(struct node_circle * node_circle, unsigned char color_r)
{
    node_circle->color_r = color_r;
}

void node_circle_set_color_g(struct node_circle * node_circle, unsigned char color_g)
{
    node_circle->color_g = color_g;
}

void node_circle_set_color_b(struct node_circle * node_circle, unsigned char color_b)
{
    node_circle->color_b = color_b;
}

void node_circle_set_color_a(struct node_circle * node_circle, unsigned char color_a)
{
    node_circle->color_a = color_a;
}

void node_circle_set_color(struct node_circle * node_circle, unsigned char color_r, unsigned char color_g, unsigned char color_b, unsigned char color_a)
{
    node_circle_set_color_r(node_circle, color_r);
    node_circle_set_color_g(node_circle, color_g);
    node_circle_set_color_b(node_circle, color_b);
    node_circle_set_color_a(node_circle, color_a);
}
