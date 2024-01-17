#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int> > graph;
unordered_set<int> visited;
vector<vector<int> > result;
int v; // no of vertices
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}
void dfs(int node){
    visited.insert(node);
    for(auto nb:graph[node]){
        if(visited.find(nb)==visited.end()){
            dfs(nb);
        }
    }
}
int connectedComponents(vector<list<int> > &graph){
    int result=0;
    for(int i=0;i<v;i++){
        if(visited.find(i)==visited.end()){
            result++;
            dfs(i);
        }
    }
    return result;
}


int main() {
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    cout<<connectedComponents(graph);
    return 0;
}