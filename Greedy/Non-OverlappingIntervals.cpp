#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Have to sort acc to end times, u may miss
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int m = 2;

        sort(intervals.begin(),intervals.end(),compare);

        int prev = intervals[0][1];
        int ct = 1;

        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=prev) 
            {
                ct++;
                prev = intervals[i][1];
            }
        }
        return (n-ct);
    }
};