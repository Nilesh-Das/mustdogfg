#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/

int findDuplicate1(vector<int> nums);
int findDuplicate2(vector<int> nums);
int findDuplicate3(vector<int> nums);


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> nums = {2,2,2,2};
  cout << findDuplicate3(nums) << '\n';
  
  return 0;
}

int findDuplicate1(vector<int> nums) {
  int low = 1;
  int high = nums.size() - 1;

  while(low < high) {
    int mid = low + (high - low) / 2;

    int count = 0;
    for(int x : nums) {
      if(x <= mid) count++;
    }

    if(count <= mid) low = mid+1;
    else high = mid;
  }

  return low;
}

int findDuplicate2(vector<int> nums) {
  unordered_set<int> s;
  for(int x : nums) {
    if(s.find(x) == s.end()) {
      s.insert(x);
    } else {
      return x;
    }
  }
  return 0;
}

int findDuplicate3(vector<int> nums) {
  int slow = nums[0];
  int fast = nums[nums[0]];

  while(fast != slow) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }

  fast = 0;
  while(fast != slow) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}