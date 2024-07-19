#include<bits/stdc++.h>
using namespace std;

// Brute approach, for every node, maxi = max(maxi, max(lh+rh) + 1)
int findMax(TreeNode* node)
{
    if(node == NULL) return 0;

    int lh = findH(node -> left);
    int rh = findH(node -> right);

    maxi = max(maxi, (lh+rh));

    findMax(node -> left);
    findMax(node -> right);

    return maxi+1;
}

// Optimal, in height we find max(lh,rh), here find max(lh+rh) at every step, that's all
class Solution {
public:
    int findMax(TreeNode* root,int maxi){
        if(root == NULL) return 0;

        int lh = findMax(root -> left, maxi);
        int rh = findMax(root -> right, maxi);

        return (1+max(maxi,lh+rh));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // When we are at specific node. THen maxHeight of left + right gives us the answer
        return findMax(root,0);
    }
};