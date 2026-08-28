class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int whiteCount = 0;

        // Count whites in the first window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }

        int minOps = whiteCount;

        // Slide the window
        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') whiteCount--;  // remove leftmost
            if (blocks[i] == 'W') whiteCount++;      // add rightmost
            minOps = min(minOps, whiteCount);
        }

        return minOps;
    }
};
