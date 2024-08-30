class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,vector<vector<string>>& ans,int n){
        // Ensuring no queens on same row,col and diagonal
        int duprow = row;
        int dupcol = col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        // This loop is not needed, since we didn't solve for right ones
        while(row<n && col<n){
            if(board[row][col]=='Q') return false;
            row++;
            col++;
        }

        row = duprow;
        col = dupcol;

        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;

        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col,int n,vector<string>& v,vector<vector<string>>& ans){
        // For each column, on which row, we want to keep
        if(col == n){
            ans.push_back(v);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,v,ans,n)){
                v[row][col] = 'Q';
                solve(col+1,n,v,ans);
                v[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n, string(n, '.'));

        // for(int i=0;i<n;i++){
        //     v[i] = s;
        // }
        solve(0,n,v,ans);   // 1st 0 is our column
        return ans;
    }
};