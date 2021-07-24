#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  // given arr, n
  int n = 4;
  vector<int> arr = {1, 5, 3, 2}

  // soln
  unordered_map<int, int> freq;
  for(int i=0; i<n; i++) {
    freq[arr[i]]++;
  }
  int count = 0;

  // 0 0 0 
  count += ( freq[0] * (freq[0]-1) * (freq[0]-2) ) / 6;

  // 0 x x
  for(int i=0; i<n; i++) {
    int x = arr[i];
    count += ( freq[0] * freq[x] * (freq[x]-1) ) / 2;
  }

  // x x 2*x
  for(int i=0; i<n; i++) {
    int x = arr[i];
    count += ( freq[x] * (freq[x]-1) * freq[2*x]) / 2;
  }

  // x y x+y
  for(int i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      int x = arr[i];
      int y = arr[j];
      count += (freq[x] * freq[y] * freq[x+y]);
    }
  }

  cout << count << '\n';
  // return count;
  
  return 0;
}