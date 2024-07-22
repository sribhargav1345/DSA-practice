// String machine

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;

    string s1;
    cin>>s1;

    ll m;
    cin>>m;

    string s2;
    cin>>s2;

    vector<ll> arr;
    for(int i=0;i<m;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }

    ll i=0,j=0;
    ll ans = 0;

    map<char,ll> mp;
    ll prev = -1;

    while(j<m)
    {
        char c = s2[arr[j] - 1];
        if(mp.find(c) == mp.end())
        {
            mp[c] = arr[j];
        }
        else 
        {
            mp[c] = min(arr[j],mp[c]);
        }
        
        if(s1[i] == c)
        {
            if(mp[s2[j]]>prev)
            {
                i++;
                prev = mp[s2[j]];
            }
        }
        j++;
        ans++;

        if(i==n) break;
    }

    if(i<n)
    {
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;

}

int main()
{
    ll t;
    cin>>t;

    while(t--){
        solve();    
    }
}