// We will check all words of strings
// for a word
// we check if it exsits or not
// if not then return word
// else when we found first isEnd true
// while searching that word we will return string upto that word.

class Node {
public:
    bool isEnd;                     
    unordered_map<char,Node *> children;       
    Node(): isEnd(false) {}
};

class Trie {
public:
    Node *root = new Node();
    
    void insert(string &word) {
        Node *curr = root;
        
        for(auto ch : word){
            if(curr->children.find(ch) == curr->children.end()){
                curr->children[ch] = new Node();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }

    string getRootValue(string &word){
        Node *curr = root;
        
        string res = "";
 
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(curr->isEnd) return res;
            if(curr->children.find(ch) == curr->children.end()) 
                return word;
            
            res = res + ch;
            curr = curr->children[ch];
        }
        
        return res;
    }
    
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        Trie trie = Trie();
        
        for (auto word : dictionary)
            trie.insert(word);

        string ans;

        vector<string> newSentence = splitString(sentence);
        
        for(auto word : newSentence){
            string newWord = trie.getRootValue(word);
            ans = ans + newWord + " ";
        }
        
        ans.pop_back();
        
        return ans;
    }
    
private :
    vector<string> splitString(string &str){
        vector<string> splits;
        string del = " ";
        int start = 0;
        int end = str.find(" ");
        
        while(end != -1){
            string token = str.substr(start, end - start);
            if(token.length() != 0) splits.push_back(token);
            start = end + del.size();
            end = str.find(del, start);
        }
        splits.push_back(str.substr(start, end - start));
        
        return splits;
    }
}; 