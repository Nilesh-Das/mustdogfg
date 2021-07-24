#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n = 5;
  vector<int> arr = {1,2,3,-2,5};

  // kadane algo
  int curr = 0, best = INT_MIN;
  for(int i=0; i<n; i++) {
    curr = max(arr[i], curr + arr[i]);
    best = max(best, curr);
  }
  cout << best << '\n';
  // return best;
  
  return 0;
}