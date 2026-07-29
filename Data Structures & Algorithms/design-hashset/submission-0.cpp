#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    vector<bool> storage;  
public:
    MyHashSet() {
        storage.resize(1000001, false); 
    }
    
    void add(int key) {
        storage[key] = true;
    }
    
    void remove(int key) {
        storage[key] = false;
    }
    
    bool contains(int key) {
        return storage[key];
    }
};
