class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();

        string p = "";
        stack<string> st;

        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ') p += s[i];
            else 
            {
                if(p!="") st.push(p);
                p = "";
            }
        } 
        if(p!="") st.push(p);

        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            if(st.size()!=1) ans += " ";

            st.pop();
        }
        return ans;
    }
};