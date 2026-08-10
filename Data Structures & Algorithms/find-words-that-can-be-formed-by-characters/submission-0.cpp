class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Step 1: Count frequency of chars
        unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }
        
        int totalLength = 0;
        
        // Step 2: Check each word
        for (string word : words) {
            unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }
            
            bool canForm = true;
            for (auto [c, freq] : wordCount) {
                if (charCount[c] < freq) {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                totalLength += word.size();
            }
        }
        
        return totalLength;
    }
};
