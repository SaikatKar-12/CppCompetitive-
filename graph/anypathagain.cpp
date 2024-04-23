#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<int>>result;
vector<int> path;
vector<vector<int>> graph;
unordered_set<int> visited;

void dfs(int curr, int end) {
    if (curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for (int i = 0; i < graph.size(); i++) {
        if (visited.find(i) == visited.end() && graph[curr][i] != 0) {
            dfs(i, end);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void allpath(int src, int dest) {
    visited.clear(); // Clear visited set for each call
    return dfs(src, dest);
}

int main() {
    graph = {
        {0, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}
    };
    allpath(0,3);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
