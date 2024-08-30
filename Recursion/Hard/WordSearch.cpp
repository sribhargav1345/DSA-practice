class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int n,int m,int id,int p,int row,int col){
        if(id==p){
            return true;
        }

        if(row<0 || col<0 || row>=n || col>=m || board[row][col] != word[id]){
            return false;
        }

        char c = board[row][col];
        board[row][col] = '*';

        bool gotop = solve(board,word,n,m,id+1,p,row-1,col);
        bool goleft = solve(board,word,n,m,id+1,p,row,col-1);
        bool godown = solve(board,word,n,m,id+1,p,row+1,col);
        bool goright = solve(board,word,n,m,id+1,p,row,col+1);

        board[row][col] = c;
        return gotop | goleft | godown | goright;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int p = word.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0]){
                    if(solve(board,word,n,m,0,p,i,j)) return true;
                }
            }
        }
        return false;
    }
};