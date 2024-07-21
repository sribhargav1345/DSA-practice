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

        seg[ind] = (seg[2*ind+1] + seg[2*ind+2]);
    }

    int query(int ind,int low,int high,int a,int b){

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

        return left + right;
    }

    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)/2;
        
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
};

// Use like this
// SGTree sg1(n);
// sg1.build(0,0,n-1,v);

int main(){
    ll n,q;
    cin>>n>>q;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }

    SGTree seg(n);
    seg.build(0,0,n-1,arr);
    
    for(int i=0;i<q;i++)
    {
        char c;
        cin>>c;

        if(c == '?')
        {
            ll k,x;
            cin>>k>>x;

            seg.update(0,0,n-1,k-1,x);
        }
        else
        {
            ll a,b;
            cin>>a>>b;

            cout<<seg.query(0,0,n-1,a,b)<<endl;
        }
    }
}