// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> mp;
        stack<int> stk;
        for(int x : b) {
            while(!stk.empty() && stk.top() < x) {
                mp[stk.top()] = x;
                stk.pop();
            }
            stk.push(x);
        }
        vector<int> res;
        for(int x : a) {
            if(mp.find(x) == mp.end()) 
                res.push_back(-1);
            else
                res.push_back(mp[x]);
        }
        return res;
    }
};