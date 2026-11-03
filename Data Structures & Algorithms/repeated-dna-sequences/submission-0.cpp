class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i + 9 < s.size(); i++) {
            string cur = s.substr(i, 10);

            if (seen.count(cur)) {
                repeated.insert(cur);
            } else {
                seen.insert(cur);
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};