#ifndef QUEUE_H
#define QUEUE_H

#include"node.h"

struct queue_t {
    node_heap_t* front;
    node_heap_t* rear;
};

typedef struct queue_t queue_t;

static queue_t* QUEUE_Create(void);
static void QUEUE_Put(queue_t* p_queue, int vertex, int dist);
static node_heap_t* QUEUE_Get(queue_t* p_queue);
static void QUEUE_Free(queue_t* p_queue);

queue_t* QUEUE_Create(void) {
    queue_t* p_queue = (queue_t*)malloc(sizeof(queue_t));

    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

void QUEUE_Put (queue_t* p_queue, int vertex, int dist) { 
    node_heap_t* p_node = NODE_HEAP_Create(vertex, dist, 0);
    if(p_queue->front == NULL || dist < p_queue->front->total_dist_to_src) {
        p_node->next = p_queue->front;
        p_queue->front = p_node;
    }
    else{
        node_heap_t* curr = p_queue->front;
        node_heap_t* pre = NULL;
        while(curr != NULL && dist >= curr->total_dist_to_src){
            pre = curr;
            curr = curr->next;
        }
        pre->next = p_node;
        p_node->next = curr;
    }
}

node_heap_t* QUEUE_Get(queue_t* p_queue) {
    if(p_queue->front == NULL){
        return NULL;
    }

    node_heap_t* p_node = NODE_HEAP_Create(p_queue->front->vertexName, p_queue->front->total_dist_to_src, 0);
    node_heap_t* temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if(p_queue->front == NULL) {
        p_queue->rear = NULL;
    }

    NODE_HEAP_Free(temp);
    return p_node;
}

void QUEUE_Free(queue_t* p_queue) {
    p_queue->front = NULL;
    p_queue->rear = NULL;
    free(p_queue);
}

#endif