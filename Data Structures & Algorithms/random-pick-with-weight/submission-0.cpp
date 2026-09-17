class Solution {
    vector<int> prefix;  // prefix sum array
    int total;           // total sum of weights
    
public:
    Solution(vector<int>& w) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefix[i] = prefix[i - 1] + w[i];
        }
        total = prefix.back();  // sum of all weights
    }
    
    int pickIndex() {
        // Generate a random number in [1, total]
        int target = rand() % total + 1;
        
        // Binary search to find the corresponding index
        int left = 0, right = prefix.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};