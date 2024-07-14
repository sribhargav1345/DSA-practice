#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});

        ans[sr][sc] = color;

        vector<vector<int>> visited(n,vector<int>(m,0));
        //visited[sr][sc] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            int r = itr.first;
            int c = itr.second;

            visited[r][c] = 1;

            for(int i=0;i<4;i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && ans[newr][newc] == image[r][c] && visited[newr][newc] == 0)
                {
                    ans[newr][newc] = color;
                    q.push({newr,newc});
                }
            }
        }
        return ans;
    }
};