#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(nlogn)
class Solution
{
    public:
    int longestSubsequence(int n, int arr[])
    {
       vector<int> temp;
       temp.push_back(arr[0]);
       
       for(int i=1;i<n;i++)
       {
            if(arr[i]>temp.back())
            {
                temp.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
                temp[ind] = arr[i];
            } 
       }
       
       int k = temp.size();
       return k;
    }
};