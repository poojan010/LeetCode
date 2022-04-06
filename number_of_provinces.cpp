class Solution {
    vector<bool> visited;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        visited.resize(n,false);
        
        int ans = 0;
        
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j || isConnected[i][j] == 0) 
                    continue;
                graph[i].push_back(j);
            }
        }
         
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            ans += 1;
            dfs(graph,i);
        }
        
        return ans;
    }
  
    void dfs(vector<vector<int>>& graph,int node){
        if(visited[node]) return;
        
        visited[node] = true;
        
        if(graph[node].size() == 0) return;
        
        for(int num : graph[node])
            dfs(graph,num);
        
        return;
    }
};