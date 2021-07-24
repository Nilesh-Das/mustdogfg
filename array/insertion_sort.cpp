#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> a = {1, 3, 5, 2, 4};
  int n = a.size();

  int key;
  for(int i=1; i<n; i++) {
    int j, key=a[i];
    for(j=i-1; j>=0 && a[j]>key; j--) {
      a[j+1] = a[j];
    }
    a[j+1] = key;
  }

  for(int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  
  return 0;
}