class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int freshCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            minutes++;
            for (int k = 0; k < size; k++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    freshCount--;
                    q.push({nx, ny});
                }
            }
        }

        return freshCount == 0 ? minutes : -1;
    }
};

