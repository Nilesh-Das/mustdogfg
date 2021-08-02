#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int lowerBound(vector<int>& a, int k) {
    int l = 0, r = a.size();
    while(l < r) {
        int m = l + (r-l)/2;
        if(a[m] < k) l = m + 1;
        else r = m;
    }
    if(l < a.size() && a[l] < k) l++;
    return l;
}

int upperBound(vector<int>& a, int k) {
    int l = 0, r = a.size();
    while(l < r) {
        int m = l + (r-l)/2;
        if(a[m] <= k) l = m + 1;
        else r = m;
    }
    if(l < a.size() && a[l] <= k) l++;
    return l;
}

int binSearch(vector<int>& a, int k) {
    int l = 0, r = a.size();
    while(l < r) {
        int m = l + (r-l)/2;
        if(a[m] < k) l = m + 1;
        else r = m;
    }
    return (a[l] == k ? l : -1);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << lower_bound(a.begin(), a.end(), k)-a.begin() << '\n';
    cout << upper_bound(a.begin(), a.end(), k)-a.begin() << '\n';
    cout << binary_search(a.begin(), a.end(), k) << '\n';
    cout << lowerBound(a, k) << '\n';
    cout << upperBound(a, k) << '\n';
    cout << binSearch(a, k) << '\n';
}