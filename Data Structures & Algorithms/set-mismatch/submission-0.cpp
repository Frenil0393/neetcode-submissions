class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, missing = -1;
        
        // Mark visited numbers
        for (int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            if (nums[val - 1] < 0) {
                duplicate = val;  // already visited
            } else {
                nums[val - 1] *= -1;  // mark as visited
            }
        }
        
        // Find missing number
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;  // index not visited
            }
        }
        
        return {duplicate, missing};
    }
};
