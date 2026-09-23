class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int countA = 0, countB = 0;
        
        for (int i = 0; i < n; i++) {
            // Expected char for pattern starting with '0'
            char expectedA = (i % 2 == 0) ? '0' : '1';
            // Expected char for pattern starting with '1'
            char expectedB = (i % 2 == 0) ? '1' : '0';
            
            if (s[i] != expectedA) countA++;
            if (s[i] != expectedB) countB++;
        }
        
        return min(countA, countB);
    }
};
