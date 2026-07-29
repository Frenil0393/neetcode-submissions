class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        
        function<void(int)> backtrack = [&](int start) {
            res.push_back(path);
            for (int i = start; i < nums.size(); i++) {
                if (i > start && nums[i] == nums[i-1]) continue;
                path.push_back(nums[i]);
                backtrack(i+1);
                path.pop_back();
            }
        };
        
        backtrack(0);
        return res;
    }
};
