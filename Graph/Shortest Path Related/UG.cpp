#include<bits/stdc++.h>
using namespace std;

// Shortest path in undirected graph, dist between each is 1. Remember in these BFS, inside for loop u have to mention (if(dist[node]<dist+1)), not like a visited array.
// Don't use visited array here

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        
        queue<int> q;
        q.push(src);
        
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> ans(n,INT_MAX);
        ans[src] = 0;
        
        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();
            
            for(auto x:adj[itr])
            {
                if(ans[x] > ans[itr] + 1)
                {
                    ans[x] = ans[itr] + 1;
                    q.push(x);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(ans[i]==INT_MAX) ans[i] = -1;
        }
        
        return ans;
    }
};