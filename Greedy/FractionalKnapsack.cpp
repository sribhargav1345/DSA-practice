#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool compare(pair<int,int>& a,pair<int,int>& b)
    {
        double oa = (double)a.first/(double)a.second;
        double ob = (double)b.first/(double)b.second;
        
        return oa>ob;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i].value,arr[i].weight});
        }
        
        sort(v.begin(),v.end(),compare);
        double ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(v[i].second<=w)
            {
                ans += v[i].first;
                w -= v[i].second;
            }
            else
            {
                double kg = (w * v[i].first)/(double)v[i].second;
                ans += kg;
                
                break;
            }
        }
        return ans;
    }
};