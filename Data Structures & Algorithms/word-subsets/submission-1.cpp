class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> need(26, 0);

        // Build combined requirement
        for (string &w : words2) {
            vector<int> freq(26, 0);

            for (char c : w)
                freq[c - 'a']++;

            for (int i = 0; i < 26; i++)
                need[i] = max(need[i], freq[i]);
        }

        vector<string> ans;

        // Check each word in words1
        for (string &w : words1) {
            vector<int> freq(26, 0);

            for (char c : w)
                freq[c - 'a']++;

            bool valid = true;

            for (int i = 0; i < 26; i++) {
                if (freq[i] < need[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(w);
        }

        return ans;
    }
};