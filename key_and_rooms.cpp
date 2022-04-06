class Solution {
    vector<bool> visited;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visited.resize(n,false);
        
        dfs(rooms,0);
        
        for(bool room : visited){
            if(!room) return false;
        }
        
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms,int curr){
        
        if(visited[curr]) return;
        
        visited[curr] = true;
        
        for(int num : rooms[curr])
            dfs(rooms,num);
         
        
        return;
    }
};