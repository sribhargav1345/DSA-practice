#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int i = 0, j = 0;
        set<char> st;

        int maxi = 0;

        while(j<n)
        {
            if(st.find(s[j])!=st.end())
            {
                while(st.find(s[j])!=st.end())
                {
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};