// Similar to striver (Leetcode premium ques, so done from gfg)

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.size();
        int i = 0,j = 0;
        int maxi = -1;
        
        map<int,int> mp;
        
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size()==k)
            {
                maxi = max(maxi,j-i+1);
            }
            else if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    
                    i++;
                }
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};