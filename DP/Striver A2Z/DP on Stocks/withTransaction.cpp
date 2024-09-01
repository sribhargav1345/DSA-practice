class Solution {
public:
    int solve(int id,int buy,vector<int>& prices,int n,vector<vector<int>>& dp, int fee){
        if(id>=n){
            return 0;
        }

        if(dp[id][buy] != -1){
            return dp[id][buy];
        }

        int profit = 0;
        if(buy == 0){
            profit = max(-prices[id] + solve(id+1,1,prices,n,dp,fee), solve(id+1,0,prices,n,dp,fee));
        }
        else
        {
            profit = max(prices[id] + solve(id+1,0,prices,n,dp,fee) - fee, solve(id+1,1,prices,n,dp,fee));
        }

        return dp[id][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans = solve(0,0,prices,n,dp,fee);

        return ans;
    }
};