class Solution {
public:
    string customSortString(string order, string s) {
        // Count frequency of each character in s
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        string result;
        
        // Place characters in the order specified
        for (char c : order) {
            if (freq.count(c)) {
                result.append(freq[c], c); // append c freq[c] times
                freq.erase(c); // remove once processed
            }
        }
        
        // Append remaining characters not in order
        for (auto &p : freq) {
            result.append(p.second, p.first);
        }
        
        return result;
    }
};
