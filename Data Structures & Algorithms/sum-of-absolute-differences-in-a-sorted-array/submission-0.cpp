class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        vector<int> ans(n);
        long long prefixSum = 0;

        for (int i = 0; i < n; i++) {
            long long left =
                1LL * i * nums[i] - prefixSum;

            long long right =
                (totalSum - prefixSum - nums[i]) -
                1LL * (n - i - 1) * nums[i];

            ans[i] = left + right;

            prefixSum += nums[i];
        }

        return ans;
    }
};