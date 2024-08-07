#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int good(int n,string s){
    int ct = 0;

    map<char,int> mp;
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
        maxi = max(maxi,mp[s[i]]);
    }

    vector<int> v(maxi+1,0);
    for(auto it:mp){
        v[it.second]++;
    }

    
}