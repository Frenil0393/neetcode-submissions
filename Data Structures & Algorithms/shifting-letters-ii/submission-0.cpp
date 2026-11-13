class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        // Difference array of size n + 1 to handle the (end + 1) boundary easily
        vector<int> diff(n + 1, 0);
        
        // Populate the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }
        
        int currentShift = 0;
        // Apply the cumulative shifts to the string
        for (int i = 0; i < n; ++i) {
            currentShift += diff[i];
            
            // Normalize the shift to prevent negative numbers and wrap it within 0-25
            int netShift = (currentShift % 26 + 26) % 26;
            
            // Shift the character and wrap around the alphabet
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }
        
        return s;
    }
};