// when num is odd then we have to set LSB to 1.
// so (i-1)/2 + 1
// for even num it will be same as i/2 num.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0; i<=n; i++){
            if(i<=1){ 
                ans[i] = i;
                continue;
            }
            if(i%2 == 0) ans[i] = ans[i/2];
            else ans[i] = ans[(i-1)/2] + 1;
        }
        
        return ans;
    }
};