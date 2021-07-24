#include <bits/stdc++.h>

using namespace std;

long sum(vector<int> &bit, int i) {
  long res = 0;
  for(; i<(int)bit.size(); i+=i&-i)
    res += bit[i];
  return res;
}

void insert(vector<int> &bit, int i) {
  for(; i; i-=i&-i) bit[i]+=1;
}

long countInversions(vector<int> arr) {
  int n = arr.size();
  long count = 0;
  vector<int> temp = arr;
  sort(temp.begin(), temp.end());
  
  vector<int> bit(n+1);
  
  for(int i=0; i<n; i++) {
    int t = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
    arr[i] = t;
  }
  
  
  for(int i=0; i<n; i++) {
    count += sum(bit, arr[i]+1);
    insert(bit, arr[i]);
  }
  
  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
      cin >> arr[i];
    }        
    cout << countInversions(arr) << '\n';
  }
}