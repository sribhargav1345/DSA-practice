#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        int mod = 1e9 + 7;
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)                       // Have to give correct inputs
            {
                if(arr[i-1]<=j)
                {
                    int take = (dp[i-1][j-arr[i-1]]);
                    int nottake = (dp[i-1][j]);
                    
                    dp[i][j] = (take + nottake)%mod;      // Have to find no.of ways
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
	}
	  
};