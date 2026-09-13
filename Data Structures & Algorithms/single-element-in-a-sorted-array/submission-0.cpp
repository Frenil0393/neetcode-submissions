class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (mid % 2 == 1) mid--;  // make mid even
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;  // single element is on the right
            } else {
                high = mid;     // single element is on the left
            }
        }
        return nums[low];
    }
};
