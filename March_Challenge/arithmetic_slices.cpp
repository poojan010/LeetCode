// we will find prefix values from left side.
// so we don't have to find differences.
// when differences are same then we keep
// incrementing i count.
// that will give us length of that segment. by i-j+1
// we have function for finding subarrays for given length.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        
        int ans = 0;
        vector<int> prefix(n-1);
        for(int i=1; i<n; i++) 
            prefix[i-1] = nums[i] - nums[i-1];
        
        for(int i=1; i<n-1; i++){
            int j = i-1;
            while(i < n-1 && prefix[i] == prefix[j]) i++;
            ans += totalSubArrays(i-j+1);
        }
        
        return ans;
    }
    
    int totalSubArrays(int n){
        int res = 0;
        
        for(int i=3; i<=n; i++) res += (n-i+1);
        
        return res;
    }
};