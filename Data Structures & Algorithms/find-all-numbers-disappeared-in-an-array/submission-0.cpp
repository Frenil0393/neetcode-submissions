class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Step 1: Mark visited numbers
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;   // map value to index
            if (nums[index] > 0) {
                nums[index] = -nums[index]; // mark as visited
            }
        }

        // Step 2: Collect missing numbers
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {              // unvisited index → missing number
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
