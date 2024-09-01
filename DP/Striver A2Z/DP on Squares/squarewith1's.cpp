class Solution {
public:
    // int solve(int n){
    //     int k = n*(n+1);
    //     return (k/2);
    // }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1]==1)
                {
                    dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //cout<<dp[i][j]<<" ";
                ans += (dp[i][j]);
            }
            //cout<<endl;
        }
        return ans;
    }
};