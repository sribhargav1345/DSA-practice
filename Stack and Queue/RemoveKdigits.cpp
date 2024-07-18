#include<bits/stdc++.h>
using namespace std;

// Think twice
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        // Here the thing is, u have to return (n-k) continuous small number present in nums, as a string
        string ans = "";

        stack<char> st;
        int flag = 0,ct = 0;

        for(int i=0;i<n;i++)
        {
            if(flag == 1)
            {
                st.push(num[i]);
                continue;
            }
            if(st.empty() || st.top()<num[i])
            {
                st.push(num[i]);
            }
            else
            {
                while(!st.empty() && st.top()>num[i])
                {
                    ct++;
                    st.pop();

                    if(ct == k)
                    {
                        flag = 1;
                        st.push(num[i]);
                        break;
                    }
                }
                if(flag == 0) st.push(num[i]);
            }
        }

        while(!st.empty() && ct<k)
        {
            ct++;
            st.pop();
        }

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        string op = "";

        flag = 0;

        for(int i=0;i<ans.size();i++)
        {
            if(flag == 1)
            {
                op += ans[i];
                continue;
            }

            if(ans[i]=='0') 
            {
                continue;
            }
            else
            {
                flag = 1;
                op += ans[i];
            }
        }

        if(op=="") op += '0';
        return op;
    }
};