// https://leetcode.com/problems/number-of-islands/

class Solution {
    int n, m;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
public:
    void dfs(vector<vector<char>> &g, int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return;
        if(g[x][y] != '1') return;
        g[x][y] = '0';
        for(int i = 0; i < 4; i++) 
            dfs(g, x+dx[i], y+dy[i]);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) { 
                if(grid[i][j] == '0') continue; 
                dfs(grid, i, j); 
                count++; 
            }
        }

        return count;
    }
};