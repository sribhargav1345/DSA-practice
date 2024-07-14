#include<bits/stdc++.h>
using namespace std;

// Same as of UG , take a queue, instead of visited arrays, in for loop, u have to write dist[...]>... and also initialise dist to INT_MAX
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        
        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();
            
            for(auto x:adj[itr.first])
            {
                if(dist[x.first]> dist[itr.first] + x.second)
                {
                    dist[x.first] = dist[itr.first] + x.second;
                    q.push({x.first,dist[x.first]});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};