#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    void merge(vector<pair<int,int>>& nums,int low,int mid,int high,vector<int>& ans){

        vector<pair<int,int>> temp;

        int left = low;
        int right = mid+1;

        int ct = 0;

        while(left<=mid && right<=high)
        {
            if(nums[left].first<=nums[right].first) 
            {
                temp.push_back(nums[left]);
                ans[nums[left].second] += ct;

                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                ct++;
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            ans[nums[left].second] += ct;
            left++;
        }

        while(right<=high){
            temp.push_back(nums[right]);
            right++;        
            // ct++;       // There is no left to add this so no needed
        }

        for(int i=low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }
    }

    void mergeSort(vector<pair<int,int>>& nums,int low,int high,vector<int>& ans){
        if(low >= high) return;

        int mid = (low+high)/2;

        mergeSort(nums,low,mid,ans);
        mergeSort(nums,mid+1,high,ans);

        merge(nums,low,mid,high,ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
        {
            a.push_back({nums[i],i});
        }

        vector<int> ans(n);
        mergeSort(a,0,n-1,ans);

        return ans;
    }
};