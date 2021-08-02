#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int nqueen(int n) {
    vector<vector<int>> grid(n, vector<int>(n));
    vector<bool> d1(2*n), d2(2*n), col(2*n);
    int res = 0;

    function<void(int)> util = [&](int r) {
        if(r == n) { res++; return; }
        for(int c = 0; c < n; c++) {
            if(!col[c] && !d1[r-c+n-1] && !d2[r+c]) {
                col[c] = d1[r-c+n-1] = d2[r+c] = grid[r][c] = 1;
                util(r+1);
                col[c] = d1[r-c+n-1] = d2[r+c] = grid[r][c] = 0;
            }
        }
    };

    util(0);
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << nqueen(n) << '\n';
    }
    return 0;
}