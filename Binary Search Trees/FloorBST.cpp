#include<bits/stdc++.h>
using namespace std;

lass Solution{

public:
    int floor(Node* root, int t) {
        if (root == NULL) return -1;
        
        // Your code here
        int floor = -1;
        while(root != NULL)
        {
            if(root -> data == t){
                floor = t;
                return t;
            }
            else
            {
                if(root -> data > t)
                {
                    root = root -> left;
                }
                else
                {
                    floor = root -> data;
                    root = root -> right;
                }
            }
        }
        return floor;
    }
};