#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;

    vector<ll> arr;
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
        sum += x;
    }

    if(sum%2!=0) return -1;

    ll k = sum/2;
    
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {

        }
    }
}


