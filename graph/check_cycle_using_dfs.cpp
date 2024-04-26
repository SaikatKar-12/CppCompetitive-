#include<iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;
unordered_set<int> visited;
bool dfs(int src,int parent,vector<vector<int>> graph){
    visited.insert(src);
    for(int i=0;i<graph[0].size();i++){
        if(graph[src][i]==1){
            if(visited.find(i)!=visited.end() && i!=parent){
                return true;
            }
            if(visited.find(i)==visited.end()){
                bool res=dfs(i,src,graph);
                if(res==true) return true;
            }
        }
    }
    return false;
}
bool checkCycle(vector<vector<int>> graph){
    for(int i=0;i<graph.size();i++){
        if(visited.find(i)==visited.end()){
            bool result = dfs(i,-1,graph);
            if(result==true) return true;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> graph={
        {0,1,0,0},
        {1,0,1,0},
        {0,1,0,1},
        {0,0,1,0}
    };
    cout<<checkCycle(graph);
    return 0;
}