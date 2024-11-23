class Solution{
public:
    void solve(int idx,int n,vector<string>& ans,string& s,int prev){
        if(idx == n){
            ans.push_back(s);
            return;
        }    
        
        if(prev != 1){
            s.push_back('0');
            solve(idx+1,n,ans,s,0);
            s.pop_back();
            
            s.push_back('1');
            solve(idx+1,n,ans,s,1);
            s.pop_back();
        }
        else
        {
            s.push_back('0');
            solve(idx+1,n,ans,s,0);
            s.pop_back();
        }
        return;
    }
    
    vector<string> generateBinaryStrings(int x){
        //Write your code
        vector<string> ans;
        string s = "";
        
        solve(0,x,ans,s,-1);
        return ans;
    }
};