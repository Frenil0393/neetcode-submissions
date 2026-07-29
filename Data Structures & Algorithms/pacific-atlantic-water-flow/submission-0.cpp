class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        vector<vector<int>> res;
        
        for (int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0, heights[i][0]);
            dfs(heights, atl, i, n - 1, heights[i][n - 1]);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pac, 0, j, heights[0][j]);
            dfs(heights, atl, m - 1, j, heights[m - 1][j]);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& h, vector<vector<int>>& ocean, int r, int c, int prev) {
        int m = h.size(), n = h[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || ocean[r][c] || h[r][c] < prev) return;
        ocean[r][c] = 1;
        dfs(h, ocean, r + 1, c, h[r][c]);
        dfs(h, ocean, r - 1, c, h[r][c]);
        dfs(h, ocean, r, c + 1, h[r][c]);
        dfs(h, ocean, r, c - 1, h[r][c]);
    }
};
