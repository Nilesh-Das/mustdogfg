#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    if(s.empty()) return 0;
    
    unordered_map<char, int> rom;
    rom['I'] = 1;
    rom['V'] = 5;
    rom['X'] = 10;
    rom['L'] = 50;
    rom['C'] = 100;
    rom['D'] = 500;
    rom['M'] = 1000;

    int sum = 0;
    int curr = rom[s.front()];
    for(int i = 1; i < s.size(); i++) {
        int prev = curr;
        curr = rom[s[i]];
        if(curr > prev) {
            sum -= prev;
        } else {
            sum += prev;
        }

    }
    return sum + curr;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << romanToInt(s) << '\n';
    }
    return 0;
}