#ifndef VERTEX_H
#define VERTEX_H

#include"graph.h"

#define MAX_VERTICES 100
struct vertex_t {
    int visited;
    int shortest_dist_to_src;
    int preVertex;
    edge_t* edge;
};
typedef struct vertex_t vertex_t;



#endif