#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

*/

int minSOP(vector<int>& a, vector<int>& b) {
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int res = 0;
    for(int i = 0; i < n; i++) 
        res += a[i]*b[i];
    return res;
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
        cout << minSOP(a, b) << '\n';
    }
}