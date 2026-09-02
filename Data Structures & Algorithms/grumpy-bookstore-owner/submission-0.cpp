class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseSatisfied = 0;

        // Step 1: Count already satisfied customers
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                baseSatisfied += customers[i];
            }
        }

        // Step 2: Sliding window for extra satisfied customers
        int extra = 0, maxExtra = 0;

        // Initial window
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
        }
        maxExtra = extra;

        // Slide the window
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                extra -= customers[i - minutes];
            }
            maxExtra = max(maxExtra, extra);
        }

        return baseSatisfied + maxExtra;
    }
};
