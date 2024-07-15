#include<bits/stdc++.h>
using namespace std;

// Weighted, Undirected graphs
// Not applicable for -ve weights and cycles.

// We can use priority_queue/ queue(takes more time)/ set(similar to pq) for Dijkstra
// Whenever Dijkstra, u need to get priority_queue and Dist array to your mind

class Solution
{
	public:
    vector<int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        
        vector<int> dist(n,INT_MAX);
        dist[s] = 0;
        
        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();
            
            int dis = itr.first;
            int node = itr.second;
            
            for(auto it: adj[node])
            {
                if(dist[it[0]]>dis + it[1])
                {
                    dist[it[0]] = dis + it[1];
                    pq.push({dist[it[0]],it[0]});
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