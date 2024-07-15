#include<bits/stdc++.h>
using namespace std;

// Pure Dijkstra No change
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;

        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();

            int min_time = itr.first;
            int node = itr.second;

            for(auto it: adj[node])
            {
                int other = it.first;
                int time = it.second;

                if(dist[other] > min_time + time){
                    dist[other] = min_time + time;
                    pq.push({dist[other],other});
                }
            }
        }

        int maxi = 0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};