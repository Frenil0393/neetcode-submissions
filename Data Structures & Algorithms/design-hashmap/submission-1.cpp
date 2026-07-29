#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    vector<int> storage;  
public:
    MyHashMap() {
        storage.resize(1000001, -1); 
    }
    
    void put(int key, int value) {
        storage[key] = value;
    }
    
    int get(int key) {
        return storage[key];
    }
    
    void remove(int key) {
        storage[key] = -1;
    }
    
};
