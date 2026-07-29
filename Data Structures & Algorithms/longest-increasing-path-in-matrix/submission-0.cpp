class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        function<int(int,int)> dfs = [&](int i, int j) {
            if (dp[i][j] != 0) return dp[i][j];
            int best = 1;
            vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [dx,dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (x>=0 && y>=0 && x<n && y<m && matrix[x][y] > matrix[i][j]) {
                    best = max(best, 1 + dfs(x,y));
                }
            }
            return dp[i][j] = best;
        };
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ans = max(ans, dfs(i,j));
            }
        }
        return ans;
    }
};
