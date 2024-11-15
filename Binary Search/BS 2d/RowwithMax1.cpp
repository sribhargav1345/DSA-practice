class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int mini = m;
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            int low = upper_bound(arr[i].begin(),arr[i].end(),0) - arr[i].begin();
            low--;
            
            if(low != m-1 && low<mini)
            {
                mini = low;
                ans = i;
            }
        }
        return ans;
    }
};