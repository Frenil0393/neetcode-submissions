class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalOnes = 0;
        
        // Count total number of '1's in the string
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        int maxScore = 0;
        int leftZeros = 0, rightOnes = totalOnes;
        
        // Iterate through the string, but stop before the last character
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        
        return maxScore;
    }
};
