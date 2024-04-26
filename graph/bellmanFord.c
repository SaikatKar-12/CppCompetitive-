#include<stdio.h>
#include<limits.h>
#define V 3
void printSolution(int dist[]){
    for(int i=0;i<V;i++){
        printf("%d : %d ",i,dist[i]);
        printf("\n");
    }
}
void bellmanFord(int graph[V][V],int src){
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                    dist[v]=dist[u]+graph[u][v];
                }
            }
        }
    }

    printSolution(dist);
    for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                    printf("\n");
                    printf("graph contains negative edge cycle");
                }
            }
        }
    
}


int main(){
    int graph[V][V]={
        {0,10,5},
        {0,0,-8},
        {0,0,0}
    };
    bellmanFord(graph,0);
    return 0;
}