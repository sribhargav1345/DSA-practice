#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    
	void dfs(int i,vector<int>& visited,stack<int>& st,vector<int> adj[])
	{
	    visited[i] = 1;
	    for(auto it: adj[i])
	    {
	        if(!visited[it]) dfs(it,visited,st,adj);
	    }
	    
	    st.push(i);
	    
	}
	
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(n+1,0);
	    stack<int> st;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(i,visited,st,adj);
	        }
	    }
	    
	    vector<int> topo;
	    while(!st.empty())
	    {
	        auto itr = st.top();
	        st.pop();
	        
	        topo.push_back(itr);
	    }
	    return topo;
	}
};