// We will keep track of current capacity.
// when current capacity < capacity
// then we go back to river that will cost us i*2

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        
        int ans = 0, n = plants.size();
        
        int curr_capacity = capacity;
        
        for(int i =0; i<n; i++){
            int plant = plants[i];
            
            if(curr_capacity < plant) {
                ans += (i*2);
                curr_capacity = capacity;
            }
            
            curr_capacity = curr_capacity - plant;
            ans++;
        }
    
        return ans;
    }
};