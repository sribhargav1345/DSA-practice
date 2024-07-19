#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums,int n,int mid){
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += ceil(float(nums[i])/mid);
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,nums[i]);
        }
        // Max number will be maxi, so high = maxi;

        int low = 1,high = maxi;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(f(nums,n,mid)<=threshold)
            {
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};