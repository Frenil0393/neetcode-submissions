class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({"0000", 0});
        visited.insert("0000");
        
        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();
            if (cur == target) return steps;
            
            for (int i = 0; i < 4; i++) {
                string up = cur, down = cur;
                up[i] = (cur[i] - '0' + 1) % 10 + '0';
                down[i] = (cur[i] - '0' + 9) % 10 + '0';
                
                if (!dead.count(up) && !visited.count(up)) {
                    visited.insert(up);
                    q.push({up, steps + 1});
                }
                if (!dead.count(down) && !visited.count(down)) {
                    visited.insert(down);
                    q.push({down, steps + 1});
                }
            }
        }
        return -1;
    }
};
