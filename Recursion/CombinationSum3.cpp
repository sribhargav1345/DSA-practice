class Solution {
public:
    void solve(vector<int>& arr,int n,int k,int idx,vector<int>& v,vector<vector<int>>& ans,int sum,int items)
    {
        if(idx == 9){
            if(sum == n && items == k){
                ans.push_back(v);
            }
            return;
        }

        if(items>k){
            return;
        }

        if(arr[idx] + sum <= n){
            v.push_back(arr[idx]);
            solve(arr,n,k,idx+1,v,ans,sum+arr[idx],items+1);
            v.pop_back();
        }
        solve(arr,n,k,idx+1,v,ans,sum,items);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};

        vector<int> v;
        vector<vector<int>> ans;

        solve(arr,n,k,0,v,ans,0,0);
        return ans;
    }
};