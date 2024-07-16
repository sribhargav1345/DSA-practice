#include<bits/stdc++.h>
using namespace std;

// Finding shortest dist from given node to all other nodes. 
// Can also calculate in case of negative edges and negative cycles

class Solution {
  public:
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {

        vector<int> dist(n,1e8);
        dist[src] = 0;
        
        // N-1 Relaxations
        for(int i=0;i<n-1;i++)
        {
            for(auto it:edges)
            {
                int u = it[0];
                int v = it[1];
                
                int wt = it[2];
                
                if(dist[u] != 1e8 && dist[u] + wt< dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Nth relaxation
        int flag = 0;
        for(auto it :edges) 
        {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				flag = 1;
			}
		}
		if(flag == 1)
		{
		    vector<int> v;
		    v.push_back(-1);
		    
		    return v;
		}
		
		return dist;
    }
};