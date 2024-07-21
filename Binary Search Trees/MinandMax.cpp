#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        if(root == NULL) return NULL;
        
        if(root -> left) return minValue(root -> left);
        else return root -> data;
    }
};