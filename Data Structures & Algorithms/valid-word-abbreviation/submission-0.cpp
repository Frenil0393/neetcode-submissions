class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false; // leading zero
                int num = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num; // skip characters
            } else {
                if (word[i] != abbr[j]) return false;
                i++;
                j++;
            }
        }
        return i == word.size() && j == abbr.size();
    }
};
