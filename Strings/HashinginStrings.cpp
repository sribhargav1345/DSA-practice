#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Maybe there is a better way to solve this
class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n = text.size();
        int m = pat.size();
        
        for(int i=0;i<n-m+1;i++)
        {
            string p = text.substr(i,m);
            if(p == pat) return i;
        }
        return -1;
    }
};