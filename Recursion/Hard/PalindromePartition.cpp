class Solution {
public:
    bool isPali(string s){
        int n = s.size();
        for(int i=0;i<(n/2);i++)
        {
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }

    void solve(string s,int id,int n,vector<vector<string>>& ans,vector<string>& v){
        // Starting from that index,how many palindromes can u form
        if(id==n){
            ans.push_back(v);
            return;
        }

        for(int j=id;j<n;j++)
        {
            string p = s.substr(id,j-id+1);
            if(isPali(p)){
                v.push_back(p);
                solve(s,j+1,n,ans,v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> v;

        solve(s,0,n,ans,v);
        return ans;
    }
};