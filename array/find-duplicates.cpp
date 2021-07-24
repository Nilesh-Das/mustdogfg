#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/find-all-duplicates-in-an-array/

vector<int> findDuplicates(vector<int> nums);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<int> nums = {4,3,2,7,8,2,3,1};

  for(int x : findDuplicates(nums)) {
    cout << x << ' ';
  }
  cout << '\n';
  
  return 0;
}

vector<int> findDuplicates(vector<int> nums) {
  vector<int> res;
  for(int i=0; i<nums.size(); i++) {
    int x = abs(nums[i])-1;
    if(nums[x] < 0) res.push_back(x+1);
    else nums[x] = -nums[x];
  }
  return res;
}