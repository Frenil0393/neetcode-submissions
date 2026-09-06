class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1;
        int prefixSum = 0, count = 0;
        for (int num : nums) {
            prefixSum += num;
            if (prefixCount.count(prefixSum - goal)) {
                count += prefixCount[prefixSum - goal];
            }
            prefixCount[prefixSum]++;
        }
        return count;
    }
};
