#include <iostream>
#include <vector>
#include <string>
using namespace std;

string largestNumber(int sum, int num) {
    if(sum == 0) return (num == 1 ? "0" : "nil");
    if(sum > 9*num) return "nil";
    string res(num, '9');
    int x = sum % 9;
    int i = (sum + 8)/9;
    res[i++] = char(x+'0');
    for(; i < num; i++) res[i] = '0';
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int sum, num;
        cin >> sum >> num;
        cout << largestNumber(sum, num) << '\n';
    }
}