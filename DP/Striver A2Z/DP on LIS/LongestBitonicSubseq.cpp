#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        
        vector<int> dp(n+1,1);      // For longest increasing subseq
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(nums[i-1]>nums[j-1])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        
        vector<int> nums2 = nums;
        reverse(nums.begin(),nums.end());
        
        vector<int> dp2(n+1,1);     // For longest increasing subseq from reverse
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(nums[i-1]>nums[j-1])
                {
                    dp2[n-i+1] = max(dp2[n-i+1],dp2[n-j+1]+1);
                }
            }
        }
        
        int maxi = 1;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]>1 && dp2[i]>1)
            {
                maxi = max(dp[i]+dp2[i],maxi);   
            }
        }
        return maxi - 1;
    }
};