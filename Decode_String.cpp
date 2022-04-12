class Solution {
public:
    string decodeString(string s) {
        string ans;
        int n = s.length();
        
        for(int i=0; i<n; ++i){
            
            if(isdigit(s[i])) ans += decode(i,s);
            
            else ans.push_back(s[i]);
            
        }
        return ans;
    }
    
    string decode(int& i,string ss){
        string str;
        
        // Decode digit
        string digit_str;
        digit_str.push_back(ss[i++]);
        while(ss[i] != '[') digit_str.push_back(ss[i++]);
        
        int digit = stoi(digit_str);
        
        ++i;
        // Decode repeating substring
        while(ss[i] != ']'){
            if(isdigit(ss[i])) str += decode(i,ss);     // recursion
            else str.push_back(ss[i]);
            i++;
        }
        
        string ans;
        while(digit--) ans += str;
        
        return ans;
        
    }
};