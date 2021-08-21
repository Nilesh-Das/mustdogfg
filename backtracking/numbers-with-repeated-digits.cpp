// https://leetcode.com/problems/numbers-with-repeated-digits/

#include <iostream>
using namespace std;

class Solution {
public:
    void backtrack(long curr, int mask, int& N, int& uniqueDigits) {
        if(curr > N) return;
        uniqueDigits++;
        for(int digit = 0; digit < 10; digit++) {
            if(!mask && !digit) continue;
            if(mask & (1 << digit)) continue;
            backtrack(curr*10 + digit, mask|(1<<digit), N, uniqueDigits);
        }
    }

    int numDupDigitsAtMostN(int N) {
        int uniqueDigits = 0;
        backtrack(0, 0, N, uniqueDigits);
        return N - uniqueDigits + 1;
    }
};

int main() {
    int t;
    cin >> t;
    Solution sol;
    while(t--) {
        int n;
        cin >> n;
        cout << sol.numDupDigitsAtMostN(n) << '\n';
    }
}