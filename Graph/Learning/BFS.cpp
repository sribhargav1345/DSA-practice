#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    // Code here
    queue<int> q;
    q.push(0);
    
    vector<int> visited(n,0);
    vector<int> ans;
    
    while(!q.empty())
    {
        auto itr = q.front();
        q.pop();
        
        if(visited[itr]==0)
        {
            visited[itr] = 1;
            ans.push_back(itr);
        }
        
        for(auto x:adj[itr])
        {
            if(visited[x]==0)
            {
                q.push(x);
            }
        }
    }
    
    return ans;
};