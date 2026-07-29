class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build adjacency list and indegree count
        for (auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        // Start with courses having no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            order.push_back(curr);

            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        // If we processed all courses, return order; otherwise cycle exists
        if (order.size() == numCourses) return order;
        return {};
    }
};
