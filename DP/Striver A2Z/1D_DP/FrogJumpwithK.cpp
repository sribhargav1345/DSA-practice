#include<bits/stdc++.h>
using namespace std;

int minimizeCost(vector<int>& height, int n, int k) {
    // Code here
    vector<int> dp(n+1,INT_MAX);
    dp[1] = 0;
    dp[2] = abs(height[1] - height[0]);
    
    for(int i=3;i<=n;i++)
    {
        for(int j=i-1;j>=max(1,i-k);j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(height[i-1]-height[j-1]));
        }
    }
    
    //for(auto x:dp) cout<<x<<" ";
    return dp[n];
}