class Solution {
    int ans = 0;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int startX = 0, startY = 0, totalZeros = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] != -1) totalZeros++;
                if(grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } 
                
            }
        }

        dfs(grid,startX,startY,n,m,totalZeros,1);
        
        return ans;
        
    }
    
private:
    void dfs(vector<vector<int>>& grid, int x, int y, int rows, int cols, int totalZeros, int curr_zeros){
        
        if(x<0 || x>=rows || y<0 || y>=cols || grid[x][y] == -1) return;

        
        if(grid[x][y] == 2){
            if(curr_zeros == totalZeros) ans++;
            return;
        }
        
        grid[x][y] = -1;
        
        dfs(grid,x-1,y,rows,cols,totalZeros,curr_zeros+1);
        dfs(grid,x+1,y,rows,cols,totalZeros,curr_zeros+1);
        dfs(grid,x,y-1,rows,cols,totalZeros,curr_zeros+1);
        dfs(grid,x,y+1,rows,cols,totalZeros,curr_zeros+1);
     
        grid[x][y] = 0;
        
        return;
    }
};