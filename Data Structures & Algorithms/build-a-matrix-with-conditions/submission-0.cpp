class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto topoSort = [&](vector<vector<int>>& edges) {
            vector<int> indegree(k+1, 0);
            vector<vector<int>> graph(k+1);
            for (auto &e : edges) {
                graph[e[0]].push_back(e[1]);
                indegree[e[1]]++;
            }
            queue<int> q;
            for (int i = 1; i <= k; i++) if (indegree[i] == 0) q.push(i);
            vector<int> order;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (int v : graph[u]) {
                    if (--indegree[v] == 0) q.push(v);
                }
            }
            if ((int)order.size() != k) return vector<int>(); // cycle
            return order;
        };

        vector<int> rowOrder = topoSort(rowConditions);
        vector<int> colOrder = topoSort(colConditions);
        if (rowOrder.empty() || colOrder.empty()) return {};

        vector<int> rowPos(k+1), colPos(k+1);
        for (int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int num = 1; num <= k; num++) {
            matrix[rowPos[num]][colPos[num]] = num;
        }
        return matrix;
    }
};
