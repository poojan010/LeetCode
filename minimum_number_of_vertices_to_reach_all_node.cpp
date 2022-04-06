class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n);
    
        vector<int> ans, degree(n,0);
        
        for(auto it : edges){
            int v1 = it[0], v2 = it[1];
            degree[v2]++;
        }
        
        for(int i=0; i<n; i++){
            if(degree[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};