// Stores number in trie 
// in form of 1st digit, 2ND digit, .. nth digit.
// then traverse in tree by mode of dfs 
// and when isEnd = true found 
// then calculate number from digits.

class Node {
public:
    bool isEnd;                     
    vector<Node *> children;       
    Node(): isEnd(false), children(10, nullptr) {}
};

class Trie {
public:
    Node *root = new Node();

    vector<int> getDigits(int num){
        vector<int> res;
        while(num > 0){
            res.push_back(num%10);
            num = num/10;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
    
    void insert(int n) {
        Node *curr = root;
        vector<int> digits = getDigits(n);
        
        for(int num : digits){
            if(curr->children[num] == NULL)
                curr->children[num] = new Node();
            
            curr = curr->children[num];
        }

        curr->isEnd = true;
    }

    vector<int> lexicgraphicalNums(){
        vector<int> res;
        string str;
        Node *curr = root;
        dfs(root,res,str);
        return res;
    }
    
    void dfs(Node *curr, vector<int> &res, string &word) {
        
        if (curr->isEnd) {
            int num = 0;
            int n = word.length()-1;
            for(int i=0; i<word.length(); i++){
                num += pow(10,n)*(word[i]-'0');
                n--;
            }
            res.push_back(num);
        }
            
        
        for (int i = 0; i<10; i++) {
            if (curr->children[i]) {
                word.push_back(char('0'+i));
                dfs(curr->children[i], res, word);
                word.pop_back();
            }
        }
         
        return;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        Trie trie = Trie();
        vector<int> ans;
        
        for(int i=1; i<=n; i++) 
            trie.insert(i);

        ans =  trie.lexicgraphicalNums();          
    
        return ans;
    }
};