#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(matrix[mid][0] < target) l = mid + 1;
            else r = mid;
        }
        if(l < n && matrix[l][0] == target) return 1;
        if(l == 0) return 0;
        int i = l - 1;
        
        l = 0, r = m;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(matrix[i][mid] < target) l = mid + 1;
            else r = mid;
        }
        if(l < m && matrix[i][l] == target) return 1;
        return 0;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        Solution sol;
        cout << sol.searchMatrix(v, k) << '\n';
    }
}