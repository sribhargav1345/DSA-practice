#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll id,vector<vector<ll>>& arr,ll n,vector<ll>& dp,ll prev)
{
    if(id==n){
        return 0;
    }

    if(dp[id]!=-1){
        return dp[id];
    }

    if(arr[id][0]>prev){
        ll take = arr[id][2] + solve(id+1,arr,n,dp,max(arr[id][1],prev));
        ll nottake = solve(id+1,arr,n,dp,prev);

        return dp[id] = max(take,nottake);
    }

    return dp[id] = solve(id+1,arr,n,dp,prev);
}

ll project(ll n,vector<vector<ll>>& arr)
{
    vector<ll> dp(n,-1);
    sort(arr.begin(),arr.end());

    ll ans = solve(0,arr,n,dp,0);

    return ans;
}

int main()
{
    ll n;
    cin>>n;

    vector<vector<ll>> arr;

    for(int i=0;i<n;i++)
    {
        ll a,b,p;
        cin>>a>>b>>p;

        vector<ll> v;

        v.push_back(a);
        v.push_back(b);
        v.push_back(p);

        arr.push_back(v);
    }

    cout<<project(n,arr)<<endl;
}