#include<bits/stdc++.h>
using namespace std;

// Easy but u got many Wrongs(tricky test cases)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        stack<int> st;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                st.push(nums[i]);
            }
            else
            {
                int r = abs(nums[i]);
                if(!st.empty() && st.top()<0) 
                {
                    st.push(nums[i]);
                    continue;
                }

                while(!st.empty() && st.top()<r)
                {
                    if(st.top()<0) 
                    {
                        st.push(nums[i]);
                        break;
                    }
                    st.pop();
                }

                if(st.empty())
                {
                    st.push(nums[i]);
                    continue;
                } 

                if(st.top() == r) st.pop();
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};