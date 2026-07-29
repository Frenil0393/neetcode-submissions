class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        using P = pair<int,int>; // {time, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();
            if(time > dist[node]) continue;

            for(auto &[nei, wt] : graph[node]) {
                if(dist[node] + wt < dist[nei]) {
                    dist[nei] = dist[node] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
