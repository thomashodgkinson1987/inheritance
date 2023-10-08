#include "node_2d.h"

#include <assert.h>
#include <stdlib.h>

struct node_2d * node_2d_create(char * name, float x, float y)
{
    struct node_2d * node_2d = malloc(sizeof(struct node_2d));
    assert(node_2d != NULL);

    //

    node_2d->base = node_create(name);

    //

    node_2d->type = NODE_TYPES_NODE_2D;

    //

    node_2d->x = x;
    node_2d->y = y;

    //

    node_2d->fp_create = node_2d_create;
    node_2d->fp_free = node_2d_free;

    //

    node_2d->fp_get_type = node_2d_get_type;
    node_2d->fp_get_name = node_2d_get_name;

    node_2d->fp_set_name = node_2d_set_name;

    //

    node_2d->fp_get_x = node_2d_get_x;
    node_2d->fp_get_y = node_2d_get_y;

    node_2d->fp_set_x = node_2d_set_x;
    node_2d->fp_set_y = node_2d_set_y;

    //

    return node_2d;
}

void node_2d_free(struct node_2d * node_2d)
{
    node_2d->base->fp_free(node_2d->base);
    node_2d->base = NULL;

    //

    node_2d->type = 0;

    //

    node_2d->x = 0;
    node_2d->y = 0;

    //

    node_2d->fp_create = NULL;
    node_2d->fp_free = NULL;

    //

    node_2d->fp_get_type = NULL;
    node_2d->fp_get_name = NULL;

    node_2d->fp_set_name = NULL;

    //

    node_2d->fp_get_x = NULL;
    node_2d->fp_get_y = NULL;

    node_2d->fp_set_x = NULL;
    node_2d->fp_set_y = NULL;

    //

    free(node_2d);
    node_2d = NULL;
}

//

enum node_type node_2d_get_type(struct node_2d * node_2d)
{
    return node_2d->type;
}

char * node_2d_get_name(struct node_2d * node_2d)
{
    return node_2d->base->fp_get_name(node_2d->base);
}



void node_2d_set_name(struct node_2d * node_2d, char * name)
{
    node_2d->base->fp_set_name(node_2d->base, name);
}

//

float node_2d_get_x(struct node_2d * node_2d)
{
    return node_2d->x;
}

float node_2d_get_y(struct node_2d * node_2d)
{
    return node_2d->y;
}



void node_2d_set_x(struct node_2d * node_2d, float x)
{
    node_2d->x = x;
}

void node_2d_set_y(struct node_2d * node_2d, float y)
{
    node_2d->y = y;
}
