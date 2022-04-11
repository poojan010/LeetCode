class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size(), m = grid[0].size();
        
        k = k%(n*m);
        
        vector<vector<int>> ans = grid;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                
                int x = i*m + j + k;
                x = x%(n*m);
                
                int row = x/m, col = x%m;   // new row,col after shift

                ans[row][col] = grid[i][j];
            }
        }
        
        return ans;
    }
};