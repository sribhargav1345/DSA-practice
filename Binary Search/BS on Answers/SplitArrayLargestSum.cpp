#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums,int n,int mid){
        int sum = 0;
        int ct = 1;
        for(int i=0;i<n;i++)
        {
            if(sum+nums[i]>mid){
                ct++;
                sum = nums[i];
            }
            else sum += nums[i];
        }
        return ct;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Hard tag seems easier at this point
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(f(nums,n,mid)>k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};