class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int,int>> keyToValFreq; // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys;       // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freq list
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!keyToValFreq.count(key)) return -1;
        updateFreq(key);
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyToValFreq.count(key)) {
            keyToValFreq[key].first = value;
            updateFreq(key);
            return;
        }
        
        if (keyToValFreq.size() == capacity) {
            int evictKey = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            keyToIter.erase(evictKey);
            keyToValFreq.erase(evictKey);
        }
        
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
    
private:
    void updateFreq(int key) {
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);
        
        if (freqToKeys[freq].empty() && freq == minFreq) {
            minFreq++;
        }
        
        keyToValFreq[key].second++;
        freqToKeys[freq+1].push_front(key);
        keyToIter[key] = freqToKeys[freq+1].begin();
    }
};
