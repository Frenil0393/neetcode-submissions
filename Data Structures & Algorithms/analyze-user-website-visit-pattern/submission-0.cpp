class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<tuple<int,string,string>> visits;
        for (int i = 0; i < n; i++) {
            visits.push_back({timestamp[i], username[i], website[i]});
        }
        sort(visits.begin(), visits.end());

        // Group visits by user
        unordered_map<string, vector<string>> userVisits;
        for (auto& [t, u, w] : visits) {
            userVisits[u].push_back(w);
        }

        // Map pattern -> set of users
        map<vector<string>, set<string>> patternUsers;

        for (auto& [user, sites] : userVisits) {
            if (sites.size() < 3) continue;
            set<vector<string>> seenPatterns;
            for (int i = 0; i < sites.size(); i++) {
                for (int j = i+1; j < sites.size(); j++) {
                    for (int k = j+1; k < sites.size(); k++) {
                        vector<string> pattern = {sites[i], sites[j], sites[k]};
                        if (seenPatterns.insert(pattern).second) {
                            patternUsers[pattern].insert(user);
                        }
                    }
                }
            }
        }

        // Find best pattern
        vector<string> best;
        int maxScore = 0;
        for (auto& [pattern, users] : patternUsers) {
            int score = users.size();
            if (score > maxScore || (score == maxScore && pattern < best)) {
                best = pattern;
                maxScore = score;
            }
        }
        return best;
    }
};
