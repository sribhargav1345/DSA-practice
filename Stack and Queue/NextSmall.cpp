#include<bits/stdc++.h>
using namespace std;

// For next smaller, stack should be increasing from bottom to top
vector<int> prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> st;
    
    vector<int> ans;
    ans.push_back(-1);
    st.push(A[0]);
    
    for(int i=1;i<n;i++)
    {
        while(!st.empty() && st.top()>=A[i])
        {
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        
        st.push(A[i]);
    }
    
    return ans;
}
