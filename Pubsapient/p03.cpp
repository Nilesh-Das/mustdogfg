#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // djikstra
    int src = 1, tar = 5;
    vector<int> dist(n+1, 1e9);
    vector<int> par(n+1, -1);
    dist[src] = 0;
    set<vector<int>> pq;
    pq.insert({dist[src], src});
    while(!pq.empty()) {
        int u = (*s.begin())[1];
        s.erase(s.begin());
        if(vis[u]) continue;
        vis[u] = true;
        if(u == tar) break;
        for(auto e : adj[u]) {
            int v = e[0];
            int d = e[1];
            if(dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                par[v] = u;
                s.insert({dist[v], v});
            }
        }
    }
    if(!vis[tar]) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> path;
    for(int v = tar; v != src; v = par[v]) {
        path.push_back(v);
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    for(int x : path) {
        cout << x << ' ';
    }
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