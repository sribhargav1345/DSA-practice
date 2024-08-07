#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class SGTree{
public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }

    void build(int ind,int low,int high,vector<int>& arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    // What will be the query? Think about that first. We have to find index with sum == need
    int query(int ind,int low,int high,int need){
        if(low == high){
            return low;
        }
        
        int mid = (low+high)/2;

        if(need<seg[2*ind+1]){
            return query(2*ind+1,low,mid,need);
        }
        else{
            return query(2*ind+2,mid,high,need-seg[2*ind+1]);
        }
    }

    void update(int ind,int low,int high,int pos,vector<int>& arr){
        if(low==high){
            arr[low] = arr[low]^1;
            seg[ind] = arr[low];

            return;
        }

        int mid = (low+high)/2;
        
        if(pos<=mid) update(2*ind+1,low,mid,pos,arr);
        else update(2*ind+2,mid+1,high,pos,arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
};

// Use like this
// SGTree sg1(n);
// sg1.build(0,0,n-1,v);

int main(){
    ll n,q;
    cin>>n>>q;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }

    SGTree seg(n);
    seg.build(0,0,n-1,arr);

    while(q--){
        ll type;
        cin>>type;

        if(type == 1){
            int pos;
            cin>>pos;

            seg.update(0,0,n-1,pos,arr);
        }
        else{
            int need;
            cin>>need;

            ll ans = seg.query(0,0,n-1,need+1);
            cout<<ans<<endl;
        }
    }
}