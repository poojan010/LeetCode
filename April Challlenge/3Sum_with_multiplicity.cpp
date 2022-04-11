class Solution {
    int MOD = int(1e9 + 7);
public:
    int threeSumMulti(vector<int>& nums, int target) {
        
        long ans = 0;
        int n = nums.size();
        unordered_map<int, long> c;
        
        for(int num : nums) ++c[num];
        
        for (auto it1 : c){
            for (auto it2 : c) {
                int i = it1.first, j = it2.first, k = target - i - j;
                
                if (!c.count(k)) continue;
                
                if (i == j && j == k){      // nC3
                    ans += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                }
                else if (i == j && j != k){  // 1st can be filled in i ways, 2nd i-1 ways, 3rd in k ways
                    ans += c[i] * (c[i] - 1) / 2 * c[k];
                }
                else if (i < j && j < k){  // 1st box is filled in i ways, 2nd in j ways, 3rd in k ways
                    ans += c[i] * c[j] * c[k];
                }
                    
            }
        }
        
        return (int)(ans % MOD);

    }
};