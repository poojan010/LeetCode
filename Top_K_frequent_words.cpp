struct CompareHeapElements {
    bool operator()(pair<int,string> const& p1, pair<int,string> const& p2)
    {
        if(p1.first > p2.first) return true;  
        else if(p1.first == p2.first && p1.second < p2.second) return true;
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        
        for(string str : words) ++mp[str];
        
        // so we get max frequncy words during pop operation
        priority_queue<pair<int,string>, vector<pair<int,string>>,CompareHeapElements> max_heap;
        
        for(auto it : mp){
            string a = it.first;
            int b = it.second;
            cout << a << " : " << b << endl;
            max_heap.push({b,a});
            if(max_heap.size() > k) max_heap.pop(); // we do not need words after kth max words element.
        }
        
        vector<string> ans;
        
        while(max_heap.size()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};