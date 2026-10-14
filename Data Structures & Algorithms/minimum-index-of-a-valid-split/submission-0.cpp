class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find dominant element
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        
        int dominant = -1;
        for (auto &p : freq) {
            if (p.second * 2 > n) {
                dominant = p.first;
                break;
            }
        }
        
        // Step 2: Iterate and check splits
        int totalCount = freq[dominant];
        int prefixCount = 0;
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == dominant) prefixCount++;
            
            int prefixLen = i+1;
            int suffixLen = n - prefixLen;
            
            if (prefixCount * 2 > prefixLen &&
                (totalCount - prefixCount) * 2 > suffixLen) {
                return i;
            }
        }
        
        return -1;
    }
};
