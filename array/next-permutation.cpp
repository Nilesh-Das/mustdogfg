#include <bits/stdc++.h>
#define ll long long
using namespace std;

void reverse(vector<int> &nums, int s, int e) {
  while(s <= e) {
    swap(nums[s], nums[e]);
    s++, e--;
  }
}

void nextPermutation(vector<int>& nums) {
  int n = nums.size();
  int p, q;
  for(p=n-2; p>=0; p--) {
    if(nums[p+1] > nums[p]) break;
  }
  if(p<0) reverse(nums, 0, n-1);
  else {
    for(q=n-1; q>p; q--) {
      if(nums[q] > nums[p]) break;
    }
    swap(nums[p], nums[q]);
    reverse(nums, p+1, n-1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> nums = {2,3,6,5,4,1};
  nextPermutation(nums);
  for(int x : nums) {
    cout << x << ' ';
  }
  cout << '\n';
  
  return 0;
}