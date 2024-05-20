#include<stdio.h>
#include"BFS.h"

void GRAPH_Print(graph_t* p_graph) {
    unsigned int numVer;
    for(numVer = 0; numVer < p_graph->numVertices; numVer++){
        vertex_t* temp = p_graph->adjLists[numVer];
        printf("\nVertex %d\n", numVer);
        while(temp){
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    graph_t* p_graph = GRAPH_Create(6);
    GRAPH_addEdge(p_graph, 0, 1);
    GRAPH_addEdge(p_graph, 0, 2);
    GRAPH_addEdge(p_graph, 0, 5);
    GRAPH_addEdge(p_graph, 1, 3);
    GRAPH_addEdge(p_graph, 1, 4);
    GRAPH_addEdge(p_graph, 2, 4);
    GRAPH_addEdge(p_graph, 2, 5);
    GRAPH_addEdge(p_graph, 3, 4);
    GRAPH_addEdge(p_graph, 3, 5);
    GRAPH_addEdge(p_graph, 4, 5);


    unsigned int startVertex;
    scanf("%u", &startVertex);
    BFS(p_graph, startVertex);

    GRAPH_Free(p_graph);
    return 0;
}




