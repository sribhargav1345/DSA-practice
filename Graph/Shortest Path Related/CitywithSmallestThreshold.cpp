#include<bits/stdc++.h>
using namespace std;

// Application of Floyd Warshall -> If they gave in matrix form, use Floyd Warshall only
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // These type can be solved by Floyd Warshall
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            adj[i][i] = 0;
        }

        for(auto it:edges)
        {
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
                }
            }
        }

        int mini = INT_MAX;
        int ans = -1;

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++)
        {
            int ct = 0;
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]<=distanceThreshold) ct++;
            }
            if(mini>=ct)
            {
                mini = ct;
                ans = i;
            }
        }
        return ans;
    }
};