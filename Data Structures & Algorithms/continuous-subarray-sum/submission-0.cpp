class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remIndex;
        remIndex[0] = -1;

        long long prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if (remIndex.count(rem)) {
                if (i - remIndex[rem] > 1)
                    return true;
            } else {
                remIndex[rem] = i; // store first occurrence
            }
        }

        return false;
    }
};