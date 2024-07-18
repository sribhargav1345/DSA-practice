#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        vector<int> ans;

        // Doubling the array hypotetically
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && nums[i%n] >= st.top()){
                st.pop();
            }

            if(!st.empty() && i<n) ans.push_back(st.top());
            else if(i<n) ans.push_back(-1);

            st.push(nums[i%n]);  
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};