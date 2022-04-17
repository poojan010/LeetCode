class Solution {
public:
    string digitSum(string s, int k) {
        
        string ans = s;
        
        while(ans.length() > k){
            int c = 0;
            int x = 0;
            string newS;
            
            for(int i=0; i<ans.length(); ++i){
                x += (ans[i]-'0');
                c++;
                if(c == k){
                    newS += to_string(x);
                    c = 0, x = 0;
                }
            }
            if(c > 0) {
                newS += to_string(x);
            }
            ans = newS;
        }
        
        return ans;
    }
};