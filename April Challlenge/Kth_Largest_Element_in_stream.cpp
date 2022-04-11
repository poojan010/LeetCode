
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> max_heap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int num : nums) {
            max_heap.push(num);
            if(max_heap.size() > K) max_heap.pop();
        }
    }
    
    int add(int val) {
        max_heap.push(val);
        if(max_heap.size() > K) max_heap.pop();
        return max_heap.top();
    }
};