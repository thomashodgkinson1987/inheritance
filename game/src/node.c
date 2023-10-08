#include "node.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct node * node_create(char * name)
{
    struct node * node = malloc(sizeof(struct node));
    assert(node != NULL);

    //

    node->type = NODE_TYPES_NODE;

    node->name = malloc(strlen(name) + 1);
    assert(node->name != NULL);
    strcpy(node->name, name);

    //

    node->on_tick = NULL;

    node->fp_tick = node_tick;

    //

    node->fp_create = node_create;
    node->fp_free = node_free;

    //

    node->fp_get_type = node_get_type;
    node->fp_get_name = node_get_name;

    node->fp_set_name = node_set_name;

    //

    return node;
}

void node_free(struct node * node)
{
    node->type = 0;
    free(node->name);
    node->name = NULL;
    free(node);
    node = NULL;
}

//

void node_register_callback_on_tick(struct node * node, void(*on_tick)(struct node * node))
{
    node->on_tick = on_tick;
}

void node_tick(struct node * node)
{
    if (node->on_tick != NULL)
    {
        node->on_tick(node);
    }
}

//

enum node_type node_get_type(struct node * node)
{
    return node->type;
}

char * node_get_name(struct node * node)
{
    return node->name;
}



void node_set_name(struct node * node, char * name)
{
    char * ptr = realloc(node->name, strlen(name) + 1);
    assert(ptr != NULL);
    node->name = ptr;
    strcpy(node->name, name);
}
