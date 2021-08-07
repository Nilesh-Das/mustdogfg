#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// activity selection
// coin piles
// maximize toys
// page faults lru
// largest no possible
// minimize heights
// minimize sum of prod
// huffman decoding
// min spanning tree
// djikstra

// fractional knapsack can be solved with greedy
// 0/1 knapsack cannot be solved with greedy

// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), res = 0;
        sort(piles.begin(), piles.end());
        for(int i = n/3; i < n; i += 2) res += piles[i];
        return res;
    }
};

int main() {
    int t;
    cin >> t;

    Solution sol;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << sol.maxCoins(a) << '\n';
    }
}