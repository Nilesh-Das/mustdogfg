#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  char s[] = "nilesh";

  int n = sizeof(s) / sizeof(s[0]);

  // n i l e s h \0
  // |         |
  // p         q

  
  char *p = s;
  char *q = s+n-2;

  for(int i=0; i<n/2; i++) {
    char tmp = *p;
    *p = *q;
    *q = tmp;

    p++, q--;
  }

  cout << s << '\n';

  return 0;
}