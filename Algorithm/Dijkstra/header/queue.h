#ifndef QUEUE_H
#define QUEUE_H

#include"node.h"

struct queue_t {
    node_t* front;
    node_t* rear;
};

typedef struct queue_t queue_t;

static queue_t* QUEUE_Create(void);
static void QUEUE_Put(queue_t* p_queue, int vertex, int dist);
static node_t* QUEUE_Get(queue_t* p_queue);
static void QUEUE_Free(queue_t* p_queue);

queue_t* QUEUE_Create(void) {
    queue_t* p_queue = (queue_t*)malloc(sizeof(queue_t));

    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

void QUEUE_Put(queue_t* p_queue,int vertex, int dist) {
    node_t* p_node = NODE_Create(vertex, dist);
    if(p_queue->front == NULL || dist < p_queue->front->shortest_dist_to_src){
        p_node->next = p_queue->front;
        p_queue->front = p_node;
    } 
    else{
        node_t* curr = p_queue->front;
        node_t* pre  =  NULL;
        while(curr != NULL && dist >= curr->shortest_dist_to_src) {
            pre = curr;
            curr = curr->next;
        }
        pre->next = p_node;
        p_node->next = curr;
    }
}

node_t* QUEUE_Get(queue_t* p_queue) {
    if(p_queue->front == NULL){
        return NULL;
    }
    node_t* p_node =  NODE_Create(p_queue->front->vertex, p_queue->front->shortest_dist_to_src) ;
    node_t* temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if(p_queue->front == NULL) {
        p_queue->rear = NULL;
    }
    NODE_Free(temp);
    return p_node;
}

void QUEUE_Free(queue_t* p_queue){
    p_queue->front = NULL;
    p_queue->rear = NULL;
    free(p_queue);
    
}


#endif