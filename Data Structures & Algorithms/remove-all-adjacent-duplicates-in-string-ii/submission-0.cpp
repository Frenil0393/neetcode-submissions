class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack to store characters and their counts
        vector<pair<char, int>> st;
        
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
                // If count reaches k, remove this group
                if (st.back().second == k) {
                    st.pop_back();
                }
            } else {
                st.push_back({c, 1});
            }
        }
        
        // Rebuild the final string
        string result;
        for (auto &p : st) {
            result.append(p.second, p.first);
        }
        
        return result;
    }
};
