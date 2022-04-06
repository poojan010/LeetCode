class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
    
    void dfs(vector<int>& nums,int index){  
        
        if(index == nums.size() - 1) 
            ans.push_back(nums);
        
        for(int i=index; i<nums.size(); i++){
            swap(nums[index],nums[i]);
            dfs(nums,index+1);
            swap(nums[index],nums[i]);
        }
        
        return;
    }
};