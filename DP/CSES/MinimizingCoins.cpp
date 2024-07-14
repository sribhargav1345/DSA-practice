#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Correct as of CPH, getting Runtime error in CSES
ll solve(ll n,ll sum,vector<ll>& coins)
{
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,INT_MAX));
    for(ll i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            if(coins[i-1]<=j)
            {
                ll take = dp[i][j-coins[i-1]] + 1;
                ll nottake = dp[i-1][j];

                dp[i][j] = min(take,nottake);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][sum] == INT_MAX) return -1;
    return dp[n][sum];
}

int main()
{
    ll n,x;
    cin>>n>>x;

    vector<ll> arr;
    for(ll i=0;i<n;i++)
    {
        ll p;
        cin>>p;
    
        arr.push_back(p);
    }

    cout<<solve(n,x,arr)<<endl;
}