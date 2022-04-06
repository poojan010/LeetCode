class Solution {
    vector<int> parent;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        parent.resize(n,-1);
        
        vector<int> ans;
        
        for(auto it : edges){
            int v1 = it[0] - 1, v2 = it[1] - 1 ;
            int s1 = find(v1);
            int s2 = find(v2);
            if(s1 == s2) return it;
            parent[s1] = s2;
        }
        
        return ans;
    }
    
    int find(int v){
        if(parent[v] == -1) return v;
        parent[v] = find(parent[v]);
        return find(parent[v]);
    }
};