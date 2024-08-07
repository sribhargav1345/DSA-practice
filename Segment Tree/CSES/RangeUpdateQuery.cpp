#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll sum;
    node(){
        sum = 0;
    }
};

node merge(node a,node b){
    node ans;
    ans.sum = a.sum + b.sum;

    return ans;
}

node seg[4*200200];

void build(ll id,ll low,ll high){     // Id of node, responsibile for tree from index low to high

    if(low==high){    // Leaf node
        seg[id].sum = 0;
        return;
    }

    ll mid = (low+high)/2;

    build(2*id+1,low,mid);
    build(2*id+2,mid+1,high);

    seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}

void update(ll id,ll low,ll high,ll pos,ll val){

    if(pos<low || pos>high){
        return;
    }

    if(low==high){
        seg[id].sum += val;
        return;
    }

    ll mid = (low+high)/2;

    update(2*id+1,low,mid,pos,val);
    update(2*id+2,mid+1,high,pos,val);

    seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}

node query(ll id,ll low,ll high,ll l,ll r){             // Have to perform query between l to r
    if(l>high || r<low){                        // No overlap case
        return node();
    }

    if(l<=low && high<=r){                      // Complete overlap case
        return seg[id];
    }

    ll mid = (low+high)/2;

    node a = query(2*id+1,low,mid,l,r);
    node b = query(2*id+2,mid+1,high,l,r);

    return merge(a,b);
}


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

    build(0,0,n-1);
    
    while(q--){
        ll type;
        cin>>type;

        if(type == 1){
            ll a,b,u;
            cin>>a>>b>>u;

            a--;
            b--;

            // Have to update sum values from a to b with (+u)
            update(0,0,n-1,a,u);
            update(0,0,n-1,b+1,-u);
        }
        else{
            ll k;
            cin>>k;

            k--;
            node ans = query(0,0,n-1,0,k);
            cout<<ans.sum+arr[k]<<endl;
        }
    }
}