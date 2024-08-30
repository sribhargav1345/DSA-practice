class Solution {
public:
    void solve(string s,int id,int n,vector<string>& ans,vector<string>& v,string p){
        if(id==n){
            ans.push_back(p);
            return;
        }

        char index = s[id];
        int l = index - '0';

        for(int i=0;i<v[l].size();i++){
            p += v[l][i];
            solve(s,id+1,n,ans,v,p);
            p.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();

        if(digits.empty()) return ans;

        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string p;

        solve(digits,0,n,ans,pad,p);
        return ans;
    }
};