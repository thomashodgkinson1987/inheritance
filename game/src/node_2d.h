#ifndef NODE_2D_H
#define NODE_2D_H

#include "node_types.h"

#include "node.h"

struct node_2d
{
    struct node base;

    //

    enum node_type type;

    //

    float x;
    float y;

    //

    void(*on_tick)(struct node_2d * node_2d);

    void(*fp_tick)(struct node_2d * node_2d);

    //

    struct node_2d(*fp_create)(char * name, float x, float y);
    void(*fp_free)(struct node_2d * node_2d);

    //

    enum node_type(*fp_get_type)(struct node_2d * node_2d);
    char * (*fp_get_name)(struct node_2d * node_2d);

    void(*fp_set_name)(struct node_2d * node_2d, char * name);

    //

    float(*fp_get_x)(struct node_2d * node_2d);
    float(*fp_get_y)(struct node_2d * node_2d);

    void(*fp_set_x)(struct node_2d * node_2d, float x);
    void(*fp_set_y)(struct node_2d * node_2d, float y);
};

struct node_2d node_2d_create(char * name, float x, float y);
void node_2d_free(struct node_2d * node2d);

//

void node_2d_register_callback_on_tick(struct node_2d * node_2d, void(*on_tick)(struct node_2d * node_2d));

void node_2d_tick(struct node_2d * node_2d);

//

enum node_type node_2d_get_type(struct node_2d * node2d);
char * node_2d_get_name(struct node_2d * node_2d);

void node_2d_set_name(struct node_2d * node_2d, char * name);

//

float node_2d_get_x(struct node_2d * node_2d);
float node_2d_get_y(struct node_2d * node_2d);

void node_2d_set_x(struct node_2d * node_2d, float x);
void node_2d_set_y(struct node_2d * node_2d, float y);

#endif
