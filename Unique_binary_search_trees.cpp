/*
        (root)      Then there is 3*2 ways of unique BSTs 
       /      \
     [a,b,c]  [d,e]
     suppose n = 4 
     one way = (1)          2nd = (2)       3rd = (3)           4th = (4)
              /   \              /   \           /   \               /   \  
            []    [2,3,4]       [1]  [3,4]      [1,2] [4]       [1,2,3]   []
    1st way : 
    right subtree can be costructed in unique ways(Example of n = 3) 
    left subtree unique ways 1,
    so total ways 1*3, we have to perform this by taking all values as root one by one
    so ways[4] = ways[0]*ways[3] + ways[1]*ways[2] + ways[2]*ways[1] + ways[3]*ways[0];  
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1, dp[1] = 1;
        
        for(int i=2; i<=n; ++i){

            for(int j=0; j<i; ++j){
                 dp[i] += (dp[j]*dp[i-1-j]);
            }

        }
        
        return dp[n];
    }
};