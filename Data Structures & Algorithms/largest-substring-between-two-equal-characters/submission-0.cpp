class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // Map to store the first occurrence of each character
        vector<int> firstIndex(26, -1);
        int maxLen = -1;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (firstIndex[idx] == -1) {
                // First time seeing this character
                firstIndex[idx] = i;
            } else {
                // Calculate substring length between two equal characters
                maxLen = max(maxLen, i - firstIndex[idx] - 1);
            }
        }
        return maxLen;
    }
};
