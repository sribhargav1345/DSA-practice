#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countWays(const string &p, const string &q, const string &r) {
    int n = p.length();
    int m = q.length();
    int l = r.length();

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,0)));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j][0] = 1;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=1;k<=l;k++) 
            {
                if(i>0 && p[i-1] == r[k-1]) {
                    dp[i][j][k] += dp[i-1][j][k-1]; 
                }

                if(j>0 && q[j-1] == r[k-1]){
                    dp[i][j][k] += dp[i][j-1][k-1]; // Take from q
                }
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=1;k<=l;k++) 
            {
                cout<<dp[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            result += dp[i][j][l];
        }
    }

    return result;
}

int main() {
    string p = "abd";
    string q = "bcd";
    string r = "abcd";

    int result = countWays(p, q, r);
    cout << "Number of ways to form string r: " << result << endl;

    return 0;
}
