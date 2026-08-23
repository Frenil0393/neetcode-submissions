class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            // Move left forward if it's even
            if (nums[left] % 2 == 0) {
                left++;
            } 
            // Move right backward if it's odd
            else if (nums[right] % 2 == 1) {
                right--;
            } 
            // Swap when left is odd and right is even
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};
