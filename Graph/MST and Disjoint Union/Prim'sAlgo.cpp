#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // Just taking min-heap and storing weights upto we count all the vertices
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> visited(n,0);
        
        pq.push({0,0});
        
        int sum = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(visited[node] == 1) continue;

            // Add node to MST
            visited[node] = 1;
            
            sum += wt;
            
			for(auto it:adj[node]) 
			{
				int adjNode = it[0];
				int edW = it[1];
				
				if(!visited[adjNode]) 
				{
					pq.push({edW, adjNode});
				}
			}
        }
        return sum;
    }
};