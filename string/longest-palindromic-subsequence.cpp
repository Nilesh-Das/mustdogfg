#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for(int l = n-1; l >= 0; l--) {
        dp[l][l] = 1;
        for(int r = l+1; r < n; r++) {
            if(s[l] == s[r]) 
                dp[l][r] = dp[l+1][r-1] + 2;
            else 
                dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
        }
    }
    return dp[0][n-1];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << longestPalindromeSubseq(s) << '\n';
    }
    return 0;
}