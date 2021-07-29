#include <bits/stdc++.h>
#define ll long long
using namespace std;

string longestPalindrome(string s) {
  int n = s.size();
  int ii=0, jj=0;
  vector<vector<bool>> dp(n, vector<bool>(n));
  for(int r=0; r<n; r++) {
    for(int l=0; l<=r; l++) { 
      if(s[l] == s[r] && (r-l <= 2 || dp[l+1][r-1])) {
        dp[l][r] = true;
        if(jj-ii < r-l) ii=l, jj=r;
      }
    }
  }
  return s.substr(ii, jj-ii+1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  cin >> s;
  
  int n = s.length();
  
  int maxlen=0, start=0, l, r;
  
  for(int i=1; i<n; i++) {
    // even length substr
    l = i, r = i-1;
    while(l>=0 && r<n && s[l] == s[r]) {
      if(r-l+1 > maxlen) {
        start = l;
        maxlen = r-l+1;
      }
      l--, r++;
    }
    
    // odd length substr
    l = i-1, r = i-1;
    while(l>=0 && r<n && s[l] == s[r]) {
      if(r-l+1 > maxlen) {
        start = l;
        maxlen = r-l+1;
      }
      l--, r++;
    }
  }
  if(n==1)
    cout << s << '\n';
  else
    cout << s.substr(start, maxlen) << '\n';
  
  return 0;
}