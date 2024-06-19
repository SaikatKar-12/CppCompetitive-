#include <stdio.h>
#include <limits.h>

#define V 4  // Number of vertices in the graph
#define INF INT_MAX  // Define infinity as a large value (can be any large number)

void printSolution(int dist[][V]);

// void floydWarshall(int graph[][V]) {
//     int dist[V][V], i, j, k;

//     // Initialize the solution matrix same as input graph matrix.
//     // Or we can say the initial values of shortest distances
//     // are based on shortest paths considering no intermediate vertex.
//     for (i = 0; i < V; i++)
//         for (j = 0; j < V; j++)
//             dist[i][j] = graph[i][j];

//     // Add all vertices one by one to the set of intermediate vertices.
//     // ---> Before start of an iteration, we have shortest distances between all pairs of vertices
//     // such that the shortest distances consider only the vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
//     // ----> After the end of an iteration, vertex no. k is added to the set of intermediate vertices
//     // and the set becomes {0, 1, 2, .. k}
//     for (k = 0; k < V; k++) {
//         // Pick all vertices as source one by one
//         for (i = 0; i < V; i++) {
//             // Pick all vertices as destination for the above picked source
//             for (j = 0; j < V; j++) {
//                 // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
//                 if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
//                     dist[i][j] = dist[i][k] + dist[k][j];
//             }
//         }
//     }

//     // Print the shortest distance matrix
//     printSolution(dist);
// }
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
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3
    */
    int graph[V][V] = { {0,   8,  INF, 1},
                        {INF, 0,   1, INF},
                        {4, INF, 0,   INF},
                        {INF, 2, 9, 0}
                      };

    // Print the solution
    floydWarshall(graph);
    return 0;
}
