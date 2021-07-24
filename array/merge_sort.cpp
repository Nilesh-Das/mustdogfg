#include <bits/stdc++.h>
#define ll long long
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int i, j, k;

  vector<int> L(n1), R(n2);
  for(i=0; i<n1; i++) L[i]=arr[l+i];
  for(i=0; i<n2; i++) R[i]=arr[m+i+1];

  for(i=0, j=0, k=l; i<n1 && j<n2; k++) {
    if(L[i] <= R[j]) arr[k] = L[i++];
    else arr[k] = R[j++];
  }

  while(i<n1) arr[k++]=L[i++]; 
  while(j<n2) arr[k++]=R[j++]; 
}

void merge_sort(vector<int> &arr, int l, int r) {
  if(l < r) {
    int m = l + (r-l)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n = 5;
  vector<int> arr = {3, 4, 2, 1, 5};

  merge_sort(arr, 0, n-1);

  for(int x : arr)
    cout << x << ' ';
  cout << '\n';
  
  return 0;
}