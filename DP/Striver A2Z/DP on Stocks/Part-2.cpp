#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int id,vector<int>& prices,int buy,int n,vector<vector<int>>& dp){
        if(id==n) return 0;

        if(dp[id][buy] != -1) return dp[id][buy];
        int profit = 0;

        if(buy == 0){
            profit = max(-prices[id] + solve(id+1,prices,1,n,dp), solve(id+1,prices,0,n,dp));
        }
        else
        {
            profit = max(prices[id] + solve(id+1,prices,0,n,dp), solve(id+1,prices,1,n,dp));
        }

        return dp[id][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        if(n==0) return 0;

        int ans = solve(0,prices,0,n,dp);
        return ans;
    }
};