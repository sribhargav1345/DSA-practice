#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll max_val;
    node(){
        max_val = 0;
    }
};

node merge(node a,node b){
    node ans;
    ans.max_val = max(a.max_val, b.max_val);

    return ans;
}

node seg[4*200200];

void build(ll id,ll low,ll high,vector<ll>& arr){     // Id of node, responsibile for tree from index low to high

    if(low==high){    // Leaf node
        seg[id].max_val = arr[low];
        return;
    }

    ll mid = (low+high)/2;

    build(2*id+1,low,mid,arr);
    build(2*id+2,mid+1,high,arr);

    seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}

void update(ll id,ll low,ll high,ll pos,ll val){

    if(pos<low || pos>high){
        return;
    }

    if(low==high){
        seg[id].max_val -= val;
        return;
    }

    ll mid = (low+high)/2;

    update(2*id+1,low,mid,pos,val);
    update(2*id+2,mid+1,high,pos,val);

    seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}

int query(ll id,ll low,ll high,ll p){  

    if(seg[id].max_val < p) return -1;
    if(low == high) return low;

    int mid = (low+high)/2;

    if(seg[2*id+1].max_val >= p){
        return query(2*id+1,low,mid,p);
    }
    else{
        return query(2*id+2,mid+1,high,p);
    }
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

    build(0,0,n-1,arr);
    
    while(q--){
        ll p;
        cin>>p;

        ll index = query(0,0,n-1,p);
        if(index != -1){
            cout<<index+1<<" ";         // Have to print 1-based index
            update(0,0,n-1,index,p);
        }
        else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
}