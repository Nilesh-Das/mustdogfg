#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permute(string s, int l, int r, vector<string>& v) {
    if(l == r) {
        v.push_back(s);
        return;
    }
    for(int i = l; i <= r; i++) {
        swap(s[i], s[l]);
        permute(s, l+1, r, v);
        swap(s[i], s[l]);
    }
}

vector<string> permutation(string s) {
    int n = s.size();
    vector<string> v;
    permute(s, 0, n-1, v);
    return v;
}

int main() {
    int t;
    while(t--) {
        string s;
        cin >> s;
        for(string x : permutation(s)) {
            cout << x << '\n';
        }
    }
    return 0;
}