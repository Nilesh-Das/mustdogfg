#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

void solve() {
    string s; int k;
    cin >> s >> k;

    int n = s.size();
    vector<int> cnt(26);
    int j = 0, res = 0;
    for(int i = 0; i < n; i++) {
        while(cnt[s[i]-'a'] + 1 > k) {
            cnt[s[j]-'a']--;
            j++;
        }
        cnt[s[i]-'a']++;
        res++;
    }
    cout << res << '\n';
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