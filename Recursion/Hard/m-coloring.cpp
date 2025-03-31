class Solution {
  public:
    bool isOk(int idx,vector<vector<int>>& adj,int color,vector<int>& op){
        for(auto x:adj[idx]){
            if(op[x] == color){
                return false;
            }
        }
        return true;
    }
    
    bool solve(int idx,int v,vector<vector<int>>& adj,int m,vector<int>& op){
        if(idx == v){
            return true;
        }
        
        for(int i=0;i<m;i++)
        {
            if(isOk(idx,adj,i,op)){
                op[idx] = i;
                if(solve(idx+1,v,adj,m,op)) return true;
                op[idx] = -1;
            }
        }
        return false;
    }
    
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(int i=0;i<edges.size();i++){
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        
        vector<int> op(v,-1);
        
        return solve(0,v,adj,m,op);
    }
};
