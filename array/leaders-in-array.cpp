#include <iostream>
#include <vector>
using namespace std;

void printLeaders(vector<int> arr) {
    int mx = arr.back();
    cout << mx << ' ';
    for (int i = arr.size()-2; i >= 0; i--) {
        if (mx < arr[i]) {
            mx = arr[i];
            cout << mx << ' ';
        }
    }
    cout << '\n';
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    printLeaders(arr);

    return 0;
}

