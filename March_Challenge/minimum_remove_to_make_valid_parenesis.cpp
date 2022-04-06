class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = s;
        
        stack<char> st;
        
        for(int i=0; i<ans.length(); i++){
            
            char ch = ans[i];
            
            if(isalpha(ch)) continue;
            
            if(ch == '('){
                st.push(ch);
            }
            else{
                if( st.empty() || st.top() != '('){
                    ans.erase(i,1);
                    i -= 1;
                }
                else st.pop();
            }
        }
        
        int k = st.size();
        
        for(int i=ans.length()-1; i>=0; i--){
            if(k == 0) break;
            if(ans[i] == '('){
                ans.erase(i,1);
                k--;
            }
        }

        
        return ans;
    }
};