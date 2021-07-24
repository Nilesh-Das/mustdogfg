#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int N = 1e5;
vector<int> adj[N];
int mark[N], par[N];
bool cycle;

bool dfs(int u) {
	mark[u] = 1;
	for(int v : adj[u]) {
		if(mark[v] == 0) {
			par[v] = u;
			if(dfs(v)) return true;
		}
		if(mark[v] == 1) {
			return true;
		}
	}
	mark[u] = 2;
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
		if(mark[i]==0 && dfs(i)) break;
	cout << (cycle ? "Yes\n" : "No\n");

	// reset
	cycle = false;
	for(int i = 0; i < N; i++) adj[i].clear();
	memset(mark, 0, sizeof(mark)); 
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