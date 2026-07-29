class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;

        // Union-Find setup
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu != pv) parent[pu] = pv;
        };

        // Map emails to account index and union accounts with shared emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                emailToName[email] = accounts[i][0];
                if (emailToIndex.count(email)) {
                    unite(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }

        // Group emails by root parent
        unordered_map<int, set<string>> merged;
        for (auto& [email, idx] : emailToIndex) {
            int root = find(idx);
            merged[root].insert(email);
        }

        // Build result
        vector<vector<string>> result;
        for (auto& [root, emails] : merged) {
            vector<string> account;
            account.push_back(accounts[root][0]); // name
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        return result;
    }
};
