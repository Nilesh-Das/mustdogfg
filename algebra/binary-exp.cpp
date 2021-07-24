#include <bits/stdc++.h>
#define ll long long
using namespace std;

int bin_exp(int x, int y) {
  int res = 1;
  while(y) {
    if(y&1) res = res*x;
    x = x*x;
    y >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int x = 5, y = 3;
  cout << bin_exp(x, y) << '\n';
  
  return 0;
}