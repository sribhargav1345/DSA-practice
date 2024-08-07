#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();

        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        if (totSum - target < 0 || (totSum - target) % 2 != 0) return 0;

        target = (totSum - target)/2;   // half elements, choose +

        // Pick '+' ones, that would be enough ig
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        if(arr[0]==0) dp[1][0] = 2; // pick, notpick
        else dp[1][0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
        dp[1][arr[0]] = 1;

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(arr[i-1]<=j)
                {
                    int take = dp[i-1][j-arr[i-1]];
                    int nottake = dp[i-1][j];

                    dp[i][j] = take + nottake;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};