#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Trying in Binary search approach -> More optimised than xor

        // The approach is simple. If the mid element is odd index(0-index), then if(nums[i]==nums[i-1]) target is on right
        int n = nums.size();
        if(n==1) return nums[0];

        int low = 0;
        int high = n-1;

        while(low<high)
        {
            int mid = (low+high)/2;
            //cout<<mid<<endl;

            if(mid%2==0)
            {
                if(nums[mid]==nums[mid-1])
                {
                    high = mid-2;
                }
                else if(nums[mid]==nums[mid+1])
                {
                    low = mid+2;
                }
                else return nums[mid];
            }
            else
            {
                if(nums[mid]==nums[mid+1])
                {
                    high = mid-1;
                }
                else if(nums[mid]==nums[mid-1])
                {
                    low = mid+1;
                }
                else return nums[mid];
            }
        }
        return nums[high];
    }
};