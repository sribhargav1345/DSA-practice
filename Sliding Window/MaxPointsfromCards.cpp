#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        // Nice question with sliding window idea, we have to minimise the sum of 
        // the window of size (n-k)

        //if(k>n) return 

        int n = card.size();
        int req = n-k;

        int i=0,j=0;

        int sum = 0;
        int mini = INT_MAX;

        int ans = 0;

        for(int i=0;i<n;i++) ans += card[i];

        if(k==n) return ans;

        while(j<n)
        {
            if(j-i+1<req)
            {
                sum += card[j];
                j++;
            } 
            else
            {
                sum += card[j];

                mini = min(mini,sum);
                sum -= card[i];

                i++;
                j++;
            }
        }
        return (ans-mini);
    }
};