#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n,ll w, vector<ll>& weights, vector<ll>& values)
{   
    vector<vector<ll>> dp(n+1,vector<ll>(w+1,0));

    for(int i=1;i<=n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(weights[i-1] <= j)
            {
                ll take = dp[i-1][j-weights[i-1]] + values[i-1];
                ll nottake = dp[i-1][j];

                dp[i][j] = max(take,nottake);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int main()
{
    ll n,w;
    cin>>n>>w;

    vector<ll> weights, values;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
    
        weights.push_back(x);
        values.push_back(y);
    }

    // for(int i=0;i<n;i++){
    //     cout<<values[i]<<" ";
    // }

  cout<<solve(n,w,weights,values)<<endl;
}