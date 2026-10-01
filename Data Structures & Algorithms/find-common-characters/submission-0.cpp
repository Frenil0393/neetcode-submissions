class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX);
        
        for (auto &w : words) {
            vector<int> temp(26, 0);
            for (char c : w) {
                temp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                freq[i] = min(freq[i], temp[i]);
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i]; j++) {
                result.push_back(string(1, 'a' + i));
            }
        }
        return result;
    }
};
