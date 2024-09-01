class Solution {
public:
    int solve(int id,int buy,int n,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(id==n || cap == 0){
            return 0;
        }

        if(dp[id][buy][cap] != -1){
            return dp[id][buy][cap];
        }

        int profit = 0;
        if(buy == 0){
            profit = max(-prices[id] + solve(id+1,1,n,cap,prices,dp), solve(id+1,0,n,cap,prices,dp));
        }
        else{
            profit = max(prices[id] + solve(id+1,0,n,cap-1,prices,dp), solve(id+1,1,n,cap,prices,dp));
        }
        return dp[id][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans = solve(0,0,n,2,prices,dp);

        return ans;
    }
};