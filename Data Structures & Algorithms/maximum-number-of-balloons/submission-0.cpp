class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        
        // Count frequency of each character
        for (char c : text) {
            freq[c - 'a']++;
        }
        
        // Calculate possible instances
        int countB = freq['b' - 'a'] / 1;
        int countA = freq['a' - 'a'] / 1;
        int countL = freq['l' - 'a'] / 2;
        int countO = freq['o' - 'a'] / 2;
        int countN = freq['n' - 'a'] / 1;
        
        // Minimum of all counts
        return min({countB, countA, countL, countO, countN});
    }
};
