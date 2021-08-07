#include <iostream>
#include <vector>
using namespace std;

struct Bone {
    int val;
    vector<Bone> children;
};

int main() {
    vector<int> v = {1,2,3};
    Bone par;
    par.val = 0;
    for(int x : v) {
        Bone child;
        child.val = x;
        par.children.push_back(child);
    }
    for(auto child : par.children) {
        cout << child.val << '\n'; 
    }
}