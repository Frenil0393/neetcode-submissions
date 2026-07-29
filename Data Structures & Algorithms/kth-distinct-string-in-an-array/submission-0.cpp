class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        
        // Count frequency of each string
        for (auto &s : arr) {
            freq[s]++;
        }
        
        // Traverse in original order and check distinct ones
        for (auto &s : arr) {
            if (freq[s] == 1) {
                k--;
                if (k == 0) return s;
            }
        }
        
        return "";
    }
};
