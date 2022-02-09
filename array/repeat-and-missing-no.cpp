#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
vector<int> find(vector<int> &A) {
    int x=0, y=0, z=0;
    int n = A.size();

    for(int i=1; i<=n; i++) {
        z ^= i;
        z ^= A[i-1];
    }

    int lsb = z & ~(z-1);
    for(int i=1; i<=n; i++) {
        if(lsb & A[i-1]) x^=A[i-1];
        else y ^= A[i-1];
        if(lsb & i) x^=i;
        else y^=i;
    }

    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> A = {3,1,2,5,3};
    for(int x : find(A))
        cout << x << ' ';
    cout << '\n';

    return 0;
}