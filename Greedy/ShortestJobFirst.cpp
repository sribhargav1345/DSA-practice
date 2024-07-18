#include<bits/stdc++.h>
using namespace std;

// Just thinking that's all
class Solution {
  public:
    long long solve(vector<int>& bt) {

        int n = bt.size();
        sort(bt.begin(),bt.end());
        
        vector<int> prefix(n,0);
        prefix[0] = bt[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + bt[i];
        }
        
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += (prefix[i]-bt[i]);
        }
        //cout<<sum<<endl;
        sum/= n;
        
        return sum;
    }
};