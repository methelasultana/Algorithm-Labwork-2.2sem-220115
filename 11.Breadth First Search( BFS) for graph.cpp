#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Function to perform BFS on a graph
void bfs(const unordered_map<int, vector<int>>& graph, int start) {
    unordered_map<int, bool> visited;  // Track visited nodes
    queue<int> q;  // Queue for BFS

    // Start from the initial node
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // Visit the current node

        // Explore the neighbors
        for (int neighbor : graph.at(node)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Graph represented as an adjacency list
    unordered_map<int, vector<int>> graph;

    // Add edges to the graph (example graph)
    graph[1] = {2, 3};
    graph[2] = {1, 4, 5};
    graph[3] = {1, 6};
    graph[4] = {2};
    graph[5] = {2};
    graph[6] = {3};

    // Perform BFS starting from node 1
    cout << "BFS Traversal starting from node 1: ";
    bfs(graph, 1);
    
    return 0;
}
