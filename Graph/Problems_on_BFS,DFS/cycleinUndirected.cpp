bool bfs(int i,int v,vector<int> adj[],vector<int>& visited){
        
    visited[i]= 1;
    
    queue<pair<int,int>> q;
    q.push({i,-1});
    
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        
        int node = it.first;
        
        for(auto itr:adj[node])
        {
            if(visited[itr] == 0)
            {
                visited[itr] = 1;
                q.push({itr,node});
            }
            else
            {
                if(it.second!=itr) return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]) {
    
    vector<int> visited(v);
    
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            if(bfs(i,v,adj,visited) == true) return true;
        }
    }
    return false;
}