#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        long long ans = 0;

        while(!q.empty())
        {
            long long size = q.size();
            long long index = q.front().second;

            long long first,last;
            for(long long i=0;i<size;i++)
            {
                long long cur_id = q.front().second - index;
                TreeNode* node = q.front().first;

                q.pop();

                if(i==0) first = cur_id;
                if(i==size - 1) last = cur_id;

                if(node -> left)
                {
                    q.push({node -> left, cur_id*2+1});
                }
                if(node -> right)
                {
                    q.push({node -> right, cur_id*2+2});
                }
            }
            ans = max(ans,last-first+1);
        } 
        return ans;
    }
};