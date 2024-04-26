#include<stdio.h>
#include<limits.h>
#define V 4

int min_distance(int visited[],int dist[]){
    int min=INT_MAX;
    int min_index;
    for(int v=0;v<V;v++){
        if(dist[v]<min && visited[v]==0){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void print_solution(int dist[]){
    for(int i=0;i<V;i++){
        printf("%d : %d ",i,dist[i]);
        printf("\n");
    }
}

void dijkstra(int graph[V][V],int src){
    int dist[V];
    int visited[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int u=min_distance(visited,dist);
        visited[u]=1;
        for(int v=0;v<V;v++){
            if(graph[u][v] && visited[v]==0 && dist[u]!=INT_MAX && dist[v]>(dist[u]+graph[u][v])){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    print_solution(dist);
}

int main(){
    int graph[V][V]={
        {0,2,0,7},
        {2,0,1,0},
        {0,1,0,3},
        {7,0,3,0}
    };
    dijkstra(graph,0);
    return 0;
}