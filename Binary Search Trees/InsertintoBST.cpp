#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* r = new TreeNode(val);

        if(root == NULL)
        {
            root = r;
            return root;
        }

        TreeNode* head = root;

        while(root != NULL)
        {
            if(root -> val > val)
            {
                if(root -> left) root = root -> left;
                else{
                    root -> left = r;
                    return head;
                } 
            }
            else
            {
                if(root -> right) root = root -> right;
                else{
                    root -> right = r;
                    return head;
                } 
            }
        }
        return root;
    }
};