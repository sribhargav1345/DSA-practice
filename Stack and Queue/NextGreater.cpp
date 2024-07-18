#include<bits/stdc++.h>
using namespace std;

// Just maintain stack and iterate from last, u can find the rest
// For Next Greater element, stack should be decreasing from bottom to top
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();

        vector<int> ans;

        stack<int> st;

        st.push(nums2[n-1]);
        ans.push_back(-1);

        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else ans.push_back(st.top());

            st.push(nums2[i]);
        }

        reverse(ans.begin(),ans.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums2[i]] = ans[i];
        }

        vector<int> ct(m);

        for(int i=0;i<m;i++)
        {
            ct[i] = mp[nums1[i]];
        }
        return ct;
    }
};