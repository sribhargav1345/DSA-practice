#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Sort acc to 1st value only, think
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());
        vector<int> v = intervals[0];
        int prev = v[1];

        for(int i=1;i<n;i++)
        {
            if(prev >= intervals[i][0])
            {
                v[1] = max(intervals[i][1],prev);
                prev = v[1];
            }
            else
            {
                ans.push_back(v);
                v = intervals[i];
                prev = v[1];
            }
        }
        ans.push_back(v);

        return ans;
    }
};