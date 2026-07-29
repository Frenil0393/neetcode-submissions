class Solution {
public:
    int reverse(int x) {
        long long result = 0;   // use long long to detect overflow
        while (x != 0) {
            int digit = x % 10;   // extract last digit
            result = result * 10 + digit;
            x /= 10;
        }
        // check 32-bit signed integer range
        if (result < INT_MIN || result > INT_MAX) return 0;
        return (int)result;
    }
};
