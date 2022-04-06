class Solution {
     vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n,string(n,'.'));

        solve(board,0);
        
        return ans;
    }
    
    void solve(vector<string>& board,int row){

        int n = board.size();
        
        if(row == n){ 
            ans.push_back(board);
            return ;
        }

        for(int i=0; i<n; i++)
        {
            if(isValid(board, row, i))
            {
                board[row][i] = 'Q';
                solve(board, row+1);
                board[row][i] = '.';
            }
        }
    }

    bool isValid(vector<string> &board, int row, int col){

        // columns
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;

        // left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;

        // right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        
        return true;
    }
};