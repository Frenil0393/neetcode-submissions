class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // Iterate through adjacent pairs
        for (int i = 1; i < nums.size(); i++) {
            // If both have same parity (both even or both odd), return false
            if ((nums[i] % 2) == (nums[i - 1] % 2)) {
                return false;
            }
        }
        // If no adjacent pair violates the rule, return true
        return true;
    }
};
