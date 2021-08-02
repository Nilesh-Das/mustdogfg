#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<int> ans, vis;

void dfs(int u, int p=-1) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs(v);
    ans.push_back(u);
}

void toplogicalSort(int n) {
    ans.clear();
    vis.assign(n, 0);
    for(int i = 0; i < n; i++)
        if(!vis[i]) dfs(i);
    reverse(ans.begin(), ans.end());
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    toplogicalSort(n);
    for(int x : ans) cout << x+1 << ' ';
    cout << '\n';
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