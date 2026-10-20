class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int rem = total % p;
        if (rem == 0) return 0;

        unordered_map<int,int> seen;
        seen[0] = -1;  // prefix before start
        long long prefix = 0;
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int cur = prefix % p;
            int target = (cur - rem + p) % p;
            if (seen.count(target)) {
                res = min(res, i - seen[target]);
            }
            seen[cur] = i;
        }
        return res == nums.size() ? -1 : res;
    }
};
