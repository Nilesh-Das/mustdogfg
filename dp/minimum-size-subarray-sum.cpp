// https://leetcode.com/problems/minimum-size-subarray-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 1e9, sum = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(sum >= target) {
                res = min(res, i-j+1);
                sum -= nums[j++];
            }
        }
        return res == 1e9 ? 0 : res;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        Solution sol;
        cout << sol.minSubArrayLen(k, a) << '\n';
    }
}