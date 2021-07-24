#include <bits/stdc++.h>
#define ll long long
using namespace std;

void pascal(int n) {
  vector<int> prev = {1};
  for(int i=0; i<n-1; i++)
    cout << " ";
  cout << "1\n";

  for(int i=1; i<n; i++) {
    vector<int> curr(i+1);

    for(int j=0; j<n-i-1; j++)
      cout << " ";

    for(int j=0; j<=i; j++) {
      if(j==0 || j==i) curr[j]=1;
      else curr[j] = prev[j-1] + prev[j];
      cout << curr[j] << " ";
    }
    cout << '\n';
    prev = curr;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  pascal(n);
  
  return 0;
}