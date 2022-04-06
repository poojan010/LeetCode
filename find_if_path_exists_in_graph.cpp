class Solution {
    bool ans = false;
    vector<bool> visited;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     
        visited.resize(n,false);
        vector<vector<int>> graph(n);
    
        for(auto it : edges){
            int v1 = it[0], v2 = it[1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        dfs(graph,source,destination);
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph,int curr, int dest){
        
        if(visited[curr] || ans) return;
        
        if(curr == dest){ 
            ans = true;
            return;
        }
        
        visited[curr] = true;
        

        for(int num : graph[curr])
            dfs(graph,num,dest);
        
        
        return;
    }
};