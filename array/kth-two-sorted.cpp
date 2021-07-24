#include <bits/stdc++.h>
#define ll long long
using namespace std;

int bin_search(vector<int> A, vector<int> B, int m, int n, int k) {
  int l=0, r=min(m,k-1), i, j;
  while(l <= r) {
    i = l+(r-l)/2;
    j = k-i-1;

    if(A[i] < B[j-1]) l=i+1;
    else if(i and A[i-1] > B[j]) r=i-1;
    else return min(A[i], B[j]);
  }
  return -1;
}

int findkth(vector<int> A, vector<int> B, int k) {
  int m = A.size();
  int n = B.size();

  if(m+n < k) return -1;

  if(m > n) return bin_search(B,A,n,m,k);
  return bin_search(A,B,m,n,k);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  // 1 2 3 4 6 7 8 9 10
  int k = 6;
  vector<int> A = {2,3,6,7,9};
  vector<int> B = {1,4,8,10};

  cout << findkth(A, B, k) << '\n';
  
  return 0;
}