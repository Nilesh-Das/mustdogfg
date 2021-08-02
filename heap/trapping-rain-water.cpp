#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int trappingRainwater(vector<int>& height) {
    int n = height.size();
    if(n == 0) return 0;

    vector<int> vis(n);
    vector<int> dir = {-1, 1};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({height[0], 0}); vis[0] = 1;
    pq.push({height[n-1], n-1}); vis[n-1] = 1;

    int ans = 0;
    int h, x;
    while(!pq.empty()) {
        tie(h, x) = pq.top(); pq.pop();
        for(int d : dir) {
            int nx = x + d;
            if(nx < 0 || nx >= n || vis[nx]) continue;
            vis[nx] = 1;
            if(h > height[nx]) ans += h - height[nx];
            pq.push({max(h, height[nx]), nx});
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cout << trappingRainwater(a) << '\n';
    }
}