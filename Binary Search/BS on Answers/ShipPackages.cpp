#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& weights,int mid,int n){
        int sum = 0;
        int days = 1;
        for(int i=0;i<n;i++)
        {
            if(sum+weights[i]>mid)
            {
                days++;
                sum = weights[i];
            }
            else sum += weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int sum = 0;
        for(auto x:weights) sum += x;

        int low = *max_element(weights.begin(), weights.end());     // Wrong range teesukunte problems vastay choosuko
        int high = sum;             // Taking max to be it's sum

        //cout<<low<<high<<endl;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(f(weights,mid,n)<=days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};