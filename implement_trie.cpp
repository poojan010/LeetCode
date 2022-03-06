// Proper trie data structure implementation.

class Node {
public:
    bool isEnd;                     
    vector<Node *> children;       
    Node(): isEnd(false), children(26, nullptr) {}
};

class Trie {
public:
    Node* root = new Node();
    Trie() {
           
    }
    
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
    
    bool search(string word) {
        Node *curr = root;
        
        for(char ch : word){
            int index = ch - 'a';
            if(curr->children[index] == NULL)
                return false;
            
            curr = curr->children[index];
        }
        
        return curr->isEnd ? true : false;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        
        for(char ch : prefix){
            int index = ch - 'a';
            if(curr->children[index] == NULL)
                return false;
            
            curr = curr->children[index];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */