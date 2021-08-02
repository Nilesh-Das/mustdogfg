#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int N = 1e5;
vector<int> adj[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    
    for(int i = 0; i < N; i++) adj[i].clear();
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