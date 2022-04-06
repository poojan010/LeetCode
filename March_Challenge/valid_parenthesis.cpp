class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char& ch : s){
            switch(ch){
                case '{':
                case '(':
                case '[':
                    st.push(ch);
                    break;
                case '}':
                    if(st.empty() || st.top() != '{') return false;
                    else st.pop();
                    break;
                case ')':
                    if(st.empty() || st.top() != '(') return false;
                    else st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != '[') return false;
                    else st.pop();
                    break;
                default :
                    break;
            }
        }
        
        return st.empty();
    }
};