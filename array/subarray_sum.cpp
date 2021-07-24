#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int &n, int &s)
{
  int l = 0;
  int curr = arr[0];
  
  for(int r=0; r<n; r++) {
    while(curr > s && l < r) {
      curr -= arr[l++];
    }

    if(curr == s) {
      return {l+1, r+1};
    }
    
    if(r+1 < n) curr += arr[r+1];
  }

  return {-1};
}

int main() {
  int n=5, s=12;
  vector<int> arr = {1, 2, 3, 7, 5};
  
  for(int x : subarraySum(arr, n, s))
    cout << x << ' ';
  cout << '\n';
}
