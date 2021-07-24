#include <bits/stdc++.h>
#define ll long long
using namespace std;

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