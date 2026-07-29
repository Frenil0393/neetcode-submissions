class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        // reachable[i][j] = true if i is prerequisite of j
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int next : adj[curr]) {
                // curr is prerequisite of next
                reachable[curr][next] = true;

                // propagate: if i is prerequisite of curr, then i is also prerequisite of next
                for (int i = 0; i < numCourses; i++) {
                    if (reachable[i][curr]) {
                        reachable[i][next] = true;
                    }
                }

                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        // Answer queries
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(reachable[q[0]][q[1]]);
        }
        return ans;
    }
};
