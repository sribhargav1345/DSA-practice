#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    static bool compare(pair<int,int>&a, pair<int,int>& b)
    {
        return (a.second<b.second);
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),compare);
        
        int ct = 1;
        int prev = v[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(prev<v[i].first)
            {
                prev = v[i].second;
                ct++;
            }
        }
        return ct;
    }
};