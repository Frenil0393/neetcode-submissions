class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            // Check substring of length 3
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string candidate = num.substr(i, 3);
                if (ans.empty() || candidate > ans) {
                    ans = candidate;
                }
            }
        }
        return ans;
    }
};
