class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        // Build adjacency list and degree count
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        // Initialize leaves
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        // Trim leaves layer by layer
        int remaining = n;
        while (remaining > 2) {
            int leafCount = q.size();
            remaining -= leafCount;
            for (int i = 0; i < leafCount; i++) {
                int leaf = q.front(); q.pop();
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) q.push(neighbor);
                }
            }
        }

        // Remaining nodes are centers (MHT roots)
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
