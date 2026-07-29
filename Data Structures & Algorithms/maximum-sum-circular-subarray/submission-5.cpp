class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;
        
        for (int x : nums) {
            total += x;
            
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);
            
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }
        
        if (maxSum < 0) return maxSum;       // all negative case
        return max(maxSum, total == minSum ? maxSum : total - minSum);
    }
};
