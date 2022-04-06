class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, n = s.length();
        stack<int> st;
        
        for(int i=0; i<n; i++){
            if(s[i] == '(') st.push(0);
            else{
                if(st.top() == 0){
                    st.pop();
                    st.push(1);
                }
                else{
                    int t = 0;
                    while(st.top() != 0){
                        t += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(t*2);
                }
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};