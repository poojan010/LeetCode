class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        
        vector<int> odds, evens;
        
        for(int i=0; i<str.length(); i++){
            int ch = str[i] - '0';
            if(ch%2 == 0){
                evens.push_back(ch);
                str[i]= 'e';
            }
            else{
                odds.push_back(ch);
                str[i] = 'o';
            }
        }
        
        sort(odds.begin(),odds.end());
        sort(evens.begin(),evens.end());
        
        for(int i=0; i<str.length(); ++i){
            if(str[i] == 'o'){
                char ch = (char)('0'+odds.back());
                odds.pop_back();
                str[i] = ch;
            }
            else{
                char ch = (char)('0'+evens.back());
                evens.pop_back();
                str[i] = ch;
            }
        }
        cout << str;
        return stoi(str);
    }
};