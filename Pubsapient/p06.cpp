#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<string> rbt;
    for(int mask = 0; mask < (1<<n); mask++) {
        string t;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) t += s[i];
        }
        rbt.insert(t);
    }
    for(string x : rbt) 
        cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}