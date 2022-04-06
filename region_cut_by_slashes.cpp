class Solution {
    vector<int> parent;
    vector<int> rank;
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size();
        int dots = n+1;
        
        initialize(dots);
        
        int ans = 1;
        
        for(int i=0; i<n; i+=1){
            for(int j=0; j<n; j+=1){
                
                char ch = grid[i][j];
                
                if(ch == ' ') continue;
                
                int v1,v2;
                if(ch =='/'){
                    int a1 = i+1, b1 = j;
                    int a2 = i, b2 = j+1;
                    v1 = (a1*dots + b1);
                    v2 = (a2*dots + b2);
                }
                else{
                    int a1 = i, b1 = j;
                    int a2 = i+1, b2 = j+1;
                    v1 = (a1*dots + b1);
                    v2 = (a2*dots + b2);
                }
                
                int s1 = find(v1);
                int s2 = find(v2);
                
                // if both s1 and s1 are in same set 
                // then it forms the cycle.
                // 1 cycle divides region in 1 part.
                if(s1 == s2) ans += 1;
                
                else if(rank[s1] > rank[s2]) unionNodes(s1,s2);   
                
                else unionNodes(s2,s1);

                
            }
        }
        
        return ans;
    }

    // connecting boundaries of the grid
    void initialize(int dots){
        parent.resize(dots*dots,-1);
        rank.resize(dots*dots,0);
        
        for(int i=0; i<dots; i++){
            for(int j=0; j<dots; j++){
                
                if(i == 0 || j == 0 || i == dots-1 || j == dots-1){
                    int v1 = i*dots + j;
                    if(v1 != 0) unionNodes(0,v1);
                }
                
            }
        }
        return;
    }
    
    void unionNodes(int v1,int v2){
        int s1 = find(v1);
        int s2 = find(v2);
        
        parent[s2] = s1;
        rank[s1] += rank[s2];

        return;
    }
    
    int find(int v){
        if(parent[v] == -1) return v;
        parent[v] = find(parent[v]);
        return find(parent[v]);
    }
};