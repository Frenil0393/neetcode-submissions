class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        string s = "L" + dominoes + "R";
        string res = "";

        int i = 0;

        for (int j = 1; j < s.size(); j++) {
            if (s[j] == '.') continue;

            int middle = j - i - 1;

            if (i > 0)
                res += s[i];

            if (s[i] == s[j]) {
                // L...L or R...R
                res.append(middle, s[i]);
            }
            else if (s[i] == 'L' && s[j] == 'R') {
                // L...R
                res.append(middle, '.');
            }
            else {
                // R...L
                res.append(middle / 2, 'R');

                if (middle % 2 == 1)
                    res += '.';

                res.append(middle / 2, 'L');
            }

            i = j;
        }

        return res;
    }
};