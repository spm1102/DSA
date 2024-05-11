#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

struct node_t {
    int value;
    struct node_t* next;
};

typedef struct node_t node_t;


static node_t* NODE_Create(int value);
static void NODE_Free(node_t* p_node);


node_t* NODE_Create(int value) {
    node_t* p_node = (node_t*) malloc(sizeof(node_t));
    if (!p_node) return NULL;

    p_node->value = value;
    p_node->next = NULL;

    return p_node;
}

void NODE_Free(node_t* p_node) {
    free(p_node);
}

#endif