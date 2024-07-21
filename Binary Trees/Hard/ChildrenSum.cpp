#include<bits/stdc++.h>
using namespace std;

// This is as per striver
void changeTree(TreeNode* root){
    if(root == NULL) return;

    int child = 0;
    if(root -> left) child += (root -> left -> data);
    if(root -> right) child += (root -> right -> data);

    if(child >= root -> data) root -> data = child;
    else{
        if(root -> left) root -> left -> data = root -> data;
        if(root -> right) root -> right -> data = root -> data;
    }

    reorder(root -> left);
    reorder(root -> right);

    int tot = 0;
    if(root -> left) tot += (root -> left -> data);
    if(root -> right) tot += (root -> right -> data);
    if(root -> left or root -> right) root -> data = tot;
}

// This is not as per striver (gfg) -> Just calculating whether it is Children sum or not
class Solution{
    public:
    int isSumProperty(Node *root)
    {
     // Add your code here
        // if(root == NULL) return 1;
        if(!root -> left && !root -> right) return 1;
        
        if(root -> left && root -> right)
        {
            if(root -> left -> data + root -> right -> data == root -> data)
            {
                return isSumProperty(root -> left) && isSumProperty(root -> right);
            }
            else return 0;
        }
        else if(root -> left){
            if(root -> data == root -> left -> data){
                return isSumProperty(root -> left);
            }
            else return false;
        }
        else if(root -> right){
            if(root -> data == root -> right -> data){
                return isSumProperty(root -> right);
            }
            else return false;
        }
    }
};