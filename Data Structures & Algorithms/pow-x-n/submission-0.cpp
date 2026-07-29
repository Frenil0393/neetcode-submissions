class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponent
        long long N = n;  // use long long to avoid overflow when n = INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current = x;
        
        // Binary exponentiation
        while (N > 0) {
            if (N % 2 == 1) {
                result *= current;
            }
            current *= current;
            N /= 2;
        }
        
        return result;
    }
};


