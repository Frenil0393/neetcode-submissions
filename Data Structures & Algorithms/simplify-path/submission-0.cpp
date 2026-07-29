class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string token;
        stringstream ss(path);
        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") continue;
            if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }
        string res = "/";
        for (int i = 0; i < stack.size(); i++) {
            res += stack[i];
            if (i < stack.size() - 1) res += "/";
        }
        return res;
    }
};
