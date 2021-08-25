class Solution {
    string s; int n;
    vector<vector<bool>> dp;
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string t) {
        s = t; n = s.length();     
        dp.resize(n, vector<bool>(n));
        for(int r=0; r<n; r++) {
            for(int l=0; l<=r; l++) { 
                if(s[l] == s[r] && (r-l <= 2 || dp[l+1][r-1])) {
                    dp[l][r] = true;
                }
            }
        }
        vector<string> path;
        dfs(0, path);
        
        return res;
    }
    
    void dfs(int l, vector<string> &path) {
        if(l == n) {
            res.push_back(path);
            return;
        }
        for(int r = l; r < n; r++) {
            if(dp[l][r]) {
                path.push_back(s.substr(l,r-l+1));
                dfs(r+1, path);
                path.pop_back();
            }
        }
    }
};