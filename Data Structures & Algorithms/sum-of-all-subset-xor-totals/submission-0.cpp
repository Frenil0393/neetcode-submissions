class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
    
    int dfs(vector<int>& nums, int index, int currentXor) {
        if (index == nums.size()) return currentXor;
        return dfs(nums, index + 1, currentXor ^ nums[index]) +
               dfs(nums, index + 1, currentXor);
    }
};
