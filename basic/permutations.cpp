#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  if(n<=4) {
    if(n==1) cout << "1\n";
    else if(n==4) cout << "2 4 1 3\n";
    else cout << "NO SOLUTION\n";
  } else {
    for(int i=n; i>0; i-=2)
      cout << i << ' ';
    for(int i=n-1; i>0; i-=2)
      cout << i << ' ';
    cout << '\n';
  }
}
