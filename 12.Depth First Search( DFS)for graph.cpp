#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
    cout << node << " ";  // Process the node
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj);
        }
    }
}

int main() {
    int vertices = 5;  // Number of vertices
    vector<vector<int>> adj(vertices);

    // Example graph edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    dfs(0, visited, adj);  // Start DFS from node 0

    return 0;
}