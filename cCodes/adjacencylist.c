#include <stdio.h>
#include <stdlib.h>
int visited[10]={0,0,0,0,0,0,0,0,0,0};
// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int V;              // Number of vertices
    struct Node** array; // Array of linked lists
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'V' vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for an array of linked lists
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));

    // Initialize each linked list as empty
    for (int i = 0; i < V; ++i) {
        graph->array[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; ++i) {
        printf("Adjacency list of vertex %d: ", i);
        struct Node* temp = graph->array[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void dfs(struct Graph* graph,int i){
    visited[i]=1;
    printf("%d ",i);
    struct Node* temp=graph->array[i];
    while(temp!=NULL){
        if(visited[temp->data]==0){
            dfs(graph,temp->data);
        }
        temp=temp->next;
    }
}
int main() {
    // Number of vertices in the graph
    int V = 5;

    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 4);

    // Print the adjacency list representation of the graph
    printGraph(graph);
    //dfs(graph,0);
    return 0;
}
