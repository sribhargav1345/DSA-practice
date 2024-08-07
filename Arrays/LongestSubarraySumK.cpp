#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lenOfLongSubarr(int arr[],  int n, int k) 
{ 
    int sum = 0;

    map<int,int> mp;
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        
        if(sum == k) ans = max(ans,i+1);
        
        if(mp.find(sum)==mp.end()) mp[sum] = i;

        if(mp.find(sum-k) != mp.end())
        {
            ans = max(ans,i-mp[sum-k]);
        }
    }
    return ans;
} 

// No. of subarrays, whose sum is k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Prefixmap concept?

        int n = nums.size();
        map<int,vector<int>> mp;

        int ans = 0;

        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            if(sum == k) ans += 1;

            if(mp.find(sum-k) != mp.end())
            {
                ans += mp[sum - k].size();
            }

            mp[sum].push_back(i);
        }
        return ans;

    }
};