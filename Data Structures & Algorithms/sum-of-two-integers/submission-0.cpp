class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (unsigned)(a & b) << 1; // common set bits
            a = a ^ b;   // sum without carry
            b = carry;   // carry shifted left
        }
        return a;
    }
};
