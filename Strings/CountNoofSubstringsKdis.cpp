class Solution
{
  public:
    long long int solve(string s,int k){
        int n = s.size();
        int i = 0,j = 0;
        
        map<int,int> mp;
        int cnt = 0;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
    
    long long int substrCount (string s, int k) {
    	//code here.
    	int n = s.size();
    	if(k == 1){
    	    return solve(s,k);
    	}
    	return solve(s,k)-solve(s,k-1); // atmost k distinct chars
    }
};