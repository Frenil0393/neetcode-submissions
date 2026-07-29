class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto &f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }
        
        using T = tuple<int,int,int>; // cost, node, stops
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, src, 0});
        
        vector<vector<int>> best(n, vector<int>(k+2, INT_MAX));
        best[src][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top(); pq.pop();
            if (u == dst) return cost;
            if (stops > k) continue;
            
            for (auto &[v, w] : graph[u]) {
                int newCost = cost + w;
                if (newCost < best[v][stops+1]) {
                    best[v][stops+1] = newCost;
                    pq.push({newCost, v, stops+1});
                }
            }
        }
        return -1;
    }
};
