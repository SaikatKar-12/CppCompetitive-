#include<iostream>
#define v 6
using namespace std;
void topobfs(int graph[v][v]){
    int qu[100];
    int f=0;
    int r=0;
    int visited[v]={0};
    int indegree[v]={0};
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(graph[i][j]>0){
                indegree[j]++;
            }
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qu[r]=i;
            r++;
        }
    }
    while((r-f)!=0){
        int curr=qu[f];
        cout<<curr<<" ";
        visited[curr]=1;
        f++;
        for(int i=0;i<v;i++){
            if(graph[curr][i]==1 && visited[i]==0){
                indegree[i]--;
                if(indegree[i]==0){
                    qu[r]=i;
                    r++;
                }
            }
        }
    }
    // for(int i=0;i<v;i++){
    //     cout<<endl<<indegree[i]<<" ";
    // }
}
int main(){
    int graph[v][v]={
        {0,0,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,0,1,1,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };
    topobfs(graph);
    return 0;
}