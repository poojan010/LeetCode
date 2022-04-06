class Solution {
    vector<vector<int>> ans;
    set<vector<int>> st;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
    
    void dfs(vector<int>& nums,int index){  
        
        if(index == nums.size() - 1){
            if(st.find(nums) == st.end()){
                ans.push_back(nums);
                st.insert(nums);
            }
        } 
            
        for(int i=index; i<nums.size(); i++){
            swap(nums[index],nums[i]);
            dfs(nums,index+1);
            swap(nums[index],nums[i]);
        }
        
        return;
    }
};