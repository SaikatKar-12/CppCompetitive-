#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& graph, int node, int k, vector<bool>& visited, vector<int>& distances, vector<vector<int>>& result) {
    visited[node] = true;
    
    // Check if distance from current node is divisible by k
    if (distances[node] % k == 0) {
        result[distances[node] / k].push_back(node);
    }
    
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[node][i] != 0 && !visited[i]) {
            distances[i] = distances[node] + graph[node][i];
            dfs(graph, i, k, visited, distances, result);
        }
    }
}

vector<vector<int>> findVerticesWithDistanceDivisibleByK(const vector<vector<int>>& graph, int k) {
    int n = graph.size(); // Number of vertices
    vector<bool> visited(n, false);
    vector<int> distances(n, 0);
    vector<vector<int>> result(n);

    // Start DFS from each node
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(graph, i, k, visited, distances, result);
        }
    }

    return result;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {0, 2, 0, 1},
        {3, 0, 4, 0},
        {0, 4, 0, 2},
        {1, 0, 2, 0}
    };
    int k = 2;

    vector<vector<int>> result = findVerticesWithDistanceDivisibleByK(graph, k);

    // Display the result
    cout << "Vertices whose distances are divisible by " << k << ":" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "From vertex " << i << ": ";
        for (int v : result[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

