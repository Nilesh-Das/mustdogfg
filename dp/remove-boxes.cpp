// https://leetcode.com/problems/remove-boxes/

class Solution {
public:
    int dp[100][100][100];
    int solve(vector<int>& A, int l, int r, int k) {
        if(l > r) return 0;
        if(dp[l][r][k] != -1) return dp[l][r][k];
        int res = (k+1)*(k+1) + solve(A,l+1,r,0);
        for(int i = l+1; i <=r; i++)
            if(A[i] == A[l]) 
                res = max(res, solve(A,l+1,i-1,0)+solve(A,i,r,k+1));
        return dp[l][r][k] = res;
    }
    
    int removeBoxes(vector<int>& boxes) {    
        memset(dp, -1, sizeof dp);
        return solve(boxes, 0, boxes.size()-1, 0);   
    }
};