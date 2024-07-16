#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        int mod = 100000;
        
        queue<pair<int,int>> pq;
        pq.push({0,start});
        
        vector<int> dist(100000,INT_MAX);
        dist[start] = 0;
        
        while(!pq.empty())
        {
            auto itr = pq.front();
            pq.pop();
            
            int dis = itr.first;
            int node = itr.second;
            
            if(node == end) return dis;
            
            for(int i=0;i<n;i++)
            {
                long long p = (arr[i]*node)%mod;
                
                if(dist[p]>dis+1)
                {
                    dist[p] = dis + 1;
                    if(p == end) return (dis + 1);
                    
                    pq.push({dis+1,p});
                }
            }
        }
        return -1;
    }
};