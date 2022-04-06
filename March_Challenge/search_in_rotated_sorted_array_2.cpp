class Solution {
public:
    int search(vector<int>& a, int target) {
        int low = 0, high = a.size() - 1; 
        
        while(low <= high) {
            int mid = low + (high-low)/2;    
            
            if(a[mid] == target) return true; 
            
            // the left side is sorted
            if(a[low] < a[mid]) {
                if(target >= a[low] && target < a[mid]) // target lies in low to mid
                    high = mid - 1; 
                else 
                    low = mid + 1; 
            }
            // right part is sorted
            else if(a[low] > a[mid]) {
                if(target > a[mid] && target <= a[high]) // target lies in low to mid
                    low = mid + 1; 
                else 
                    high = mid - 1; 
            }
            else ++low; // duplicated
        } 
        return false; 
    }
};