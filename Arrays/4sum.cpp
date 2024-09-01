class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        set<vector<int>> st;

        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int a = j+1;
                int b = n-1;
                
                long long sum = nums[i] + nums[j];
                vector<int> v;

                while(a<b)
                {
                    if(sum+nums[a]+nums[b]==target)
                    {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[a]);
                        v.push_back(nums[b]);

                        if(st.find(v)==st.end()) 
                        {
                            ans.push_back(v);
                            st.insert(v);
                        }
                        v.clear();

                        a++;
                        b--;
                    }
                    else if(sum+nums[a]+nums[b]>target) b--;
                    else a++;
                }
            }
        }
        return ans;
    }
};