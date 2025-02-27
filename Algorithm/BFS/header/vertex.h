#ifndef VERTEX_H
#define VERTEX_H

#include<stdlib.h>


#define MAX_VERTICES 100
struct vertex_t {
    unsigned int vertex;
    struct vertex_t* next;
};
typedef struct vertex_t vertex_t;

static vertex_t* VERTEX_Create(unsigned int value);
static void VERTEX_Free(vertex_t* p_vertex);

inline vertex_t* VERTEX_Create(unsigned int value){
    vertex_t* p_vertex = (vertex_t*)malloc(sizeof(vertex_t));
    if(!p_vertex){
        return NULL;
    }
    
    p_vertex->vertex = value;
    p_vertex->next = NULL;
    return p_vertex;
}


inline void VERTEX_Free(vertex_t* p_vertex){
    free(p_vertex);
}
#endif