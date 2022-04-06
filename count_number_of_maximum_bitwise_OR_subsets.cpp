class Solution {
    int ans = 0, maxOR = 0;
public:
    int countMaxOrSubsets(vector<int>& nums) {

        for(int num : nums) maxOR |= num;
        
        dfs(nums,0,0);
        
        return ans;
    }
    
    void dfs(vector<int>& nums, int index, int curOR){
        
        if(curOR == maxOR) ans++;
        
        for(int i=index; i<nums.size(); i++){
            dfs(nums,i+1,curOR | nums[i]);
        }
        
        return;
        
    }
};