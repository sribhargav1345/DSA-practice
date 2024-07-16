#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        map<int,int> mp;
        mp[5] = 0;
        mp[10] = 0;
        mp[20] = 0;

        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                mp[5] += 1;
            }

            else if(bills[i]==10)
            {
                mp[10] += 1;

                if(mp[5]>0) mp[5] -= 1;
                else return false;
            }

            else
            {
                mp[20] += 1;

                if(mp[10]>0)
                {
                    mp[10] -= 1;

                    if(mp[5]>0) mp[5] -= 1;
                    else return false;
                }
                else
                {
                    if(mp[5]>=3) mp[5] -= 3;
                    else return false;
                }
            }
        }
        return true; 
    }
};