class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        int maxi = 1;
        map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                if(mp.find(nums[i]+1)!=mp.end())
                {
                    if(mp.find(nums[i]-1)!=mp.end())
                    {
                        mp[nums[i]] = mp[nums[i]-1] + mp[nums[i]+1] + 1;
                        mp[nums[i]+1] = mp[nums[i]];
                        mp[nums[i]-1] = mp[nums[i]];
                    }
                    else
                    {
                        mp[nums[i]] = 1 + mp[nums[i]+1];
                        mp[nums[i]+1] = mp[nums[i]];
                    }
                }
                else
                {
                    if(mp.find(nums[i]-1)!=mp.end())
                    {
                        mp[nums[i]] = mp[nums[i]-1] + 1;
                        mp[nums[i]-1] += 1;
                    }
                    else
                    {
                        mp[nums[i]] = 1;
                    }
                }
            }

            cout<<nums[i]<<" "<<mp[nums[i]]<<endl;
        }

        for(auto x:mp)
        {
            //cout<<x.first<<" "<<x.second<<endl;
            maxi = max(maxi,mp[x.first]);
        }
        return maxi;
    }
};