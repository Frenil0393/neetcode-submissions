class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long add = n - 1;   // we need n numbers, starting from x
        int bit = 0;
        
        while (add > 0) {
            // if current bit in x is 0, we can use it to place bits from add
            if ((ans & (1LL << bit)) == 0) {
                if (add & 1) ans |= (1LL << bit);
                add >>= 1;
            }
            bit++;
        }
        return ans;
    }
};
