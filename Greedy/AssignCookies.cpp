#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int n = s.size();
        if(n==0) return 0;

        int i=0,j=0;
        int ct = 0;
        while(i<m && j<n)
        {
            if(g[i]<=s[j])
            {
                ct++;
                i++;
            }
            j++;
        }

        return ct;
    }
};