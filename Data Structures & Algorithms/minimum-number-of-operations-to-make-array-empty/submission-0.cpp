class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 0;

        for (auto &p : freq) {
            int f = p.second;

            if (f == 1) {
                return -1;
            }

            ans += (f + 2) / 3; // ceil(f / 3)
        }

        return ans;
    }
};