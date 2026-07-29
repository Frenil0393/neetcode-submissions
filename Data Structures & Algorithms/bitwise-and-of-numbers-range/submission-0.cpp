class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1); // clear the lowest set bit
        }
        return right;
    }
};
