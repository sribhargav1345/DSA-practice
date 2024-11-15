#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll>& arr,ll n)
{
    sort(arr.begin(),arr.end());
    int i = 0,j = 1;
    ll cnt = 0;

    while(j<n)
    {
        if(arr[i] == arr[j]){
            j++;
        }
        else
        {
            cnt++;
            i++;
            j++;
        }
    }
    return cnt;
}

int main()
{
    ll n;
    cin>>n;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }
    
    cout<<solve(arr,n)<<endl;
}