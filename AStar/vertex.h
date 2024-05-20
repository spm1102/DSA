struct vertex_t {
    unsigned int vertex;

    unsigned int weight_next;
    struct vertex_t* next;

    unsigned int heuristic;
};

typedef struct vertex_t vertex_t;