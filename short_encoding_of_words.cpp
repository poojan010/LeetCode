// We will add words in reverse 
// bcoz seen in example : time , me => time#
// We have to find all leaf nodes
// add depths of leaf nodes in ans

class Node {
public:
    bool isEnd;
    vector<Node *> children;       
    Node(): isEnd(false), children(26, nullptr) {}
};

class Trie {
public:
    Node* root = new Node();
    int ans;
    Trie(): ans(0) {}
    
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
    
    int getAns(){
        Node* curr = root;
        int init = 1;       // for depth
        for(int i=0; i<26; i++){
            if(curr->children[i]){
                dfs(curr->children[i],init);
            }
        }
        
        return ans;
    }
    
    void dfs(Node* curr,int index){
        if(curr == NULL) return;
        
        int t = 0;
        for(int i=0; i<26; i++){
            if(curr->children[i]){
                t = 1;
                dfs(curr->children[i],index+1);
            }
        }
        if(t == 0) ans += index+1;
        
        return;
    }
    
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie = Trie();
        
        for(string word : words){
            reverse(word.begin(),word.end());
            trie.insert(word);
        }
    
        int ans = trie.getAns();
        
        return ans;
    }
};