class Solution {
  public:
     // Optimised -> Using pq   
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<int> ans = {0,0};
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({deadline[i],profit[i]});
        }
        
        sort(v.begin(),v.end());    // Sort based on deadlines
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:v)
        {
            if(x.first > pq.size()){
                pq.push(x.second);
            }
            else if(!pq.empty() && pq.top() < x.second){
                pq.pop();
                pq.push(x.second);
            }
        }
        
        while(!pq.empty())
        {
            ans[1] += pq.top();
            pq.pop();
            ans[0]++;
        }
        
        return ans;
    }
};
