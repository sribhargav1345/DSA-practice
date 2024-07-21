#include<bits/stdc++.h>
using namespace std;

int findCeil(Node* root, int t) {
    if (root == NULL) return -1;
    
    int ceil = -1;
    while(root != NULL)
    {
        if(root -> data == t){
            ceil = t;
            return t;
        }
        else
        {
            if(root -> data > t)
            {
                ceil = root -> data;
                root = root -> left;
            }
            else
            {
                root = root -> right;
            }
        }
    }
    return ceil;
    
}