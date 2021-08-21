#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {4, 5 ,7};
    int n = v.size(), k = 8;
    int l = 0, r = n;
    while(l < r) {
        int m = l + (r-l)/2;
        if(v[m] < k) l = m + 1;
        else r = m;
    }
    cout << l << '\n';
}