class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;  // 0 and 1 are perfect squares

        long left = 2, right = num / 2;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long sq = mid * mid;

            if (sq == num) return true;
            else if (sq < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
