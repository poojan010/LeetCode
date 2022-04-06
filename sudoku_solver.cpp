class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        return;
    }
    
    bool solve(vector<vector<char>>& board,int i, int j){

        if(i==9) return true;       // reacehd end
        if(j==9) return solve(board, i+1, 0);     // reached column end
        if(board[i][j] != '.') return solve(board, i, j+1);

        for(char c='1'; c<='9'; c++)
        {
            if(isValid(board, i, j, c))
            {
                board[i][j] = c;
                if(solve(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
        
    bool isValid(vector<vector<char>>& board, int row, int col, int num){
        for(int i=0; i<9; i++)
            if(board[row][i] == num)
                return false;
        
        for(int i=0; i<9; i++)
            if(board[i][col] == num)
                return false;
        
        int a = row - row%3;
        int b = col - col%3;
        
        for(int i=a; i<a+3; i++){
            for(int j=b; j<b+3; j++){
                if(board[i][j] == num) return false;
            }
        }
        
        return true;
    }
};