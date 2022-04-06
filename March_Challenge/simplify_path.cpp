class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        int n = path.length();
        
        vector<string> folders = splitString(path);
  
        stack<string> st;
        
        for(int i=0; i<folders.size(); i++){
            if(folders[i] == "." || folders[i] == "") continue;
            else if(folders[i] == "..") {
                if(!st.empty()) st.pop();
            }
            else st.push(folders[i]);
        }
        
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans == "") ans = "/";
        return ans;
    }
    
    
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
};