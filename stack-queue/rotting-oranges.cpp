// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        if(!fresh) return 0;
        
        int count = 0;
        while(!q.empty()) {
            int x, y, k = q.size();
            while(k--) {
                tie(x, y) = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2; fresh--;
                    q.push({nx, ny});
                }
            }
            if(!q.empty()) count++;
        }
        return (!fresh ? count : -1);
    }
};