class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int curr_area = 0, max_area = 0;
        
        int l=0 , r=height.size()-1;
        
        while(l<r){
            int lh = height[l];
            int lr = height[r];
            
            curr_area = min(lr,lh)*(r-l);
            
            if(curr_area > max_area) max_area = curr_area;
            
            if(lr < lh) r--;
            else l++;
            
        }
        
        return max_area;
        
    }
};