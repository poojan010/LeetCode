// traverse in trie tree
// only for nodes which has isEnd = true.
// update ans string whenever curr string size > ans string size

class Node {
public:
    bool isEnd;                     
    vector<Node *> children;       
    Node(): isEnd(false), children(26, nullptr) {}
};

class Trie {
public:
    Node* root = new Node();
    Trie() {}
    
    void insert(string word) {
        Node *curr = root;
        
        for(char ch : word){
            int index = ch - 'a';
            if(curr->children[index] == NULL)
                curr->children[index] = new Node();
            
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    
    string getLongestWord() {
        Node *curr = root;
        
        string ans,str;
        
        dfs(curr,str,ans);
        
        return ans;
    }
    
     void dfs(Node* node,string& curr, string& ans){
        
        if(node == NULL) return;
        
        if(curr.length() > ans.length()) ans = curr;
        
        for(int i=0; i<26; i++){
            if(node->children[i] && node->children[i]->isEnd){
                curr.push_back((char)('a'+i));
                dfs(node->children[i],curr,ans);
                curr.pop_back();
            }
        }
        
        return;
    }

};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie = Trie();
        
        for(string word : words) trie.insert(word);
        
        string ans = trie.getLongestWord();
        
        return ans;
    }
};