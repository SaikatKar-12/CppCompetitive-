#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> visited(10,0);
vector<vector<int>> graph;
vector<int> dist(10,-1);
void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src]=1;
    dist[src]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<graph.size();i++){
           if(visited[i]==0 && graph[curr][i]!=0){
            q.push(i);
            visited[i]=1;
            dist[i]=dist[curr]+1;
            } 
        }
    }
}

int main(){
    graph = {
        {0, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0}
    };
    bfs(0);
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}