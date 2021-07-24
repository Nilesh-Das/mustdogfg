#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  bool row = 0, col = 0;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(matrix[i][j] == 0) {
        if(i == 0) row = 1;
        if(j == 0) col = 1;
        matrix[i][0] = matrix[0][j] = 0;
      }
    }
  }

  for(int i=1; i<n; i++) {
    for(int j=1; j<m; j++) {
      if(matrix[i][0] == 0 || matrix[0][j] == 0)
        matrix[i][j] = 0;
    }
  }

  if(col) for(int i=0; i<n; i++) matrix[i][0] = 0;
  if(row) for(int j=0; j<m; j++) matrix[0][j] = 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    
  vector<vector<int>> matrix;
  matrix = {{1,1,1},{1,0,1},{1,1,1}};
  setZeroes(matrix);
  for(int x : matrix) {
    for(int y : x) {
      cout << y << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}