// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp) {
        if(m == 1 || n == 1) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        dp[m-1][n] = solve(m-1, n, dp);
        dp[m][n-1] = solve(m, n-1, dp);
        return dp[m][n] = dp[m-1][n] + dp[m][n-1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, dp);
    }
};