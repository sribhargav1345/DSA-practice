#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // normal sliding window sum
        // 0's count is important here

        int n = nums.size();

        int ct = 0;
        int sum = 0;

        int i = 0;
        int j = 0;

        while(j<n) 
        {
            sum += nums[j];

            while(i<j && sum>goal) 
            {
                sum -= nums[i];
                i++;
            }

            if(sum == goal) 
            {
                ct++;

                int temp = i;
                while(temp<j && nums[temp] == 0) 
                {
                    ct++;
                    temp++;
                }
            }

            j++;
        }

        return ct;
    }
};