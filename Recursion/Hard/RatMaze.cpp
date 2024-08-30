void solve(vector<vector<int>> &mat,int n,vector<string>& ans,string s,int row,int col){
        if(row == n-1 && col == n-1 && mat[row][col] != 0){
            ans.push_back(s);
            return;
        }
        
        if(row<0 || row>=n || col<0 || col>=n || mat[row][col] == 0 || mat[row][col]==-1){
            return;
        }
        
        int a = mat[row][col];
        mat[row][col] = -1;
        
        solve(mat,n,ans,s+'U',row-1,col);
        solve(mat,n,ans,s+'D',row+1,col);
        solve(mat,n,ans,s+'L',row,col-1);
        solve(mat,n,ans,s+'R',row,col+1);
        
        mat[row][col] = 1;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        vector<string> ans;
        
        if (mat[0][0] == 0) {
            return ans;
        }
        
        string s = "";
        solve(mat,n,ans,s,0,0);
        
        if(ans.size()==0) return ans;
        
        return ans;
    }