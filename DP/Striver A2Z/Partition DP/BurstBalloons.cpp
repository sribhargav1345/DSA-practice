#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int take = nums[k]*nums[i-1]*nums[j+1] + solve(i,k-1,nums,dp) + solve(k+1,j,nums,dp);  // why taken nums[k]*nums[i-1]*nums[j+1] instead of nums[k]*nums[k-1]*nums[k+1]? nums[k-1],nums[k+1] balloons may not exist
            maxi = max(maxi,take);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,dp);
    }
};