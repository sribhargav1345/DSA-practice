#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) 
        {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } 
            else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } 
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

int solve(int n, vector<Edge>& edges) {

    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.w > b.w;
    });

    DSU dsu(n);

    int mst_weight = 0;
    int total_weight = 0;

    for (const auto& edge : edges) {
        total_weight += edge.w;
    }

    for (const auto& edge : edges){
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_weight += edge.w;
        }
    }

    return total_weight - mst_weight;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<Edge> edges(n - 1);
    
        for (int i = 0; i < n - 1; i++) 
        {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
    
        cout << solve(n, edges) << endl;
    }
    

    return 0;
}