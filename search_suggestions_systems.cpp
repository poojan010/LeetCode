class Node {
public:
    bool isEnd;                     // last char of word or not 
    vector<Node *> children;        // map for a-z
    Node(): isEnd(false), children(26, nullptr) {}
};

class Trie {
public:
    Node *root = new Node();

    void insert(string &product) {
        Node *curr = root;
        for (char ch : product) {
            int index = ch - 'a';
            if (!curr->children[index]) 
                curr->children[index] = new Node();
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    vector<string> getSuggestions(string &prefix) {
        vector<string> res;
        Node *curr = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!curr->children[index]) return {};
            curr = curr->children[index];
        }
        dfs(curr, res, prefix);
        return res;
    }

    void dfs(Node *curr, vector<string> &res, string &word) {
        if (res.size() == 3) return;
        
        if (curr->isEnd) res.push_back(word);
        
        for (int i = 0; i < 26; ++i) {
            if (curr->children[i]) {
                word.push_back((char) ('a' + i));
                dfs(curr->children[i], res, word);
                word.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        
        vector<vector<string>> ans;
        Trie trie = Trie();
        
        for (auto product : products) 
            trie.insert(product);
        
        string prefix;
        for (char ch : searchWord) {
            prefix.push_back(ch);
            ans.push_back(trie.getSuggestions(prefix));
        }
        return ans;
    }
};