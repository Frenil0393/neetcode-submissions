class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string curr;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(num);
                result.push(curr);
                num = 0;
                curr.clear();
            } else if (c == ']') {
                string temp = curr;
                curr = result.top();
                result.pop();
                int repeat = counts.top();
                counts.pop();
                while (repeat--) curr += temp;
            } else {
                curr.push_back(c);
            }
        }
        return curr;
    }
};
