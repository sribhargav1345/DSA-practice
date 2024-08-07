#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution{
public:
    int knapSack(int n, int sum, int val[], int wt[])
    {
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(wt[i-1]<=j)
                {
                    int take = dp[i][j-wt[i-1]] + val[i-1];
                    int nottake = dp[i-1][j];
                    
                    dp[i][j] = max(take,nottake);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};