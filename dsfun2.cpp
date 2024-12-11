#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,k;
    cin>>n>>k;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }
    
    vector<int> temp(k,0);
    for(int i=n-k;i<n;i++)
    {
        temp[i-(n-k)] = arr[i];
    }

    for(int i=n-k-1;i>=0;i--)
    {
        arr[i+k] = arr[i];
    }

    for(int i=0;i<k;i++)
    {
        arr[i] = temp[i];
    }
}