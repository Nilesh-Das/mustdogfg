#include <bits/stdc++.h>
#define ll long long
using namespace std;

int merge(vector<int> &arr, vector<int> &temp, int l, int m, int r)
{
  int count = 0;

  int i = l;
  int j = m+1;
  int k = l;

  while(i<=m && j<=r) {
    if(arr[i] <= arr[j]) temp[k++]=arr[i++];
    else { temp[k++]=arr[j++]; count+=m-i+1; }
  }

  while(i<=m) temp[k++] = arr[i++];
  while(j<=r) temp[k++] = arr[j++];

  for(int i=l; i<=r; i++) arr[i]=temp[i];

  return count;
}

int mergeSort(vector<int> &arr, vector<int> &temp, int l, int r)
{
  int count = 0;
  if(l < r) {
    int m = l + (r-l)/2;
    count += mergeSort(arr, temp, l, m);
    count += mergeSort(arr, temp, m+1, r);
    count += merge(arr, temp, l, m, r);
  }
  return count;
}

int countInversion(vector<int> arr) {
  int n = arr.size();
  vector<int> temp(n);
  return mergeSort(arr, temp, 0, n-1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> arr = {3,1,2};
  cout << countInversion(arr) << '\n';
  
  return 0;
}