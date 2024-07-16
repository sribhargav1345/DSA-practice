#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n = nums.size();
        if(k<0) return 0;

        int i = 0,j = 0,odd = 0,cnt = 0;
        while(j<n)
        {
            if(nums[j]%2) odd++;
            while(odd>k)
            {
                if(nums[i]%2) odd--;
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // same as the problem of Binary Subarray with sum
        return (solve(nums,k) - solve(nums,k-1));
    }
};