// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m));
        for (int d = 2; d < m; ++d) {
            for (int i = 0; i < m - d; ++i) {
                int j = i + d;
                dp[i][j] = 1e9;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][m - 1];
    }
};