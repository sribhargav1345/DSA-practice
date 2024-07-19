#include<bits/stdc++.h>
using namespace std;

// It can go from lower bound to upper bound
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

        cout<<lb<<" "<<ub<<endl;

        if(lb>=n) return n;  
        if(ub<=0) return 0;

        return (ub-lb+1); 
    }
};