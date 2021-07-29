#include <bits/stdc++.h>
#define ll long long
using namespace std;

// longest common prefix :
// word by word

string lcpUtil(string a, string b) {
    string pref;
    int n = a.length();
    int m = b.length();
    
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] != b[j]) break;
        pref.push_back(a[i]);
        i++, j++;
    }
    return pref;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    string pref = strs[0];
    for(int i = 1; i < strs.size(); i++) {
        pref = lcpUtil(pref, strs[i]);
    }
    return pref;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << '\n';
    
    return 0;
}