class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // Precompute perfect squares
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        for (int i = 1; i <= n; i++) {
            for (int sq : squares) {
                if (i - sq >= 0) {
                    dp[i] = min(dp[i], dp[i - sq] + 1);
                }
            }
        }
        return dp[n];
    }
};
