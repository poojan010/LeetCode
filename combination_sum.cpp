class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        dfs(curr,0,candidates,target);
        return ans;
    }
    void dfs(vector<int>& curr, int index, vector<int>& nums,int target){
        
        if(target < 0) return;
        
        if(target == 0){
            ans.push_back(curr);
            return;
        }
            
        
        for(int i=index; i<nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(curr,i,nums,target-nums[i]);
            curr.pop_back();
        }
        
        return;
    }
}; 