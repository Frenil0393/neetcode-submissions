class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        
        auto canForm = [&](int mid) {
            int count = 0;
            for (int i = 0; i < nums.size() - 1; ) {
                if (nums[i+1] - nums[i] <= mid) {
                    count++;
                    i += 2; // use both indices
                } else {
                    i++;
                }
                if (count >= p) return true;
            }
            return false;
        };
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canForm(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
