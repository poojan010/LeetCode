class Solution {
    vector<string> temp;
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        dfs(0,s,temp);
        return ans;
    }
    
    void dfs(int index, string s, vector<string>& temp){
        if(index == s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index; i<s.length(); ++i){
            if(!isPalindrome(s.substr(index,i-index+1))) continue;
            
            /* 
              if palindromic substring found
              then add it into temp Vector
              and solve remaining part
            */
            temp.push_back(s.substr(index,i-index+1));
            dfs(i+1,s,temp);
            temp.pop_back();    // backtracking
        }
        
        return;
    }
    
    bool isPalindrome(string str){
        int i=0, j = str.length()-1;
        while(i < j){
            if(str[i] != str[j]) return false;
            ++i,--j;
        }
        return true;
    }
};