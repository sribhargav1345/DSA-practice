#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});             // Storing max_diff, row,col

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        // For every step, u will calculate max_diff and store
        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();

            int max_effort = itr.first;
            
            int r = itr.second.first;
            int c = itr.second.second;

            if(r==n-1 && c == m-1) return max_effort;

            for(int k=0;k<4;k++)
            {
                int newr = r + dr[k];
                int newc = c + dc[k];

                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    int newEffort = max(max_effort,abs(heights[newr][newc] - heights[r][c]));

                    if(dist[newr][newc] > newEffort){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};