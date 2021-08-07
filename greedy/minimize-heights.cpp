#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minHeights(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    int res = a[n-1] - a[0];
    for(int i = 1; i < n; i++) {
        if(a[n-1] >= k && a[i] >= k) {
            int mx = max(a[i-1]+k, a[n-1]-k);
            int mn = min(a[0]+k, a[i]-k);
            res = min(res, mx-mn);
        } 
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << minHeights(a, k) << '\n';
    }
}