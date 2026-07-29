class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string path;
        unordered_map<char, string> phone = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
        };
        backtrack(digits, 0, path, res, phone);
        return res;
    }
private:
    void backtrack(string& digits, int idx, string& path, vector<string>& res, unordered_map<char,string>& phone) {
        if (idx == digits.size()) {
            res.push_back(path);
            return;
        }
        for (char c : phone[digits[idx]]) {
            path.push_back(c);
            backtrack(digits, idx+1, path, res, phone);
            path.pop_back();
        }
    }
};
