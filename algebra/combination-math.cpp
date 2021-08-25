#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int N = 1e5;
const int mod = 1e9 + 7;
vector<long> fact(N + 1);
vector<long> invfact(N + 1);

long exp(long x, long y) {
  long res = 1;
  while(y) {
    if(y & 1) res = (res*x) % mod;
    x = (x*x) % mod;
    y >>= 1;
  }
  return res;
}

long inv(long x) {
  return exp(x, mod - 2);
}

long mul(long x, long y) {
  return (x * y) % mod;
}

void init() {
    invfact[1] = invfact[0] = fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++) {
        fact[i] = mul(fact[i - 1], i);
        invfact[i] = mul(invfact[i - 1], inv(i));
    }
}

long C(long n, long k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  init();
  int x = 5, y = 3;
  cout << C(x, y) << '\n';
  
  return 0;
}