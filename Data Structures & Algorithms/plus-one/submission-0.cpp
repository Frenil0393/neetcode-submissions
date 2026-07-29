class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from the last digit backwards
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // Increment and return
                return digits;
            }
            digits[i] = 0;     // Set to 0 and carry over
        }
        
        // If all digits were 9, prepend 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
