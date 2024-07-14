#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        // This can be done using sliding window, assuming we can turn k 0's atmost
        int i = 0,j = 0;
        int maxi = 0;

        map<int,int> mp;
        while(j<n)
        {
            if(nums[j]==0)
            {
                mp[0]++;
                if(mp[0]>k)
                {
                    while(mp[0]>k)
                    {
                        mp[nums[i]]--;
                        i++;
                    }
                }
            }
            else
            {
                mp[1]++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};