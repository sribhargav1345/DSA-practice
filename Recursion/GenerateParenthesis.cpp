#include<bits/stdc++.h>
using namespace std;

// Just have to think, the approach to do
class Solution {
public:
    void solve(vector<string>& v,string s,int open,int close,int n){
        if(open == n && close == n){
            v.push_back(s);
            return;
        }

        if(open == close){
            string op = s;
            op += '(';
            solve(v,op,open+1,close,n);
        }        
        else if(open == n){
            string op = s;
            op += ')';
            solve(v,op,open,close+1,n);
        }
        else if(close == n){
            string op = s;
            op += '(';
            solve(v,op,open+1,close,n);
        }
        else
        {
            string op1 = s;
            string op2 = s;

            op1 += '(';
            solve(v,op1,open+1,close,n);

            op2 += ')';
            solve(v,op2,open,close+1,n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;

        string ans = "";

        solve(v,ans,0,0,n);       // ct for count of parenthesis

        return v;
    }
};