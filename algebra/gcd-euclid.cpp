#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b) {
  return b? gcd(b, a%b) : a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int x = 20, y = 24;
  cout << gcd(x, y) << '\n';
  
  return 0;
}