// We will store all indexes of char in map by key value = char
// then we will check all words
// upper_bound value gives ref of value greater than "curr"(see function call) 
// we will update curr value 
// if upper_bound gives end value 
// that means no char found greater than curr => then solution not possible
// if traverse all char of word then it is counted as matching subsequence.

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        map<char,vector<int>> mpp;
        
        int i = 0;
        for(char ch : s) mpp[ch].push_back(i++);
    
        int ans = 0;
        
        for(string word : words){
            int curr = -1;
            int n = word.length();
            
            for(int i=0; i<n; i++){
                
                char c = word[i];
                if(mpp.find(c) == mpp.end()) break;
                
                auto it = upper_bound(mpp[c].begin(),mpp[c].end(),curr);
                if(it == mpp[c].end()) break;
                curr = *it;
                
                if(i == n-1) ans++;
            }
            
        }
        
        
        return ans;
    }
};