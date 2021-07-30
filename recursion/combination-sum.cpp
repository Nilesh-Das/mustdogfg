// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        
        sort(candidates.begin(), candidates.end());
        
        function<void(int,int)> dfs = [&](int start, int x) {
            if(x < 0) return;
            
            if(x == 0) {
                res.push_back(comb);
                return;
            } 

            for(int i = start; i < candidates.size(); i++) {
                comb.push_back(candidates[i]);
                dfs(i, x - candidates[i]);
                comb.pop_back();
            }
        };
        
        dfs(0, target);

        return res;
    }
};