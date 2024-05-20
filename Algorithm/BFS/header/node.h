#ifndef NODE_H
#define NODE_H

#include<stdlib.h>

struct node_t {
    int vertex;
    struct node_t* next;
};

typedef struct node_t node_t;


static node_t* NODE_Create(unsigned int ver);
static void NODE_Free(node_t* p_node);

inline node_t* NODE_Create(unsigned int ver){
    node_t* p_node = (node_t*)malloc(sizeof(node_t));
    p_node->vertex = (int)ver;
    p_node->next = NULL;
    return p_node;
}

inline void NODE_Free(node_t* p_node){
    free(p_node);
}


#endif