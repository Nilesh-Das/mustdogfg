#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool vis[N];

void bfs(int u, int p=-1) {
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		vis[node] = true;
		cout << node+1 << ' ';
		for(int v : adj[node])
			if(!vis[v]) q.push(v);
	}
	cout << '\n';
	for(int i = 0; i < N; i++) adj[i].clear();
	memset(vis, 0, sizeof(vis));
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(0);
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