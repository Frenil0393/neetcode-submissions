class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int x = 1; x <= n; x++) {
            // Count how many elements >= x
            int count = nums.end() - lower_bound(nums.begin(), nums.end(), x);
            if (count == x) return x;
        }
        
        return -1;
    }
};
