#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(vector<vector<int>>& graph,int i,int n,vector<int>& visited){

        // The whole part, that I am doing is of one component

        queue<pair<int,int>> q;
        q.push({i,0});              // Let me color them with 2 colors ->  0,1

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            int u = itr.first;
            int color = itr.second;

            visited[u] = color;

            for(auto x:graph[u])
            {
                if(visited[x] == -1)
                {
                    q.push({x,1^color});
                }
                else 
                {
                    if(visited[x] == color) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n,-1);

        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                if(bfs(graph,i,n,visited) == false) return false;
            }
        }
        return true;
    }
};