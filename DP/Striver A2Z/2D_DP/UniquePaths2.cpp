#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        int flag = 0;
        for(int i=1;i<=n;i++)
        {
            if(grid[i-1][0] == 1) 
            {
                flag = 1;
                dp[i][1] = 0;
            }
            if(flag==0) dp[i][1] = 1;
        }

        flag = 0;
        for(int i=1;i<=m;i++)
        {
            if(grid[0][i-1] == 1) 
            {
                flag = 1;
                dp[1][i] = 0;
            }
            if(flag==0) dp[1][i] = 1;
        }

        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=m;j++)
            {
                if(grid[i-1][j-1]==1) dp[i][j] = 0;
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};