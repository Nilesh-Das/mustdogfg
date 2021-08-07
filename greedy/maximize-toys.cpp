#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxToys(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    int count = 0, spent = 0;
    for(int x : a) {
        spent += x;
        if(spent > k) break;
        count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << maxToys(a, k) << '\n';
    }
}