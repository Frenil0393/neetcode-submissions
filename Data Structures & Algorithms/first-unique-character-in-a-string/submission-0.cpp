class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);  // frequency array for 'a' to 'z'
        
        // Step 1: Count frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Step 2: Find first unique character
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;  // no unique character found
    }
};
