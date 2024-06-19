#include <stdio.h>
#include <limits.h>

#define NUM_NODES 5
#define INF INT_MAX

// Function to find the node with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < NUM_NODES; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int n, int parent[]) {
    printf("Node \t Distance from Source \t Path\n");
    for (int i = 0; i < n; i++) {
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

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[NUM_NODES][NUM_NODES], int src) {
    int dist[NUM_NODES]; // The output array. dist[i] will hold the shortest distance from src to i
    int visited[NUM_NODES]; // visited[i] will be true if node i is included in shortest path tree
    int parent[NUM_NODES]; // Array to store the shortest path tree

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < NUM_NODES; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Distance of source node from itself is always 0
    dist[src] = 0;

    // Find shortest path for all nodes
    for (int count = 0; count < NUM_NODES - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < NUM_NODES; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, NUM_NODES, parent);
}

int main() {
    /* Let us create the example graph from the problem statement */
    int graph[NUM_NODES][NUM_NODES] = {
        // Home, Area1, Area2, Area3, College
        {0,    10,    30,    0,     0    }, // Home
        {0,    0,     0,     5,     20   }, // Area1
        {0,    0,     0,     0,     0    }, // Area2
        {0,    0,     15,    0,     10   }, // Area3
        {0,    0,     0,     0,     0    }  // College
    };

    int start_node = 0; // Home
    int end_node = 4;   // College

    dijkstra(graph, start_node);

    return 0;
}
