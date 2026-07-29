class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // Quick check: tree must have n-1 edges

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa == pb) return false; // cycle detected
            parent[pa] = pb;
            return true;
        };

        for (auto& e : edges) {
            if (!unite(e[0], e[1])) return false;
        }

        return true; // connected and no cycles
    }
};
