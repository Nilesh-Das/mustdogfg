#include <bits/stdc++.h>
#define ll long long
using namespace std;

// returns no of elements greater
int sum(vector<int> &bit, int i) {
  int res = 0;
  for(; i < bit.size(); i+=i&-i) {
    res += bit[i];
  }
  return res;
}

void insert(vector<int> &bit, int i) {
  for(; i>0; i-=i&-i) {
    bit[i] += 1;
  }
}

// lower_bound
int search(vector<int> &temp, int x) {
  int n = temp.size();
  int l=0, r=n, m;
  while(l < r) {
    m = l + (r-l)/2;
    if(temp[m] < x) l=m+1;
    else r=m;
  }
  return l;
}

int reversePairs(vector<int> nums) {
  int n = nums.size();
  int count = 0;

  vector<int> temp = nums;
  sort(temp.begin(), temp.end());

  for(int i=0; i<n; i++)
    nums[i] = search(temp, nums[i]) + 1;

  vector<int> bit(n+1);
  int idx;
  for(int x : nums) {
    idx = search(temp, 2*x+1);
    count += sum(bit, idx);
    idx = search(temp, x);
    insert(bit, idx);
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> nums = {2,4,3,5,1};
  cout << reversePairs(nums) << '\n';
  
  return 0;
}