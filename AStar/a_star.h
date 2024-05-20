#include "graph.h"

struct node_t {
    vertex_t* vertex;

    unsigned int g;
    unsigned int f;

    struct node_t*  parent;
    struct node_t** child;
};

typedef struct node_t node_t;

node_t* NODE_Create(vertex_t* vertex, unsigned int g, unsigned int f, node_t* parent);

