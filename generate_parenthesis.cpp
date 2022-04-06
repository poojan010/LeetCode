class Solution {
    vector<string> ans;
    int N;
public:
    vector<string> generateParenthesis(int n) {
        N = n;
        string curr;
        dfs(curr,n,n);
        return ans;
    }
    
    void dfs(string& curr,int l, int r){
        
        if(curr.length() == N*2){
            ans.push_back(curr);
            return;
        }
        
        if(l > 0){
            curr.push_back('(');
            dfs(curr,l-1,r);
            curr.pop_back();
        }           
        if(r > l){
            curr.push_back(')');
            dfs(curr,l,r-1);
            curr.pop_back();
        }
            
        return;
    }
};