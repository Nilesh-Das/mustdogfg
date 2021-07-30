#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int MAX_CHAR = 26;

void firstnonrepeating(string str) {
    queue<char> q;
    vector<int> charCount(MAX_CHAR);

    for(int i = 0; str[i]; i++) {
        q.push(str[i]);
        charCount[str[i] - 'a']++;
        while (!q.empty()) {
            if(charCount[q.front() - 'a'] > 1) q.pop();
            else {
                cout << q.front() << " ";
                break;
            }
        }
        if(q.empty()) cout << -1 << " ";
    }
    cout << endl;
}

int main() {
    string str = "aabc";
    firstnonrepeating(str);

    return 0;
}
