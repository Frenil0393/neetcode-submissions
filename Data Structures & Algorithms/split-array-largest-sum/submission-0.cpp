class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        while (left < right) {
            long long mid = left + (right - left) / 2;
            int cnt = 1;
            long long sum = 0;
            for (int n : nums) {
                if (sum + n > mid) {
                    cnt++;
                    sum = 0;
                }
                sum += n;
            }
            if (cnt > k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
