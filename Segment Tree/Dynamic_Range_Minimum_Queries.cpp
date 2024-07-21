#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class SGTree{
public:
    vector<ll> seg;
    SGTree(ll n){
        seg.resize(4*n+1);
    }

    void build(ll ind,ll low,ll high,vector<ll>& arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        ll mid = (low+high)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }

    ll query(ll ind,ll low,ll high,ll l,ll r){

        // Case of No overlap
        if(low>r || high<l){
            return INT_MAX;
        }

        // Case of complete overlap
        if(low>=l && high<=r){
            return seg[ind];
        }

        ll mid = (low+high)/2;

        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);

        return min(left,right);
    }

    void update(ll ind,ll low,ll high,ll i,ll val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        ll mid = (low+high)/2;
        
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);

        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
};

// Use like this
// SGTree sg1(n);
// sg1.build(0,0,n-1,v);

int main(){
    ll n,q;
    cin>>n>>q;

    vector<ll> arr;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }

    SGTree seg(n);
    seg.build(0,0,n-1,arr);
    
    for(ll i=0;i<q;i++)
    {
        ll type,l,r;
        cin>>type>>l>>r;

        if(type == 1){
            seg.update(0,0,n-1,l-1,r);
            continue;
        }

        cout<<seg.query(0,0,n-1,l-1,r-1)<<endl;
    }
}