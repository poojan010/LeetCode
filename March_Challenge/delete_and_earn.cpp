// DP approach
// we will track 2 values included and excluded
// max of both will be answer.

// to inclue num
// we will add previous nums exclude value nd respective value
// to exclude num
// we will select max of previous num's include and exclude

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        int incl= 0 , excl = 0;
        
        vector<int> dp(10001);
        
        for(int num : nums) dp[num]++;
        
        for(int i=0; i<=10000 ; i++){
            
            int notIncuded = max(incl,excl);
            int included = excl + i*dp[i];
            
            incl = included;
            excl = notIncuded;
        }
        
        return max(incl,excl);
    }
};