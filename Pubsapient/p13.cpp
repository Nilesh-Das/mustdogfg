int findPairs(vector<int> nums, int k) {
    map<int, int> cnt;
    for (int x : nums) {
        cnt[x] += 1;
    }
    int res = 0;
    for (auto p : cnt) {
        int x = p.first;
        int y = p.second;
        if ((k > 0 && cnt.find(x + k) != cnt.end()) || (k == 0 && y > 1)) {
            res++;
        }
    }
    return res;
}