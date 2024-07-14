#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dup = grid;
        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int time = 0;
        int ct = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dup[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else if(dup[i][j]==1)
                {
                    ct++;
                }
                else visited[i][j] = 1; // If no oranges
            }
        }

        int t = 0;
        int cnt = 0;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            int r = itr.first.first;
            int c = itr.first.second;

            t = max(itr.second,t);

            for(int k=0;k<4;k++)
            {
                int newr = r + dr[k];
                int newc = c + dc[k];

                if(newr>=0 && newr<n && newc>=0 && newc<m && visited[newr][newc]==0)
                {
                    visited[newr][newc] = 2;
                    q.push({{newr,newc},t+1});

                    cnt++;
                }
            }
        }
        if(cnt!=ct) return -1;
        return t;
    }
};