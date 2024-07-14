#include<bits/stdc++.h>
using namespace std;

void dfs(int n,vector<int>& visited,vector<int>& ans,vector<int> adj[])
{
    visited[n] = 1;
    ans.push_back(n);
    
    for(int x:adj[n])
    {
        if(visited[x]==0)
        {
            dfs(x,visited,ans,adj);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ans;
    
    vector<int> visited(V+1,0);
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,ans,adj);
        }
    }
    
    return ans;
}