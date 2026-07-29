class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1; // empty string
        dp[1] = 1; // first char valid since not '0'
        
        for (int i = 2; i <= n; i++) {
            // Single digit decode
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            // Two digit decode
            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};

