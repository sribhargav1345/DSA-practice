#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Edge {
    int u, v, weight;
};

// Comparator function to sort edges in descending order of weights
bool compare(Edge a, Edge b) {
    return a.weight > b.weight;
}

// DSU (Disjoint Set Union) class for union-find operations
class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int maximumSpanningTree(int n, vector<Edge>& edges) {
    DSU dsu(n);
    sort(edges.begin(), edges.end(), compare); // Sort edges in descending order of weight

    int maxWeight = 0;

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unionSet(u, v);
            maxWeight += edge.weight;
            cout << "Adding edge (" << u << ", " << v << ") with weight " << edge.weight << endl;
        } else {
            cout << "Skipping edge (" << u << ", " << v << ") with weight " << edge.weight << " (already connected)" << endl;
        }
    }

    return maxWeight;
}

int main() {
    int n = 5; // Number of vertices
    vector<Edge> edges = {
        {1, 2, 2},
    {1, 3, 4},
    {2, 3, 6},
    {4, 5, 1}
    };

    // Find and process each connected component
    DSU dsu(n);
    unordered_set<int> processed;

    int totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        if (processed.find(dsu.find(i)) == processed.end()) {
            vector<Edge> componentEdges;
            for (const auto& edge : edges) {
                if (dsu.find(edge.u) == dsu.find(i) || dsu.find(edge.v) == dsu.find(i)) {
                    componentEdges.push_back(edge);
                }
            }
            totalWeight += maximumSpanningTree(n, componentEdges);
            for (int j = 0; j < n; ++j) {
                if (dsu.find(j) == i) {
                    processed.insert(dsu.find(j));
                }
            }
        }
    }

    cout << "Total Maximum Spanning Tree weight: " << totalWeight << endl;

    return 0;
}
