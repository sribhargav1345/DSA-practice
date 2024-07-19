#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums,int ind,int n,vector<vector<int>>& ans,vector<int>& v){
        
        ans.push_back(v);

        for(int i=ind;i<n;i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;      // For equal elements, dont add to the vector

            v.push_back(nums[i]);
            solve(nums,i+1,n,ans,v);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        int ind = 0;

        solve(nums,ind,n,ans,v);
        return ans;
    }
};