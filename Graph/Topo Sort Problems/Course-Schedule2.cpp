#include<bits/stdc++.h>
using namespace std;

// Just a Topo sort printing
class Solution {
public:
    vector<int> findOrder(int course, vector<vector<int>>& pre) {
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
        vector<int> ans;
        for(int i=0;i<course;i++)
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

            for(auto x:adj[itr])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        if(ans.size() == course) return ans;

        vector<int> v;
        return v;
    }
};