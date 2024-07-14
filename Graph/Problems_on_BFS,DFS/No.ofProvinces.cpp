#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,vector<int> adj[],int n,vector<int>& visited)
    {
        visited[i] = 1;
        
        for(int x:adj[i])
        {
            if(visited[x]==0)
            {
                dfs(x,adj,n,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> adj[n+1];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int ct = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,n,visited);
                ct++;
            }
        }
        return ct;
    }
};