#include <bits/stdc++.h>
#define ll long long
using namespace std;

// check for pythagorean triplets
bool checkTriplet(int arr[], int n) {
  int big = *max_element(arr, arr+n);

  unordered_map<int, bool> mp;
  for(int i=0; i<n; i++) {
    mp[arr[i]] = 1;
  }

  for(int i=1; i<big; i++) {
    for(int j=i+1; j<=big; j++) {
      if(mp[i] & mp[j]) {
        int c = sqrt(i*i + j*j);

        if(c >= i+j) continue;

        if(c*c != i*i + j*j) continue;

        if(c > big) continue;

        if(mp[c]) return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int arr[] = {6,5,4,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << (checkTriplet(arr, n) ? "YES" : "NO") << '\n';
  
  return 0;
}