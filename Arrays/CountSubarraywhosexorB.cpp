int Solution::solve(vector<int> &a, int B) {
    int n = a.size();
    int xr = 0;
    
    map<int,int> mp;
    mp[xr]++;
    
    int ct = 0;
    
    for(int i=0;i<n;i++)
    {
        xr = xr ^ a[i];
        
        // if(xr == B){
        //     ct++;
        // }
        
        if(mp.find(xr^B) != mp.end()) ct += mp[xr^B];
        mp[xr] += 1;
    }
    return ct;
};