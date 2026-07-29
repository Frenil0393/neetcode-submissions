class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> q; // (query, index)
        for (int i = 0; i < queries.size(); i++) q.push_back({queries[i], i});
        sort(q.begin(), q.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;
        vector<int> ans(queries.size(), -1);
        int i = 0;

        for (auto [query, idx] : q) {
            // Add intervals starting before or at query
            while (i < intervals.size() && intervals[i][0] <= query) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                heap.push({len, intervals[i][1]});
                i++;
            }
            // Remove intervals ending before query
            while (!heap.empty() && heap.top().second < query) {
                heap.pop();
            }
            if (!heap.empty()) ans[idx] = heap.top().first;
        }
        return ans;
    }
};
