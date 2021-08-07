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

/*
input:
2
3
10 12 20
20 25 30
6
1 3 0 5 8 5
2 4 6 7 9 9
output:
2
4
*/

int activitySelection(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({a[i], b[i]});
    }
    auto comp = [&](vector<int>& x, vector<int>& y) {
        return x[1] < y[1];
    };
    sort(v.begin(), v.end(), comp);
    int count = 1, prev = v[0][1];
    for(int i = 1; i < n; i++) {
        cout << prev << ' ' << v[i][0] << '\n';
        if(prev <= v[i][0]) {
            prev = v[i][1];
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        cout << activitySelection(a, b) << '\n';
    }
}