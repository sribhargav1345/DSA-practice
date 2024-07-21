#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        int n = arr.size();
        // The special thing is if inorder traversal is sorted, then it is BST
        
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>=arr[i+1]) return false;
        }
        return true;
    }
};