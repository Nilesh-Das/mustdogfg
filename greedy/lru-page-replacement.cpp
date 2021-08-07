#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
input:
1
13 4
7 0 1 2 0 3 0 4 2 3 0 3 2
output:
6
*/

int pageFaults(vector<int>& pages, int capacity) {
    int n = pages.size();
    int res = 0;
    vector<int> cache;
    for(int page : pages) {
        auto it = find(cache.begin(), cache.end(), page);
        if(it == cache.end()) {
            if(cache.size() == capacity) 
                cache.erase(cache.begin());
            res++;
        } else {
            cache.erase(it);
        }
        cache.push_back(page);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, capacity;
        cin >> n >> capacity;
        vector<int> pages(n);
        for(int i = 0; i < n; i++) cin >> pages[i];
        cout << pageFaults(pages, capacity) << '\n';
    }
}