#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string S = "i.like.this.program.very.much";

  // output : much.very.program.this.like.i

  string D = ".";
  string token;

  vector<string> res;

  size_t pos = 0;
  while((pos = S.find(D)) != string::npos) {
    token = S.substr(0, pos);
    res.push_back(token);
    S.erase(0, pos + D.length());
  }
  res.push_back(S);

  string RS = "";
  for(auto x=res.rbegin(); x!=res.rend(); x++) {
    RS += *x + ".";
  }
  RS.pop_back();

  cout << RS << '\n';
  
  return 0;
}