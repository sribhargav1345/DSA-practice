class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        // we can do this in 26*n i guess
        int maxi = 0;
        for(int l=0;l<26;l++)
        {
            char c = static_cast<char>(65+l);

            int i = 0,j = 0;
            map<char,int> mp;

            int ans = 0;

            while(j<n)
            {
                mp[s[j]]++;
                if(mp[c]+k < j-i+1)
                {
                    while(mp[c]+k < j-i+1)
                    {
                        mp[s[i]]--;
                        if(mp[s[i]]==0) mp.erase(s[i]);

                        i++;
                    }
                }
                ans = max(ans,j-i+1);
                j++;
            }
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};