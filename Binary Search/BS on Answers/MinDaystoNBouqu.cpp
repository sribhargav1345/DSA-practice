#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isP(vector<int>& bloom,int mid,int m,int k,int n){
        int ans = 0;
        int ct = 0;
        for(int i=0;i<n;i++)
        {
            if(bloom[i]<=mid)
            {
                ct++;
            }
            else
            {
                ct = 0;
            }

            if(ct==k)
            {
                ans++;
                ct = 0;
            }
        }
        if(ans>=m)
        {
            return true;
        }
        return false;
    }

    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();

        for(int i=1;i<=k;i++)
        {
            if(m*i>n) return -1;
        }

        int low = 1;
        int high = 0;
        
        for(int i=0;i<n;i++)
        {
            high = max(high,bloom[i]);      // U cannot simply sort, needed k adjacent
        }

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(isP(bloom,mid,m,k,n))
            {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};