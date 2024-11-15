
// Find largest k such that nums[k] < nums[k+1]
// If no above exist, reverse nums
// Find largest index l such that nums[k] < nums[l]
// swap nums[k] & nums[l]
// reverse the subarray nums[k+1:]

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        int i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1]) break;
        }

        if(i<0) reverse(nums.begin(),nums.end());
        else
        {
            int l;
            for(l=n-1;l>i;l--)
            {
                if(nums[l]>nums[i]) break;
            }
            swap(nums[i],nums[l]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};