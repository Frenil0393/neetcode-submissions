class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Compare mid with its right neighbor
            if (nums[mid] > nums[mid + 1]) {
                // Peak lies on the left side (including mid)
                right = mid;
            } else {
                // Peak lies on the right side
                left = mid + 1;
            }
        }
        
        return left; // or right, since left == right
    }
};
