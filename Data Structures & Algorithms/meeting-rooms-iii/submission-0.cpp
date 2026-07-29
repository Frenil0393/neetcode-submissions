class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for available rooms (lowest number first)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) available.push(i);

        // Min-heap for ongoing meetings (endTime, roomNumber)
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> ongoing;

        vector<int> count(n, 0);

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];

            // Free up rooms
            while (!ongoing.empty() && ongoing.top().first <= start) {
                available.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!available.empty()) {
                // Assign to available room
                int room = available.top(); available.pop();
                ongoing.push({end, room});
                count[room]++;
            } else {
                // Delay meeting until earliest room frees up
                auto [endTime, room] = ongoing.top(); ongoing.pop();
                long long duration = end - start;
                long long newEnd = endTime + duration;
                ongoing.push({newEnd, room});
                count[room]++;
            }
        }

        // Find room with max count
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans] || 
               (count[i] == count[ans] && i < ans)) {
                ans = i;
            }
        }
        return ans;
    }
};
