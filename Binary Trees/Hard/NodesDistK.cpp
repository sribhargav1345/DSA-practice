#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Here, we have to perform 2 BFS, one for finding child-parent relationships,
        // 2nd for finding the required answer

        queue<TreeNode*> q;
        q.push(root);

        unordered_map<TreeNode*,TreeNode*> mp;

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
        queue<pair<TreeNode*,int>> pq;
        pq.push({target,0});

        vector<int> ans;

        unordered_set<int> st;
        st.insert(target -> val);

        while(!pq.empty())
        {
            auto it = pq.front();

            TreeNode* itr = it.first;
            int dis = it.second;

            if(dis == k){
                int size = pq.size();

                for(int i=0;i<size;i++)
                {
                    ans.push_back(pq.front().first -> val);
                    pq.pop();
                }
                return ans;
            }
            pq.pop();

            if(itr -> left)
            {
                //cout<<itr -> left -> val<<endl;
                if(st.find(itr -> left -> val) == st.end())
                {
                    //cout<<itr -> left -> val<<endl;

                    st.insert(itr -> left -> val);
                    pq.push({itr -> left,dis+1});
                }
            }
            if(itr -> right)
            {
                if(st.find(itr -> right -> val) == st.end())
                {
                    st.insert(itr -> right -> val);
                    pq.push({itr -> right,dis+1});
                }
            }
            if(mp.find(itr)!=mp.end())
            {
                if(st.find(mp[itr] -> val) == st.end())
                {
                    pq.push({mp[itr],dis+1});
                    st.insert(mp[itr] -> val);
                }
            }
        }
        return ans;
    }
};