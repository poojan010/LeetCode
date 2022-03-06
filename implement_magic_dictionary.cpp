// i will store strings of equal length in map.
// then i will check searchWord
// in map[searchWoed.length]
// i will iterate through every string 
// check if char diff is 1 bw searchWord & string
// if yes => answer found.

class MagicDictionary {
public:
    map<int,vector<string>> mp;
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        for(string word : dictionary){
            int n = word.length();
            mp[n].push_back(word);
        }
    }
    
    bool search(string searchWord) {
        
        int n = searchWord.length();
        bool ans = false;
        
        vector<string> words = mp[n];
        
        for(string word : words){
            int count = 0;
            for(int i=0; i<n; i++){
                if(word[i] != searchWord[i]) count++;
                if(count > 1) break;
            }
            if(count == 1){ 
                ans = true;
                break;
            }

        }
        
        return ans;
    }

};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */