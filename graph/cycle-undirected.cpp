#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool cycle, vis[N];
int par[N];

bool dfs(int u, int p) {
	vis[u] = true;
	for(int v : adj[u]) {
		if(v == p) continue;
		if(vis[v]) {cycle=true; return true;}
		par[v] = u;
		if(dfs(v, u)) return true;
	}
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
		if(!vis[i] && dfs(i, par[i])) break;
	cout << (cycle ? "Yes\n" : "No\n");
	cycle = false;
	for(int i = 0; i < N; i++) adj[i].clear();
	memset(vis, 0, sizeof(vis));
	memset(par, -1, sizeof(par));
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