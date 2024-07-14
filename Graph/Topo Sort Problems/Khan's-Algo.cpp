#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // I am doing using BFS. -> Store indegree = 0 ones and continue
	    vector<int> indegree(v,0);
	    for(int i=0;i<v;i++)
	    {
	        for(auto x:adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	        
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	            ans.push_back(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        auto itr = q.front();
	        q.pop();
	        
	        for(auto it: adj[itr])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	                ans.push_back(it);
	            }
	        }
	    }
	    return ans;
	}