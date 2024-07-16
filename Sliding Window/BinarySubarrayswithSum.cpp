#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n = nums.size();
        int i = 0,j = 0,sum = 0, cnt = 0;

        if(goal<0) return 0;    // Base case is imp in these type

        while(j<n)
        {
            sum += nums[j];
            while(sum>goal)
            {
                sum -= nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // This can be done by any means, but the best way is below
        // Find sum <= goal, and then find sum <= goal-1, subtract 2 from 1, u will get the answer

        return (solve(nums,goal) - solve(nums,goal-1));
    }
};

// 2nd method, better follow above one
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