// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    bool nextPermutation(string& s) {
        if(s.empty()) return false;
        int i = s.size()-1;
        while(i > 0 && s[i] <= s[i-1]) i--;
        if(i == 0) return false;
        
        int j = s.size()-1;
        while(s[j] <= s[i-1]) j--;
        swap(s[i-1], s[j]);
        
        reverse(s.begin()+i, s.end());
        return true;
    }
    
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(!nextPermutation(s)) return -1;
        long res = stol(s);
        if(res > INT_MAX || res <= n) return -1;
        return res;
    }
};