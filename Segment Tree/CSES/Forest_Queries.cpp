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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;

    vector<vector<ll>> v;
    for(int i=0;i<n;i++)
    {
        vector<ll> arr;
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;

            if(c == '*') arr.push_back(1);
            else arr.push_back(0);
        }
        v.push_back(arr);
    }

    build(0,0,n-1);
}