#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    Node* search(Node* root,int target){
        if (root == nullptr) return nullptr;
        if (root->data == target) return root;
    
        Node* leftResult = search(root->left, target);
        if (leftResult != nullptr) return leftResult;
    
        return search(root->right, target);
    }
    
    int minTime(Node* root, int target) 
    {
        // Here, we have to perform 2 BFS, one for finding child-parent relationships,
        // 2nd for finding the required answer

        queue<Node*> q;
        q.push(root);

        unordered_map<Node*,Node*> mp;

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            if(itr -> left){
                mp[itr -> left] = itr;
                q.push(itr -> left);
            }
            if(itr -> right){
                mp[itr -> right] = itr;
                q.push(itr -> right);
            }
        }


        // Now coming to 2nd BFS
        Node* a = search(root,target);
        
        queue<pair<Node*,int>> pq;
        pq.push({a,0});

        vector<int> ans;

        unordered_set<int> st;
        st.insert(a -> data);
        
        int dis;

        while(!pq.empty())
        {
            auto it = pq.front();

            Node* itr = it.first;
            dis = it.second;

            pq.pop();

            if(itr -> left)
            {
                //cout<<itr -> left -> val<<endl;
                if(st.find(itr -> left -> data) == st.end())
                {
                    //cout<<itr -> left -> val<<endl;

                    st.insert(itr -> left -> data);
                    pq.push({itr -> left,dis+1});
                }
            }
            if(itr -> right)
            {
                if(st.find(itr -> right -> data) == st.end())
                {
                    st.insert(itr -> right -> data);
                    pq.push({itr -> right,dis+1});
                }
            }
            if(mp.find(itr)!=mp.end())
            {
                if(st.find(mp[itr] -> data) == st.end())
                {
                    pq.push({mp[itr],dis+1});
                    st.insert(mp[itr] -> data);
                }
            }
        }
        return dis;
    }
};