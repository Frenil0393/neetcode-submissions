class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> countMap;
        countMap[0] = 1; // base case
        int prefixSum = 0, result = 0;
        
        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k; // handle negatives
            if (countMap.count(remainder)) {
                result += countMap[remainder];
            }
            countMap[remainder]++;
        }
        return result;
    }
};
