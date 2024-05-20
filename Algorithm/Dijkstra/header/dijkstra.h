#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include"graph.h"
#include"queue.h"

static void dijkstra(graph_t* p_graph, int startVertex);

inline void dijkstra(graph_t* p_graph, int startVertex) {
    queue_t* p_queue = NULL;
    p_queue = QUEUE_Create();
    p_graph->vertices[startVertex].shortest_dist_to_src = 0;
    QUEUE_Put(p_queue, startVertex, 0);
    while(p_queue->front != NULL) {
        node_t* minNode = QUEUE_Get(p_queue);
        int currentVertex = minNode->vertex;
        NODE_Free(minNode);

        if(p_graph->vertices[currentVertex].visited){
            continue;
        }
        p_graph->vertices[currentVertex].visited = 1;

        edge_t* temp = p_graph->vertices[currentVertex].edge;
        while(temp != NULL) {
            int nextVertex = temp->dest;
            int weight = temp->weight;

            if(!p_graph->vertices[nextVertex].visited) {
                int new_dist = p_graph->vertices[currentVertex].shortest_dist_to_src + weight;
                if (new_dist < p_graph->vertices[nextVertex].shortest_dist_to_src) {
                    p_graph->vertices[nextVertex].shortest_dist_to_src = new_dist;
                    p_graph->vertices[nextVertex].preVertex = currentVertex;
                    QUEUE_Put(p_queue, nextVertex, new_dist);
                }
            }
            temp = temp->next;
        }
    }
    QUEUE_Free(p_queue);
}

#endif