#include <bits/stdc++.h>
#define ll long long
using namespace std;

int atoi(string str)
{  
  bool neg = 0;
  if(str[0]=='-') {
    neg=1;
    str.erase(str.begin());
  }
  int n = str.length();
  int mul = pow(10, n-1);
  int res = 0;
  for(char c : str) {
    int x = c - '0';
    if(x<0 || x>9) return -1;
    res += (x * mul);
    mul /= 10;
  }
  if(neg) res*=(-1);

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string s = "123";
  cout << atoi(s) << '\n';
    
  return 0;
}