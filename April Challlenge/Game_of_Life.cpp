class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size(), n = board[0].size();
        
        vector<vector<int>> grid = board;
        
        vector<int> dx = {1,1,0,-1,-1,-1,0,1};
        vector<int> dy = {0,1,1,1,0,-1,-1,-1};
        
        for(int i=0; i<m ; i++){
            for(int j=0; j<n ; j++){
                
                int live_counts = 0;
                
                for(int k=0;k<8;k++){
                    if(isValid(i+dx[k],j+dy[k],m,n)){
                        if(grid[i+dx[k]][j+dy[k]] == 1) live_counts++;
                    }
                }
                
                if(grid[i][j] == 0 && live_counts == 3) board[i][j] = 1;
                else if(board[i][j] == 1 && live_counts < 2 || live_counts > 3) board[i][j] = 0;
                
            }
        }    
        
    }
    
private: 
    bool isValid(int x, int y, int rows, int cols){
        return (x>=0 && x<rows && y>=0 && y<cols);
    }
};