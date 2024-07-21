#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // LCA 
        if(root == NULL) return NULL;

        int ans = root -> val;
        if(p -> val < ans && q -> val < ans)
        {
            return lowestCommonAncestor(root -> left, p, q);
        }
        else if(p -> val > ans && q -> val > ans)
        {
            return lowestCommonAncestor(root -> right, p, q);
        }

        return root;
    }
};