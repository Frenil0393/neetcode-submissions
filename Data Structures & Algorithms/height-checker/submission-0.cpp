class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Step 1: Create a copy of heights
        vector<int> expected = heights;
        
        // Step 2: Sort the copy to get the expected order
        sort(expected.begin(), expected.end());
        
        // Step 3: Count mismatches
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }
        
        return count;
    }
};
