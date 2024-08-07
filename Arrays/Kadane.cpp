#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Max Sum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {   
            sum += nums[i];
            maxi = max(sum,maxi);

            if(sum<0) sum = 0;
        }
        return maxi;
    }
};

// Print subarray with max Sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int maxi = INT_MIN;

        int start_idx = 0;
        int end_index = 0;

        for(int i=0;i<n;i++)
        {   
            if(sum == 0) start_idx = i;

            sum += nums[i];
            if(maxi<=sum)
            {
                maxi = sum;
                end_index = i;
            }

            if(sum<0) sum = 0;
        }
        return maxi;
    }
};

// Max Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Extension of Kadane's Algorithm
        int n = nums.size();
        
        int ans = 1;
        int maxi = nums[0];

        for(int i=0;i<n;i++)
        {
            ans *= nums[i];
            maxi = max(maxi,ans);

            if(ans==0) ans = 1;
        }

        ans = 1;
        for(int i=n-1;i>=0;i--)
        {
            ans *= nums[i];
            maxi = max(maxi,ans);

            if(ans==0) ans = 1;
        }

        return maxi;
    }
};