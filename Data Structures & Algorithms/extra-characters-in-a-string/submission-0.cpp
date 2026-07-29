class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        // dp[i] = minimum extra characters for substring s[i..n-1]
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // Option 1: treat s[i] as extra
            dp[i] = 1 + dp[i + 1];

            // Option 2: try matching dictionary words starting at i
            for (int len = 1; len <= n - i; len++) {
                string sub = s.substr(i, len);
                if (dict.count(sub)) {
                    dp[i] = min(dp[i], dp[i + len]);
                }
            }
        }
        return dp[0];
    }
};
