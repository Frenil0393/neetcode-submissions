class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int num : nums) {
            // If num has appeared before, each previous occurrence forms a good pair
            count += freq[num];
            freq[num]++;
        }
        
        return count;
    }
};
