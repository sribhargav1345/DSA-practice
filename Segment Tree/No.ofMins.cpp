#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class SGTree{
public:
    vector<pair<int,int>> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }

    void build(int ind,int low,int high,vector<int>& arr){
        if(low==high){
            seg[ind].first = arr[low];
            seg[ind].second = 1;
            return;
        }

        int mid = (low+high)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        if(seg[2*ind+1].first < seg[2*ind+2].first){
            seg[ind].first = seg[2*ind+1].first;
            seg[ind].second = seg[2*ind+1].second;
        }
        else if(seg[2*ind+1].first > seg[2*ind+2].first){
            seg[ind].first = seg[2*ind+2].first;
            seg[ind].second = seg[2*ind+2].second;
        }
        else{
            seg[ind].first = seg[2*ind+1].first;
            seg[ind].second = seg[2*ind+1].second + seg[2*ind+2].second;
        }
    }

    pair<int,int> query(int ind,int low,int high,int l,int r){

        // Case of No overlap
        if(low>r || high<l){
            return {INT_MAX,-1};
        }

        // Case of complete overlap
        if(low>=l && high<=r){
            return seg[ind];
        }

        int mid = (low+high)/2;

        pair<int,int> left = query(2*ind+1,low,mid,l,r);
        pair<int,int> right = query(2*ind+2,mid+1,high,l,r);

        pair<int,int> q;

        if(left.first < right.first){
            q = q1;
        }
        else if(left.first > right.first){
            q = q2;
        }
        else{
            q.first = left.first;
            q.second = q1.second + q2.second;
        }

        return q;
    }

    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind].first = val;
            seg[ind].second = 1;
            return;
        }

        int mid = (low+high)/2;
        
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);

        if(seg[2*ind+1].first < seg[2*ind+2].first){
            seg[ind].first = seg[2*ind+1].first;
            seg[ind].second = seg[2*ind+1].second;
        }
        else if(seg[2*ind+1].first > seg[2*ind+2].first){
            seg[ind].first = seg[2*ind+2].first;
            seg[ind].second = seg[2*ind+2].second;
        }
        else{
            seg[ind].first = seg[2*ind+1].first;
            seg[ind].second = seg[2*ind+1].second + seg[2*ind+2].second;
        }
    }
};

// Use like this
// SGTree sg1(n);
// sg1.build(0,0,n-1,v);