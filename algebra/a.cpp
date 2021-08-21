#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(vector<int> a) {
  for(auto x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  set<vector<int>, greater<vector<int>>> s;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    s.insert({x, y, i});
  }
  for(auto x : s) {
    print(x);
  }

  if(s.count({0,0,3})) print(*s.find({0,0,3}));
  
  return 0;
}