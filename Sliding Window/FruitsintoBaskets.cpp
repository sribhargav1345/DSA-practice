#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        // Here, basically, in our window, we should only have 2 types of fruits, and he asks for longest window -> Sliding window

        int i=0,j=0;
        unordered_map<int,int> mp;

        int maxi = 0;

        while(j<n)
        {
            mp[fruits[j]]++;

            if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0) mp.erase(fruits[i]);

                    i++;
                }
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};