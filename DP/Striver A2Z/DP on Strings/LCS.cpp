#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

void printLCS(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int len = longestCommonSubsequence(s1,s2);

    string ans = "";
    for(int i=0;i<len;i++) ans += '$';

    int index = len - 1;
    int i = n;j = m;

    while(i>=0 && j>=0) 
    {
        if(s1[i-1]==s2[j-1])
        {
            ans[index] = s1[i-1];
            index -= 1;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    cout<<ans<<endl;
}