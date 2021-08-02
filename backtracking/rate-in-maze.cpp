#include <iostream>
#include <vector>
using namespace std;

// Rat in Maze
class Solution {
    int n;
    vector<vector<bool>> grid;
    vector<vector<bool>> soln;

public:
    Solution(int x) {
        n = x;
        grid.resize(n,vector<bool>(n));
        soln.resize(n,vector<bool>(n));
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            for(int j=0; j<n; j++) {
                grid[i][j] = (s[j]=='o');
            }
        }
    }

    void print() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cout << (soln[i][j]? "o":"x");
            cout << "\n";
        }
    }

    bool isNotSafe(int x, int y) {
        return (x<0 or y<0 or x>=n or y>=n or !grid[x][y]);
    }

    bool isEnd(int x, int y) {
        return (x==n-1 && y==n-1);
    }

    bool util(int x, int y) {
        if(isNotSafe(x,y)) return 0;
        soln[x][y] = 1;
        if(isEnd(x,y)) return 1;
        if(util(x+1, y)) return 1;
        if(util(x, y+1)) return 1;
        soln[x][y] = 0;
        return 0;
    }

    void solve() {
        if(util(0,0)) print();
        else cout << "No\n";
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    Solution obj(n);
    obj.solve();

    return 0;
}
