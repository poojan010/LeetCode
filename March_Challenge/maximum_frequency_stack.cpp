class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> mp;
    int maxfreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        maxfreq = max(maxfreq, ++freq[val]);
        mp[freq[val]].push(val);
    }
    
    int pop() {
        int x = mp[maxfreq].top();
        mp[maxfreq].pop();
        if (!mp[freq[x]--].size()) maxfreq--;
        return x;        
    }
};