class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        // Initialize parent array
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union function with union by rank
        auto unite = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) return false; // cycle detected
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
            return true;
        };

        // Process edges
        for (auto& e : edges) {
            if (!unite(e[0], e[1])) {
                return e; // this edge creates a cycle
            }
        }
        return {};
    }
};
