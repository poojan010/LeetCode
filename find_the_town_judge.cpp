class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> people(n+1);
        
        for(auto nums : trust) people[nums[0]] = 1;
        
        int poss_judge = -1;
        for(int i=1; i<=n ; i++) {
            if(people[i] != 1) poss_judge = i;
        }
        if(poss_judge == -1) return -1;

        int count = 0;
        for(auto nums : trust) if(nums[1] == poss_judge) count++;
        
        return (count == n-1) ? poss_judge : -1;
    
    }
};