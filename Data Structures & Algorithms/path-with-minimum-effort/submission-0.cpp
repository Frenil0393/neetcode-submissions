class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        using T = pair<int, pair<int,int>>; // {effort, {row, col}}
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, {0,0}});

        vector<int> dirs = {0,1,0,-1,0};

        while(!pq.empty()) {
            auto [effort, pos] = pq.top(); pq.pop();
            int r = pos.first, c = pos.second;

            if(r == rows-1 && c == cols-1) return effort;
            if(effort > dist[r][c]) continue;

            for(int i=0; i<4; i++) {
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if(nr<0 || nc<0 || nr>=rows || nc>=cols) continue;

                int nextEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                if(nextEffort < dist[nr][nc]) {
                    dist[nr][nc] = nextEffort;
                    pq.push({nextEffort, {nr,nc}});
                }
            }
        }
        return 0;
    }
};
