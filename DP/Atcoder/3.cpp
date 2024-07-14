#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Done
ll solve(ll n,vector<vector<ll>>& arr)
{
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                dp[i][j] = max(dp[i-1][1],dp[i-1][2]) + arr[i-1][j];
            }
            if(j==1)
            {
                dp[i][j] = max(dp[i-1][0],dp[i-1][2]) + arr[i-1][j];
            }
            if(j==2)
            {
                dp[i][j] = max(dp[i-1][1],dp[i-1][0]) + arr[i-1][j];
            }
        }
    }
    return max({dp[n][0],dp[n][1],dp[n][2]});
}

int main()
{
    ll n;
    cin>>n;

    vector<vector<ll>> arr;

    for(int i=0;i<n;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;

        vector<ll> v;

        v.push_back(a);
        v.push_back(b);
        v.push_back(c);

        arr.push_back(v);
    }

    cout<<solve(n,arr)<<endl;
}