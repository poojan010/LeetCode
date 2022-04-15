/*
 since string length is only 10 
 we will follow bruteforce approach
 when we spit string from parenthesis and "+" we get 4 values
 a, b , c, d => minimize a*(b+c)*d 
 store minimized value's index 
 insert parenhesis at index
*/

class Solution {
public:
    string minimizeResult(string expression) {
    
        int n = expression.length();
        int plus = 0, left = -1, right = -1;        // indexes
        for(int i=0; i<n; ++i){
            if(expression[i] == '+'){ plus = i; break; }
        }
        
        int minVal = INT_MAX;
        
        for(int i=0; i<plus; ++i){
            for(int j=plus+1; j<n; ++j){
                string s1,s2,s3,s4;
                s1 = expression.substr(0,i);
                s2 = expression.substr(i,plus-i);
                s3 = expression.substr(plus+1,j+1 - plus-1);
                s4 = expression.substr(j+1,n-j-1);
                
                int a,b,c,d;
                a = s1.length() == 0 ? 1 : stoi(s1);
                b = s2.length() == 0 ? 0 : stoi(s2);
                c = s3.length() == 0 ? 0 : stoi(s3);
                d = s4.length() == 0 ? 1 : stoi(s4);
                
                int val = a*(b+c)*d;
                
                if(val < minVal){
                    minVal = val;
                    left = i, right = j+1;
                }
                
            }
        }

        string ans = expression;
        ans.insert(left,1,'(');
        ans.insert(right+1,1,')');  //right + 1 bcoz '(' added so string length increased
        
        return ans;
    }
};