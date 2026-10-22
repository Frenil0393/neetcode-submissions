class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        int unbalanced = 0;

        for (char c : s) {
            if (c == '[') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    unbalanced++;
                }
            }
        }

        return (unbalanced + 1) / 2;
    }
};