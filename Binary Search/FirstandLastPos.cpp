#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;

        vector<int> v;

        if(lb>=n || lb>ub) 
        {
            v.push_back(-1);
            v.push_back(-1);

            return v;
        }
        v.push_back(lb);
        v.push_back(ub);

        return v;
    }
};