class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0); // since arr[i] <= 500
        
        // Count frequencies
        for(int num : arr) {
            freq[num]++;
        }
        
        int result = -1;
        // Check lucky condition
        for(int i = 1; i <= 500; i++) {
            if(freq[i] == i) {
                result = i; // keep updating with latest lucky integer
            }
        }
        
        return result;
    }
};
