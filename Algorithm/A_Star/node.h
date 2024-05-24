#ifndef NODE_HEAP_H
#define NODE_HEAP_H

#include"graph.h"

struct node_heap_t {
    int vertexName;
    int real_dist;
    int total_dist_to_src;
    struct node_heap_t* next;
};

typedef struct node_heap_t node_heap_t;

static node_heap_t* NODE_HEAP_Create(int vertex, int dist, int heuristic_dist);
static void NODE_HEAP_Free(node_heap_t* p_node_heap);

inline node_heap_t* NODE_HEAP_Create(int vertex, int dist, int heuristic_dist) {
    node_heap_t* p_node_heap = (node_heap_t*)malloc(sizeof(node_heap_t));
    if(!p_node_heap) {
        return NULL;
    }
    p_node_heap->vertexName = vertex;
    p_node_heap->real_dist = dist;
    p_node_heap->total_dist_to_src = heuristic_dist + dist;
    p_node_heap->next = NULL;
    
    return p_node_heap;
}

void NODE_HEAP_Free(node_heap_t* p_node_heap) {
    free(p_node_heap);
}


#endif