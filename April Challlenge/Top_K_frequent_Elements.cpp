// compare function for max heap
struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first>p2.first) return true;        
        return false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        for(int num : nums) ++mp[num];
        
        // so we get max frequncy elements during pop operation
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;
        
        for(auto it : mp){
            int a = it.first, b = it.second;
            max_heap.push({b,a});
            if(max_heap.size() > k) max_heap.pop(); // we do not need elements after kth max frequent element.
        }
        
        vector<int> ans;
        
        while(max_heap.size()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        
        return ans;
    }
};