class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        
        // Initialize nodes
        for (auto &w : words) {
            for (char c : w) {
                indegree[c] = 0;
            }
        }
        
        // Build graph
        for (int i = 0; i < words.size()-1; i++) {
            string w1 = words[i], w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0,len) == w2.substr(0,len)) {
                return ""; // invalid prefix case
            }
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        
        // Topological sort (Kahn’s algorithm)
        queue<char> q;
        for (auto &[c, deg] : indegree) {
            if (deg == 0) q.push(c);
        }
        
        string res;
        while (!q.empty()) {
            char cur = q.front(); q.pop();
            res += cur;
            for (char nei : graph[cur]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        
        return res.size() == indegree.size() ? res : "";
    }
};
