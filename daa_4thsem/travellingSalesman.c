#include<stdio.h>
#define ncity 5
int visited[ncity];
int min_path[ncity+1];
int tsp(int graph[ncity][ncity],int count,int pos,int cost,int min_cost,int path[ncity+1]){
    if(count==ncity && graph[pos][0]){
        if (cost + graph[pos][0] < min_cost) {
            min_cost = cost + graph[pos][0];
            // Update the path array to include the return to the starting point
            path[count] = 0;
            for(int i=0;i<=ncity;i++){
                min_path[i]=path[i];
            }
        }
        return min_cost;
    }
    for(int i=0;i<ncity;i++){
        if(visited[i]==0 && graph[pos][i]){
            visited[i]=1;
            path[count]=i;
            min_cost=tsp(graph,count+1,i,cost+graph[pos][i],min_cost,path);
            visited[i]=0;
        }
    }
    return min_cost;
}
int main(){
    int graph[ncity][ncity]={
        {0, 10, 15, 20,8},
        {10, 0, 35, 25,12},
        {15,35,0,18,30},
        {20, 25, 18, 0,22},
        {8, 12, 30, 22,0}
    };
     int path[ncity + 1]; // To store the final path
    //int visited[ncity];
    
    for (int i = 0; i < ncity; i++) {
        visited[i] = 0;
    }
    
    visited[0] = 1; // Start from the first city
    path[0] = 0; // Initial city
    
    int minCost = tsp(graph,1,0,0,9999,path);
    
    printf("Minimum cost: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i <= ncity; i++) {
        printf("%d ", min_path[i]);
    }
    printf("\n");
    return 0;
}