#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank,parent;
public:
    DSU(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
    }

    int findPar(int n){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int uPar = findPar(u);
        int vPar = findPar(v);

        if(uPar == vPar) return;

        if(rank[uPar] > rank[vPar]){
            parent[vPar] = uPar;
        }
        else if(rank[vPar] > rank[uPar]){
            parent[uPar] = vPar;
        }
        else{
            parent[vPar] = uPar;
            rank[uPar]++;
        }
    }
};

vector<int> noofIslands(int n,int m,vector<vector<int>>& operators){
    DSU dsu(n*m);
    vector<vector<int>> vis(n,vector<int>(m,0));

    int cnt = 0;        // No. of Islands
    vector<int> ans;
    for(auto it: operators){
        int row = it[0];
        int col = it[1];

        if(vis[row][col] == 1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k=0;k<4;k++)
        {
            int adjr = row + dr[k];
            int adjc = col + dc[k];

            if(adjr>=0 && adjc>=0 && adjr<n && adjc<m && vis[adjr][adjc]==1){
                int node = row*m + col;
                int adjNode = adjr*m + adjc;

                if(ds.findUPar(node) != ds.findUPar(adjNode)){
                    cnt--;
                    ds.unionBySize(node, adjNode);
                }
            }
        }
        ans.push_back(cnt);
    }
}