class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Step 1: Store allowed characters in a set for quick lookup
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        
        int count = 0;
        
        // Step 2: Check each word
        for (string &word : words) {
            bool isConsistent = true;
            
            // Step 3: Verify all characters of the word
            for (char c : word) {
                if (allowedSet.find(c) == allowedSet.end()) {
                    isConsistent = false;
                    break;  // No need to check further
                }
            }
            
            // Step 4: If consistent, increment count
            if (isConsistent) count++;
        }
        
        return count;
    }
};

