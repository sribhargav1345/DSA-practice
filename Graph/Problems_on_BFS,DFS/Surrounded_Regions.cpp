#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board, vector<vector<int>>& visited,int n,int m){
        visited[i][j] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        for(int k=0;k<4;k++)
        {
            int newr = i + dr[k];
            int newc = j + dc[k];

            if(newr>=0 && newr<n && newc>=0 && newc<m && !visited[newr][newc] && board[newr][newc] == 'O'){
                dfs(newr,newc,board,visited,n,m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
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
                    if(board[i][j] == 'O')
                    {
                        dfs(i,j,board,visited,n,m);
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O')
                {
                    if(!visited[i][j]) board[i][j] = 'X';
                }
            }
        }
    }
};