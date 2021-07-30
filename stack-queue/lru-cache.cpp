#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> pos;
    
    void use(int key, int value){
        cache.erase(pos[key]);
        cache.push_front({key, value});
        pos[key] = cache.begin();
    }
    
public:
    LRUCache(int n): capacity(n) {}
    
    int get(int key) {
        if(pos.find(key) == pos.end()) return -1;
        use(key, (*pos[key]).second);
        return (*pos[key]).second;
    }
    
    void put(int key, int value) {
        if(pos.find(key) == pos.end()) {
            cache.push_front({key, value});
            pos[key] = cache.begin();
            if(pos.size() > capacity) {
                pos.erase(cache.back().first);
                cache.pop_back();
            }
        } else use(key,value);
    }

    void display() {
        cout << "KEY VALUE\n";
        for(auto it = cache.begin(); it != cache.end(); it++) {
            cout << (*it).first << ' ' << (*it).second << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    LRUCache ca(2); 
    
    ca.put(1, 1); 
    ca.put(2, 2); 
    cout << ca.get(1) << '\n'; 
    ca.put(3, 3); 
    cout << ca.get(2) << '\n'; 
    ca.put(4, 4); 
    cout << ca.get(1) << '\n';
    cout << ca.get(3) << '\n';
    cout << ca.get(4) << '\n';
    ca.display();

    return 0;
}