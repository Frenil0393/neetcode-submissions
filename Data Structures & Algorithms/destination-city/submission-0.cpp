class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // Collect all cities that have outgoing trips
        unordered_set<string> outgoing;
        for (auto &p : paths) {
            outgoing.insert(p[0]);
        }
        
        // The destination city is the one that never appears in outgoing
        for (auto &p : paths) {
            if (outgoing.find(p[1]) == outgoing.end()) {
                return p[1];
            }
        }
        return "";
    }
};
