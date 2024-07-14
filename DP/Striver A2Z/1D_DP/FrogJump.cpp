#include<bits/stdc++.h>
using namespace std;

int minimumEnergy(vector<int>& nums, int n) {
    // Code here
    vector<int> dp(n+1,INT_MAX);
    dp[1] = 0;
    dp[2] = abs(nums[1]-nums[0]);
    
    for(int i=3;i<=n;i++)
    {
        dp[i] = min(dp[i-1] + abs(nums[i-1]-nums[i-2]), dp[i-2] + abs(nums[i-1]-nums[i-3]));
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<dp[i]<<endl;
    // }
    return dp[n];
}