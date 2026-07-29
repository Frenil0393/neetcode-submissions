class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n + 1, 0);

        for (auto& t : trust) {
            score[t[0]]--;  // person trusts someone
            score[t[1]]++;  // person is trusted
        }

        for (int i = 1; i <= n; i++) {
            if (score[i] == n - 1) {
                return i;  // found the judge
            }
        }
        return -1;  // no judge exists
    }
};
