class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = 1 << k;

        if (s.size() - k + 1 < total)
            return false;

        vector<bool> seen(total, false);

        int mask = total - 1;
        int num = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            num = ((num << 1) & mask) | (s[i] - '0');

            if (i >= k - 1) {
                if (!seen[num]) {
                    seen[num] = true;
                    count++;

                    if (count == total)
                        return true;
                }
            }
        }

        return false;
    }
};