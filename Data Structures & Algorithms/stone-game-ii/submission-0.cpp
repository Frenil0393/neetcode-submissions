class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n+1, 0);
        for (int i = n-1; i >= 0; i--) suffix[i] = suffix[i+1] + piles[i];
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        function<int(int,int)> solve = [&](int i, int M) {
            if (i >= n) return 0;
            if (dp[i][M] != -1) return dp[i][M];
            int best = 0;
            for (int x = 1; x <= 2*M && i+x <= n; x++) {
                best = max(best, suffix[i] - solve(i+x, max(M, x)));
            }
            return dp[i][M] = best;
        };
        return solve(0, 1);
    }
};
