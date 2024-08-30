#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    void solve(vector<int>& candidates, int id, int n, int sum,int target,vector<vector<int>>& ans,vector<int>& v){
    
        if(sum == target){
            ans.push_back(v);
            return;
        }

        if(id<n && candidates[id] + sum <= target)
        {
            v.push_back(candidates[id]);
            solve(candidates,id,n,sum+candidates[id],target,ans,v);
            v.pop_back();
        }
        if(id+1<n) solve(candidates,id+1,n,sum,target,ans,v);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        int n = candidates.size();

        solve(candidates,0,n,0,target,ans,v);
        return ans;
    }
};