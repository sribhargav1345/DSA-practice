#include<bits/stdc++.h>
using namespace std;

// This is basically knapsack, getting wrong
int mod = 1e9 + 7;

int solve(int sum)
{
    int n = 6;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(i<=j)
            {
                int take = dp[i][j-i];
                int nottake = dp[i-1][j];

                dp[i][j] = (take + nottake)%mod;
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
  int n;
  cin>>n;

  cout<<solve(n)<<endl;
}