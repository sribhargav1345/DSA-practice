#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        // Everytime, we have to check, the left-most greatest and rightmost greatest, and take (min of those-that element)
        vector<int> right;

        int maxi = 0;

        for(int i=n-1;i>=0;i--)
        {
            maxi = max(maxi,height[i]);
            right.push_back(maxi);
        }
        reverse(right.begin(),right.end());

        // cout<<left.size()<<right.size()<<endl;

        int ans = 0;
        int ct = 0;

        for(int i=0;i<n;i++)
        {
            ct = max(height[i],ct);
            if(min(ct,right[i])-height[i] > 0) ans += min(ct,right[i])-height[i];
        }
        return ans;
    }
};