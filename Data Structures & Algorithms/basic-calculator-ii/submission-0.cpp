class Solution {
public:
    int calculate(string s) {
        long num = 0;
        char op = '+';
        stack<int> st;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * num);
                } else if (op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / num);
                }
                op = s[i];
                num = 0;
            }
        }
        
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
