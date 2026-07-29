class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        
        sort(nums.rbegin(), nums.rend()); // sort descending for pruning
        vector<int> buckets(k, 0);
        
        return backtrack(nums, buckets, target, 0);
    }
    
    bool backtrack(vector<int>& nums, vector<int>& buckets, int target, int idx) {
        if (idx == nums.size()) {
            for (int b : buckets) {
                if (b != target) return false;
            }
            return true;
        }
        
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i] + nums[idx] <= target) {
                buckets[i] += nums[idx];
                if (backtrack(nums, buckets, target, idx + 1)) return true;
                buckets[i] -= nums[idx];
            }
            // Optimization: if this bucket was empty and failed, no need to try other empty buckets
            if (buckets[i] == 0) break;
        }
        return false;
    }
};
