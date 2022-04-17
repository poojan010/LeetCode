class Solution {
    map<int,int> mp;
public:
    int minimumRounds(vector<int>& tasks) {
        for(int task : tasks) ++mp[task];
        
        int ans = 0;
        
        for(auto it : mp){
            int x = it.second;
            
            if(x == 1) return -1;
            
            if(x%3 == 0){
                ans += x/3;
            }
            else if(x%3 == 2){
                ans += ((x/3) + 1);
            }
            else{
                x -= 4;
                ans += ((x/3) + 2);
            }
            
        }
        
        return ans;
    }
};