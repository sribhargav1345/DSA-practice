
// Recursive for Word Break
class Solution {
public:
    bool solve(string s,int id,set<string> st,int n){
        if(id==n){
            return true;
        }

        for(int k=id;k<n;k++)
        {
            if(st.find(s.substr(id,k-id+1))!=st.end()){
                if(solve(s,k+1,st,n)) return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& word) {
        int n = s.size();
        set<string> st;

        for(int i=0;i<word.size();i++){
            st.insert(word[i]);
        }

        for(int i=0;i<n;i++)
        {
            string p = s.substr(0,i+1);
            if(st.find(p) != st.end())
            {
                if(solve(s,i+1,st,n)) return true;
            }
        }
        return false;
    }
};


// dp
class Solution {
public:
    bool solve(string s,int id,set<string> st,int n,vector<int>& dp){
        if(id==n){
            return true;
        }

        if(dp[id]!=-1) return dp[id];

        for(int k=id;k<n;k++)
        {
            if(st.find(s.substr(id,k-id+1))!=st.end()){
                if(solve(s,k+1,st,n,dp)) return dp[id] = true;
            }
        }
        return dp[id] = false;
    }

    bool wordBreak(string s, vector<string>& word) {
        int n = s.size();
        set<string> st;

        for(int i=0;i<word.size();i++){
            st.insert(word[i]);
        }

        vector<int> dp(n,-1);

        for(int i=0;i<n;i++)
        {
            string p = s.substr(0,i+1);
            if(st.find(p) != st.end())
            {
                if(solve(s,i+1,st,n,dp)) return true;
            }
        }
        return false;
    }
};