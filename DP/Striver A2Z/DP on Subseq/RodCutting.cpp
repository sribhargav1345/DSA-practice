#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,0);
        dp[1] = price[0];
        
        for(int i=2;i<=n;i++)
        {
            dp[i] = price[i-1];
            for(int j=i-1;j>=1;j--)
            {
                dp[i] = max(dp[j]+dp[i-j],dp[i]);
            }
        }
        return dp[n];
    }
};