// https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> mp;
    int maxfreq;
public:
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        maxfreq = max(maxfreq, freq[val]);
        mp[freq[val]].push(val);
    }
    
    int pop() {
        int x = mp[maxfreq].top(); mp[maxfreq].pop();
        if(mp[freq[x]].empty()) maxfreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */