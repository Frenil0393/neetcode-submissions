class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check mapping s -> t
            if (mapST.count(c1) && mapST[c1] != c2) return false;
            mapST[c1] = c2;

            // Check mapping t -> s
            if (mapTS.count(c2) && mapTS[c2] != c1) return false;
            mapTS[c2] = c1;
        }
        return true;
    }
};
