class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0], B = equations[i][1];
            double val = values[i];
            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        // Helper DFS function
        function<double(string, string, unordered_set<string>&)> dfs = 
        [&](string src, string dst, unordered_set<string>& visited) {
            if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) 
                return -1.0;
            if (src == dst) return 1.0;

            visited.insert(src);
            for (auto& [neighbor, weight] : graph[src]) {
                if (visited.count(neighbor)) continue;
                double res = dfs(neighbor, dst, visited);
                if (res != -1.0) return res * weight;
            }
            return -1.0;
        };

        // Answer queries
        vector<double> result;
        for (auto& q : queries) {
            unordered_set<string> visited;
            result.push_back(dfs(q[0], q[1], visited));
        }
        return result;
    }
};
