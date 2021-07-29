#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> res;

    int rowBegin = 0, rowEnd = n-1;
    int colBegin = 0, colEnd = m-1;

    while(rowBegin <= rowEnd && colBegin <= colEnd) {
        for(int i = colBegin; i <= colEnd; i++) {
            res.push_back(matrix[rowBegin][i]);
        }
        rowBegin++;

        for(int i = rowBegin; i <= rowEnd; i++) {
            res.push_back(matrix[i][colEnd]);
        }
        colEnd--;

        if(rowBegin <= rowEnd) {
            for(int i = colEnd; i >= colBegin; i--) {
                res.push_back(matrix[rowEnd][i]);
            }
        }
        rowEnd--;

        if(colBegin <= colEnd) {
            for(int i = rowEnd; i >= rowBegin; i--) {
                res.push_back(matrix[i][colBegin]);
            }
        }
        colBegin++;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for(int x : spiralOrder(mat)) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}