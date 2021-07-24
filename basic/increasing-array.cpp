#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  
  ll res = 0;
  for(int i=1; i<n; i++) {
    if(a[i-1] > a[i]) res+=(a[i-1]-a[i]), a[i]=a[i-1];
  }
  cout << res << '\n';
  
  return 0;
}