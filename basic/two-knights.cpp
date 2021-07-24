#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  // a(n) = (n - 1)(n + 4)(n^2 - 3n + 4)/2
  for(ll k=1; k<=n; k++) {
    ll total = ((k*k) * (k*k-1)) / 2;
    ll star = 4*(k-1)*(k-2);
    cout << (total - star) << '\n';
  }
  
  return 0;
}