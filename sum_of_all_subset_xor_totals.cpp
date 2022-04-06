class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums,0,0);
    }
    int dfs(vector<int>& nums,int level, int currXOR){
        
        if(level == nums.size()) return currXOR;
        
        // Constructing subsets
        // we have two chices
        // whether we want to include number or not.
        int include = dfs(nums,level+1,currXOR^nums[level]);
        
        int exclude = dfs(nums,level+1,currXOR);
        
        return include + exclude;
    }
};