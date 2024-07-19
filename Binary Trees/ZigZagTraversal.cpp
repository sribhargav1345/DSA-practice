#include<bits/stdc++.h>
using namespace std;

// Just a level order traversal, u need to reverse direction every time
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        // Basic level order traversal
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty())
        {
            vector<int> v;
            int size = q.size();

            int rev = q.front().second;
            int op = rev^1;

            for(int i=0;i<size;i++)
            {
                TreeNode* it = q.front().first;
                q.pop();

                v.push_back(it -> val);

                if(it -> left != NULL) q.push({it -> left,op});
                if(it -> right != NULL) q.push({it -> right,op});
            }

            if(rev == 1) reverse(v.begin(),v.end());
            ans.push_back(v);
        }
        return ans;
    }
};