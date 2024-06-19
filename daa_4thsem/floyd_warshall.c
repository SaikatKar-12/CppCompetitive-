#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph
#define INF INT_MAX  // Define infinity as a large value (can be any large number)

void printSolution(int dist[][V]);

void floydWarshall(int graph[V][V]){
    int dist[V][V],i,j,k;

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            dist[i][j]=graph[i][j];
        }
    }

    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices\n");
    printf("   ");
    for(int i=0;i<V;i++){
        printf("\tDC%d",i+1);
    }
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("DC%d",i+1);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("\t%s", "INF");
            else
                printf("\t%d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
   
    int graph[V][V] = { {0,10,INF,30,INF},
                        {10, 0,5,INF,20},
                        {INF,5, 0,15,10},
                        {30,INF,15, 0,INF},
                        {INF,20,10,INF,0}
                      };

    // Print the solution
    floydWarshall(graph);
    return 0;
}
