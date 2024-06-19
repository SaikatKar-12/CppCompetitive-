#include <stdio.h>
#include <limits.h>

#define NUM_NODES 5
#define INF INT_MAX

// Function to print the shortest distances and paths from the source
void printSolution(int dist[], int parent[]) {
    printf("Node \t Distance from Source \t Path\n");
    for (int i = 0; i < NUM_NODES; i++) {
        printf("%d \t\t %d \t\t\t ", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

// Function to print the path from source to j
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Function to implement the Bellman-Ford algorithm
void bellmanFord(int graph[NUM_NODES][NUM_NODES], int src) {
    int dist[NUM_NODES];
    int parent[NUM_NODES];

    // Initialize distances from src to all other nodes as INFINITE
    for (int i = 0; i < NUM_NODES; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Relax all edges |NUM_NODES - 1| times
    for (int i = 1; i <= NUM_NODES - 1; i++) {
        for (int u = 0; u < NUM_NODES; u++) {
            for (int v = 0; v < NUM_NODES; v++) {
                if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < NUM_NODES; u++) {
        for (int v = 0; v < NUM_NODES; v++) {
            if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    printSolution(dist, parent);
}

int main() {
    int graph[NUM_NODES][NUM_NODES] = {
        // Jadavpur, Garia, Ballygunge, Rashbihari, Kalighat
        {0, 6, 5, INF, INF},       // Jadavpur
        {INF, 0, INF, 1, INF},     // Garia (with off-peak discount to Rashbihari)
        {INF, 2, 0, 4, 3},         // Ballygunge (with off-peak discount to Garia)
        {INF, INF, INF, 0, 3},     // Rashbihari
        {INF, INF, INF, INF, 0}    // Kalighat
    };

    int start_node = 0; // Jadavpur

    bellmanFord(graph, start_node);

    return 0;
}
