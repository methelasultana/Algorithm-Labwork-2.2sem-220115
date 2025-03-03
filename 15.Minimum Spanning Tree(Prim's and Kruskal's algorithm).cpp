#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (weight, node)

// Graph Representation
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// **Prim's Algorithm (Min-Heap / Priority Queue)**
void primMST(vector<vector<pii>>& adj, int V) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    key[0] = 0;
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto [weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print MST edges
    cout << "Edges in the MST (Prim's Algorithm):\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
    }
}

// **Disjoint Set Union-Find for Kruskal's Algorithm**
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// **Kruskal's Algorithm**
void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    vector<Edge> mst;
    
    for (Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            if (mst.size() == V - 1) break;
        }
    }

    // Print MST edges
    cout << "Edges in the MST (Kruskal's Algorithm):\n";
    for (auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
    }
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 3}, {1, 2, 3}, {1, 4, 5},
        {2, 4, 4}, {3, 4, 1}
    };

    // Convert edges list to adjacency list for Prim's
    for (auto edge : edges) {
        adj[edge.u].push_back({edge.weight, edge.v});
        adj[edge.v].push_back({edge.weight, edge.u});
    }

    int choice;
    cout << "Choose MST algorithm:\n1. Prim's Algorithm\n2. Kruskal's Algorithm\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        primMST(adj, V);
    } else if (choice == 2) {
        kruskalMST(edges, V);
    } else {
        cout << "Invalid choice!";
    }

    return 0;
}