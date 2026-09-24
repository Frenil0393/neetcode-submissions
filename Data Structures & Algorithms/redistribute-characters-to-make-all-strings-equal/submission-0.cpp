class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        
        // Count frequency of each character
        for (auto &w : words) {
            for (char c : w) {
                freq[c - 'a']++;
            }
        }
        
        int n = words.size();
        // Check divisibility
        for (int count : freq) {
            if (count % n != 0) return false;
        }
        
        return true;
    }
};
