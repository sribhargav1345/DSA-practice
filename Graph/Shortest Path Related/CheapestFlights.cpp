class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<m;i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{k,src}});

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            int cost = itr.first;
            int stops = itr.second.first;
            int node = itr.second.second;

            if(stops == -1) continue;

            for(auto x:adj[node])
            {
                if(cost + x.second < dist[x.first]){
                    dist[x.first] = cost + x.second;
                    q.push({dist[x.first],{stops-1,x.first}});
                }
            }
        }
        // for(int i=0;i<n;i++) cout<<dist[i]<<" ";
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};