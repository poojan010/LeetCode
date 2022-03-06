// Firts i have removed "/" from string 
// and inserted folders in trie
// while traversing through trie
// when isEnd true founr
// then 1. clear all key value pairs
// 2. strore string upto that in ans vector 

class Node {
public:
    bool isEnd;                     
    unordered_map<string,Node *> children;       
    Node(): isEnd(false) {}
};

class Trie {
public:
    Node *root = new Node();

    vector<string> splitString(string &str){
        vector<string> splits;
        string del = "/";
        int start = 0;
        int end = str.find("/");
        
        while(end != -1){
            string token = str.substr(start, end - start);
            if(token.length() != 0) splits.push_back(token);
            start = end + del.size();
            end = str.find(del, start);
        }
        splits.push_back(str.substr(start, end - start));
        
        return splits;
    }
    
    void insert(string &folder) {
        Node *curr = root;
        vector<string> folderNames = splitString(folder);
        for(auto name : folderNames){
            if(curr->children.find(name) == curr->children.end())
                curr->children[name] = new Node();
                curr = curr->children[name];
        }

        curr->isEnd = true;
    }


    void dfs(Node *curr, vector<string> &res, string &word) {
        if (curr == NULL) return;
        
        if (curr->isEnd) {
            for (auto it : curr->children)
                curr->children[it.first] = NULL;
    
            res.push_back(word);
            return;
        }
        
        for (auto it : curr->children) {
                
                string oldWord = word;
                word = word + "/" + it.first;

                dfs(curr->children[it.first], res, word);       
            
                word = oldWord;
        }
    }
    
    vector<string> removeSubFolders(){
        Node *curr = root;
        vector<string> res; 
        string str;
        dfs(curr,res,str);
        return res;
    }
    
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        Trie trie = Trie();
        
        for (auto fold : folder)
            trie.insert(fold);
            

        return trie.removeSubFolders();
    } 
    
};