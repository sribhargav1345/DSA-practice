class Solution {
public:
    string solve(int id,string ct,int n){

        if(id == n) return ct;

        int p = ct.size();
        char prev = ct[0];

        int op = 1;

        string ans = "";
        for(int i=1;i<p;i++)
        {
            if(ct[i]==prev)
            {
                op++;
            }
            else
            {
                ans += to_string(op);
                ans += prev;

                op = 1;
                prev = ct[i];
            }
        }
        ans += to_string(op);
        ans += prev;

        // cout<<ans<<endl;

        return solve(id+1,ans,n);
    }

    string countAndSay(int n) {
        if(n==1) return "1";
        return solve(1,"1",n);
    }
};