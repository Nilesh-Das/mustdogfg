#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/sort-colors/

void sort_colors1(vector<int> &nums) {
  int a=0,b=0,c=0;
  for(int x : nums) {
    if(x == 0) a++;
    if(x == 1) b++;
    if(x == 2) c++;
  }

  nums.resize(0);
  while(a or b or c) {
    if(a) nums.push_back(0), a--;
    else if(b) nums.push_back(1), b--;
    else nums.push_back(2), c--;
  }
}

void sort_colors2(vector<int> &nums) {
  int a=0, b=0, c=0;
  for(int x : nums) {
    if(x==0) {
      nums[a++]=2; nums[b++]=1; nums[c++]=0;
    } else if(x==1) {
      nums[a++]=2; nums[b++]=1;
    } else {
      nums[a++]=2;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> nums = {2,0,2,1,1,0};
  sort_colors2(nums);

  for(int x : nums) {
    cout << x <<  ' ';
  }
  cout << '\n';
  
  return 0;
}