#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int>& piles, int mid,int h)           // Can it eat before h hours, if it can, then u can decrease the speed, so high = mid-1
    {
        long long ans = 0;
        for(int i=0;i<piles.size();i++)
        {
           ans += ceil(static_cast<double>(piles[i])/mid);
        }

        return (ans<=h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());

        // I have to perform binary search between piles[n-1] and n, until u get desired k
        int low = 1;
        long long high = piles[n-1];          // High is in safe position at starting, so return low at last

        while(low<=high)
        {
            long long mid = (low+high)/2;

            if(f(piles,mid,h)) high = mid-1;     
            else low = mid+1;  
        }
        return low;
    }
};