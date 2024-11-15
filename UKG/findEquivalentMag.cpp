#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long int

const int MOD = 1e9 + 7;

void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& ans)
{
    for(auto& [child, weight] : adj[node])
    {
        ans[child] = (ans[node] * weight) % MOD;
        dfs(child, adj, ans);
    }
}

vector<int> findEquivalentMagnitude(int unit_nodes, vector<int> unit_from, vector<int> unit_to, vector<int> unit_weight, int x)
{
    vector<vector<pair<int,int>>> adj(unit_nodes + 1);
    int n = unit_from.size();

    for(int i = 0; i < n; i++)
    {
        adj[unit_from[i]].push_back({unit_to[i], unit_weight[i]});
    }

    vector<int> ans(unit_nodes + 1, 0);
    ans[1] = x;

    dfs(1, adj, ans); 
    return ans;
}

signed main()
{
    int n;
    cin >> n;

    n -= 1;

    vector<ll> arr;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    
    vector<ll> brr;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        brr.push_back(x);
    }
    
    vector<ll> crr;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        crr.push_back(x);
    }
    
    int x;
    cin >> x;

    vector<int> result = findEquivalentMagnitude(n + 1, arr, brr, crr, x);
    for(int i = 1; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
