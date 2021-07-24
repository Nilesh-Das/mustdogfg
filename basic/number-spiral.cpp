#include <iostream>
#define ll long long
using namespace std;

void find(ll x, ll y) {
  if(x==y) {
    cout << x*(x-1)+1 << '\n';
    return;
  }
  ll r, c;
  if(x > y) {
    if(x&1) {
      r=(x-1)*(x-1)+1;
      cout << r+y-1 << '\n';
    } else {
      r=x*x;
      cout << r-y+1 << '\n';
    }
    return;
  }
  if(x < y) {
    if(y&1) {
      c=y*y;
      cout << c-x+1 << '\n';
    } else {
      c=(y-1)*(y-1)+1;
      cout << c+x-1 << '\n';
    }
    return;
  }
} 

int main() {
  int q;
  cin >> q;
  while(q--) {
    ll x, y;
    cin >> x >> y;

    find(x, y);
  }
}
