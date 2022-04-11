class Solution {
public:
    bool validPalindrome(string s) {

        for (int i = 0, j = s.size() - 1; i < j; i++, j--){ 
            
            if(s[i] == s[j]) continue;      

            // if non equal characters are found 
            // then we have 2 choices 
            // either skip last element of that string or first element of string
            // and then check if one of them can make string palindrome or not
            int len = j - i;            
            string str1 = s.substr(i,len);
            string str2 = s.substr(i+1,len);

            return isPalindrome(str1) || isPalindrome(str2);

        }
        
        return true;
    }
    
    
    bool isPalindrome(string s){
        
        int start = 0, end = s.length() - 1;
        
        while(start < end){
            if(s[start] != s[end]) return false;
            ++start, --end;
        }
        
        return true;
    }
};