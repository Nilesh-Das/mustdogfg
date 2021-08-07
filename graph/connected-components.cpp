#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int src, vector<bool>& vis, vector<vector<int>>& adj) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = true;
        for(int v : adj[u]) {
            if(!vis[v]) q.push(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            bfs(i, vis, adj);
            count++;
        }
    }
    cout << count << '\n';
}