#include<bits/stdc++.h>
using namespace std;

void preOrder(Node* root)
{
    if(root == NULL) return;

    v.push_back(root -> val);
    preOrder(root -> left);
    preOrder(root -> right);
}

void InOrder(Node* root)
{
    if(root == NULL) return;

    InOrder(root -> left);
    v.push_back(root -> val);
    InOrder(root -> right);
}

void postOrder(Node* root)
{
    if(root == NULL) return;

    postOrder(root -> left);
    postOrder(root -> right);
    v.push_back(root -> val);
}

// Level Order
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;

    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        vector<int> level;
        int size = q.size();

        for(int i=0;i<size;i++)
        {
            Node* node = q.front();
            q.pop();

            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);

            level.push_back(node -> val);
        }
    }
    return ans;
}