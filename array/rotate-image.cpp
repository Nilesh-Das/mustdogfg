#include <bits/stdc++.h>
#define ll long long
using namespace std;

void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  
  for(int i=0; i<n/2; i++) {
    for(int j=0; j<n; j++) {
      swap(matrix[i][j], matrix[n-i-1][j]);
    }
  }
  
  for(int i=1; i<n; i++) {
    for(int j=0; j<i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<vector<int>> matrix;
  matrix = {{1,2,3},{4,5,6},{7,8,9}};
  
  return 0;
}