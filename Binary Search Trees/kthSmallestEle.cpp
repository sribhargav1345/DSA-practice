#include<bits/stdc++.h>
using namespace std;

// Inorder traversal
class Solution {
public:
    vector<int> inorder(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL) return ans;
        
        inorder(root -> left,ans);
        ans.push_back(root -> val);
        inorder(root -> right,ans);
        
        return ans;
    }
    
    int kthSmallest(TreeNode *root, int k)
    {
        // I think we can do inorder traversal, we will get it in sorted form
        // Then we can take kth element from the begin.
        
        if(root == NULL) return -1;
        
        vector<int> ans;
        inorder(root,ans);
        
        int n = ans.size();
        
        if(k>n) return -1;
        else
        {
            return ans[k-1];
        }
    }
};