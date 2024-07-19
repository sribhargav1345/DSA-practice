#include<bits/stdc++.h>
using namespace std;

// Brute force, go to every node, check left height, right height and check if abs(leftHei - rightHei) > 1 -> O(n**2)
bool check(TreeNode* node)
{
    if(node == NULL) return true;

    int lh = findHeight(node -> left);
    int rh = findHeight(node -> right);

    if(abs(lh-rh)>1) return false;

    bool left = check(node -> left);
    bool right = check(node -> right);

    if(!left || !right) return false;
    return true;
}

// Optimised
bool check(TreeNode* node)
{
    if(node == NULL) return true;

    int lh = findHeight(node -> left);
    int rh = findHeight(node -> right);

    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh)>1) return false;

    return max(lh,rh) + 1;      // Just finding height, if at any moment, abs(lh-rh)>1 return false;
}