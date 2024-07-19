#include<bits/stdc++.h>
using namespace std;

// Common approach
class Solution {
public:
    void solve(int i,int n,vector<int>& nums,vector<int>& v,vector<vector<int>>& ans)
    {
        if(i==n)
        {
            ans.push_back(v);
            return;
        } 

        v.push_back(nums[i]);
        solve(i+1,n,nums,v,ans);

        v.pop_back();
        solve(i+1,n,nums,v,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> v;

        solve(0,n,nums,v,ans);
        return ans;
    }
};