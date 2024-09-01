class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        vector<int> ans;
        if(root == NULL) return ans;

        while(!q.empty())
        {
            int size = q.size();
            ans.push_back(q.front().first -> val);

            for(int i=0;i<size;i++)
            {
                auto itr = q.front().first;
                q.pop();

                int level = q.front().second;

                if(itr -> right){
                    q.push({itr -> right,++level});
                }
                if(itr -> left){
                    q.push({itr -> left,++level});
                }
            }
        }
        return ans;
    }
};