#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

long optimalKeys(int N) {
    if(N <= 6) return N;

    vector<long> dp(N + 1);
    for(int i = 1; i <= 6; i++) dp[i] = i;
 
    for(int i = 7; i <= N; i++) {
        for(int j = i - 3; j >= 1; j--) {
            int curr = (i - j - 1) * dp[j];
            if(curr > dp[i]) dp[i] = curr;
        }
    }
 
    return dp[N];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << optimalKeys(n) << '\n';
    }

    return 0;
}
