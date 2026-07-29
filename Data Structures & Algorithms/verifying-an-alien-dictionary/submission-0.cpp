class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1: Build mapping of alien order
        vector<int> pos(26);
        for (int i = 0; i < 26; i++) {
            pos[order[i] - 'a'] = i;
        }

        // Step 2: Compare adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i+1], pos)) {
                return false;
            }
        }
        return true;
    }

private:
    bool compare(string& w1, string& w2, vector<int>& pos) {
        int n1 = w1.size(), n2 = w2.size();
        for (int i = 0; i < min(n1, n2); i++) {
            if (w1[i] != w2[i]) {
                return pos[w1[i] - 'a'] < pos[w2[i] - 'a'];
            }
        }
        // If all characters match, shorter word should come first
        return n1 <= n2;
    }
};
