class Node {
public:
    bool isEnd;
    map<char,Node *> children;       
    Node(): isEnd(false) {}
};
class Trie {
public:
    Node *root = new Node();
    Trie(){} 
    
    void insert(string &word) {
        Node *curr = root;
        for(char ch : word){
            if(curr->children[ch] == NULL){
                curr->children[ch] = new Node();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }

    bool check(string &word){
        Node *curr = root;
        for(char ch : word){
            if(curr->children[ch] == NULL){
                if(isupper(ch)) return false;   // bcoz only lowercase letters are allowd.
            }
            else curr = curr->children[ch];
        }
        if(curr->isEnd) return true;        // If any char remains from pattern then solution not possible.
        return false;
    }
    
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie trie = Trie();
        trie.insert(pattern);
        
        int n = queries.size();
        vector<bool> ans(n);
        
        for(int i=0; i<n; i++){
            string query = queries[i];
            ans[i] = trie.check(query);
        }
        
        return ans;
    }
};