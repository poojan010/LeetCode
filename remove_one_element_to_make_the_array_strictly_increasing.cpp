// Whenever num[i] > num[i+1] found
// then we will form two arrays left and right.
// and check if right array is sorted or not
// not sorted => print false
// then we will check compare left[x-1], left[x-2], right[0], right[1]
// see compare conditions in code.
// one of (x-1) or (x-2) < right[0] or right[1] => true 
// else => false

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        
        int n = nums.size();
        
        
        vector<int> first, last;
        int index = n-1;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1])
                first.push_back(nums[i-1]);
            else{
                first.push_back(nums[i-1]);
                last.push_back(nums[i]);
                index = i;
                break;
            }
        }
        
        while(index < n-1){
            if(nums[index] >= nums[index+1]) return false;
            last.push_back(nums[index+1]);
            index++;
        }
        
        for(int num : first) cout << num << " ";
        cout << "\n";
        for(int num : last) cout << num << " ";
        
        if(first.size() > 0 && last.size() > 0){
            if(first.size() == 1 || last.size() == 1) return true;
            
            int x = first.size(), y = last.size();
            if(first[x-1] < last[0]) return true;
            if(first[x-2] < last[0]) return true;
            if(first[x-1] < last[1]) return true;
            return false;
        }
        
        return true;
    }
};