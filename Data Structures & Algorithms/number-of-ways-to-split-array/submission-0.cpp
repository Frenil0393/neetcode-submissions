class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;

        for (int num : nums) {
            total += num;
        }

        long long leftSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];

            if (leftSum >= total - leftSum) {
                count++;
            }
        }

        return count;
    }
};