#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return -1;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 1;

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();

            int dis = itr.first;
            int r = itr.second.first;
            int c = itr.second.second;

            for(int k=0;k<8;k++)
            {
                int newr = r + dr[k];
                int newc = c + dc[k];

                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && dist[newr][newc]> dist[r][c] + 1)
                {
                    dist[newr][newc] = dist[r][c] + 1;
                    pq.push({dist[newr][newc],{newr,newc}});
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};