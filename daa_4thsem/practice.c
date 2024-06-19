#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<limits.h>
#define V 5
#define INF INT_MAX
int visited[V];
int min_distance(int graph[][V],int dist[]){
    int min=INT_MAX;
    int min_index=-1;
    for(int i=0;i<V;i++){
        if(visited[i]!=1 && dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void print_solution(int dist[],int path[]){
    for(int i=0;i<V;i++){
        printf("%d %d ",i,dist[i]);
        print_path(path,i);
        printf("\n");
    }
}
void print_path(int path[],int i){
    if(path[i]==-1) return;
    print_path(path,path[i]);
    printf("%d ",i);
}
void dijkstra(int graph[][V],int src){
    int dist[V];
    int path[V];
    for(int i=0;i<V;i++){
        dist[i]=INF;
        visited[i]=0;
        path[i]=-1;
    }
    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int u=min_distance(graph,dist);
        visited[u]=1;
        for(int v=0;v<V;v++){
            if(visited[v]!=1 && graph[u][v] && dist[u]!=INF && (dist[u]+graph[u][v]<dist[v])){
                path[v]=u;
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    print_solution(dist,path);
}
int main(){
    int graph[V][V] = {
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