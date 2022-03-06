// Traversal will be same as Pascal triangle.
// Few modifications.
// while assigning values to glass 
// we will select top two glasses and takes half champengne from that glasses.
// initialize first glass with poured amount.

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> result(query_row+1);
        
        result[0].push_back(poured);

        for(int i=1; i<=query_row ; i++){
            result[i].resize(i+1);
            result[i][0] = result[i-1][0] > 1 ? (result[i-1][0] - 1)/2 : 0.0;
            result[i][i] = result[i-1][i-1] > 1 ? (result[i-1][i-1] - 1)/2 : 0.0;
            
            for(int j=1; j<i ; j++){
                double num1,num2;
                if(result[i-1][j-1] <= 1) num1 = 0;
                else num1 = (result[i-1][j-1] - 1)/2;
                if(result[i-1][j] <= 1) num2 = 0;
                else num2 = (result[i-1][j] - 1)/2;
                result[i][j] = num1 + num2;
            }
        }
        
        double ans = min(1.0,result[query_row][query_glass]);
        // ans = max(ans,0.0);
        return ans;
    }
};