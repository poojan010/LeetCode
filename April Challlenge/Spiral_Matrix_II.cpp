/*
    l = left, r= right, t = top, d = down
    We have 4 directions to follow l to r, t to b, r to l, b to t
    so we will traverse direction to direction and update l,r,t,b variables after each traversal
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        
        int index = 0,dir = 0, top = 0, down = n-1, left = 0, right = n-1;
        
        int curr = 1;
        
        while(top <= down && left <= right){
            
            if(dir == 0){
                for(int i=left; i<=right; i++) ans[top][i] = curr++;
                top++;
            }
            else if(dir == 1){
                for(int i=top; i<=down; i++) ans[i][right] = curr++; 
                right--;
            }
            else if(dir == 2){
                for(int i=right; i>=left; i--) ans[down][i] = curr++;
                down--;
            }
            else{
                for(int i=down; i>=top; i--) ans[i][left] = curr++;
                left++;
            }
            
            dir = (dir+1)%4;
            
        }
        
        return ans;
    }
};