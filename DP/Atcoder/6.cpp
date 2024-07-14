// LCS, striver question
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(string text1,string text2,vector<vector<int>>& dp)
{
    int m = text1.size();
    int n = text2.size();

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

string solve2(string s,string p,vector<vector<int>>& dp)
{
    int n = s.size();
    int m = p.size();

    int lcs = solve(s,p,dp);

    string ans = "";
    for(int i=0;i<lcs;i++)
    {
        ans += '$';
    }

    int ind = 0;
    int i = 0,j = 0;
    while(j<m && i<n)
    {
        if(s[i]==p[j])
        {
            ans[ind] = s[i];
            i++;
            j++;

            ind++;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i++;
        else j++;
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;

    string p;
    cin>>p;

    int m = s.size();
    int n = p.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    cout<<solve2(s,p,dp)<<endl;
}