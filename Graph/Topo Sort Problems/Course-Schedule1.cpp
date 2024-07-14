#include<bits/stdc++.h>
using namespace std;

// Just same as Topo Sort
class Solution {
public:
    bool canFinish(int course, vector<vector<int>>& pre) {
        int n = pre.size();

        vector<vector<int>> adj(course);
        for(int i=0;i<n;i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        // Topo Sort problem
        vector<int> indegree(course,0);
        for(int i=0;i<n;i++)
        {
            indegree[pre[i][0]]++;
        }

        queue<int> q;
        int ct = 0;
        for(int i=0;i<course;i++)
        {
            if(indegree[i]==0) 
            {
                q.push(i);
                ct++;
            }
        }

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            for(auto x:adj[itr])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    ct++;
                    q.push(x);
                }
            }
        }
        if(ct == course) return true;
        return false;
    }
};