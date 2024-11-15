#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void findMaxMatrixSize(vector<vector<ll>>& arr, int p)
{
    ll n = arr.size();
    ll m = arr[0].size();
 
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            dp[i][j] = arr[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    ll ans = 0;
 
    for(ll i=1;i<=n;i++) 
    {
        for(ll j=1;j<=m;j++) 
        {
            ll op = dp[i][j];

            if(op<=p){
                ans = max(ans,i*j);
            }
            else
            {
                for(ll k=1;k<=i;k++)
                {
                    for(ll l=1;l<=j;l++)
                    {
                        if(op-dp[k][l]<=p)
                        {
                            ans = max(ans,(i-k)*(j-l));
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
 
// Driver Code
int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        vector<vector<ll>> arr(n,vector<ll>(m,0));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
    
        findMaxMatrixSize(arr,k);
    }   
    return 0;
}