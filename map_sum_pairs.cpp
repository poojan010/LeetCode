// we will store keys ans strings
// first we will find end node for prefix string
// then we apply dfs and add all values of all nodes. 

class Node {
public:
    bool isEnd;
    int val;
    vector<Node *> children;       
    Node(): isEnd(false), val(0), children(26, nullptr) {}
};

class MapSum {   
public:
    Node* root = new Node();
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        Node *curr = root;
        
        for(char ch : key){
            int index = ch - 'a';
            
            if(curr->children[index] == NULL)
                curr->children[index] = new Node();
            
            curr = curr->children[index];
        }
        
        curr->isEnd = true;
        curr->val = val;
    }
    
    int sum(string prefix) {
        Node *curr = root;
        int ans = 0;
        
        for(char ch : prefix){
            
            int index = ch - 'a';
            
            if(curr->children[index] == NULL)
                return 0;

            curr = curr->children[index];
        }
        
        ans += dfs(curr);
        
        return ans;
    }
    
    int dfs(Node* node){
        
        if(node == NULL) return node->val;
        
        int curr_sum = node->val;
        
        for(int i=0; i<26; i++){
            if(node->children[i]){
                curr_sum += dfs(node->children[i]);
            }
        }
        
        return curr_sum;
    }
    
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */