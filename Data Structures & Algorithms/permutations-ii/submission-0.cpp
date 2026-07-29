class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        
        function<void()> backtrack = [&]() {
            if (path.size() == nums.size()) {
                res.push_back(path);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                backtrack();
                path.pop_back();
                used[i] = false;
            }
        };
        
        backtrack();
        return res;
    }
};
