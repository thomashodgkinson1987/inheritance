#ifndef NODE_H
#define NODE_H

#include "node_types.h"

struct node
{
    enum node_type type;
    char * name;

    //

    void(*on_tick)(struct node * node);

    void(*fp_tick)(struct node * node);

    //

    struct node * (*fp_create)(char * name);
    void(*fp_free)(struct node * node);

    //

    enum node_type(*fp_get_type)(struct node * node);
    char * (*fp_get_name)(struct node * node);

    void(*fp_set_name)(struct node * node, char * name);
};

struct node * node_create(char * name);
void node_free(struct node * node);

//

void node_register_callback_on_tick(struct node * node, void(*on_tick)(struct node * node));

void node_tick(struct node * node);

//

enum node_type node_get_type(struct node * node);
char * node_get_name(struct node * node);

void node_set_name(struct node * node, char * name);

#endif
