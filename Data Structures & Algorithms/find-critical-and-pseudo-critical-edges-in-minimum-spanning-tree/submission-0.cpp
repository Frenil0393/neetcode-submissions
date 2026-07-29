class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        bool unite(int x, int y) {
            int rx = find(x), ry = find(y);
            if (rx == ry) return false;
            if (rank[rx] < rank[ry]) swap(rx, ry);
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
            return true;
        }
    };
    
    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {
        DSU dsu(n);
        int cost = 0, count = 0;
        
        if (force != -1) {
            auto &e = edges[force];
            if (dsu.unite(e[0], e[1])) {
                cost += e[2];
                count++;
            }
        }
        
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip) continue;
            auto &e = edges[i];
            if (dsu.unite(e[0], e[1])) {
                cost += e[2];
                count++;
            }
        }
        return count == n-1 ? cost : INT_MAX;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Attach original indices
        for (int i = 0; i < edges.size(); i++) edges[i].push_back(i);
        
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        int base = kruskal(n, edges, -1, -1);
        vector<int> critical, pseudo;
        
        for (int i = 0; i < edges.size(); i++) {
            if (kruskal(n, edges, i, -1) > base) {
                critical.push_back(edges[i][3]);
            } else if (kruskal(n, edges, -1, i) == base) {
                pseudo.push_back(edges[i][3]);
            }
        }
        
        return {critical, pseudo};
    }
};
