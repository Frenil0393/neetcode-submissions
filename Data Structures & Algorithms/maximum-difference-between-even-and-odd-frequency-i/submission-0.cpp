class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        // Step 1: Count frequencies of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        // Step 2: Separate odd and even frequencies
        for (int f : freq) {
            if (f > 0) {
                if (f % 2 == 1) {
                    maxOdd = max(maxOdd, f);
                } else {
                    minEven = min(minEven, f);
                }
            }
        }

        // Step 3: Compute maximum difference
        return maxOdd - minEven;
    }
};
