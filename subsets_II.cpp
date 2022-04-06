class Solution {
    vector<vector<int>>  ans;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        dfs(curr,0,nums);
        return ans;
    }
    
    void dfs(vector<int>& curr, int index, vector<int>& nums){
        
        ans.push_back(curr);

        
        for(int i=index; i<nums.size(); i++){
            
            if (i > index and nums[i] == nums[i - 1]) 
                continue;
            
            curr.push_back(nums[i]);
            dfs(curr,i+1,nums);
            curr.pop_back();
        }
        
        return;
    }
};