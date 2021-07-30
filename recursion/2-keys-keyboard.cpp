// https://leetcode.com/problems/2-keys-keyboard/

class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if(n == 1) return 0;
        if(dp[n] != -1) return dp[n];
        int best = 1e9;
        for(int i = 1; i <= n/2; i++) {
            if(n % i == 0) 
                best = min(best, solve(dp, i) + n/i);
        }
        return dp[n] = best;
    }
    
    int minSteps(int n) {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
};