#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Top to bottom vellali, paina ekkada nunchi aina start cheyyachhu
        // Kani direct ga kindaki vellakoodadu... 
        
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==2)
                {
                    dp[i][j] = max(dp[i-1][j-1],dp[i-1][j-2]) + points[i-1][j];
                }
                else if(j==1)
                {
                    dp[i][j] = max(dp[i-1][j+1],dp[i-1][j-1]) + points[i-1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j+1],dp[i-1][j+2]) + points[i-1][j];
                }
            }
        }
        return max({dp[n][0],dp[n][1],dp[n][2]});
    }
};