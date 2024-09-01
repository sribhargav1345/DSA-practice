#include<bits/stdc++.h>
using namespace std;

Struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<int> TopView(Node* root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    map<int,int> mp;        // Storing vertical levels and node values

    queue<pair<Node*,int>> q;
    q.push({root,0});       // Pushing root node with it's vertical position

    while(!q.empty())
    {
        auto itr = q.front();
        q.pop();

        Node* present = itr.first;
        int level = itr.second;

        if(mp.find(level) == mp.end()) mp[level] = present -> data;

        if(present -> left)
        {
            q.push({present -> left,level-1});
        }
        if(present -> right)
        {
            q.push({present -> right,level+1});
        }
    }

    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}