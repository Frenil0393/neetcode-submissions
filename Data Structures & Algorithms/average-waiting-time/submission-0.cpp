class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWait = 0;   // sum of all waiting times
        long long currentTime = 0; // when the chef is free

        for (auto &c : customers) {
            int arrival = c[0];
            int cookTime = c[1];

            // Chef starts at max(currentTime, arrival)
            if (currentTime < arrival) {
                currentTime = arrival;
            }

            currentTime += cookTime; // finish time
            totalWait += (currentTime - arrival); // waiting time for this customer
        }

        return (double)totalWait / customers.size();
    }
};
