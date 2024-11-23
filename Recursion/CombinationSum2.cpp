class Solution {
public:
    void solve(int idx, int n, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& take, int sum) {
        if (sum == target) {
            ans.push_back(take);
            return;
        }
        
        for(int i=idx;i<n;i++) 
        {
            if(i>idx && arr[i] == arr[i-1]) continue;

            if(sum+arr[i]>target) break;

            take.push_back(arr[i]);
            solve(i+1,n,arr,target,ans,take,sum+arr[i]);
            take.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> take;

        sort(arr.begin(), arr.end());
        solve(0, arr.size(), arr, target, ans, take, 0);

        return ans;
    }
};
