class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<vector<int>> ans;

        for (int num : nums) {
            int row = freq[num];

            if (row == ans.size()) {
                ans.push_back({});
            }

            ans[row].push_back(num);
            freq[num]++;
        }

        return ans;
    }
};