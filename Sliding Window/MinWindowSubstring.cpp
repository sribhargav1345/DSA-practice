#include<bits/stdc++.h>
using namespace std;

// Hard problem in Lt, but easy for u
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        map<char,int> mpt;
        map<char,int> mp;

        string ans = "";
        if(n<m) return ans;

        for(auto x:t)
        {
            mpt[x]++;
        }

        int i = 0,j = 0;
        int mini = INT_MAX;

        while(j<n)
        {
            mp[s[j]]++;
            int flag = 0;
            for(auto x:mpt)
            {
                if(mp[x.first]<mpt[x.first])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                while(mp[s[i]]>mpt[s[i]])
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                if(j-i+1 < mini)
                {
                    mini = j-i+1;
                    ans = s.substr(i,mini);
                }
            }
            j++;
        }
        return ans;
    }
};