#include<bits/stdc++.h>
using namespace std;

// Infix To PostFix conversion
class Solution {
  public:
    int priority(char c) {
        if (c == '+' || c == '-') {
            return 1;
        }
        if (c == '*' || c == '/') {
            return 2;
        }
        if (c == '^') {
            return 3;
        }
        return 0;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        int n = s.size();
        
        stack<char> st;
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
            if((s[i]>='A' && s[i] <= 'Z') || (s[i]>='a' && s[i] <= 'z') || (s[i]>='0' && s[i] <= '9'))
            {
                ans += s[i];
            }
            else
            {
                if(s[i]=='(') st.push(s[i]);
                else if(s[i]==')')
                {
                    while(!st.empty() && st.top() != '(')
                    {
                        ans += st.top();
                        st.pop();
                    }
                    if (!st.empty()) {
                        st.pop(); 
                    }
                }
                else
                {
                    while (!st.empty() && priority(st.top()) >= priority(s[i])) {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};

// For Infix to Prefix
/*
    1. Reverse the Infix
    2. Do Infix to Prefix
    3. Reverse the answer
*/

