#include<bits/stdc++.h>
using namespace std;

// Tell whether Binary tree is BSt or not
class Solution {
public:
    bool isValid(TreeNode* root, long a, long b){
        if(root == NULL) return true;

        if(root -> val >= b || root -> val <= a) return false;
        return isValid(root -> left,a,root -> val) && isValid(root -> right,root -> val,b);
    }

    bool isValidBST(TreeNode* root) {   
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};