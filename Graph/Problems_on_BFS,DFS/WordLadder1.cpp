#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& arr) {
        int n = arr.size();
        
        queue<pair<string,int>> q;
        q.push({begin,1});

        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(arr[i]==begin)
            {
                visited[i] = 1;
                break;
            }
        }

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            auto str = itr.first;

            cout<<str<<" ";
            int leng = itr.second;


            if(str==end) return leng;

            if(find(arr.begin(),arr.end(),str) != arr.end() || str == begin)
            {
                for(int i=0;i<n;i++)
                {
                    if(visited[i]==0)
                    {
                        int op = arr[i].size();
                        int ct = 0;
                        for(int j=0;j<op;j++)
                        {
                            if(arr[i][j]!=str[j]) ct++;
                        }
                        if(ct==1)
                        {
                            visited[i] = 1;
                            int opt = leng + 1;

                            q.push({arr[i],opt});
                        }
                    }
                }
            }
        }
        return 0;
    }
};