#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class SGTree{
public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }

    int solve(int a,int b){
        return 2*a + b;
    }

    void build(int ind,int low,int high,vector<ll>& arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = solve(seg[2*ind+1], seg[2*ind+2]);
    }

    int query(int ind,int low,int high,int l,int r){

        // Case of No overlap
        if(low>r || high<l){
            return 0;
        }

        // Case of complete overlap
        if(low>=l && high<=r){
            return seg[ind];
        }

        int mid = (low+high)/2;

        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);

        return solve(left,right);
    }

    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)/2;
        
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);

        seg[ind] = solve(seg[2*ind+1],seg[2*ind+2]);
    }
};

// Use like this
// SGTree sg1(n);
// sg1.build(0,0,n-1,v);

int main(){

    int t;
    cin>>t;

    int n,q;
    cin>>n>>q;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }

    vector<vector<int>> queries;
    for(int i=0;i<q;i++)
    {
        vector<int> v;

        int a,b,c;
        cin>>a>>b>>c;

        v.push_back(a);
        v.push_back(b);
        v.push_back(c);

        queries.push_back(v);
    }
    
    SGTree sg1(n);
    sg1.build(0,0,n-1,arr);

    vector<ll> op;

    for(int i=0;i<q;i++)
    {
        if(queries[i][0]==1)
        {
            sg1.update(0,0,n-1,queries[i][1]-1,queries[i][2]);
        }    
        else
        {
            int ans = sg1.query(0,0,n-1,queries[i][1]-1,queries[i][2]-1);
            op.push_back(ans);
        }
    }

    for(auto x:op){
        cout<<x<<" ";
    }
    cout<<endl;
}