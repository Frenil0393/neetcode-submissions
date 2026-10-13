class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> edgeCount;
        int maxEdges = 0;

        for (auto &row : wall) {
            int sum = 0;
            // skip last brick to avoid wall edge
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                edgeCount[sum]++;
                maxEdges = max(maxEdges, edgeCount[sum]);
            }
        }
        return wall.size() - maxEdges;
    }
};
