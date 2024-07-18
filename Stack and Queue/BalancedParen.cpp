#include<bits/stdc++.h>
using namespace std;

// Just a basic stack
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        if(n%2!=0) return false;
        else{
            stack<char> st;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='[' || s[i]=='{' || s[i]=='(') st.push(s[i]);
                else if(s[i]==']')
                {
                    if(st.empty() || st.top()!='[') return false;
                    else st.pop();
                }
                else if(s[i]=='}')
                {
                    if(st.empty() || st.top()!='{') return false;
                    else st.pop();
                }
                else if(s[i]==')')
                {
                    if(st.empty() || st.top()!='(') return false;
                    else st.pop();
                }
            }
            if(st.empty()==false) return false;
            return true;
        }
         
    }
};