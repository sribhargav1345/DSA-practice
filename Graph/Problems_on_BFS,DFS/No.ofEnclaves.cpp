#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& board, vector<vector<int>>& visited,int n,int m){
        visited[i][j] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        for(int k=0;k<4;k++)
        {
            int newr = i + dr[k];
            int newc = j + dc[k];

            if(newr>=0 && newr<n && newc>=0 && newc<m && !visited[newr][newc] && board[newr][newc] == 1){
                dfs(newr,newc,board,visited,n,m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) {

        // Same as Surrounded Regions problem
        int n = board.size();
        int m = board[0].size();

        // Let's marks boundary elements as visited
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(board[i][j] == 1)
                    {
                        dfs(i,j,board,visited,n,m);
                    }
                }
            }
        }

        int ct = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 1)
                {
                    if(!visited[i][j]) ct++;
                }
            }
        }
        return ct;
    }
};