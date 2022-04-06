// compare function for max heap
struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first) return true;      
        else if(p1.first==p2.first && p1.second<p2.second) return true;     
        return false;
    }
};

class Solution {
    // calculate the soldier count using binary search
    int calculateSoldierCount(vector<int>& v) {
        int low = 0; int high = v.size()-1;
        
        while(low <= high) {
            
            int mid = low + (high-low)/2;
            
            if(v[mid]==0) high = mid-1;
            
            else low = mid+1;
            
        }
        return high;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // We will use max_heap of pairs because we need the top k minimum strength row index(s)
        // element of max_heap => {each row soldier count,row index}.
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;
        

        for(int i=0;i<mat.size();++i){
            max_heap.push({calculateSoldierCount(mat[i]),i});
            // pair after kth pair is not needed.
            if(max_heap.size()>k) max_heap.pop();
        }
        
        vector<int>ans;
        
        while(max_heap.size()){ 
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }

        // added in order that highest soldier count index will be at last index
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};