#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        map<char,int> mp;

        for(auto x:tasks)
        {
            mp[x]++;
        }

        int k = tasks.size();
        vector<int> v(26,0);

        unordered_set<int> st;

        priority_queue<pair<int,int>> pq;
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }

        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();

            v[itr.second-'A'] += (n+1);
            while(st.find(v[itr.second - 'A'])!=st.end())
            {
                v[itr.second-'A'] += 1;
            }

            st.insert(v[itr.second-'A']);

            itr.first -= 1;

            if(itr.first>0)
            {
                pq.push(itr);
            }
        }

        int maxi = 0;

        for(int i=0;i<26;i++)
        {
            maxi = max(maxi,v[i]);
        }
        return maxi-(n);
   }
};