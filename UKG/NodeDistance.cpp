#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<pair<int,int>>>& adj,int x,vector<int>& v)
{
    for(auto& [node,weight]: adj[x]){
        if(v[node] == -1){
            v[node] = v[x] + weight;
            dfs(adj,node,v);
        }
    }
}

int solve(int n,vector<int>& from,vector<int>& to,vector<int>& weights,ll x,ll y,ll z)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        adj[from[i]].push_back({to[i],weights[i]});
        adj[to[i]].push_back({from[i],weights[i]});
    }

    vector<int> v(n+1,-1);   // This denotes the distance from 1st node
    v[1] = 0;

    dfs(adj,1,v);
    int mini = INT_MAX;

    for(int i=0;i<n;i++)
    {
        int p = v[i];
        mini = min(mini,abs(p-v[x])+abs(p-v[y])+abs(p-v[z]));
    }
    return mini;
}

int main()
{
    ll n;
    cin>>n;

    vector<int> from;
    vector<int> to;
    vector<int> weights;

    for(int i=0;i<n-1;i++)
    {
        ll x;
        cin>>x;

        from.push_back(x);
    }

    for(int i=0;i<n-1;i++)
    {
        ll x;
        cin>>x;

        to.push_back(x);
    }

    for(int i=0;i<n-1;i++)
    {
        ll x;
        cin>>x;

        weights.push_back(x);
    }

    ll x,y,z;
    cin>>x>>y>>z;

    cout<<solve(n,from,to,weights,x,y,z)<<endl;
}