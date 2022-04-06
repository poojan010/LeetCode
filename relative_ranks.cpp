// compare function for max heap
struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first) return true;       
        return false;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;
        
        for(int i=0;i<n;++i) max_heap.push({score[i],i});
        
        int i=1;
        vector<string> ans(n);
        
        while(max_heap.size()){ 
            if(i == 1){
                int index = max_heap.top().second;
                ans[index] = "Gold Medal";
            }
            else if(i == 2){
                int index = max_heap.top().second;
                ans[index] = "Silver Medal";
            }
            else if(i == 3){
                int index = max_heap.top().second;
                ans[index] = "Bronze Medal";
            }
            else{
                int index = max_heap.top().second;
                ans[index] = to_string(i);
            }

            max_heap.pop();
            ++i;
        }

        return ans;
    }
};