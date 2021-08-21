// https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = right;
        while(res > left) res &= (res - 1);
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        Solution sol;
        cout << sol.rangeBitwiseAnd(l, r) << '\n';
    }
}