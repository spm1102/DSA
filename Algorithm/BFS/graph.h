#ifndef GRAPH_H
#define GRAPH_H

#include"vertex.h"


struct graph_t {
    unsigned int numVertices;
    struct vertex_t** adjLists;
};

typedef struct graph_t graph_t;

static graph_t* GRAPH_Create(unsigned int vertices);
static void GRAPH_addEdge(graph_t* p_graph, unsigned int s, unsigned int d);
static unsigned int GRAPH_Num_adj_vertex(graph_t* p_graph, int vertex);
static void GRAPH_Free(graph_t* p_graph);


inline graph_t *GRAPH_Create(unsigned int vertices) {
    graph_t* p_graph = (graph_t*)malloc(sizeof(graph_t));
    p_graph->numVertices = vertices;
    p_graph->adjLists = (vertex_t**)malloc(vertices * sizeof(vertex_t*));


    for(unsigned int i = 0; i < vertices; i++) {
        p_graph->adjLists[i] = NULL;
    }
    return p_graph;
}

inline void GRAPH_addEdge(graph_t* p_graph, unsigned int src, unsigned int des) {
    vertex_t* p_vertex = VERTEX_Create(des);
    p_vertex->next = p_graph->adjLists[src];
    p_graph->adjLists[src] = p_vertex;

    p_vertex = VERTEX_Create(src);
    p_vertex->next = p_graph->adjLists[des];
    p_graph->adjLists[des] = p_vertex;
}

inline unsigned int GRAPH_Num_adj_vertex(graph_t* p_graph, int vertex){
    vertex_t* temp = p_graph->adjLists[vertex];
    unsigned int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

inline void GRAPH_Free(graph_t* p_graph){
    unsigned int i = 0;
    while(i < p_graph->numVertices){
        vertex_t* temp = p_graph->adjLists[i];
        while(temp){
            VERTEX_Free(temp);
            temp = temp->next;
        }
        i++;
    }
    free(p_graph->adjLists);
    free(p_graph);
}


#endif