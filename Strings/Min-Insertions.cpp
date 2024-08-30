class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ct = 0;
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') 
            {
                if(ct<0)
                {
                    ans -= ct;
                    ct = 0;
                }
                ct++;
            }
            else ct--;
        }

        return abs(ans) + abs(ct);
    }
};