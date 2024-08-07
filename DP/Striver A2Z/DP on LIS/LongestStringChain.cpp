#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int diff(string& a,string& b){
        if(a.size()-b.size() != 1) return false;

        int n = a.size();
        int m = n-1;

        int i=0,j=0;

        int ct = 0;

        while(i<n)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else 
            {
                ct++;
                i++;
            }
            if(ct>1) return false;
        }
        if(ct!=1) return false;
        return true;
    }

    static bool compare(string& a,string& b){
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // U need to find out that, this is the sequel of Longest Increasing Subsequence
        sort(words.begin(),words.end(),compare);

        vector<int> dp(n+1,1);

        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(diff(words[i-1],words[j-1]))
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++)
        {
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};