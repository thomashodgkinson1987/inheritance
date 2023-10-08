#ifndef NODE_CIRCLE_H
#define NODE_CIRCLE_H

#include "node_types.h"

#include "node_2d.h"

struct node_circle
{
    struct node_2d base;

    //

    enum node_type type;

    //

    float radius;
    unsigned char color_r;
    unsigned char color_g;
    unsigned char color_b;
    unsigned char color_a;

    //

    void(*on_tick)(struct node_circle * node_circle);

    void(*fp_tick)(struct node_circle * node_circle);

    //

    struct node_circle (*fp_create)(char * name, float x, float y, float radius, unsigned char color_r, unsigned char color_g, unsigned char color_b, unsigned char color_a);
    void(*fp_free)(struct node_circle * node_circle);

    //

    enum node_type(*fp_get_node_type)(struct node_circle * node_circle);
    char * (*fp_get_name)(struct node_circle * node_circle);

    void(*fp_set_name)(struct node_circle * node_circle, char * name);

    //

    float(*fp_get_x)(struct node_circle * node_circle);
    float(*fp_get_y)(struct node_circle * node_circle);

    void(*fp_set_x)(struct node_circle * node_circle, float x);
    void(*fp_set_y)(struct node_circle * node_circle, float y);

    //

    float(*fp_get_radius)(struct node_circle * node_circle);
    unsigned char(*fp_get_color_r)(struct node_circle * node_circle);
    unsigned char(*fp_get_color_g)(struct node_circle * node_circle);
    unsigned char(*fp_get_color_b)(struct node_circle * node_circle);
    unsigned char(*fp_get_color_a)(struct node_circle * node_circle);

    void(*fp_set_radius)(struct node_circle * node_circle, float radius);
    void(*fp_set_color_r)(struct node_circle * node_circle, unsigned char color_r);
    void(*fp_set_color_g)(struct node_circle * node_circle, unsigned char color_g);
    void(*fp_set_color_b)(struct node_circle * node_circle, unsigned char color_b);
    void(*fp_set_color_a)(struct node_circle * node_circle, unsigned char color_a);
    void(*fp_set_color)(struct node_circle * node_circle, unsigned char color_r, unsigned char color_g, unsigned char color_b, unsigned char color_a);
};

//

struct node_circle node_circle_create(char * name, float x, float y, float radius, unsigned char color_r, unsigned char color_g, unsigned char color_b, unsigned char color_a);
void node_circle_free(struct node_circle * node_circle);

//

void node_circle_register_callback_on_tick(struct node_circle * node_circle, void(*on_tick)(struct node_circle * node_circle));

void node_circle_tick(struct node_circle * node_circle);

//

enum node_type node_circle_get_type(struct node_circle * node_circle);
char * node_circle_get_name(struct node_circle * node_circle);

void node_circle_set_name(struct node_circle * node_circle, char * name);

//

float node_circle_get_x(struct node_circle * node_circle);
float node_circle_get_y(struct node_circle * node_circle);

void node_circle_set_x(struct node_circle * node_circle, float x);
void node_circle_set_y(struct node_circle * node_circle, float y);

//

float node_circle_get_radius(struct node_circle * node_circle);
unsigned char node_circle_get_color_r(struct node_circle * node_circle);
unsigned char node_circle_get_color_g(struct node_circle * node_circle);
unsigned char node_circle_get_color_b(struct node_circle * node_circle);
unsigned char node_circle_get_color_a(struct node_circle * node_circle);

void node_circle_set_radius(struct node_circle * node_circle, float radius);
void node_circle_set_color_r(struct node_circle * node_circle, unsigned char color_r);
void node_circle_set_color_g(struct node_circle * node_circle, unsigned char color_g);
void node_circle_set_color_b(struct node_circle * node_circle, unsigned char color_b);
void node_circle_set_color_a(struct node_circle * node_circle, unsigned char color_a);
void node_circle_set_color(struct node_circle * node_circle, unsigned char color_r, unsigned char color_g, unsigned char color_b, unsigned char color_a);

#endif
