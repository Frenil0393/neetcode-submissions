class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Frequency array since nums[i] <= 500
        vector<int> freq(501, 0);
        
        // Count occurrences
        for (int num : nums) {
            freq[num]++;
        }
        
        // Check if all counts are even
        for (int count : freq) {
            if (count % 2 != 0) return false;
        }
        
        return true;
    }
};
