#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long solve(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];
        
        long long mini = INT_MAX;
        for(int k=i;k<=j;k++)
        {   
            long long cut = solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp) + cuts[j+1] - cuts[i-1];
            mini = min(mini,cut);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end());
        int c = cuts.size();

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(1,c-2,cuts,dp);
    }
};