#include<bits/stdc++.h>
using namespace std;

class ST{
    vector<int> seg,lazy;

public:
    ST(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int ind,int low,int high,vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void update(int ind,int low,int high,int l,int r,vector<int>& arr){
        // l,r indexes where u r updating

        // Update prev remaining updates and propagate downwards
        if(lazy[ind] != 0){
            seg[ind] = (high-low+1) - seg[ind];

            // propagating lazy update downwards for remaining elements
            if(low != high){
                lazy[2*ind+1] = !lazy[2*ind+1];
                lazy[2*ind+2] = !lazy[2*ind+2];
            }

            lazy[ind] = 0;
        }

        // No overlap
        if(high < l || low > r){
            return;
        }

        // Complete overlap
        if(low >= l && high <= r){
            seg[ind] = (high-low+1) - seg[ind];
            
            // If a leaf node, it will have children
            if(low != high){
                lazy[2*ind+1] = !lazy[2*ind+1];
                lazy[2*ind+2] = !lazy[2*ind+2];
            }
            return;
        }

        // Partial
        int mid = (low+high)/2;
        update(2*ind+1,low,mid,l,r);
        update(2*ind+2,mid+1,high,l,r);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2]; 

    }

    int query(int ind,int low,int high,int l,int r){

        // Update if any updates are remaining, as node will stay fresh
        if(lazy[ind] != 0){
            seg[ind] = (high-low+1) - seg[ind];

            // propagating lazy update downwards for remaining elements
            if(low != high){
                lazy[2*ind+1] = !lazy[2*ind+1];
                lazy[2*ind+2] = !lazy[2*ind+2];
            }

            lazy[ind] = 0;
        }

        // NO overlap
        if(high<l || low>r){
            return 0;
        }

        // Complete overlap
        if(low>=l && high <=r) return seg[ind];

        int mid = (low+high)/2;

        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);

        return left+right;
    }
};
 
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    ST seg(n);
    seg.build(0,0,n-1,arr);

    int q;
    cin>>q;

    while(q--){
        int type;
        cin>>type;

        if(type == 1){
            int l,r;
            cin>>l>>r;

            cout<<st.query(0,0,n-1,l,r)<<endl;
        }
        else
        {
            int l,r,val;
            cin>>l>>r>>val;

            st.update(0,0,n-1,l,r);
        }
    }
}