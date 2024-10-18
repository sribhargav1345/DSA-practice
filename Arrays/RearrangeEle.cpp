class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        int j = 0,k = 0;
        while(nums[j]<0)
        {
            j++;
        }
        while(nums[k]>0)
        {
            k++;
        }

        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                // It has to be even
                v.push_back(nums[j]);
                j++;
                while(j<n && nums[j]<0) j++;
            }
            else 
            {
                v.push_back(nums[k]);
                k++;
                while(k<n && nums[k]>0) k++;
            }
        }
        return v;
    }
};