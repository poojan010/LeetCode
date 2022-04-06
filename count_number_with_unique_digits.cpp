class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if( n == 0 ) return 1;
        if( n == 1 ) return 10;
        
        
        vector<int> dp(n+1);
        dp[0] = 1 , dp[1] = 9;
        
        int ans = 10;
            
        for(int i=2; i<=n ; i++){
            
            int totalDigits = 9 * pow(10,i-1);
            
            int nd = dp[i-1];
            int d = totalDigits/10 - dp[i-1];
            
            int duplicates = d*10 + nd*(i-1);
            
            dp[i] = totalDigits - duplicates;
            
            ans += dp[i];
        }
        
        return ans;
    }
};