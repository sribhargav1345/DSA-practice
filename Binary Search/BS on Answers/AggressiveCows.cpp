#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int f(vector<int>& stalls,int mid,int k){
        int n = stalls.size();
        
        int prev = stalls[0];
        int ct = 1;
        
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-prev >= mid) 
            {
                ct++;
                prev = stalls[i];
            }
        }
        if(ct>=k) return true;
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(),stalls.end());
        
        int low = INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            low = min(low,stalls[i+1]-stalls[i]);
        }
        
        int high = stalls[n-1]-stalls[0];
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(f(stalls,mid,k)) low = mid+1;
            else high = mid-1;
        }
        return high;
    }
};