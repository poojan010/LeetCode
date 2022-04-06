class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        
        while(n > 1){
            
            int t =1;
            
            // if we can not reach to value k
            // even if we select 'z' character
            // then we have to choose min value b/w 'a' to 'z'
            // that satisfies our situation
            if((n-1)*26 < k){
                t = k%26;
            }
            
            char ch;

            if(t == 0){ 
                ch = 'z';
                k -= 26;
            }
            else{ 
                ch = 'a' + (t-1);
                k -= t;
            }
            ans.push_back(ch);
            
            n -= 1;
        }
        
        char ch = ('a'+(k-1));
        ans.push_back(ch);
        
        return ans;
    }
};