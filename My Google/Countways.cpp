#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    
    ll ans = 0;
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            ll p = arr[i];
            ll q = arr[j];

            ll low = j+1,high = n-1;
            while(low<=high)
            {
                if(p*arr[low] == q*arr[high])
                {
                    low++;
                    high--;
                }
                else
                {
                    
                }
            }
        }
    }
}