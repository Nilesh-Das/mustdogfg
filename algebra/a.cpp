#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int tt;
  cin >> t;
  while(tt--) {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << ' ';
    cout << lcm(a, b) << '\n';
  }
  
  return 0;
}