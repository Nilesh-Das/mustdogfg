#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll int64_t
using namespace std;

// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings

ll maxProduct(string s) {
    int n = s.size();
    // no of odd length palindrome with center i
    vector<ll> d(n);
    // max length of odd palindromes from [0:i]
    vector<ll> ltr(n, 1);
    for(ll i = 0, l = 0, r = -1; i < n; i++) {
        ll k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            ltr[i + k] = 2 * k + 1;
            k++;
        }
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    // max length of odd palindromes from [i:n]
    string ns = string(s.rbegin(), s.rend());
    vector<int> rtl(n, 1);
    for(ll i = 0, l = 0, r = -1; i < n; i++) {
        ll k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && ns[i - k] == ns[i + k]) {
            rtl[i + k] = 2 * k + 1;
            k++;
        }
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    reverse(rtl.begin(), rtl.end());
    for(int i = 1; i < n; i++) ltr[i] = max(ltr[i], ltr[i-1]);
    for(int i = n-2; i >= 0; i--) rtl[i] = max(rtl[i], rtl[i+1]);
    ll res = 0;
    for(int i = 1; i < n; i++) res = max(res, ltr[i-1]*rtl[i]);
    return res;
}

/*
ababbb
zaaaxbbby

9
9
*/

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << maxProduct(s) << '\n';
    }
}