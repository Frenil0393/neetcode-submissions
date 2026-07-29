class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(nums, target, 0, current, result);
        return result;
    }
    
    void dfs(vector<int>& nums, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (index == nums.size() || target < 0) return;
        
        current.push_back(nums[index]);
        dfs(nums, target - nums[index], index, current, result);
        current.pop_back();
        
        dfs(nums, target, index + 1, current, result);
    }
};
