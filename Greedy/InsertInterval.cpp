#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& v) {

        int n = nums.size();

        vector<vector<int>> ans;
        int k;

        for(int i=0;i<n;i++)
        {
            if(v[0]>nums[i][1]) ans.push_back(nums[i]);
            else if(v[1]<nums[i][0]) 
            {
                k = i;
                break;
            }
            else 
            {
                v[0]=min(v[0],nums[i][0]);
                v[1]=max(v[1],nums[i][1]);
            }
        }
        ans.push_back(v);

        while(k<n){
            ans.push_back(nums[k]);
            k++;
        }

        return ans;
        
    }
};