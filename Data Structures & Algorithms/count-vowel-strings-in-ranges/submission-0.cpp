class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);

        auto isVowel = [&](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i];
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefix[i+1]++;
            }
        }

        // Answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(prefix[r+1] - prefix[l]);
        }
        return ans;
    }
};
