#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<vector<int>> res;

  auto comp = [&](const vector<int> &a, const vector<int> &b)
  { return a[0] < b[0]; };
  sort(intervals.begin(), intervals.end(), comp);
  int n = intervals.size();
  res.push_back(intervals[0]);
  vector<int> v;
  for(int i=1; i<n; i++) {
    if(res.back()[1] >= intervals[i][0]) {
      v.resize(0);
      v.push_back(res.back()[0]);
      v.push_back(max(res.back()[1], intervals[i][1]));
      res.pop_back();
      res.push_back(v);
    } else {
      res.push_back(intervals[i]);
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> res = merge(intervals);
  for(auto x : res) {
    for(auto y : x) {
      cout << y << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}