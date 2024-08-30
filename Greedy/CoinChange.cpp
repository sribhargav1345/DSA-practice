// Unfortunately this problem cannot be solved using greedy ig

int minCoins(vector<int> &coins, int sum) {

    int n = coins.size();
    
    vector<vector<int>> dp(n+1,vector<int>(sum+1,INT_MAX));
    
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1]<=j)
            {
                int take = INT_MAX;
                if(dp[i][j-coins[i-1]] != INT_MAX) take = dp[i][j-coins[i-1]] + 1;
                
                int nottake = dp[i-1][j];
                
                dp[i][j] = min(take,nottake);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    if(dp[n][sum] == INT_MAX) return -1;
    return dp[n][sum];
}