// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int start = image[sr][sc];
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,-1,1};
        vector<vector<int>> vis(n, vector<int>(m));
        
        function<void(int, int)> dfs = [&](int x, int y) {
            if(x < 0 || x >= n || y < 0 || y >= m) return;
            if(image[x][y] != start || vis[x][y]) return;
            image[x][y] = newColor; vis[x][y] = 1;
            for(int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i]);
        };
        
        dfs(sr, sc);
        return image;
    }
};