#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "1, 2,-1999, null";
    vector<string> vec;

    stringstream ss(s);
    while(ss.good()) {
        string substr;
        getline(ss, substr, ',');
        vec.push_back(substr);
    }

    for(int i = 0; i < vec.size(); i++) {
        printf("%d:%s\n", i, vec[i].c_str());
    }
    printf("\n");

    return 0;
}
