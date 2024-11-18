#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;

        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                if(t[i]!=mp[s[i]]) return false;
            }
            else mp[s[i]] = t[i];
        }

        map<char,char> mp1;
        for(int i=0;i<n;i++)
        {
            if(mp1.find(t[i])!=mp1.end())
            {
                if(s[i]!=mp1[t[i]]) return false;
            }
            else mp1[t[i]] = s[i];
        }

        return true;
    }
};