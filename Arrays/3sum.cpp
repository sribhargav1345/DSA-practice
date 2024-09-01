class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        set<vector<int>> st;

        for(int i=0;i<n;i++){

            int j=i+1,k=n-1;
            int val = nums[i];

            while(j<k)
            {
                if(val + nums[j] + nums[k] == 0){
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);

                    if(st.find(v)==st.end()) ans.push_back(v);
                    st.insert(v);
                    v.clear();
                    j++;
                    k--;
                }
                else if(val + nums[j] + nums[k] < 0){
                    j++;
                }
                else k--;
            }
        }
        return ans;
    }
};