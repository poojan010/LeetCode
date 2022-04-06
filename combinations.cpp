class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        dfs(curr,0,n,k);
        return ans;   
    }
    void dfs(vector<int>& curr, int index,int size,int k){
        
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        
        for(int i=index; i < size; i++){
            curr.push_back(i+1);
            dfs(curr,i+1,size,k);
            curr.pop_back();
        }
        
        return;
    }
};